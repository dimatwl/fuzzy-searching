#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>
#include <vector>



using std::vector;
using std::string;


class Levenshtein {
    static vector<vector<unsigned int> > GetLDTable(const string& inpFirstString, const string& inpSecondString);
    static vector<string> GetListOfChangesFromTable(const vector<vector<unsigned int> > &inpLDTable, const string& inpFirstString, const string& inpSecondString);
    
public:
    static unsigned int GetLD(const string& inpFirstString, const string& inpSecondString);
    static vector<string> GetListOfChanges(const string& inpFirstString, const string& inpSecondString);
};


#endif /* __LEVENSHTEIN_H__ */