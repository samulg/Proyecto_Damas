#pragma once

#include <vector>
#include <iostream>
#include "Casilla.h"
#include "Ficha.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Reglas.h"




class Tablero
{
public:

	Tablero();
	
	std::vector <Ficha*> listaFichasB;
	std::vector <Ficha*> listaFichasN;
	
	Reglas regla;
	
	Casilla **c;//para las casillas inciales
	Casilla hand;
	
	
	
	int i, j, n, m;
	bool turno;// 0 negras, 1 blancas
	int controlSeleccion;//variable de control para los if del onkeyboardDown (evita que se actualicen instant�neamente)
	void dibujarTablero();
	void dibujarFichasIniciales();
	void moverMano(unsigned char tecla);

	//Vector2D getCasilla(int f, int c); 
	//void dibujarFichasIniciales();
	~Tablero();
};