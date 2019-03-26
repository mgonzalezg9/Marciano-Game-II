#include "Enemigo.h"
#include "Personaje.h"
#include "Estrellas.h"
#include "Enemigos.h"
#include "Balas.h"
#include "Vidas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define PuntosBalazo 20
#define WPersonaje 64
#define HPersonaje 64
#define WEnemigo 64
#define HEnemigo 64
#define WBala 15
#define HBala 45
#define WVida 25
#define HVida 25
#define VxPersonaje 20
#define VyPersonaje 20
#define VxEnemigo 10
#define VyEnemigo 10
#define VyBala 30
#define MaxEstrellas 5
#define PosVidas 70
#define DesplzVidas 5
#define ProbApEstrellas 30 // Cuanto menor sea más probable será que aparezcan
#define ProbApEnemigos 10
#define VidaInicial 3

/**

\mainpage Videojuego donde una nave guíada por el usuario debe aguantar el máximo tiempo posible sin chocar con una nave marciana enemiga, para obtener la máxima puntuación posible.
\file Principal.c
\author Manuel González García
\version 1.3

**/

Imagen fondo1, fondo2, fondo3, fondo4;

int main(int argc, char **argv)
{
    Pantalla_Crea("Marciano Game II 1.3",1280,960);
    int wPantalla = Pantalla_Anchura();
    int hPantalla = Pantalla_Altura();
    Pantalla_ColorRelleno(255,255,255,255);
    Pantalla_ColorTrazo(255,0,0,255);
    int fin = 0;
    // Lectura de imágenes
    fondo1=Pantalla_ImagenLee("PantallaInicio.bmp",0);
    fondo2=Pantalla_ImagenLee("EleccionPersonaje.bmp",0);
    fondo3=Pantalla_ImagenLee("PantallaJuego.bmp",0);
    fondo4=Pantalla_ImagenLee("PantallaFinal.bmp",0);
    Imagen Im;
    Imagen Im2=Pantalla_ImagenLee("enemigo.bmp",1);
    Imagen Im3=Pantalla_ImagenLee("estrella.bmp",1);
    Imagen Im4=Pantalla_ImagenLee("bala.bmp",1);
    Imagen Im5=Pantalla_ImagenLee("vida.bmp",1);
    // Contador de interaciones
    int fps=0;
    // FASE 1
    while(Pantalla_Activa()&&(!fin))
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))
        {
            fin=1;
        }
        if (fps>30) fps=0; // Reinicia el contador para evitar un posible desbordamiento
        fps++;
        Pantalla_DibujaImagen(fondo1,0,0,wPantalla,hPantalla);
        //Pantalla_DibujaTexto("Saludos Jugador",300,200);
        if (fps%30<=15) Pantalla_DibujaTexto("Pulsa la tecla [Enter] para continuar",10,hPantalla-35);
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    fin = 0;
    // Liberado de elementos de la pantalla anterior
    Pantalla_ImagenLibera(fondo1);
    // Imágenes del personaje a elegir
    Imagen Imp1=Pantalla_ImagenLee("personaje.bmp",1);
    Imagen Imp2=Pantalla_ImagenLee("personaje2.bmp",1);
    Imagen Imp3=Pantalla_ImagenLee("personaje3.bmp",1);
    // Variables de control
    int sel=0;
    int flag=1;
    // FASE 2
    while(Pantalla_Activa()&&(!fin))
    {
        // Condición de cambio de fase
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE))
        {
            fin=1;
        }
        // Elección de la imagen que tendrá el personaje
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)&&(flag==1)){sel++; flag=0;}
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)&&(flag==1)) {sel--; flag=0;}
        if (!Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && !Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) flag=1;
        switch (sel)
        {
            case 0: Im=Imp1; break;
            case 1: Im=Imp2; break;
            case 2: Im=Imp3; break;
        }
        if (sel>2) sel=2; // Evita que se salga del rango de imágenes
        if (sel<0) sel=0;
        // Dibujado de fondos y menús
        Pantalla_DibujaImagen(fondo2,0,0,wPantalla,hPantalla);
        Pantalla_DibujaImagen(Im,wPantalla/2-WPersonaje,hPantalla/2+50,WPersonaje*2,HPersonaje*2);
        Pantalla_DibujaTexto("Gracias por pulsar la tecla.",100,170);
        Pantalla_DibujaTexto("Para seleccionar un personaje usa las flechas.",100,200);
        Pantalla_DibujaTexto("Para jugar pulse [Espacio].",100,230);
        // Refresco de la pantalla
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    srand(time(NULL));
    // Liberado del fondo
    Pantalla_ImagenLibera(fondo2);
    // Inicialización de TDA
    Personaje p=PersonajeCrea(Im,WPersonaje,HPersonaje,rand()%(wPantalla-WPersonaje),hPantalla-HPersonaje);
    Enemigos e1=EnemigosCrea();
    Estrellas e=EstrellasCrea(MaxEstrellas);
    Balas b=BalasCrea();
    Vidas v=VidasCrea(VidaInicial);
    VidasRellena(v,Im5,WVida,HVida,DesplzVidas,PosVidas);
    // Preparación del nivel
    fin=0;
    int ti=time(NULL);
    int t2;
    int puntos;
    int puntos_estrellas=0;
    int puntos_enemigo=0;
    //fps=0;
    char mensaje[100];
    int BPuntos=0;
    flag=1;
    int primvez=1; // Determina si se ha disparado ya antes
    // FASE 3
    while(Pantalla_Activa()&&(!fin)&&(VidasGetVida(v)>0)/*&&(puntos>=0)*/)
    {
        // Condición de final de juego
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_TAB))
        {
            fin=1;
        }
        // Recuento de los puntos
        t2=time(NULL);
        //if (puntos<0) puntos=t2-ti+puntos_estrellas+BPuntos;
        puntos=t2-ti+puntos_estrellas-puntos_enemigo+BPuntos;
        // Aparición de objetos
        if (rand()%ProbApEstrellas==1)
        {
            Estrella e1=EstrellaCrea(Im3,32,32,rand()%(wPantalla-WPersonaje),rand()%(hPantalla-HPersonaje));
            EstrellasInsertaNuevaEstrella(e,e1);
        }
        if (rand()%ProbApEnemigos<2) // 20% de probabilidad de que aparezca un enemigo
        {
            Enemigo s=EnemigoCrea(Im2,WEnemigo, HEnemigo, rand()%(wPantalla-WPersonaje),0,VxEnemigo,VyEnemigo);
            EnemigosInsertaNuevoEnemigo(e1,s);
        }
        if (EstrellasColision(e,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetH(p),PersonajeGetW(p)))
        {
            puntos_estrellas+=20;
        }
        if (EnemigosColision(e1,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetH(p),PersonajeGetW(p))){
            puntos_enemigo+=20;
            VidasEliminaVida(v);
        }
        BPuntos+=BalasColision(b,e1)*PuntosBalazo;
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_F)&&(flag==1)){
                Bala bala=BalaCrea(Im4,WBala,HBala,PersonajeGetX(p)+25,PersonajeGetY(p),VyBala);
                BalasInsertaNuevaBala(b, bala);
                flag=0;
                primvez=0;
        }
        if (!Pantalla_TeclaPulsada(SDL_SCANCODE_F)) flag=1;
        sprintf(mensaje,"Puntos = %d", puntos);
        // Movimiento del personaje
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p,-VxPersonaje,0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) PersonajeMueve(p,VxPersonaje,0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) PersonajeMueve(p,0,-VxPersonaje);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) PersonajeMueve(p,0,VxPersonaje);
        // Dibuja todo lo que hay en la pantalla
        Pantalla_DibujaImagen(fondo3,0,0,wPantalla,hPantalla);
        EstrellasDibuja(e);
        EnemigosMueve(e1);
        BalasMueve(b);
        BalasDibuja(b);
        EnemigosDibuja(e1);
        PersonajeDibuja(p);
        // Dibuja un pequeño menú
        Pantalla_DibujaTexto("Para terminar el juego pulse [Tab].",10,10);
        Pantalla_DibujaTexto(mensaje,10,40);
        VidasDibuja(v);
        if (primvez) Pantalla_DibujaTexto("Pulse [f] para disparar",10,hPantalla-35); // En el caso de que no se haya disparado antes muestra el control
        // Refresco de la pantalla
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    fin=0;
    // Liberación de las TDA y de las imágenes
    EnemigosLibera(e1);
    EstrellasLibera(e);
    PersonajeLibera(p);
    BalasLibera(b);
    VidasLibera(v);
    Pantalla_ImagenLibera(fondo3);
    //Pantalla_ImagenLibera(Im);
    Pantalla_ImagenLibera(Im2);
    Pantalla_ImagenLibera(Im3);
    Pantalla_ImagenLibera(Im4);
    Pantalla_ImagenLibera(Im5);
    Pantalla_ImagenLibera(Imp1);
    Pantalla_ImagenLibera(Imp2);
    Pantalla_ImagenLibera(Imp3);
    // Guardado de la puntuación
    int datoleido;
    int puntosmax=0;
    FILE * r= fopen("record.txt","r");
    if (r!=NULL)
    {
        while (!feof(r))
        {
            fscanf(r, "%d", &datoleido);
            if (datoleido>puntosmax)
            {
                puntosmax=datoleido;
            }
        }
        fclose(r);
    }
    char texto2[100];
    if (puntosmax<puntos)
        sprintf(texto2,"Nuevo Record = %d",puntos);
    else    sprintf(texto2,"Record = %d",puntosmax);
    r = fopen("record.txt","a");
    fprintf(r,"%d\n",puntos);
    fclose(r);
    // FASE 4
    while (Pantalla_Activa()&&(!fin))
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE))
        {
            fin=1;
        }
        Pantalla_DibujaImagen(fondo4,0,0,wPantalla,hPantalla);
        Pantalla_DibujaTexto("Para salir pulse [Esc].",220,300);
        Pantalla_DibujaTexto(mensaje,255,230);
        Pantalla_DibujaTexto(texto2,250,265);
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    // Liberado de imágenes
    Pantalla_ImagenLibera(fondo4);
    // Libera la pantalla y fin del juego
    Pantalla_Libera();
    return 0;
}


