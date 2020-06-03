#pragma once

#include <vector>
#include <iostream>
#include <windows.h>

#include "Vector2D.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"

class Reglas
{
protected:
	std::vector <Ficha*> listaFichasBl;
	std::vector <Ficha*> listaFichasNe;


private:
	bool turno;
	Vector2D posicionActual;
	Vector2D posicionSiguiente;

	bool diagDer[20];
	bool diagIzq[20];
	//bool fichaComida;
public:
	Reglas();

	//BLANCAS
	bool movDiagUnit();//devuelve '1' si el movimiento que se quiere realizar es una diagonal unitaria, y además no pisa a otra ficha
	bool fichaComida();//devuelve '1' si el movimiento de comer se ha realizado correctamente
	bool posibleComerFicha();//devuelve '1' si es posible para blancas comer alguna ficha

	void hacerReina();
	bool moverReina();
	bool posibleComerConReina();
	bool fichaComidaConReina();
	

	//negras
	bool movDiagUnitN();
	bool posibleComerFichaN();
	bool fichaComidaN();

	void hacerReinaN();
	bool posibleComerConReinaN();
	bool fichaComidaConReinaN();

	//control
	bool cambiarTurno();
	bool getTurno();
	void setPosAct(Vector2D);
	void setPosSig(Vector2D);
	void setListaFichas(std::vector <Ficha*>, std::vector <Ficha*>);
	void delListaFichas(std::vector <Ficha*>, std::vector <Ficha*>);

	~Reglas();
};
