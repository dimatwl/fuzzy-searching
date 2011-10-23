#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Levenshtein {
    static std::vector<std::vector<unsigned int> > GetLDTable(const std::string& inpFirstString, const std::string& inpSecondString);
    static std::vector<std::string> GetListOfChangesFromTable(const std::vector<std::vector<unsigned int> > &inpLDTable, const std::string& inpFirstString, const std::string& inpSecondString);
    
public:
    static unsigned int GetLD(const std::string& inpFirstString, const std::string& inpSecondString);
    static std::vector<std::string> GetListOfChanges(const std::string& inpFirstString, const std::string& inpSecondString);
};


#endif /* __LEVENSHTEIN_H__ */