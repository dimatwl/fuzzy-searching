#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>
#include <vector>
#include "general_algorithm.h"


namespace libfuzzy{



using std::vector;
using std::string;
using std::min;


class Levenshtein: public GeneralAlgorithm {
    vector<vector<unsigned int> > GetLDTable(const string& inpFirstString, const string& inpSecondString) const;
    vector<string> GetListOfChangesFromTable(const vector<vector<unsigned int> > &inpLDTable, const string& inpFirstString, const string& inpSecondString) const;
    unsigned int GetLD(const string& inpFirstString, const string& inpSecondString) const;
    vector<string> GetListOfChanges(const string& inpFirstString, const string& inpSecondString) const;

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


#endif /* __LEVENSHTEIN_H__ */