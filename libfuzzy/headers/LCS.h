#ifndef __LCS_H__
#define __LCS_H__

#include <string>
#include <vector>
#include <algorithm>
#include "general_algorithm.h"

namespace libfuzzy{

using std::vector;
using std::string;
using std::max;

class LCS: public GeneralAlgorithm {
    vector<vector<unsigned int> > GetLCSTable(const string& inpFirstString, const string& inpSecondString) const;
    string GetLCSFromTable(const vector<vector<unsigned int> > &inpLCSTable, const string& inpFirstString, const string& inpSecondString) const;
    string GetLCS(const string& inpFirstString, const string& inpSecondString) const;
    unsigned int GetLCSLength(const string& inpFirstString, const string& inpSecondString) const;

    string myPattern;
    unsigned int myDistance;
    string myTestStr;
    
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

};
}


#endif /* __LCS_H__ */
