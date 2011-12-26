#ifndef __LIBFUZZY_H__
#define __LIBFUZZY_H__

#include <string>
#include "general_algorithm.h"
#include "matching_algorithm.h"

namespace libfuzzy{

using std::string;

class FuzzyLib{
    MatchingAlgorithm* myMatchingAlgorithm; //Stream algorithm
    GeneralAlgorithm* myGeneralAlgorithm;
public:
    //General interface:
    double Prefix(const string& pattern, const string& testString) const;
    double Suffix(const string& pattern, const string& testString) const;
    double Mean(const string& pattern, const string& testString) const;
    
    //Matching interface:
    void SetPattern(const string & pattern, unsigned int distance);
    bool Match(const string& testString) const;
    void ProcessSymbols(const string& testString);
    bool IsMatched() const;
    bool IsUnacceptable() const;
    void ResetCurrentTestString();
    
    FuzzyLib(GeneralAlgorithm* inpGeneralAlgorithm);
    FuzzyLib(MatchingAlgorithm* inpMatchingAlgorithm);
    
};
}


#endif /* __LIBFUZZY_H__ */