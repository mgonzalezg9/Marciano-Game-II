#ifndef ESTRELLAS_H_INCLUDED
#define ESTRELLAS_H_INCLUDED
#include "Estrella.h"

/**

\brief Módulo con operaciones para un conjunto de estrellas.
\file Estrellas.h

**/

/**
    \brief TDA Conjunto de Estrellas
 */

typedef struct EstrellasRep * Estrellas;

/**
  \brief Crea un nuevo array de estrellas.
  \param max máximo número de estrellas que pueden aparecer.
  \return Devuelve el array creado.
 */

Estrellas EstrellasCrea(int max);

/**
  \brief Comprueba si alguna estrella ha colisionado con un elemento.
  \param s TDA Estrellas.
  \param x Abscisa.
  \param y Ordenada.
  \param h Altura.
  \param w Anchura.
  \return 0 si no ha habido colisión con ninguna estrella.
  \return 1 si ha habido colisión con alguna estrella.
 */

int EstrellasColision(Estrellas s, int x, int y, int h, int w);

/**
  \brief Libera todas las estrellas del array.
  \param p TDA Estrellas.
 */

void EstrellasLibera (Estrellas p);

/**
  \brief Recorre el array de estrellas y las dibuja todas.
  \param p TDA Estrellas.
 */

void EstrellasDibuja(Estrellas p);

/**
  \brief Inserta una nueva estrella en el array.
  \param e TDA Estrellas.
  \param estrella TDA Estrella (nueva estrella que va a insertarse).
 */

void EstrellasInsertaNuevaEstrella(Estrellas e, Estrella estrella);

#endif // ESTRELLAS_H_INCLUDED
