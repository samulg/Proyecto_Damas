#pragma once
#include "Reglas.h"
#include "Jugada.h"
//#include "Tablero.h"   //por alguna razon este include revienta el programa


//esta clase solo mueve fichas negras
class ReglasBot : public Reglas {//heredamos las dos listas de fichas de Reglas, pero no los metodos private ni el constructor
//¿posicion actual y siguiente no se heredan?; ahora posicion siguiente tiene que ser un vector con TODAS las posiciones siguientes posibles
	/////////////////variables
public:
	Jugada posActSigu;
	bool mode;
	int idFicha;
	/*
	struct  posActSigu{
		int idFicha;
		Vector2D posSig;
	};
	*/
	std::vector <Jugada> posibPosSiguientes;
	std::vector <Jugada> posMismaPrioridad;
	////////////////////metodos
	void calcularPosicionesPosibles();
	Jugada* elegirMejorMov(void);
	~ReglasBot();
};