#ifndef __GENERAL_ALGORITHM_H__
#define __GENERAL_ALGORITHM_H__

#include <string>

namespace libfuzzy{

using std::string;

class GeneralAlgorithm{
public:
    virtual double Prefix(const string& pattern, const string& testString) const = 0;
    virtual double Suffix(const string& pattern, const string& testString) const = 0;
    virtual double Mean(const string& pattern, const string& testString) const = 0;
};
}


#endif /* __GENERAL_ALGORITHM_H__ */