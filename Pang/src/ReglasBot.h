#pragma once
#include "Reglas.h"



//esta clase solo mueve fichas negras
class ReglasBot : public Reglas {//heredamos las dos listas de fichas de Reglas, pero no los metodos private ni el constructor
//¿posicion actual y siguiente no se heredan?; ahora posicion siguiente tiene que ser un vector con TODAS las posiciones siguientes posibles
	/////////////////variables
public:
	bool mode;
	int idFicha;
	struct  posActSigu{
		int idFicha;
		Vector2D posSig;
	};
	
	std::vector <posActSigu> posibPosSiguientes;
	std::vector <posActSigu> posMismaPrioridad;
	////////////////////metodos
	void calcularPosicionesPosibles();
	 posActSigu elegirMejorMov(void);
};