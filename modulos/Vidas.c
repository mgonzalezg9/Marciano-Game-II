#include "Vidas.h"
#include "stdlib.h"

struct VidasRep {
    Vida * e;
    int max,n;
};

Vidas VidasCrea(int max) {
    Vidas e=malloc(sizeof(struct VidasRep)); // Creación de la estructura
    e->e =malloc(sizeof(Vida)*max);
    e->max=max;
    e->n=0;
    return e;
};

void VidasLibera (Vidas p) {
    for (int i=0; i<p->n; i++) {
        VidaLibera(p->e[i]);
    }

    free(p->e);
    free(p);

};

void VidasDibuja(Vidas p) {
    for (int i=0; i<p->n; i++)
        VidaDibuja(p->e[i]);

};

void VidasRellena(Vidas e, Imagen i, int w, int h, int x, int y) {
    while (e->n < e->max) {
        Vida v1=VidaCrea(i,w,h,x+e->n*30,y);
        e->e[e->n]=v1;
        e->n++;
    }
}

void VidasEliminaVida(Vidas v) {
    v->n--;
    VidaLibera(v->e[v->n]);
};

int VidasGetVida(Vidas v) {
    return (v->n);
}

