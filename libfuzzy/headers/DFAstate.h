
#ifndef __DFASTATE_H__
#define __DFASTATE_H__

#include <set>

#include "NFAstate.h"

namespace libfuzzy{

    using std::set;

//Declarations:

template <class T>
class DFAState{

    set<NFAState<T>, NFAStateComparation<T> > value;
    
public:
    DFAState();
    DFAState(const NFAState<T>& inpNFAState);
    DFAState(const set<NFAState<T>, NFAStateComparation<T> >& inpNFAStates);
    void AddNFAState(const NFAState<T>& inpNFAState);
    
    const set<NFAState<T>, NFAStateComparation<T> >& GetValue() const;
};

template <class T>
class DFAStateComparation{
public:
    bool operator() (const DFAState<T>& lhs, const DFAState<T>& rhs) const;
};

template <class T>
bool operator<(const DFAState<T>& inpLeftDFAState, const DFAState<T>& inpRightDFAState);

//Definitions:

template <class T>
DFAState<T>::DFAState(){}

template <class T>
DFAState<T>::DFAState(const NFAState<T>& inpNFAState){
    this->value.insert(inpNFAState);
}

template <class T>
DFAState<T>::DFAState(const set<NFAState<T>, NFAStateComparation<T> >& inpNFAStates){
    this->value = inpNFAStates;
}

template <class T>
void DFAState<T>::AddNFAState(const NFAState<T>& inpNFAState){
    this->value.insert(inpNFAState);
}

template <class T>
const set<NFAState<T>, NFAStateComparation<T> >& DFAState<T>::GetValue() const{
    return this->value;
}


template <class T>
bool DFAStateComparation<T>::operator()(const DFAState<T>& lhs, const DFAState<T>& rhs) const{
    return lhs<rhs;
}

template <class T>
bool operator<(const DFAState<T>& inpLeftDFAState, const DFAState<T>& inpRightDFAState){
    typename set<NFAState<T>, NFAStateComparation<T> >::reverse_iterator iterLeft = inpLeftDFAState.GetValue().rbegin();
    typename set<NFAState<T>, NFAStateComparation<T> >::reverse_iterator iterRight = inpRightDFAState.GetValue().rbegin();
    while (iterLeft != inpLeftDFAState.GetValue().rend() && iterRight != inpRightDFAState.GetValue().rend())
        if (*iterLeft < *iterRight)
            return true;
        else if (*iterRight < *iterLeft)
            return false;
        else{
            ++iterLeft;
            ++iterRight;
            continue;
        }
    return inpLeftDFAState.GetValue().size() < inpRightDFAState.GetValue().size();
}
}

#endif /* __DFASTATE_H__ */