#include "Balas.h"
#include "stdlib.h"

struct BalasRep
{
    Bala b;
    Balas sig;
};

Balas BalasCrea(){
    Balas b=malloc(sizeof(struct BalasRep));
    b->sig=NULL;
    return b;
}

int BalasColision(Balas b, Enemigos e){
    int Muertos=0;
    while (b->sig!=NULL)
        {
            if (EnemigosColision(e, BalaGetX(b->sig->b), BalaGetY(b->sig->b), BalaGetH(b->sig->b), BalaGetW(b->sig->b)))
            {
                Muertos++;
                printf("[Disparo] Enemigo eliminado\n");
            }
            b=b->sig;
        }
    return Muertos;
}

void BalasLibera (Balas b){
    while(b->sig!=NULL)
    {
        Balas aux = b->sig;
        b->sig=b->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }
    free(b);
}

void BalasMueve(Balas e){
    while (e->sig!=NULL)
    {
        if (BalaMueve(e->sig->b)){
            Balas aux= e->sig;
            e->sig=e->sig->sig;
            BalaLibera(aux->b);
            free(aux);
        }
        else e=e->sig;
    }

}

void BalasDibuja(Balas e){
    for (e=e->sig;e!=NULL; e=e->sig) BalaDibuja(e->b);
}

void BalasInsertaNuevaBala(Balas e, Bala bala){
    Balas p=malloc(sizeof(struct BalasRep));
    p->sig=e->sig;
    e->sig=p;
    p->b=bala;
}
