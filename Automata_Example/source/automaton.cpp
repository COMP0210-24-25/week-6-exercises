#include "automaton.h"

string strip(const map<char, unsigned int> &A, string s)
{
    auto new_end = std::remove_if(s.begin(), s.end(), [&A](char a){return A.find(a) == A.end();});
    s.erase(new_end, s.end());
    return s;
}

Automaton::Automaton(const vector<char> &A, const vector<vector<unsigned int>> &M, const vector<unsigned int> &S) : transition_matrix(M),
                                                                                                                    accepting_states(S),
                                                                                                                    alphabet(setup_alphabet(A))
{
    // Check matrix form and content
    unsigned int num_states = transition_matrix.size();
    for (auto &row : transition_matrix)
    {
        if (row.size() != A.size())
        {
            throw std::logic_error("Each row in transition matrix must have one entry per character.");
        }
        for (auto &element : row)
        {
            if (element >= num_states)
            {
                throw std::logic_error("Element found in transition matrix pointing to non existent state.");
            }
        }
    }

    // Check accepting states
    for (auto s : accepting_states)
    {
        if (s >= num_states)
        {
            throw std::logic_error("Invalid accepting state found.");
        }
    }
    if (accepting_states.size() > num_states)
    {
        throw std::logic_error("Size of accepting state vector should be less than or equal to the number of states.");
    }
}

map<char, unsigned int> Automaton::setup_alphabet(const vector<char> &A)
{
    // Setup alphabet map
    map<char, unsigned int> temp_alphabet;
    for (unsigned int i = 0; i < A.size(); i++)
    {
        temp_alphabet[A[i]] = i;
    }
    return temp_alphabet;
}

bool Automaton::Read(string word)
{
    for (auto &c : word)
    {
        auto it = alphabet.find(c);
        if (it == alphabet.end())
        {
            throw std::domain_error("Invalid character found in input string.");
        }
        unsigned int j = it->second;
        state = transition_matrix[state][j];
    }

    bool accept = std::find(accepting_states.begin(), accepting_states.end(), state) != accepting_states.end();
    state = 0;
    return accept;
}
