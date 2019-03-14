#include "Estrellas.h"
#include "Colision.h"
#include "stdlib.h"
struct EstrellasRep
{
    Estrella * e;
    int max,n;
};
Estrellas EstrellasCrea(int max)
{
    Estrellas e=malloc(sizeof(struct EstrellasRep));
    e->e =malloc(sizeof(Estrella)*max);
    e->max=max;
    e->n=0;
    return e;
};

int EstrellasColision(Estrellas s, int x, int y, int h, int w)
{
    int i=0;
    while ((i<s->n)&&(!Colision(EstrellaGetX(s->e[i]),EstrellaGetY(s->e[i]),EstrellaGetH(s->e[i]),EstrellaGetW(s->e[i]),x,y,h,w))){
        i++;
    };
    int colision=(i<s->n); //(Colision(x,y,h,w,EstrellaGetX(s->e[i]),EstrellaGetY(s->e[i]),EstrellaGetH(s->e[i]),EstrellaGetW(s->e[i])));
    if (colision){
        EstrellaLibera(s->e[i]);
        s->e[i]=s->e[s->n-1];
        s->n--;
    }
    return colision;
};

void EstrellasLibera (Estrellas p)
{
    for (int i=0; i<p->n; i++){
        EstrellaLibera(p->e[i]);
    }
    free(p->e);
    free(p);

};

void EstrellasDibuja(Estrellas p)
{
    for (int i=0; i<p->n; i++) EstrellaDibuja(p->e[i]);

};

void EstrellasInsertaNuevaEstrella(Estrellas e, Estrella estrella)
{
    if (e->n<e->max)
    {
        e->e[e->n]=estrella;
        e->n++;
    }
};

