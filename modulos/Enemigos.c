#include "Enemigos.h"
#include <stdlib.h>
#include "Colision.h"

struct EnemigosRep{
    Enemigo e;
    Enemigos sig;
};

Enemigos EnemigosCrea()
{
    Enemigos e=malloc(sizeof(struct EnemigosRep));
    e->sig=NULL;
    return e;
};

void EnemigosLibera(Enemigos e)
{
    while(e->sig!=NULL)
    {
        Enemigos aux = e->sig;
        e->sig=e->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    free(e);
};

void EnemigosDibuja(Enemigos e)
{
    for (e=e->sig;e!=NULL; e=e->sig) EnemigoDibuja(e->e);
};

int EnemigosColision(Enemigos e, int x, int y, int h, int w)
{
    while((e->sig!=NULL)&&(!Colision(EnemigoGetX(e->sig->e),EnemigoGetY(e->sig->e),EnemigoGetH(e->sig->e),EnemigoGetW(e->sig->e),x,y,h,w)))
    {
        e=e->sig;
    }
    int colision=(e->sig!=NULL);
    if (colision)
    {
        Enemigos aux= e->sig;
        e->sig=aux->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    return colision;
};

void EnemigosInsertaNuevoEnemigo(Enemigos e, Enemigo enemigo)
{
    Enemigos p=malloc(sizeof(struct EnemigosRep));
    p->sig=e->sig;
    e->sig=p;
    p->e=enemigo;
};

void EnemigosMueve(Enemigos e)
{
    while (e->sig!=NULL)
    {
        if (EnemigoMueve(e->sig->e)){
            Enemigos aux= e->sig;
            e->sig=e->sig->sig;
            EnemigoLibera(aux->e);
            free(aux);
        }
        else e=e->sig;
    }
}
