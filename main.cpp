#include "main.h"

int main (int argc, char** argv) { 
    string firstString("kitten");
    string secondString("sitting");
    cout<<firstString<<endl;
    cout<<secondString<<endl;
    GeneralAlgorithm* alg = new LCS;
    FuzzyLib lb(alg);
    cout<<"LCS:"<<endl<<"Prefix = "<<lb.Prefix(firstString,secondString)<<endl;
    cout<<"Suffix = "<<lb.Suffix(firstString,secondString)<<endl;
    cout<<"Mean = "<<lb.Mean(firstString,secondString)<<endl;
    delete alg;
    alg = new Levenshtein;
    lb.SetAlgorithm(alg);
    cout<<"Levenshtein:"<<endl<<"Prefix = "<<lb.Prefix(firstString,secondString)<<endl;
    cout<<"Suffix = "<<lb.Suffix(firstString,secondString)<<endl;
    cout<<"Mean = "<<lb.Mean(firstString,secondString)<<endl;
    return 0;
}