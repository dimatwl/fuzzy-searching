#include "libfuzzy.h"

double FuzzyLib::Prefix(const string& pattern, const string& testString) const{
    return this->myGeneralAlgorithm->Prefix(pattern, testString);
}
double FuzzyLib::Suffix(const string& pattern, const string& testString) const{
    return this->myGeneralAlgorithm->Suffix(pattern, testString);
}
double FuzzyLib::Mean(const string& pattern, const string& testString) const{
    return this->myGeneralAlgorithm->Mean(pattern, testString);
}

FuzzyLib::FuzzyLib(GeneralAlgorithm* inpGeneralAlgorithm):myMatchingAlgorithm(NULL), myGeneralAlgorithm(inpGeneralAlgorithm){}

FuzzyLib::FuzzyLib(MatchingAlgorithm* inpMatchingAlgorithm):myMatchingAlgorithm(inpMatchingAlgorithm), myGeneralAlgorithm(NULL){}


void FuzzyLib::SetPattern(const string & pattern, unsigned int distance){
	return this->myMatchingAlgorithm->SetPattern(pattern, distance);
}

bool FuzzyLib::Match(const string& testString) const{
	return this->myMatchingAlgorithm->Match(testString);
}
