#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class InputException : public runtime_error {

public:

    InputException(const string& msg)
        : runtime_error(msg) {}

};

#endif