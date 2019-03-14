#ifndef ESTRELLA_H_INCLUDED
#define ESTRELLA_H_INCLUDED
#include "Pantalla.h"

/**

\brief Implementación del TDA Estrella.
\file Estrella.h

**/

/**
    \brief TDA Estrella
 */

typedef struct EstrellaRep * Estrella;

/**
  \brief Crea una nueva estrella.
  \param i Imagen importada.
  \param w Anchura.
  \param h Altura.
  \param x Abscisa.
  \param y Ordenada.
  \return Devuelve una estrella creada.
 */

Estrella EstrellaCrea(Imagen i, int w, int h, int x, int y);

/**
  \brief Libera una estrella.
  \param p Estrella.
 */

void EstrellaLibera(Estrella p);

/**
  \brief Dibuja una estrella.
  \param p Estrella.
 */

void EstrellaDibuja(Estrella p);

/**
  \brief Obtiene la coordenada x de una estrella.
  \param p Estrella.
  \return Coordenada x de la estrella.
 */

int EstrellaGetX(Estrella p);

/**
  \brief Obtiene la coordenada y de una estrella.
  \param p Estrella.
  \return Coordenada y de la estrella.
 */

int EstrellaGetY(Estrella p);

/**
  \brief Obtiene el ancho de una estrella.
  \param p Estrella.
  \return Ancho de la estrella.
 */

int EstrellaGetW(Estrella p);

/**
  \brief Obtiene el alto de una estrella.
  \param p Estrella.
  \return Alto de la estrella.
 */

int EstrellaGetH(Estrella p);

#endif // ESTRELLA_H_INCLUDED
