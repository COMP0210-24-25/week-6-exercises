#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::map;
using std::string;

class Automaton
{
    public: 
    Automaton(const vector<char> &A, const vector<vector<unsigned int>> &M, const vector<unsigned int> &S);

    static map<char, unsigned int> setup_alphabet(const vector<char> &A);

    bool Read(string word);

    private:
    unsigned int state = 0;
    const map<char, unsigned int> alphabet;
    const vector<vector<unsigned int>> transition_matrix;
    const vector<unsigned int> accepting_states;
};

string strip(const map<char, unsigned int> &A, string s);
