#pragma once
#include "glut.h"
#include "Ficha.h"

class FichaNegra : public Ficha
{
public:
	FichaNegra(int f, int c);

	void dibujarFicha(void);


	~FichaNegra();


};