#ifndef BALAS_H_INCLUDED
#define BALAS_H_INCLUDED
#include "Bala.h"
#include "Colision.h"
#include "Enemigos.h"

/**

\brief Módulo con operaciones para el conjunto de balas
\file Balas.h

**/

/**
  \brief TDA Balas.
 */

typedef struct BalasRep * Balas;

/**
  \brief Crea una estructura de balas.
  \return Devuelve la estructura creada
 */

Balas BalasCrea();

/**
  \brief Comprueba si alguna bala ha colisionado con un enemigo.
  \param b TDA Balas.
  \param e TDA Enemigos.
  \return 0 si no ha habido colisión con ningún enemigo.
  \return 1 si ha habido colisión con algún enemigo.
 */

int BalasColision(Balas b, Enemigos e);

/**
  \brief Libera todas las balas.
  \param b TDA Balas.
 */

void BalasLibera (Balas b);

/**
  \brief Recorre la estructura de balas y las mueve.
  \param e TDA Balas.
 */

void BalasMueve (Balas e);

/**
  \brief Recorre la estructura de balas y las dibuja todas.
  \param e TDA Balas.
 */

void BalasDibuja(Balas e);

/**
  \brief Inserta una nueva bala en la estructura.
  \param e TDA Balas.
  \param bala TDA Bala (nuevo enemigo que va a insertarse).
 */

void BalasInsertaNuevaBala(Balas e, Bala bala);


#endif // BALAS_H_INCLUDED
