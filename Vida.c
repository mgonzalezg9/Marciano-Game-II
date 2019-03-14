#include "Vida.h"
#include <stdlib.h>

struct VidaRep
{
    Imagen i;
    int w,h,x,y;
};

Vida VidaCrea (Imagen i, int w, int h, int x, int y)
{
    Vida p= malloc(sizeof(struct VidaRep));
    p->i=i;
    p->w=w;
    p->h=h;
    p->x=x;
    p->y=y;
    return p;
}

void VidaLibera (Vida p)
{
    free(p);
}
void VidaDibuja(Vida p)
{
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

int VidaGetX(Vida p)
{
    return p->x;
}
int VidaGetY(Vida p)
{
    return p->y;
}

int VidaGetW(Vida p)
{
    return p->w;
}

int VidaGetH(Vida p)
{
    return p->h;
}

