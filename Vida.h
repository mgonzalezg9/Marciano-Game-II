#ifndef VIDA_H_INCLUDED
#define VIDA_H_INCLUDED
#include "Pantalla.h"

/**

\brief Implementación del TDA Vida.
\file Vida.h

**/

/**
    \brief TDA Vida
 */

typedef struct VidaRep * Vida;

/**
  \brief Crea una nueva vida.
  \param i Imagen importada.
  \param w Anchura.
  \param h Altura.
  \param x Abscisa.
  \param y Ordenada.
  \return Devuelve una vida creada.
 */

Vida VidaCrea(Imagen i, int w, int h, int x, int y);

/**
  \brief Libera una vida.
  \param p Vida.
 */

void VidaLibera(Vida p);

/**
  \brief Dibuja una Vida.
  \param p Vida.
 */

void VidaDibuja(Vida p);

/**
  \brief Obtiene la coordenada x de una Vida.
  \param p Vida.
  \return Coordenada x de la Vida.
 */

int VidaGetX(Vida p);

/**
  \brief Obtiene la coordenada y de una Vida.
  \param p Vida.
  \return Coordenada y de la Vida.
 */

int VidaGetY(Vida p);

/**
  \brief Obtiene el ancho de una Vida.
  \param p Vida.
  \return Ancho de la Vida.
 */

int VidaGetW(Vida p);

/**
  \brief Obtiene el alto de una Vida.
  \param p Vida.
  \return Alto de la Vida.
 */

int VidaGetH(Vida p);

#endif // VIDA_H_INCLUDED
