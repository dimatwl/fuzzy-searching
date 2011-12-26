#include "LCS.h"

using namespace libfuzzy;

vector<vector<unsigned int> > LCS::GetLCSTable(const string& inpFirstString, const string& inpSecondString) const{
    string X = inpFirstString;
    string Y = inpSecondString;
    size_t m = X.length();
    size_t n = Y.length();
    vector<vector<unsigned int> > c(m+1, vector<unsigned int>(n+1));
    for (size_t i = 0; i <= m; ++i)
        c[i][0] = 0;
    for (size_t j = 0; j <= n; ++j)
        c[0][j] = 0;
    for (size_t i = 1; i <= m; ++i){
        for (size_t j = 1; j <= n; ++j){
            if (X[i-1] == Y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i][j-1], c[i-1][j]);
        }
    }
    return c;
}

string LCS::GetLCSFromTable(const vector<std::vector<unsigned int> > &inpLCSTable, const string& inpFirstString, const string& inpSecondString) const{
    vector<vector<unsigned int> > c = inpLCSTable;
    string X = inpFirstString;
    string Y = inpSecondString;
    size_t i = X.length();
    size_t j = Y.length();
    string LCS = "";
    while (i != 0 && j != 0){
        if (X[i-1] == Y[j-1]){
            LCS.push_back(X[i-1]);
            --i;
            --j;
        }else if(c[i][j-1] > c[i-1][j])
            --j;
        else
            --i;
    }
    reverse (LCS.begin(),LCS.end());
    return LCS;
}


string LCS::GetLCS(const string& inpFirstString, const string& inpSecondString) const{
    vector<vector<unsigned int> > LCSTable = this->GetLCSTable(inpFirstString,inpSecondString);
    string LCS = this->GetLCSFromTable(LCSTable,inpFirstString,inpSecondString);
    return LCS;
}


unsigned int LCS::GetLCSLength(const string& inpFirstString, const string& inpSecondString) const{
    vector<vector<unsigned int> > LCSTable = this->GetLCSTable(inpFirstString,inpSecondString);
    return LCSTable[LCSTable.size()-1][LCSTable[LCSTable.size()-1].size()-1];
}

double LCS::Prefix(const string& pattern, const string& testString) const{
    return static_cast<double>(this->GetLCSLength(pattern, testString)) / static_cast<double>(pattern.length());
}
double LCS::Suffix(const string& pattern, const string& testString) const{
    return static_cast<double>(this->GetLCSLength(pattern, testString)) / static_cast<double>(testString.length());
}
double LCS::Mean(const string& pattern, const string& testString) const{
    double mean = static_cast<double>(testString.length() +pattern.length()) / 2.0;
    return static_cast<double>(this->GetLCSLength(pattern, testString)) / mean;
}

void LCS::SetPattern(const string & pattern, unsigned int distance){
    this->myPattern = pattern;
    this->myDistance = distance;
}

bool LCS::Match(const string& testString) const{
    if (this->GetLCSLength(this->myPattern, testString) <= myDistance){
        return true;
    } else{
        return false;
    }
}

void LCS::ProcessSymbols(const string& testString){
    this->myTestStr += testString;
}

bool LCS::IsMatched() const{
    if (this->GetLCSLength(this->myPattern, this->myTestStr) <= myDistance){
        return true;
    } else{
        return false;
    }
}

bool LCS::IsUnacceptable() const{
    if (this->myPattern.size() + this->myDistance < this->myTestStr.size()){
        return true;
    } else{
        return false;
    }
}

void LCS::ResetCurrentTestString(){
    this->myTestStr.clear();
}


extern "C"{
    LCS* Create(){
        return new LCS;
    }

    void Destroy(LCS* obj){
        delete obj;
    }
}