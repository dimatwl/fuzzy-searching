#ifndef __MATCHING_ALGORITHM_H__
#define __MATCHING_ALGORITHM_H__

#include <string>

using std::string;

class MatchingAlgorithm{
public:
    virtual void SetPattern(const string & pattern, unsigned int distance) = 0;
    virtual bool Match(const string& testString) const = 0;
};


#endif /* __MATCHING_ALGORITHM_H__ */