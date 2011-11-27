#ifndef LEVENSHTEIN_AUTOMATA_H
#define LEVENSHTEIN_AUTOMATA_H

#include "DFA.h"
#include "NFA.h"
#include <string>
#include "general_algorithm.h"
#include "matching_algorithm.h"

using std::string;

class LevenshteinAutomata: public MatchingAlgorithm
{
    mutable DFA<unsigned int> myDFA;
public:
    LevenshteinAutomata();
    void SetPattern(const string & pattern, unsigned int distance);
    bool Match(const string& testString) const;
};

#endif // LEVENSHTEIN_AUTOMATA_H
