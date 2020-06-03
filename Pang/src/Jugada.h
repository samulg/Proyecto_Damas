#pragma once
#include "Vector2D.h"

class Jugada {
public:
	int idFicha;
	int idFichaComer = 20; //Valor aleatorio para cambiar su valor cuando pueda comer una ficha
	Vector2D posSigComer;
	Vector2D posSig;
};