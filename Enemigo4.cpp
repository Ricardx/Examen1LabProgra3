#include "Enemigo4.h"

Enemigo4::Enemigo4(SDL_Renderer *renderer,list<Personaje*>*personajes)
{
    this->renderer = renderer;
    this->personajes = personajes;
    int w,h;
    textura = IMG_LoadTexture(renderer, "shurikens.png");
    SDL_QueryTexture(textura, NULL, NULL, &w, &h);
    rect_textura.x = 640;
    rect_textura.y = 70;
    rect_textura.w = w;
    rect_textura.h = h;

    textura_bala = IMG_LoadTexture(renderer, "bala4.png");
    SDL_QueryTexture(textura_bala, NULL, NULL, &w, &h);
    rect_bala.x = 640;
    rect_bala.y = 70;
    rect_bala.w = w;
    rect_bala.h = h;

    velocidad=3;
    velocidad_bala=2;
}

void Enemigo4::dibujar()
{
    SDL_RenderCopy(renderer, textura, NULL, &rect_textura);
    for(int i=0;i<rect_balas.size();i++)
        SDL_RenderCopy(renderer, textura_bala, NULL, &rect_balas[i]);
}

void Enemigo4::logica(bool *ase)
{
    for(int i=0;i<rect_balas.size();i++)
    {
        rect_balas[i].y-=velocidad_bala;
        rect_balas[i].x-=velocidad_bala;
    }

    if(frame%50==0)
        {
            SDL_Rect temp;
            temp.x=rect_textura.x;
            temp.y=rect_textura.y;
            temp.w=rect_bala.w;
            temp.h=rect_bala.h;
            rect_balas.push_back(temp);
        }

    list<Personaje*>::iterator i=personajes->begin();
    for(int j=0; j<rect_balas.size();j++)
    {
            if(this==*i)
            continue;
            SDL_Rect rect1 = rect_balas[j];
            SDL_Rect rect2 = (*i)->rect_textura;
            if((rect1.x+rect1.w<rect2.x)==false//Muy a la izq
                && (rect1.x>rect2.x+rect2.w)==false//Muy a la der
                && (rect1.y+rect1.h<rect2.y)==false//Muy arriba
                && (rect1.y>rect2.y+rect2.h)==false//Muy abajo
               )
            {
                cout<<"perdiste"<<endl;
                personajes->erase(i);
                rect_balas.erase(rect_balas.begin()+j);
                *ase=true;
                return;
            }
            if(rect_balas[j].y>=480)
            {
                rect_balas.erase(rect_balas.begin()+j);
                break;
            }
        }
    frame++;

    rect_textura.x-=3;
    rect_textura.y+=3;

    if(rect_textura.y==480)
    {
    rect_textura.x = 640;
    rect_textura.y = 70;
    }
}

Enemigo4::~Enemigo4()
{
    //dtor
}
