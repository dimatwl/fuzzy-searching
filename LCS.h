#ifndef __LCS_H__
#define __LCS_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class LCS {
    static std::vector<std::vector<unsigned int> > GetLCSTable(const std::string& inpFirstString, const std::string& inpSecondString);
    static std::string GetLCSFromTable(const std::vector<std::vector<unsigned int> > &inpLCSTable, const std::string& inpFirstString, const std::string& inpSecondString);
    
public:
    static std::string GetLCS(const std::string& inpFirstString, const std::string& inpSecondString);
    static unsigned int GetLCSLength(const std::string& inpFirstString, const std::string& inpSecondString);
};


#endif /* __LCS_H__ */