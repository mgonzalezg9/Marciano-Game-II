#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
#include "Pantalla.h"

/**

\brief Implementación del TDA Bala
\file Bala.h

**/

/**
  \brief TDA Bala.
 */

typedef struct BalaRep * Bala;

/**
  \brief Crea una nueva bala.
  \param i Imagen importada.
  \param w Anchura.
  \param h Altura.
  \param x Abscisa.
  \param y Ordenada.
  \param vy Velocidad en eje de ordenadas.
  \return Devuelve una nueva bala.
 */

Bala BalaCrea(Imagen i, int w, int h, int x, int y, int vy);

/**
  \brief Mueve la bala por la pantalla.
  \param p TDA Bala
  \return 1 si la bala se ha salido de la pantalla.
  \return 0 si la bala se sitúa correctamente.
*/

int BalaMueve(Bala p);

/**
  \brief Libera la memoria reservada para la bala y sus recursos asociados.
  \param p TDA Bala
 */

void BalaLibera(Bala p);

/**
  \brief Dibuja la bala en la pantalla.
  \param p TDA Bala
*/

void BalaDibuja(Bala p);

/**
  \brief Devuelve la coordenada x de la bala.
  \param p TDA Bala.
  \return Coordenada x de la bala.
*/

int BalaGetX(Bala p);

/**
  \brief Devuelve la coordenada y de la bala.
  \param p TDA Bala.
  \return Coordenada y de la bala.
*/

int BalaGetY(Bala p);

/**
  \brief Devuelve el ancho de la bala.
  \param p TDA Bala.
  \return Ancho de la bala.
*/

int BalaGetW(Bala p);

/**
  \brief Devuelve la altura de la bala.
  \param p TDA Bala.
  \return Altura de la bala.
*/

int BalaGetH(Bala p);


#endif // BALA_H_INCLUDED
