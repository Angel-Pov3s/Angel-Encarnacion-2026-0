#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

// Lee un entero validando rango y formato
int leerEnteroSeguro(const std::string& mensaje, int min, int max);

// Lee una respuesta "si" o "no"
std::string leerRespuestaSiNo(const std::string& mensaje);

#endif