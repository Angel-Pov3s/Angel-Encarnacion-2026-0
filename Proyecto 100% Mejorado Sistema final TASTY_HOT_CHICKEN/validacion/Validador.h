#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>

class Validador {

public:

    static int leer(std::string msg, int min, int max);

    static std::string leer(std::string msg);

};

#endif