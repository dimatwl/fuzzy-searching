#ifndef __MATCHING_ALGORITHM_H__
#define __MATCHING_ALGORITHM_H__

#include <string>

namespace libfuzzy{

using std::string;

class MatchingAlgorithm{
public:
    virtual void SetPattern(const string & pattern, unsigned int distance) = 0;
    virtual bool Match(const string& testString) const = 0;

    virtual void ProcessSymbols(const string& testString) = 0;
    virtual bool IsMatched() const = 0;
    virtual bool IsUnacceptable() const = 0;
    virtual void ResetCurrentTestString() = 0;
};
}


#endif /* __MATCHING_ALGORITHM_H__ */