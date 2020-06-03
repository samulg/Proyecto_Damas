#pragma once
#include "glut.h"
#include "Vector2D.h"
class Casilla
{
public:
	Casilla();
	float fm, cm;
	bool seleccionada;
	Vector2D fichaSeleccionada;
	Vector2D posicion;
	Vector2D mano;
	void dibujarCasilla(int f, int c);
	void dibujarMano(void);
	void dibujarSeleccion(void);

	~Casilla();
};

