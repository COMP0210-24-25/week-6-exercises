#include "automaton.h"
#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;
using std::string;

int main()
{
    vector<vector<unsigned int>> M{{0, 1}, {0, 1}};
    const vector<char> A{'a', 'b'}; 
    vector<unsigned int> S{1};
    Automaton ends_with_b(A, M, S);
    std::cout << "Read abab = " << ends_with_b.Read("abab") << std::endl;
    std::cout << "Read aaba = " << ends_with_b.Read("aaba") << std::endl;

    return 0;
}