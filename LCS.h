#ifndef __LCS_H__
#define __LCS_H__

#include <string>
#include <vector>
#include "general_algorithm.h"
#include "matching_algorithm.h"


using std::vector;
using std::string;
using std::max;

class LCS: public GeneralAlgorithm, public MatchingAlgorithm {
    vector<vector<unsigned int> > GetLCSTable(const string& inpFirstString, const string& inpSecondString) const;
    string GetLCSFromTable(const vector<vector<unsigned int> > &inpLCSTable, const string& inpFirstString, const string& inpSecondString) const;
    string GetLCS(const string& inpFirstString, const string& inpSecondString) const;
    unsigned int GetLCSLength(const string& inpFirstString, const string& inpSecondString) const;

    string myPattern;
    unsigned int myDistance;

    
public:
    double Prefix(const string& pattern, const string& testString) const;
    double Suffix(const string& pattern, const string& testString) const;
    double Mean(const string& pattern, const string& testString) const;

    void SetPattern(const string & pattern, unsigned int distance);
    bool Match(const string& testString) const;
};


#endif /* __LCS_H__ */