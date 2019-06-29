#include <stdlib.h>
#include "Personaje.h"
#include "Pantalla.h"

struct PersonajeRep
{
    Imagen i;
    int w,h,x,y;
};

Personaje PersonajeCrea (Imagen i, int w, int h, int x, int y)
{
    Personaje p= malloc(sizeof(struct PersonajeRep));
    p->i=i;
    p->w=w;
    p->h=h;
    p->x=x;
    p->y=y;
    return p;
}

void PersonajeLibera (Personaje p)
{
    free(p);
}
void PersonajeDibuja(Personaje p)
{
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

void PersonajeMueve(Personaje p, int vx, int vy)
{
    int wPantalla=Pantalla_Anchura();
    int hPantalla=Pantalla_Altura();
    p->x+=vx;
    p->y+=vy;
    if (p->x<0) p->x = 0;
    if (p->y<0) p->y = 0;
    if (p->x>wPantalla-p->w) p->x = wPantalla-p->w;
    if (p->y>hPantalla-p->h) p->y = hPantalla-p->h;
}

int PersonajeGetX(Personaje p)
{
    return p->x;
}
int PersonajeGetY(Personaje p)
{
    return p->y;
}

int PersonajeGetW(Personaje p)
{
    return p->w;
}

int PersonajeGetH(Personaje p)
{
    return p->h;
}
