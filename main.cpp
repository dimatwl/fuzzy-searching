#include "main.h"

int main (int argc, char** argv) { 
    string firstString("kitten");
    string secondString("sitting");
    cout<<firstString<<endl;
    cout<<secondString<<endl;
    
    void *lib_handle;
    lib_handle = dlopen("./levenshtein_automata.so", RTLD_NOW);
    LevenshteinAutomata* (*Create)();
    Create = (LevenshteinAutomata*(*)()) dlsym(lib_handle, "Create");
    LevenshteinAutomata* alg = Create();

    FuzzyLib lib(alg);
    
    //cout<<lib->Prefix(firstString,secondString)<<endl;
    lib.SetPattern(firstString,5);
    cout<<lib.Match(secondString)<<endl;
    return 0;
}
