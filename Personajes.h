#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED
#include "Personaje.h"

typedef struct PersonajesRep * Personajes;

typedef struct ListaRep * Lista;

Lista PersonajesCrea();

Personaje PersonajesEligeSiguiente(Lista l);

Personaje PersonajesEligeAnterior(Lista l);

Personaje PersonajesEligeActual(Lista l);

void PersonajesInsertaNuevoPersonaje(Lista l, Personaje personaje); // Inserta un personaje en el úlitmo lugar

void PersonajesLibera(Lista l);

#endif // PERSONAJES_H_INCLUDED
