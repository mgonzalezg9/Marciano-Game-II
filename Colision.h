#ifndef COLISION_H_INCLUDED
#define COLISION_H_INCLUDED

/**

\file Colision.h
\brief Módulo para comprobaciones de colisión entre elementos.

**/

/**
  \brief Comprueba si ha habido colisión entre elementos con distintas características.
  \param x1 Coordenada x del primer elemento.
  \param y1 Coordenada y del primer elemento.
  \param h1 Altura del primer elemento.
  \param w1 Anchura del primer elemento.
  \param x2 Coordenada x del segundo elemento.
  \param y2 Coordenada y del segundo elemento.
  \param h2 Altura del segundo elemento.
  \param w2 Anchura del segundo elemento.
 */

int Colision(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2); // Calcula el radio del circulo con los centros (x/2,y/2) y TP (h/2 y w/2, a^2=b^2+c^2); si la dis entre centros es < suma radios.



#endif // COLISION_H_INCLUDED
