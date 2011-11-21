
#ifndef lev_avt_pair_h
#define lev_avt_pair_h

template <class T>
class Pair {
    T firstValue;
    T secondValue;

public:
    Pair(const T& inpFirstValue, const T& inpSecondValue);
    const T& GetFirstValue() const;
    const T& GetSecondValue() const;
};

template <class T>
Pair<T>::Pair(const T& inpFirstValue, const T& inpSecondValue): firstValue(inpFirstValue),secondValue(inpSecondValue){}

template <class T>
const T& Pair<T>::GetFirstValue() const{
    return this->firstValue;
}

template <class T>
const T& Pair<T>::GetSecondValue() const{
    return this->secondValue;
}

#endif
