#ifndef CHOOSER_HPP
#define CHOOSER_HPP
#include <iostream>
namespace bullpgia {
class Chooser {
public:
    virtual std::string choose(uint) = 0;
};
}

#endif
