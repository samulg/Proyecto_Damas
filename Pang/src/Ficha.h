#pragma once
#include "glut.h"
#include "Vector2D.h"
class Ficha
{
public:
	Ficha();
	Vector2D posicion;
	virtual void dibujarFicha()= 0;

	~Ficha();
};