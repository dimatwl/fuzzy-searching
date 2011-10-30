#include "main.h"

int main (int argc, char** argv) { 
    string firstString("kitten");
    string secondString("sitting");
    cout<<firstString<<endl;
    cout<<secondString<<endl;
    cout<<"LCS: "<<LCS::GetLCS(firstString,secondString)<<" (length = "<<LCS::GetLCSLength(firstString,secondString)<<" )"<<endl<<endl;
    cout<<"Levenshtein: "<<endl;
    vector<string> listOfChanges = Levenshtein::GetListOfChanges(firstString,secondString);
    for (size_t i = 0; i < listOfChanges.size(); i++)
        cout<<listOfChanges[i]<<endl;
    cout<<"(distance = "<<Levenshtein::GetLD(firstString,secondString)<<" )"<<endl;
    return 0;
}