#include "main.h"

int main (int argc, char** argv) { 
    std::string firstString("kitten");
    std::string secondString("sitting");
    std::cout<<firstString<<std::endl;
    std::cout<<secondString<<std::endl;
    std::cout<<"LCS: "<<LCS::GetLCS(firstString,secondString)<<" (length = "<<LCS::GetLCSLength(firstString,secondString)<<" )"<<std::endl<<std::endl;
    std::cout<<"Levenshtein: "<<std::endl;
    std::vector<std::string> listOfChanges = Levenshtein::GetListOfChanges(firstString,secondString);
    for (size_t i = 0; i < listOfChanges.size(); i++)
        std::cout<<listOfChanges[i]<<std::endl;
    std::cout<<"(distance = "<<Levenshtein::GetLD(firstString,secondString)<<" )"<<std::endl;
    return 0;
}