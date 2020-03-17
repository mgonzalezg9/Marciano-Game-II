#include "Enemigo.h"
#include "Personaje.h"
#include "Estrellas.h"
#include "Enemigos.h"
#include "Balas.h"
#include "Vidas.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WPANTALLA       1280 // Resolución por defecto
#define HPANTALLA       960
#define NUM_ARGS        3

#define PuntosBalazo    20
#define ProbApEstrellas 30 // Cuanto menor sea más probable será que aparezcan
#define ProbApEnemigos  10
#define VidaInicial     3
#define MaxEstrellas    5
#define LimiteBalas     15 // Número máximo de balas que se pueden disparar

/**

\mainpage Videojuego donde una nave guíada por el usuario debe aguantar el máximo tiempo posible sin chocar con una nave marciana enemiga, para obtener la máxima puntuación posible.
\file Principal.c
\author Manuel González García
\version 1.4

**/


int main(int argc, char **argv) {
    // Cargado de las imágenes y creación de la pantalla
    int ancho, alto;
    if (argc < NUM_ARGS) {
        ancho = WPANTALLA;
        alto = HPANTALLA;
    } else {
        ancho = atoi(argv[1]);
        alto = atoi(argv[2]);
    }

    Imagen fondo1, fondo2, fondo3, fondo4;
    Pantalla_Crea("Marciano Game II", ancho, alto);

    int wPantalla = Pantalla_Anchura();
    int hPantalla = Pantalla_Altura();

    Pantalla_ColorRelleno(255, 255, 255, 255);
    Pantalla_ColorTrazo(0, 255, 0, 255);
    int fin = 0;

    // Definición de las características de los objetos según la pantalla
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

    // Lectura de imágenes
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
    printf("[Fase 1]\n");
    while (Pantalla_Activa() && !fin) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) {
            fin = 1;
        }
        Pantalla_DibujaImagen(fondo1, 0, 0, wPantalla, hPantalla);

        if (flag || time(NULL) - ti < 1) { // Si es la primera vez o no ha pasado un segundo dibujar texto
            Pantalla_DibujaTexto("Pulsa la tecla [Enter] para continuar", wPantalla / 100, hPantalla * 0.98);
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

    // Imágenes del personaje a elegir
    Imagen Imp1 = Pantalla_ImagenLee("sprites/personaje.bmp", 1);
    Imagen Imp2 = Pantalla_ImagenLee("sprites/personaje2.bmp", 1);
    Imagen Imp3 = Pantalla_ImagenLee("sprites/personaje3.bmp", 1);

    // Variables de control
    int sel = 0; // Indica la skin a escoger
    flag = 1; // Indica que se acaba de pulsar el boton

    // FASE 2
    printf("[Fase 2]\n");
    while (Pantalla_Activa() && (!fin)) {
        // Condición de cambio de fase
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) {
            fin = 1;
        }

        // Elección de la imagen que tendrá el personaje
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && flag) {
            sel++;
            flag = 0;
        }
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT) && flag) {
            sel--;
            flag = 0;
        }
        if (!Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT) && !Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) // Si no se pulsa ningún botón puede elegirse de nuevo
            flag = 1;

        // Según lo elegido se imprime una u otra imágen
        switch (sel) {
        case 0:
            Im = Imp1;
            break;
        case 1:
            Im = Imp2;
            break;
        case 2:
            Im = Imp3;
            break;
        }

        // Evita que se salga del rango de imágenes
        if (sel > 2) sel = 2;
        if (sel < 0) sel = 0;

        // Dibujado de fondos y menús
        Pantalla_DibujaImagen(fondo2, 0, 0, wPantalla, hPantalla);
        Pantalla_DibujaImagen(Im, wPantalla / 2 - WPersonaje, 0.65 * hPantalla, WPersonaje * 2, HPersonaje * 2); // Se dibuja la imagen a elegir el doble de grande
        Pantalla_DibujaTexto("Gracias por pulsar la tecla.", wPantalla / 3, hPantalla / 4);
        Pantalla_DibujaTexto("Para seleccionar un personaje usa las flechas.", wPantalla / 3, hPantalla * 0.3);
        Pantalla_DibujaTexto("Para jugar pulse [Espacio].", wPantalla / 3, hPantalla * 0.35);

        // Refresco de la pantalla
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    srand(time(NULL));
    // Liberado del fondo
    Pantalla_ImagenLibera(fondo2);

    // Inicialización de TDA
    Personaje p = PersonajeCrea(Im, WPersonaje, HPersonaje, rand() % (wPantalla - WPersonaje), hPantalla - HPersonaje);
    Enemigos e1 = EnemigosCrea();
    Estrellas e = EstrellasCrea(MaxEstrellas);
    Balas b = BalasCrea();
    int disparadas = 0;
    Vidas v = VidasCrea(VidaInicial);
    VidasRellena(v, Im5, WVida, HVida, wPantalla / 100, hPantalla / 12); // Se dibujan las vidas

    // Preparación del nivel
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
    printf("[Fase 3]\n");
    while (Pantalla_Activa() && !fin && VidasGetVida(v) > 0) {
        // Condición de final de juego
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_TAB)) {
            fin = 1;
        }

        // Recuento de los puntos
        t2 = time(NULL);
        puntos = t2 - ti + puntos_estrellas - puntos_enemigo + BPuntos;

        // Aparición de objetos
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
            printf("[Colision] Estrella\n");
            puntos_estrellas += 20;
        }
        if (EnemigosColision(e1, PersonajeGetX(p), PersonajeGetY(p), PersonajeGetH(p), PersonajeGetW(p))) {
            printf("[Colision] Enemigo\n");
            puntos_enemigo += 20;
            VidasEliminaVida(v);
            printf("[Vidas] Restantes: %d\n", VidasGetVida(v));
        }
        BPuntos += BalasColision(b, e1) * PuntosBalazo;
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_F) && flag && disparadas < LimiteBalas) {
            Bala bala = BalaCrea(Im4, WBala, HBala, PersonajeGetX(p) + 25, PersonajeGetY(p), VBala);
            BalasInsertaNuevaBala(b, bala);
            disparadas++;
            flag = 0;
            primvez = 0;
            printf("[Disparo] Balas disparadas: %d\n", disparadas);
        }
        if (!Pantalla_TeclaPulsada(SDL_SCANCODE_F)) flag = 1;

        sprintf(mensajePuntos, "Puntos = %d", puntos);
        sprintf(mensajeMunicion, "Municion restante: %d", LimiteBalas - disparadas);

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

        // Dibuja un pequeño menú
        Pantalla_DibujaTexto("Para terminar el juego pulse [Tab].", wPantalla / 100, hPantalla / 50);
        Pantalla_DibujaTexto(mensajePuntos, wPantalla / 100, hPantalla / 20);
        Pantalla_DibujaTexto(mensajeMunicion, wPantalla / 100, hPantalla * 0.95);
        VidasDibuja(v);
        if (primvez) Pantalla_DibujaTexto("Pulse [f] para disparar", wPantalla / 100, hPantalla * 0.98); // En el caso de que no se haya disparado antes muestra el control

        // Refresco de la pantalla
        Pantalla_Actualiza();
        Pantalla_Espera(20);
    }
    fin = 0;
    // Liberación de las TDA y de las imágenes
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
    Pantalla_ImagenLibera(Imp1);
    Pantalla_ImagenLibera(Imp2);
    Pantalla_ImagenLibera(Imp3);

    // Guardado de la puntuación
    printf("[Guardado] Puntuacion\n");
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
        sprintf(texto2, "Nuevo Record = %d", puntos);
    else
        sprintf(texto2, "Record = %d", puntosmax);

    r = fopen("record.txt", "a");
    fprintf(r, "%d\n", puntos);
    fclose(r);
    // FASE 4
    printf("[Fase 4]\n");
    while (Pantalla_Activa() && !fin) {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) {
            fin = 1;
        }

        Pantalla_DibujaImagen(fondo4, 0, 0, wPantalla, hPantalla);
        Pantalla_DibujaTexto("Para salir pulse [Esc].", wPantalla * 0.43, hPantalla / 2);
        Pantalla_DibujaTexto(mensajePuntos, wPantalla * 0.43, hPantalla * 0.55);
        Pantalla_DibujaTexto(texto2, wPantalla * 0.43, hPantalla * 0.6);

        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }

    // Liberado de imágenes
    Pantalla_ImagenLibera(fondo4);
    // Libera la pantalla y fin del juego
    Pantalla_Libera();
    return 0;
}


