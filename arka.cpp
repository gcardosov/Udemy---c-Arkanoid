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
SAMPLE *sonido_RebotaBase;
SAMPLE *sonido_VidaPerdida;
SAMPLE *sonido_gameOver;

//Declaracion de objetos
//Imagenes
//Imagenes de tipo puntero
BITMAP *buffer;
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
bool existeArchivo=;

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
int fila[]

int main ()
{

}
END_OF_MAIN();


