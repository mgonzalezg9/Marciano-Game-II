#include "Personajes.h"
#include <stdlib.h>

struct PersonajesRep
{
    Personaje p;
    Personajes sig, ant;
};

struct ListaRep
{
    Personajes primero;
    int n;
};

Lista PersonajesCrea()
{
    Lista l=malloc(sizeof(struct ListaRep));
    l->primero=malloc(sizeof(struct PersonajesRep));
    l->n=0;
    l->primero->sig=l->primero;
    l->primero->ant=l->primero;
    return l;
}

Personaje PersonajesEligeSiguiente(Lista l)
{
    l->primero=l->primero->sig;
    //PersonajeDibuja(l->primero->p);
    return l->primero->p;
}

Personaje PersonajesEligeAnterior(Lista l)
{
    l->primero=l->primero->ant;
    //PersonajeDibuja(l->primero->p);
    return l->primero->ant->p;
}

Personaje PersonajesEligeActual(Lista l)
{
    //PersonajeDibuja(l->primero->p);
    return l->primero->p;
}

void PersonajesInsertaNuevoPersonaje(Lista l, Personaje personaje) // Inserta un personaje en el úlitmo lugar
{
    if (l->primero->sig==l->primero) l->primero->p=personaje;
    else
    {
    Personajes aux=malloc(sizeof(struct PersonajesRep)); // Personaje a insertar
    aux->sig=l->primero;
    aux->ant=l->primero->ant;
    l->primero->ant=aux;
    aux->ant->sig=aux;
    aux->p=personaje;
    }
    l->n++;
};

void PersonajesLibera(Lista l)
{
    while (l->primero->sig!=l->primero)
    {
        Personajes aux= l->primero->sig;
        l->primero->sig=aux->sig;
        PersonajeLibera(aux->p);
        free(aux);
    }
    free(l->primero);
    free(l);
}
