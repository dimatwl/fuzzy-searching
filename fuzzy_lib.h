#ifndef __FUZZY_LIB_H__
#define __FUZZY_LIB_H__

#include <string>
#include "general_algorithm.h"

using std::string;

class FuzzyLib{
    GeneralAlgorithm* algoritm;
public:
    FuzzyLib(GeneralAlgorithm* inpAlgorithm);
    void SetAlgorithm(GeneralAlgorithm* inpAlgorithm);
    
    double Prefix(const string& pattern, const string& testString) const;
    double Suffix(const string& pattern, const string& testString) const;
    double Mean(const string& pattern, const string& testString) const;
};


#endif /* __FUZZY_LIB_H__ */