#pragma once

#include <vector>
#include <iostream>
#include <windows.h>

#include "Vector2D.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"

class Reglas
{
private:
	bool turno;
	Vector2D posicionActual;
	Vector2D posicionSiguiente;
	std::vector <Ficha*> listaFichasB;
	std::vector <Ficha*> listaFichasN;
	bool diagDer[20];
	bool diagIzq[20];
	//bool fichaComida;
public:
	Reglas();
	//bool turno;

	bool cambiarTurno();
	bool getTurno();//podriamos haber dejado "turno" en public y ahorrarnos esta funcion  (desde tablero accederiamos a reglas.turno)
	//pero es m�s elegante dejar turno en private y que solo Reglas lo pueda modificar
	//intentar que todo el c�digo sea igual, es decir, en tablero se acceden a m�todos de reglas, nunca a variables.
	//para ello, crear m�todos getVariable() � setVariable
	bool movDiagUnit();//devuelve '1' si el movimiento que se quiere realizar es una diagonal unitaria, y adem�s no pisa a otra ficha
	bool fichaComida();//devuelve '1' si el movimiento de comer se ha realizado correctamente
	bool movComerAdicional();
	void setPosAct(Vector2D);
	void setPosSig(Vector2D);
	void setListaFichas(std::vector <Ficha*>, std::vector <Ficha*>);
	void delListaFichas(std::vector <Ficha*>, std::vector <Ficha*>);
	bool posibleComerFicha();//devuelve '1' si es posible para blancas comer alguna ficha
	void hacerReina();
	bool moverReina();
	bool posibleComerConReina();
	bool fichaComidaConReina();

	~Reglas();
};
