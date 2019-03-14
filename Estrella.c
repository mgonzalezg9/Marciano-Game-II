#include "Estrella.h"
#include <stdlib.h>
struct EstrellaRep
{
    Imagen i;
    int w,h,x,y;
};

Estrella EstrellaCrea (Imagen i, int w, int h, int x, int y)
{
    Estrella p= malloc(sizeof(struct EstrellaRep));
    p->i=i;
    p->w=w;
    p->h=h;
    p->x=x;
    p->y=y;
    return p;
}

void EstrellaLibera (Estrella p)
{
    free(p);
}
void EstrellaDibuja(Estrella p)
{
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

int EstrellaGetX(Estrella p)
{
    return p->x;
}
int EstrellaGetY(Estrella p)
{
    return p->y;
}

int EstrellaGetW(Estrella p)
{
    return p->w;
}

int EstrellaGetH(Estrella p)
{
    return p->h;
}

