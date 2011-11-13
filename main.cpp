#include "main.h"

int main (int argc, char** argv) { 
    string firstString("kitten");
    string secondString("sitting");
    cout<<firstString<<endl;
    cout<<secondString<<endl;
    
    void *lib_handle;
    lib_handle = dlopen("./levenshtein.so", RTLD_NOW);
    Levenshtein* (*Create)();
    Create = (Levenshtein*(*)()) dlsym(lib_handle, "Create");
    Levenshtein* alg = Create();
    
    lib_handle = dlopen("./fuzzy_lib.so", RTLD_NOW);
    FuzzyLib* (*CreateM)(MatchingAlgorithm*);
    CreateM = (FuzzyLib*(*)(MatchingAlgorithm*)) dlsym(lib_handle, "CreateM");
    FuzzyLib* lib = CreateM(alg);
    
    cout<<alg->Prefix(firstString,secondString)<<endl;
    lib->SetPattern(firstString,1);
    cout<<lib->Match(secondString)<<endl;
    return 0;
}
