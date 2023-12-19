#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "modelo.h";
#include <vector>

class controlador
{
private:
    vector<Modelo> listaTareas;
public:
    controlador();
    void agregarNuevaTarea();
    void eliminarTarea();
    void modificarTarea();
};

#endif // CONTROLADOR_H
