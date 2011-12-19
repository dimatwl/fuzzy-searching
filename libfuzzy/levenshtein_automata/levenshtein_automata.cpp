#include "levenshtein_automata.h"

using namespace libfuzzy;


LevenshteinAutomata::LevenshteinAutomata(){
}


void LevenshteinAutomata::SetPattern(const string & pattern, unsigned int distance){
    //nfa = NFA((0, 0))
    NFA<unsigned int> nfa(NFAState<unsigned int>(0,0));
    //for i, c in enumerate(term):
    for (unsigned int i = 0; i < pattern.size(); ++i){
        string c(pattern, i, 1);
    //  for e in range(k + 1):
        for (unsigned int e = 0; e < distance + 1; ++e){
    //      # Correct character
    //      nfa.add_transition((i, e), c, (i + 1, e))
            nfa.AddTransition(NFAState<unsigned int>(i,e), NFAState<unsigned int>(i + 1,e), c);
    //      if e < k:
            if (e < distance){
    //          # Deletion
    //          nfa.add_transition((i, e), NFA.ANY, (i, e + 1))
                nfa.AddTransition(NFAState<unsigned int>(i,e), NFAState<unsigned int>(i,e + 1), "ANY");
    //          # Insertion
    //          nfa.add_transition((i, e), NFA.EPSILON, (i + 1, e + 1))
                nfa.AddTransition(NFAState<unsigned int>(i,e), NFAState<unsigned int>(i + 1,e + 1), "EPSILON");
    //          # Substitution
    //          nfa.add_transition((i, e), NFA.ANY, (i + 1, e + 1))
                nfa.AddTransition(NFAState<unsigned int>(i,e), NFAState<unsigned int>(i + 1,e + 1), "ANY");
            }
        }
    }
    //for e in range(k + 1):
    for (unsigned int e = 0; e < distance + 1; ++e){
    //  if e < k:
        if (e < distance)
    //      nfa.add_transition((len(term), e), NFA.ANY, (len(term), e + 1))
            nfa.AddTransition(NFAState<unsigned int>(pattern.size(),e), NFAState<unsigned int>(pattern.size(),e + 1), "ANY");
    //  nfa.add_final_state((len(term), e))
        nfa.AddFinalState(NFAState<unsigned int>(pattern.size(),e));
    }

    this->myDFA = nfa.ToDFA();
    this->myDFA.SetDeadState(DFAState<unsigned int>(NFAState<unsigned int>(pattern.size() + 1,pattern.size() + 1)));
    this->currentState = this->myDFA.GetStartState();
}

bool LevenshteinAutomata::Match(const string& testString) const{
    DFAState<unsigned int> State = this->myDFA.GetStartState();
    for (unsigned int i = 0; i < testString.size(); ++i)
        State = this->myDFA.GetNextDFAState(State, string(testString, i, 1));
    if (this->myDFA.IsFinal(State))
        return true;
    else
        return false;
}

void  LevenshteinAutomata::ProcessSymbols(const string& testString){
    for (unsigned int i = 0; i < testString.size(); ++i)
        this->currentState = this->myDFA.GetNextDFAState(this->currentState, string(testString, i, 1));
}

bool LevenshteinAutomata::IsMatched() const{
    return this->myDFA.IsFinal(this->currentState);
}

bool LevenshteinAutomata::IsUnacceptable() const{
    return this->myDFA.IsDead(this->currentState);
}


extern "C"{
    LevenshteinAutomata* Create(){
        return new LevenshteinAutomata;
    }

    void Destroy(LevenshteinAutomata* obj){
        delete obj;
    }
}
