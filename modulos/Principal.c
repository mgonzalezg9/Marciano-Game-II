#include "Enemigo.h"
#include "Personaje.h"
#include "Estrellas.h"
#include "Enemigos.h"
#include "Balas.h"
#include "Vidas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <X11/Xlib.h>

#define FACTOR_ESCALADO 0.85 // Resoluci�n de la ventana
#define NUM_ARGS        3

#define PuntosBalazo    20
#define ProbApEstrellas 30 // Cuanto menor sea m�s probable ser� que aparezcan
#define ProbApEnemigos  10
#define VidaInicial     3
#define MaxEstrellas    5
#define LimiteBalas     15 // N�mero m�ximo de balas que se pueden disparar

/**

\mainpage Videojuego donde una nave gu�ada por el usuario debe aguantar el m�ximo tiempo posible sin chocar con una nave marciana enemiga, para obtener la m�xima puntuaci�n posible.
\file Principal.c
\author Manuel Gonz�lez Garc�a
\version 1.4

**/


int main(int argc, char **argv) {
    // Obtenci�n de la resoluci�n de la pantalla
    int ancho, alto;
    if (argc != NUM_ARGS) {
        // Resoluci�n por defecto
        Display* d = XOpenDisplay(NULL);
        Screen*  s = DefaultScreenOfDisplay(d);

        ancho = s->width * FACTOR_ESCALADO;
        alto = s->height * FACTOR_ESCALADO;
    } else {
        ancho = atoi(argv[1]);
        alto = atoi(argv[2]);
    }

    printf("Window resolution: %dx%d\n", ancho, alto);

    // Cargado de las im�genes y creaci�n de la pantalla
    Imagen fondo1, fondo2, fondo3, fondo4;
    Pantalla_Crea("Marciano Game II", ancho, alto);

    int wPantalla = Pantalla_Anchura();
    int hPantalla = Pantalla_Altura();

    Pantalla_ColorRelleno(255, 255, 255, 255);
    Pantalla_ColorTrazo(0, 255, 0, 255);
    int fin = 0;

    // Definici�n de las caracter�sticas de los objetos seg�n la pantalla
    int WPersonaje = wPantalla / 12;
    int HPersonaje = WPersonaje;

    int VPersonaje = WPersonaje / 5;

    int WEnemigo = wPantalla / 12;
    int HEnemigo = WEnemigo;

    int VxEnemigo = VPersonaje * 0.75;
    int VyEnemigo = VxEnemigo;

    int WBala = wPantalla / 70;
    int HBala = WEnemigo / 2;

    int VBala = wPantalla / 45;

    int WVida = wPantalla / 50;
    int HVida = WVida;

    // Lectura de im�genes
    fondo1 = Pantalla_ImagenLee("bg/PantallaInicio.bmp", 0);
    fondo2 = Pantalla_ImagenLee("bg/EleccionPersonaje.bmp", 0);
    fondo3 = Pantalla_ImagenLee("bg/PantallaJuego.bmp", 0);
    fondo4 = Pantalla_ImagenLee("bg/PantallaFinal.bmp", 0);

    Imagen Im;
    Imagen Im2 = Pantalla_ImagenLee("sprites/enemigo.bmp", 1);
    Imagen Im3 = Pantalla_ImagenLee("sprites/estrella.bmp", 1);
    Imagen Im4 = Pantalla_ImagenLee("sprites/bala.bmp", 1);
    Imagen Im5 = Pantalla_ImagenLee("sprites/vida.bmp", 1);

    // Indicador de primera vez
    int flag = 1;
    double ti;
    // FASE 1
    printf("[Phase 1]\n");
    while (Pantalla_Activa() && !fin) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) {
            fin = 1;
        }
        Pantalla_DibujaImagen(fondo1, 0, 0, wPantalla, hPantalla);

        if (flag || time(NULL) - ti < 1) { // Si es la primera vez o no ha pasado un segundo dibujar texto
            Pantalla_DibujaTexto("Press [Enter] key to continue", wPantalla / 100, hPantalla * 0.98);
        } else {
            if (time(NULL) - ti > 1.2) { // Si no se ha dibujado el texto desde hace 1.2 - 1 seg reiniciar el tiempo
                ti = time(NULL);
            }
        }

        if (flag) flag = 0; // Indica que ya no es la primera vez

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    fin = 0;
    // Liberado de elementos de la pantalla anterior
    Pantalla_ImagenLibera(fondo1);

    // Im�genes del personaje a elegir
    int numPersonajes = 4;
    Imagen Imp[numPersonajes];
    for (int i = 0; i < numPersonajes; i++)
    {
        char filename[50];
        sprintf(filename, "sprites/personajes/%d.bmp", i + 1);
        Imp[i] = Pantalla_ImagenLee(filename, 1);
    }
    
    // Variables de control
    int sel = 0; // Indica la skin a escoger
    flag = 1;    // Indica que se acaba de pulsar el boton

    // FASE 2
    printf("[Phase 2]\n");
    while (Pantalla_Activa() && (!fin)) {
        // Condici�n de cambio de fase
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) {
            fin = 1;
        }

        // Elecci�n de la imagen que tendr� el personaje
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && flag) {
            sel++;
            flag = 0;
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT) && flag) {
            sel--;
            flag = 0;
        }
        if (!Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && !Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) // Si no se pulsa ning�n bot�n puede elegirse de nuevo
            flag = 1;

        // Evita que se salga del rango de im�genes
        if (sel > numPersonajes - 1) sel = numPersonajes - 1;
        if (sel < 0) sel = 0;

        // Seg�n lo elegido se imprime una u otra im�gen
        Im = Imp[sel];

        // Dibujado de fondos y men�s
        Pantalla_DibujaImagen(fondo2, 0, 0, wPantalla, hPantalla);
        Pantalla_DibujaImagen(Im, wPantalla / 2 - WPersonaje, 0.65 * hPantalla, WPersonaje * 2, HPersonaje * 2); // Se dibuja la imagen a elegir el doble de grande
        Pantalla_DibujaTexto("Thanks for pressing the key.", wPantalla / 3, hPantalla / 4);
        Pantalla_DibujaTexto("Use the key arrows to select a spaceship.", wPantalla / 3, hPantalla * 0.3);
        Pantalla_DibujaTexto("Press [Spacebar] to play.", wPantalla / 3, hPantalla * 0.35);

        // Refresco de la pantalla
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    srand(time(NULL));
    // Liberado del fondo
    Pantalla_ImagenLibera(fondo2);

    // Inicializaci�n de TDA
    Personaje p = PersonajeCrea(Im, WPersonaje, HPersonaje, rand() % (wPantalla - WPersonaje), hPantalla - HPersonaje);
    Enemigos e1 = EnemigosCrea();
    Estrellas e = EstrellasCrea(MaxEstrellas);
    Balas b = BalasCrea();
    int disparadas = 0;
    Vidas v = VidasCrea(VidaInicial);
    VidasRellena(v, Im5, WVida, HVida, wPantalla / 100, hPantalla / 12); // Se dibujan las vidas

    // Preparaci�n del nivel
    fin = 0;
    ti = time(NULL);
    int t2;
    int puntos;
    int puntos_estrellas = 0;
    int puntos_enemigo = 0;
    char mensajePuntos[100];
    char mensajeMunicion[100];
    int BPuntos = 0;
    flag = 1;
    int primvez = 1; // Determina si se ha disparado ya antes

    // FASE 3
    printf("[Phase 3]\n");
    while (Pantalla_Activa() && !fin && VidasGetVida(v) > 0) {
        // Condici�n de final de juego
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_TAB)) {
            fin = 1;
        }

        // Recuento de los puntos
        t2 = time(NULL);
        puntos = t2 - ti + puntos_estrellas - puntos_enemigo + BPuntos;

        // Aparici�n de objetos
        if (rand() % ProbApEstrellas == 1)
        {
            Estrella e1 = EstrellaCrea(Im3, WPersonaje / 3, HPersonaje / 3, rand() % (wPantalla - WPersonaje), rand() % (hPantalla - HPersonaje));
            EstrellasInsertaNuevaEstrella(e, e1);
        }
        if (rand() % ProbApEnemigos < 2) // 20% de probabilidad de que aparezca un enemigo
        {
            Enemigo s = EnemigoCrea(Im2, WEnemigo, HEnemigo, rand() % (wPantalla - WPersonaje), 0, VxEnemigo, VyEnemigo);
            EnemigosInsertaNuevoEnemigo(e1, s);
        }
        if (EstrellasColision(e, PersonajeGetX(p), PersonajeGetY(p), PersonajeGetH(p), PersonajeGetW(p)))
        {
            printf("[Collision] Star\n");
            puntos_estrellas += 20;
        }
        if (EnemigosColision(e1, PersonajeGetX(p), PersonajeGetY(p), PersonajeGetH(p), PersonajeGetW(p))) {
            printf("[Collision] Enemy\n");
            puntos_enemigo += 20;
            VidasEliminaVida(v);
            printf("[Lifes] Remaining: %d\n", VidasGetVida(v));
        }
        BPuntos += BalasColision(b, e1) * PuntosBalazo;
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_F) && flag && disparadas < LimiteBalas) {
            Bala bala = BalaCrea(Im4, WBala, HBala, PersonajeGetX(p) + 25, PersonajeGetY(p), VBala);
            BalasInsertaNuevaBala(b, bala);
            disparadas++;
            flag = 0;
            primvez = 0;
            printf("[Shoot] Bullets fired: %d\n", disparadas);
        }
        if (!Pantalla_TeclaPulsada(SDL_SCANCODE_F)) flag = 1;

        sprintf(mensajePuntos, "Points = %d", puntos);
        sprintf(mensajeMunicion, "Remaining ammo: %d", LimiteBalas - disparadas);

        // Movimiento del personaje
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p, -VPersonaje, 0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) PersonajeMueve(p, VPersonaje, 0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)) PersonajeMueve(p, 0, -VPersonaje);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) PersonajeMueve(p, 0, VPersonaje);

        // Dibuja todo lo que hay en la pantalla
        Pantalla_DibujaImagen(fondo3, 0, 0, wPantalla, hPantalla);
        EstrellasDibuja(e);
        EnemigosMueve(e1);
        BalasMueve(b);
        BalasDibuja(b);
        EnemigosDibuja(e1);
        PersonajeDibuja(p);

        // Dibuja un peque�o men�
        Pantalla_DibujaTexto("To end the game press [Tab].", wPantalla / 100, hPantalla / 50);
        Pantalla_DibujaTexto(mensajePuntos, wPantalla / 100, hPantalla / 20);
        Pantalla_DibujaTexto(mensajeMunicion, wPantalla / 100, hPantalla * 0.95);
        VidasDibuja(v);
        if (primvez) Pantalla_DibujaTexto("Press [f] to shoot", wPantalla / 100, hPantalla * 0.98); // En el caso de que no se haya disparado antes muestra el control

        // Refresco de la pantalla
        Pantalla_Actualiza();
        Pantalla_Espera(20);
    }
    fin = 0;
    // Liberaci�n de las TDA y de las im�genes
    EnemigosLibera(e1);
    EstrellasLibera(e);
    PersonajeLibera(p);
    BalasLibera(b);
    VidasLibera(v);
    Pantalla_ImagenLibera(fondo3);
    Pantalla_ImagenLibera(Im2);
    Pantalla_ImagenLibera(Im3);
    Pantalla_ImagenLibera(Im4);
    Pantalla_ImagenLibera(Im5);
    for (int i = 0; i < numPersonajes; i++)
    {
        Pantalla_ImagenLibera(Imp[i]);
    }

    // Guardado de la puntuaci�n
    printf("[Save] Score\n");
    int datoleido;
    int puntosmax = 0;
    FILE * r = fopen("record.txt", "r");
    if (r != NULL) {
        while (!feof(r)) {
            fscanf(r, "%d", &datoleido);
            if (datoleido > puntosmax)
                puntosmax = datoleido;
        }
        fclose(r);
    }

    char texto2[100];
    if (puntosmax < puntos)
        sprintf(texto2, "New Record = %d", puntos);
    else
        sprintf(texto2, "Record = %d", puntosmax);

    r = fopen("record.txt", "a");
    fprintf(r, "%d\n", puntos);
    fclose(r);
    // FASE 4
    printf("[Phase 4]\n");
    while (Pantalla_Activa() && !fin) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) {
            fin = 1;
        }

        Pantalla_DibujaImagen(fondo4, 0, 0, wPantalla, hPantalla);
        Pantalla_DibujaTexto("To quit press [Esc].", wPantalla * 0.43, hPantalla / 2);
        Pantalla_DibujaTexto(mensajePuntos, wPantalla * 0.43, hPantalla * 0.55);
        Pantalla_DibujaTexto(texto2, wPantalla * 0.43, hPantalla * 0.6);

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    // Liberado de im�genes
    Pantalla_ImagenLibera(fondo4);
    // Libera la pantalla y fin del juego
    Pantalla_Libera();
    return 0;
}


