
#ifndef __NFASTATE_H__
#define __NFASTATE_H__

#include <utility>

namespace libfuzzy{

//Declarations:
using std::pair;

template <class T>
class NFAState{

    pair<T,T> value;

public:
    NFAState(const T& inpFirstValue, const T& inpSecondValue);
    const pair<T,T>& GetValue() const;
};

template <class T>
class NFAStateComparation{
public:
    bool operator() (const NFAState<T>& lhs, const NFAState<T>& rhs) const;
};

template <class T>
bool operator<(const NFAState<T>& inpLeftNFAState, const NFAState<T>& inpRightNFAState);

template <class T>
bool operator<(const pair<T,T>& inpLeftPair, const pair<T,T>& inpRightPair);


//Definitions:

template <class T>
NFAState<T>::NFAState(const T& inpFirstValue, const T& inpSecondValue): value(pair<T,T>(inpFirstValue, inpSecondValue)){}

template <class T>
const pair<T,T>& NFAState<T>::GetValue() const{
    return this->value;
}


template <class T>
bool NFAStateComparation<T>::operator()(const NFAState<T>& lhs, const NFAState<T>& rhs) const{
    return lhs<rhs;
}

template <class T>
bool operator<(const NFAState<T>& inpLeftNFAState, const NFAState<T>& inpRightNFAState){
    return inpLeftNFAState.GetValue() < inpRightNFAState.GetValue();
}

template <class T>
bool operator<(const pair<T,T>& inpLeftPair, const pair<T,T>& inpRightPair){
    if (inpLeftPair.first < inpRightPair.first)
        return true;
    else if (inpLeftPair.first == inpRightPair.first)
        return inpLeftPair.second < inpRightPair.second;
    else
        return false;
}

}


#endif /* __NFASTATE_H__ */
