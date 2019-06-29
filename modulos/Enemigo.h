#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Pantalla.h"

/**

\brief Implementación del TDA Enemigo.
\file Enemigo.h

**/

/**
    \brief TDA Enemigo
 */

typedef struct EnemigoRep * Enemigo;

/**
  \brief Crea un nuevo enemigo.
  \param i Imagen importada.
  \param w Anchura.
  \param h Altura.
  \param x Abscisa.
  \param y Ordenada.
  \param vx Velocidad en eje de abscisas.
  \param vy Velocidad en eje de ordenadas.
  \return Devuelve un nuevo enemigo.
 */

Enemigo EnemigoCrea (Imagen i, int w, int h, int x, int y, int vx, int vy);

/**
  \brief Libera la memoria reservada para el enemigo y sus recursos asociados.
  \param p TDA Enemigo

 */

void EnemigoLibera (Enemigo p);

/**
  \brief Mueve el enemigo por la pantalla.
  \param p TDA Enemigo
  \return 1 si el enemigo se ha salido de la pantalla.
  \return 0 si el enemigo se sitúa correctamente.
*/

int EnemigoMueve(Enemigo p);

/**
  \brief Dibuja al enemigo en la pantalla.
  \param p TDA Enemigo
*/

void EnemigoDibuja(Enemigo p);

/**
  \brief Devuelve la coordenada x del enemigo.
  \param p TDA Enemigo
  \return Coordenada x del enemigo
*/

int EnemigoGetX(Enemigo p);

/**
  \brief Devuelve la coordenada y del enemigo.
  \param p TDA Enemigo
  \return Coordenada y del enemigo
*/

int EnemigoGetY(Enemigo p);

/**
  \brief Devuelve la anchura del enemigo.
  \param p TDA Enemigo
  \return Anchura del enemigo
*/

int EnemigoGetW(Enemigo p);

/**
  \brief Devuelve la altura del enemigo.
  \param p TDA Enemigo
  \return Altura del enemigo
*/

int EnemigoGetH(Enemigo p);

#endif // ENEMIGO_H_INCLUDED
