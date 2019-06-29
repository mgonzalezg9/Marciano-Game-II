#include "Enemigo.h"
#include <stdlib.h>

struct EnemigoRep{
    Imagen i;
    int w,h,x,y,vx,vy;
};

Enemigo EnemigoCrea (Imagen i, int w, int h, int x, int y, int vx, int vy){
    Enemigo p= malloc(sizeof(struct EnemigoRep));
    p->i=i;
    p->w=w;
    p->h=h;
    p->x=x;
    p->y=y;
    if (rand()%2==1) p->vx=-vx;
    else p->vx=vx;
    p->vy=vy;
    return p;
}

void EnemigoLibera (Enemigo p){
    free(p);
}

int EnemigoMueve(Enemigo p){
    int wPantalla=Pantalla_Anchura();
    int hPantalla=Pantalla_Altura();
    p->x+=p->vx;
    p->y+=p->vy;
    if (p->x<0){p->x = 0; p->vx*=-1;}
    if (p->y<0) p->y = 0;
    if (p->x>wPantalla-p->w) {p->x = wPantalla-p->w; p->vx*=-1;}
    if (p->y>hPantalla-p->h){p->y = 0 ;return 1;}
    return 0;
}

void EnemigoDibuja(Enemigo p){
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

int EnemigoGetX(Enemigo p)
{
    return p->x;
}

int EnemigoGetY(Enemigo p)
{
    return p->y;
}

int EnemigoGetW(Enemigo p)
{
    return p->w;
}

int EnemigoGetH(Enemigo p)
{
    return p->h;
}
