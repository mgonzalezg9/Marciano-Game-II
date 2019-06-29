#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED
#include "Enemigo.h"

/**

\brief Módulo con operaciones para un conjunto de enemigos.
\file Enemigos.h

**/

/**
    \brief TDA Conjunto de Enemigos
 */

typedef struct EnemigosRep * Enemigos;

/**
  \brief Crea una nueva estructura de enemigos.
  \return Devuelve la estructura creada.
 */

Enemigos EnemigosCrea();

/**
  \brief Libera todos los enemigos.
  \param e TDA Enemigos.
 */

void EnemigosLibera(Enemigos e);

/**
  \brief Recorre la estructura de enemigos y los mueve.
  \param e TDA Enemigos.
 */

void EnemigosMueve(Enemigos e);

/**
  \brief Comprueba si algún enemigo ha colisionado con un elemento.
  \param s TDA Enemigos.
  \param x Abscisa.
  \param y Ordenada.
  \param w Anchura.
  \param h Altura.
  \return 0 si no ha habido colisión con ningún enemigo.
  \return 1 si ha habido colisión con algún enemigo.
 */

int EnemigosColision(Enemigos s, int x, int y, int h, int w);

/**
  \brief Recorre la estructura de enemigos y los dibuja todos.
  \param e TDA Enemigos.
 */

void EnemigosDibuja(Enemigos e);

/**
  \brief Inserta un nuevo enemigo en la estructura.
  \param e TDA Enemigos.
  \param enemigo TDA Enemigo (nuevo enemigo que va a insertarse).
 */

void EnemigosInsertaNuevoEnemigo(Enemigos e, Enemigo enemigo);

#endif // ENEMIGOS_H_INCLUDED
