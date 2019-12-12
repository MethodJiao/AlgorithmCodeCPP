#include <iostream>
#include "boost/function.hpp"
#include "boost/bind.hpp"

class MyclassA {
public:
    MyclassA() {};

    virtual ~MyclassA() {};

    int Method1(int num) {
        return num;

    };

};

int main() {
    MyclassA myclassA;
    boost::function<int(int)> functionPtr = boost::bind(&MyclassA::Method1, &myclassA, _1);
    int result = functionPtr(2);
    return 0;
}