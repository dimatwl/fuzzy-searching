#ifndef __FUZZY_LIB_H__
#define __FUZZY_LIB_H__

#include <string>
#include "general_algorithm.h"
#include "matching_algorithm.h"

using std::string;

class FuzzyLib{
    MatchingAlgorithm* myMatchingAlgorithm;
    GeneralAlgorithm* myGeneralAlgorithm;
public:
    FuzzyLib(GeneralAlgorithm* inpGeneralAlgorithm);
    FuzzyLib(MatchingAlgorithm* inpMatchingAlgorithm);
    
    //General interface:
    double Prefix(const string& pattern, const string& testString) const;
    double Suffix(const string& pattern, const string& testString) const;
    double Mean(const string& pattern, const string& testString) const;
    
    //Mathing interface:
    void SetPattern(const string & pattern, unsigned int distance);
    bool Match(const string& testString) const;
    
};


#endif /* __FUZZY_LIB_H__ */