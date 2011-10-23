#include "LCS.h"

std::vector<std::vector<unsigned int> > LCS::GetLCSTable(const std::string & inpFirstString, const std::string & inpSecondString){
    std::string X = inpFirstString;
    std::string Y = inpSecondString;
    size_t m = X.length();
    size_t n = Y.length();
    std::vector<std::vector<unsigned int> > c(m+1, std::vector<unsigned int>(n+1));
    for (size_t i = 0; i <= m; i++)
        c[i][0] = 0;
    for (size_t j = 0; j <= n; j++)
        c[0][j] = 0;
    for (size_t i = 1; i <= m; i++){
        for (size_t j = 1; j <= n; j++){
            if (X[i-1] == Y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = std::max(c[i][j-1], c[i-1][j]);
        }
    }
    return c;
}

std::string LCS::GetLCSFromTable(const std::vector<std::vector<unsigned int> > &inpLCSTable, const std::string& inpFirstString, const std::string& inpSecondString){
    std::vector<std::vector<unsigned int> > c = inpLCSTable;
    std::string X = inpFirstString;
    std::string Y = inpSecondString;
    size_t i = X.length();
    size_t j = Y.length();
    std::string LCS = "";
    while (i != 0 && j != 0){
        if (X[i-1] == Y[j-1]){
            LCS.push_back(X[i-1]);
            i--;
            j--;
        }else if(c[i][j-1] > c[i-1][j])
            j--;
        else
            i--;
    }
    reverse (LCS.begin(),LCS.end());
    return LCS;
}


std::string LCS::GetLCS(const std::string& inpFirstString, const std::string& inpSecondString){
    std::vector<std::vector<unsigned int> > LCSTable = LCS::GetLCSTable(inpFirstString,inpSecondString);
    std::string LCS = LCS::GetLCSFromTable(LCSTable,inpFirstString,inpSecondString);
    return LCS;
}


unsigned int LCS::GetLCSLength(const std::string& inpFirstString, const std::string& inpSecondString){
    std::vector<std::vector<unsigned int> > LCSTable = LCS::GetLCSTable(inpFirstString,inpSecondString);
    return LCSTable[LCSTable.size()-1][LCSTable[LCSTable.size()-1].size()-1];
    /*for (size_t i = 0; i < LCSTable.size(); i++){
        for (size_t j = 0; j < LCSTable[i].size(); j++)
            std::cout<<LCSTable[i][j]<<"  ";
        std::cout<<std::endl;
    }*/
    return LCSTable[LCSTable.size()-1][LCSTable[LCSTable.size()-1].size()-1];
}