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

void FuzzyLib::ProcessSymbols(const string& testString){
	return this->myMatchingAlgorithm->ProcessSymbols(testString);
}

bool FuzzyLib::IsMatched() const{
	return this->myMatchingAlgorithm->IsMatched();
}

bool FuzzyLib::IsUnacceptable() const{
	return this->myMatchingAlgorithm->IsUnacceptable();
}