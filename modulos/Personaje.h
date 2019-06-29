#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include "Pantalla.h"

/**

\brief Implementación del TDA Personaje.
\file Personaje.h

**/

/**
    \brief TDA Personaje
 */

typedef struct PersonajeRep * Personaje;

/**
  \brief Crea un nuevo personaje.
  \param i TDA Personaje.
  \param w Anchura.
  \param h Altura.
  \param x Abscisa.
  \param y Ordenada.
  \return Devuelve el personaje creado.
 */

Personaje PersonajeCrea (Imagen i, int w, int h, int x, int y);

/**
  \brief Libera un personaje creado.
  \param p TDA Personaje.
 */

void PersonajeLibera (Personaje p);

/**
  \brief Mueve al personaje por la pantalla.
  \param p TDA Personaje.
  \param vx Velocidad en el eje x
  \param vy Velocidad en el eje y
 */

void PersonajeMueve(Personaje p, int vx, int vy);

/**
  \brief Dibuja un personaje.
  \param p TDA Personaje.
 */

void PersonajeDibuja(Personaje p);

/**
  \brief Obtiene la coordenada x de un personaje.
  \param p TDA Personaje.
  \return Coordenada x del personaje.
 */

int PersonajeGetX(Personaje p);

/**
  \brief Obtiene la coordenada y de un personaje.
  \param p TDA Personaje.
  \return Coordenada y del personaje.
 */

int PersonajeGetY(Personaje p);

/**
  \brief Obtiene la anchura de un personaje.
  \param p TDA Personaje.
  \return Anchura del personaje.
 */

int PersonajeGetW(Personaje p);

/**
  \brief Obtiene la altura de un personaje.
  \param p TDA Personaje.
  \return Altura del personaje.
 */

int PersonajeGetH(Personaje p);




#endif // PERSONAJE_H_INCLUDED
