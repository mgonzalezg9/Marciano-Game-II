#include "Colision.h"
#include "math.h"
int Colision(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2){
    double cx1,cx2,cy1,cy2,dist,r1,r2;
    cx1=x1+w1/2.0;
    cy1=y1+y1/2.0;
    cx2=x2+w2/2.0;
    cy2=y2+y2/2.0;
    r1=h1/2.0;
    r2=h2/2.0;
    dist=sqrt(pow(cx2-cx1,2.0)+pow(cy2-cy1,2.0));
    return dist<r1+r2;
}
