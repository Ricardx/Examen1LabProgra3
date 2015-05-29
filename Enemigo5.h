#ifndef ENEMIGO5_H
#define ENEMIGO5_H

#include "Personaje.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Enemigo5 : public Personaje
{
    public:
        list<Personaje*>*personajes;
        int velocidad;
        int velocidad_bala;

        void dibujar();
        void logica(bool *ase);

        Enemigo5(SDL_Renderer *renderer,list<Personaje*>*personajes);
        virtual ~Enemigo5();
    protected:
    private:
};

#endif // ENEMIGO5_H
