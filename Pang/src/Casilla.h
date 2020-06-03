#pragma once
#include "glut.h"
#include "Vector2D.h"
class Casilla
{
public:
	Casilla();

	//Variables
	float fm, cm;
	bool seleccionada;

	//Objetos
	Vector2D fichaSeleccionada;
	Vector2D posicion;
	Vector2D mano;

	//Metodos.
	void dibujarCasilla(int f, int c);
	void dibujarManoBlanca(void);
	void dibujarManoNegra(void);
	void dibujarSeleccion(void);

	~Casilla();
};

