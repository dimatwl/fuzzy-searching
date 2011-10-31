#include "fuzzy_lib.h"

double FuzzyLib::Prefix(const string& pattern, const string& testString) const{
    return this->algoritm->Prefix(pattern, testString);
}
double FuzzyLib::Suffix(const string& pattern, const string& testString) const{
    return this->algoritm->Suffix(pattern, testString);
}
double FuzzyLib::Mean(const string& pattern, const string& testString) const{
    return this->algoritm->Mean(pattern, testString);
}

FuzzyLib::FuzzyLib(GeneralAlgorithm* inpAlgorithm):algoritm(inpAlgorithm){}

void FuzzyLib::SetAlgorithm(GeneralAlgorithm* inpAlgorithm){
    this->algoritm = inpAlgorithm;
}