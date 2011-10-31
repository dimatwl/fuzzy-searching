#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>
#include <vector>
#include "general_algorithm.h"


using std::vector;
using std::string;
using std::min;


class Levenshtein: public GeneralAlgorithm {
    vector<vector<unsigned int> > GetLDTable(const string& inpFirstString, const string& inpSecondString) const;
    vector<string> GetListOfChangesFromTable(const vector<vector<unsigned int> > &inpLDTable, const string& inpFirstString, const string& inpSecondString) const;
    unsigned int GetLD(const string& inpFirstString, const string& inpSecondString) const;
    vector<string> GetListOfChanges(const string& inpFirstString, const string& inpSecondString) const;
    
public:
    double Prefix(const string& pattern, const string& testString) const;
    double Suffix(const string& pattern, const string& testString) const;
    double Mean(const string& pattern, const string& testString) const;
};


#endif /* __LEVENSHTEIN_H__ */