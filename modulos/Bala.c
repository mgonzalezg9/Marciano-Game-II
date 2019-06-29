#include "Bala.h"
#include <stdlib.h>

struct BalaRep{
    Imagen i;
    int w,h,x,y,vy;
    Bala sig;
};

Bala BalaCrea(Imagen i, int w, int h, int x, int y,int vy){
    Bala p= malloc(sizeof(struct BalaRep));
    p->i=i;
    p->w=w;
    p->h=h;
    p->x=x;
    p->y=y;
    p->vy=vy;
    return p;
}

int BalaMueve(Bala p){
    int hPantalla=Pantalla_Altura();
    p->y-=p->vy;
    if (p->y>hPantalla-p->h){p->y = 0 ;return 1;}
    return 0;
}

void BalaLibera(Bala p){
    free(p);
}

void BalaDibuja(Bala p){
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

int BalaGetX(Bala p){
    return p->x;
}

int BalaGetY(Bala p){
    return p->y;
}

int BalaGetW(Bala p){
    return p->w;
}

int BalaGetH(Bala p){
    return p->h;
}
