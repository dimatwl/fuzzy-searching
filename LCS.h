#ifndef __LCS_H__
#define __LCS_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::max;

class LCS {
    static vector<vector<unsigned int> > GetLCSTable(const string& inpFirstString, const string& inpSecondString);
    static string GetLCSFromTable(const vector<vector<unsigned int> > &inpLCSTable, const string& inpFirstString, const string& inpSecondString);
    
public:
    static string GetLCS(const string& inpFirstString, const string& inpSecondString);
    static unsigned int GetLCSLength(const string& inpFirstString, const string& inpSecondString);
};


#endif /* __LCS_H__ */