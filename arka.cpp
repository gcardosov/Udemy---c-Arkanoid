#include <allegro.h>
#include <string>
#include <conio.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <winalleg.h>
#include <fstream>

using namespace std;

/*Constantes que defienen el largo y lo ancho de la pantalla*/
#define ancho 1024
#define alto 740


//Declaracion de objetos
//Sonidos
//PARA EL AUDIO TIPO PUNTERO A MEMORIA
MIDI *musicaInicio;
MIDI *musicaJuego;
SAMPLE *sonido_InicioJuego;
SAMPLE *sonido_InicioNivel;
SAMPLE *sonido_LadrilloRoto;
SAMPLE *sonido_RebotePelota;
SAMPLE *sonido_Revivir;
SAMPLE *sonido_VidaExtra;
SAMPLE *sonido_RebotaParedes;
SAMPLE *sonido_RebotaBase;
SAMPLE *sonido_VidaPerdida;
SAMPLE *sonido_gameOver;

//Declaracion de objetos
//Imagenes
//Imagenes de tipo puntero
BITMAP *buffer; //Crea una imagen donde se arma la imagen en donde se manda directo sin intermitencias a la vista no hay parpadeos
BITMAP *logo;
BITMAP *panel;
BITMAP *recuadro;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *fondo4;
BITMAP *fondo5;
BITMAP *gameOver;
BITMAP *lad1;
BITMAP *lad2;
BITMAP *lad3;
BITMAP *lad4;
BITMAP *lad5;
BITMAP *lad6;
BITMAP *lad7;
BITMAP *ladd;
BITMAP *base;
BITMAP *base2;
BITMAP *base3;
BITMAP *base4;


int inicializo();
void inicializo_pantalla();

/*Variables para la jugabilidad*/
int retardo=100;
int vidas=3;
int level1=1;
int score=0;
bool muerte=false;
//Variable para la animación de la muerte
int secuenciaMuerte=1;
//Variables para controlar la musca y los efectos de sonido
bool musica=true;
bool efectos=true;
//Variable que controla el archvio de puntajes maximos
bool existeArchivo=false;

//Banderas del juego
bool juegoIniciado= false;
bool fin=false;
bool nuevoNivel=false;

//Cordenadas inciales rn los ejes x,y de la bola
int dirY=-1;
int dirX=1;

//Movimiento de la bola en pixeles por segundo de la nola y la base
int velocidad=3;
int velocidadInicial=3;

//Cambio de fondo
int fondoN=1;

//Cordenadas iniciales de la base
int baseX=255;
int bolaX=295;
int bolaY=650;

//Posiciones por juego es decir de los ladrillos
int mapa[63];

//Delimita el recuadro de movimiento de la bola
int puntaIzq;
int puntaDer;


//Transformacion del moviemiento de la bola en fila y columna
int colBola;
int filaBola;
//Detecta si hay un elemento en el trayecto de la bola
int elemento;

//Vector para las filas que en donde se van a representar los ladrillos
int fila[]={20,50,80,110,1140,170,200};

int main ()
{

//Funcion de inicialización
    if(inicializo() == 1) return 1;

}
END_OF_MAIN();

int inicializo()
{
    allegro_init();
    install_keyboard();
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
        {
            allegro_message("Error ! Inicializanco sistema de sonido \n\n\n", allegro_error);
            return 1;
        }

    inicializo_pantalla();
    inicializo_sonidos();

    return 0;

}

void inicializo_pantalla()
{

    set_color_depth(32);
    //Los valores en cero se usa para extener la ventana con pixels adicionales que se mantendran ocultos
    //para luego hacer el scrolling
    set_gfx_mode(GFX_AUTODETECT, ancho, alto, 0, 0);
    //Crea una area de tipo bitma que alberga el resto de la imagenes
    buffer=create_bitmap(ancho,alto);
    logo=load_bitmap("img/logo.bmp", NULL);
    panel=load_bitmap("img/panel.bmp", NULL);
    recuadro=load_bitmap("img/recuadro.bmp", NULL);
    fondo1=load_bitmap("img/fondo1.bmp", NULL);
    fondo2=load_bitmap("img/fondo2.bmp", NULL);
    fondo3=load_bitmap("img/fondo3.bmp", NULL);
    fondo4=load_bitmap("img/fondo4.bmp", NULL);
    fondo5=load_bitmap("img/fondo5.bmp", NULL);
    lad1=load_bitmap("img/lad1.bmp", NULL);
    lad2=load_bitmap("img/lad2.bmp", NULL);
    lad3=load_bitmap("img/lad3.bmp", NULL);
    lad4=load_bitmap("img/lad4.bmp", NULL);
    lad5=load_bitmap("img/lad5.bmp", NULL);
    lad6=load_bitmap("img/lad6.bmp", NULL);
    lad7=load_bitmap("img/lad7.bmp", NULL);
    ladd=load_bitmap("img/ladd.bmp", NULL);
    gameOver=load_bitmap("img/gameOver.bmp", NULL);
    base=load_bitmap("img/base.bmp", NULL);
    base2=load_bitmap("img/base2.bmp", NULL);
    base3=load_bitmap("img/base3.bmp", NULL);
    base4=load_bitmap("img/base4.bmp", NULL);

}


void inicializo_sonidos()
{
    set_volume(230, 209);
    //Archivo mid
    //El formato md se puede ejecutar en un loop de sonido
    musicaInicio=load_midi("sonidos/ark.mid");
    musicaJuego=load_midi("sonidos/Arkanoid.mid");

    //Archivos WAV
    sonido_InicioJuego=load_wav("sonidos/InicioJuego.wav");
    sonido_InicioNivel=load_wav("sonidos/InicioNivel.wav");
    sonido_LadrilloRoto=load_wav("sonidos/LadrilloRoto.wav");
    sonido_RebotePelota=load_wav("sonidos/RebotePelota.wav");
    sonido_VidaExtra=load_wav("sonidos/VidaExtra.wav");
    sonido_RebotaParedes=load_wav("sonidos/reboteParedes.wav");
    sonido_RebotaBase=load_wav("sonidos/rebotaBase.wav");
    sonido_VidaPerdida=load_wav("sonidos/fallo.wav");
    sonido_gameOver=load_wav("sonidos/game-over.wav");



}












