#include "levenshtein.h"

std::vector<std::vector<unsigned int> > Levenshtein::GetLDTable(const std::string& inpFirstString, const std::string& inpSecondString){
    std::string s = inpFirstString;
    std::string t = inpSecondString;
    size_t m = s.length();
    size_t n = t.length();
    std::vector<std::vector<unsigned int> > d(m+1, std::vector<unsigned int>(n+1));
    for (size_t i = 0; i <= m; i++)
        d[i][0] = i;
    for (size_t j = 0; j <= n; j++)
        d[0][j] = j;
    for (size_t i = 1; i <= m; i++){
        for (size_t j = 1; j <= n; j++){
            if (s[i-1] == t[j-1])
                d[i][j] = d[i-1][j-1];
            else 
                d[i][j] = std::min(std::min(
                                   d[i-1][j] + 1,   // a deletion
                                   d[i][j-1] + 1),   // an insertion
                                   d[i-1][j-1] + 1  // a substitution
                                   );
        }
    }
    return d;

}

std::vector<std::string> Levenshtein::GetListOfChangesFromTable(const std::vector<std::vector<unsigned int> > &inpLDTable, const std::string& inpFirstString, const std::string& inpSecondString){
    std::string s = inpFirstString;
    std::string t = inpSecondString;
    std::string tmpStr = s;
    size_t i = s.length();
    size_t j = t.length();
    std::vector<std::vector<unsigned int> > d = inpLDTable;
    std::vector<std::string> result(1,tmpStr);
    while (i != 0 || j != 0){
        if (i == 0){
            tmpStr = tmpStr.substr(0,i) + t[j-1] + tmpStr.substr(i,tmpStr.length()-i); // an insertion
            j--;
        }
        else if (j == 0){
            tmpStr = tmpStr.substr(0,i-1) + tmpStr.substr(i,tmpStr.length()-i); // a deletion
            i--;
        }
        else if (d[i-1][j] < d[i][j]){
            tmpStr = tmpStr.substr(0,i-1) + tmpStr.substr(i,tmpStr.length()-i); // a deletion
            i--;
        }
        else if (d[i][j-1] < d[i][j]){
            tmpStr = tmpStr.substr(0,i) + t[j-1] + tmpStr.substr(i,tmpStr.length()-i); // an insertion
            j--;
        }
        else if (d[i-1][j-1] < d[i][j]){
            tmpStr = tmpStr.substr(0,i-1) + t[j-1] + tmpStr.substr(i,tmpStr.length()-i); // a substitution
            i--;
            j--;
        }
        else{
            i--;
            j--;
            continue;
        }
        result.push_back(tmpStr);
    }
    return result;
}


unsigned int Levenshtein::GetLD(const std::string& inpFirstString, const std::string& inpSecondString){
    std::vector<std::vector<unsigned int> > LDTable = Levenshtein::GetLDTable(inpFirstString,inpSecondString);
    return LDTable[LDTable.size()-1][LDTable[LDTable.size()-1].size()-1];
}


std::vector<std::string> Levenshtein::GetListOfChanges(const std::string& inpFirstString, const std::string& inpSecondString){
    std::vector<std::vector<unsigned int> > LDTable = Levenshtein::GetLDTable(inpFirstString,inpSecondString);
    return Levenshtein::GetListOfChangesFromTable(LDTable, inpFirstString,inpSecondString);
}