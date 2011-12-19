#include "levenshtein.h"

using namespace libfuzzy;

vector<vector<unsigned int> > Levenshtein::GetLDTable(const string& inpFirstString, const string& inpSecondString) const{
    string s = inpFirstString;
    string t = inpSecondString;
    size_t m = s.length();
    size_t n = t.length();
    vector<vector<unsigned int> > d(m+1, std::vector<unsigned int>(n+1));
    for (size_t i = 0; i <= m; ++i)
        d[i][0] = i;
    for (size_t j = 0; j <= n; ++j)
        d[0][j] = j;
    for (size_t i = 1; i <= m; ++i){
        for (size_t j = 1; j <= n; ++j){
            if (s[i-1] == t[j-1])
                d[i][j] = d[i-1][j-1];
            else 
                d[i][j] = min(min(
                                   d[i-1][j] + 1,   // a deletion
                                   d[i][j-1] + 1),   // an insertion
                                   d[i-1][j-1] + 1  // a substitution
                                   );
        }
    }
    return d;

}

vector<string> Levenshtein::GetListOfChangesFromTable(const vector<vector<unsigned int> > &inpLDTable, const string& inpFirstString, const string& inpSecondString) const{
    string s = inpFirstString;
    string t = inpSecondString;
    string tmpStr = s;
    size_t i = s.length();
    size_t j = t.length();
    vector<vector<unsigned int> > d = inpLDTable;
    vector<string> result(1,tmpStr);
    while (i != 0 || j != 0){
        if (i == 0){
            tmpStr = tmpStr.substr(0,i) + t[j-1] + tmpStr.substr(i,tmpStr.length()-i); // an insertion
            --j;
        }
        else if (j == 0){
            tmpStr = tmpStr.substr(0,i-1) + tmpStr.substr(i,tmpStr.length()-i); // a deletion
            --i;
        }
        else if (d[i-1][j] < d[i][j]){
            tmpStr = tmpStr.substr(0,i-1) + tmpStr.substr(i,tmpStr.length()-i); // a deletion
            --i;
        }
        else if (d[i][j-1] < d[i][j]){
            tmpStr = tmpStr.substr(0,i) + t[j-1] + tmpStr.substr(i,tmpStr.length()-i); // an insertion
            --j;
        }
        else if (d[i-1][j-1] < d[i][j]){
            tmpStr = tmpStr.substr(0,i-1) + t[j-1] + tmpStr.substr(i,tmpStr.length()-i); // a substitution
            --i;
            --j;
        }
        else{
            --i;
            --j;
            continue;
        }
        result.push_back(tmpStr);
    }
    return result;
}


unsigned int Levenshtein::GetLD(const string& inpFirstString, const string& inpSecondString) const{
    vector<vector<unsigned int> > LDTable =this->GetLDTable(inpFirstString,inpSecondString);
    return LDTable[LDTable.size()-1][LDTable[LDTable.size()-1].size()-1];
}


vector<string> Levenshtein::GetListOfChanges(const string& inpFirstString, const string& inpSecondString) const{
    vector<vector<unsigned int> > LDTable = this->GetLDTable(inpFirstString,inpSecondString);
    return this->GetListOfChangesFromTable(LDTable, inpFirstString,inpSecondString);
}

double Levenshtein::Prefix(const string& pattern, const string& testString) const{
    return static_cast<double>(this->GetLD(pattern, testString)) / static_cast<double>(pattern.length());
}
double Levenshtein::Suffix(const string& pattern, const string& testString) const{
    return static_cast<double>(this->GetLD(pattern, testString)) / static_cast<double>(testString.length());
}
double Levenshtein::Mean(const string& pattern, const string& testString) const{
    double mean = static_cast<double>(testString.length() + pattern.length()) / 2.0;
    return static_cast<double>(this->GetLD(pattern, testString)) / mean;
}




extern "C"{
    Levenshtein* Create(){
        return new Levenshtein;
    }

    void Destroy(Levenshtein* obj){
        delete obj;
    }
}