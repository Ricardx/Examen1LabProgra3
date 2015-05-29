#ifndef ENEMIGO4_H
#define ENEMIGO4_H

#include "Personaje.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Enemigo4 : public Personaje
{
    public:
        list<Personaje*>*personajes;
        int velocidad;
        int velocidad_bala;

        void dibujar();
        void logica(bool *ase);

        Enemigo4(SDL_Renderer *renderer,list<Personaje*>*personajes);
        virtual ~Enemigo4();
    protected:
    private:
};

#endif // ENEMIGO4_H
