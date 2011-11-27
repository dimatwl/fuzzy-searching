#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>
#include <vector>
#include "general_algorithm.h"
#include "matching_algorithm.h"


using std::vector;
using std::string;
using std::min;


class Levenshtein: public GeneralAlgorithm, public MatchingAlgorithm {
    vector<vector<unsigned int> > GetLDTable(const string& inpFirstString, const string& inpSecondString) const;
    vector<string> GetListOfChangesFromTable(const vector<vector<unsigned int> > &inpLDTable, const string& inpFirstString, const string& inpSecondString) const;
    unsigned int GetLD(const string& inpFirstString, const string& inpSecondString) const;
    vector<string> GetListOfChanges(const string& inpFirstString, const string& inpSecondString) const;

    string myPattern;
    unsigned int myDistance;
    
public:
    double Prefix(const string& pattern, const string& testString) const;
    double Suffix(const string& pattern, const string& testString) const;
    double Mean(const string& pattern, const string& testString) const;

    void SetPattern(const string & pattern, unsigned int distance);
    bool Match(const string& testString) const;
};


#endif /* __LEVENSHTEIN_H__ */