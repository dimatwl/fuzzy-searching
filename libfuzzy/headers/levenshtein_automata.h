#ifndef LEVENSHTEIN_AUTOMATA_H
#define LEVENSHTEIN_AUTOMATA_H

#include <string>

#include "DFA.h"
#include "NFA.h"
#include "general_algorithm.h"
#include "matching_algorithm.h"

namespace libfuzzy{

using std::string;

class LevenshteinAutomata: public MatchingAlgorithm
{
    mutable DFA<unsigned int> myDFA;
    DFAState<unsigned int> currentState;
public:
    LevenshteinAutomata();

    void SetPattern(const string & pattern, unsigned int distance);
    bool Match(const string& testString) const;

    void ProcessSymbols(const string& testString);
    bool IsMatched() const;
    bool IsUnacceptable() const;
    void ResetCurrentTestString();
};
}

#endif // LEVENSHTEIN_AUTOMATA_H
