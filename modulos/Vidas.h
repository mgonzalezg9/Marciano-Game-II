#ifndef VIDAS_H_INCLUDED
#define VIDAS_H_INCLUDED
#include "Vida.h"
#include "Pantalla.h"

/**

\brief Módulo con operaciones para un conjunto de Vidas.
\file Vidas.h

**/

/**
    \brief TDA Conjunto de Vidas
 */

typedef struct VidasRep * Vidas;

/**
  \brief Crea un nuevo array de Vidas.
  \param max máximo número de Vidas que pueden aparecer.
  \return Devuelve el array creado.
 */

Vidas VidasCrea(int max);

/**
  \brief Libera todas las vidas del array.
  \param p TDA Vidas.
 */

void VidasLibera (Vidas p);

/**
  \brief Recorre el array de Vidas y las dibuja todas.
  \param p TDA Vidas.
 */

void VidasDibuja(Vidas p);

/**
  \brief Rellena el array de vidas.
  \param e TDA Vidas.
  \param i Imagen de la vida.
  \param w Ancho de la vida.
  \param h Alto de la vida.
  \param x Coordenada x de la vida.
  \param y Coordenada y de la vida.
 */

void VidasRellena(Vidas e, Imagen i, int w, int h, int x, int y);

/**
  \brief Elimina una vida del array
  \param s TDA Vidas.
 */

void VidasEliminaVida(Vidas s);

/**
  \brief Devuelve el número de vidas que hay
  \param v TDA Vidas
  \return Devuelve el número de vidas que hay en el array.
 */

int VidasGetVida(Vidas v);

#endif // VIDAS_H_INCLUDED
