#include "ReglasBot.h"
#include "math.h"
using namespace std;
void ReglasBot::calcularPosicionesPosibles() {
	Vector2D posSigu;
	Jugada str;
	bool t = true;
	for (int i = 0; i < 12; i++) {
		if (listaFichasNe[i]->estado == 0) { //si la ficha esta viva

			this->setPosAct(listaFichasNe[i]->posicion);
			//MOVIMIENTO DIAGONAL UNITARIO
			//Derecha
			posSigu.x = (listaFichasNe[i]->posicion.x + 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);

			this->setPosSig(posSigu);

			if (this->movDiagUnitN()) { //devuelve true si el mov a la posicion indicada por posSiguDer es posible (no hay ficha
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}

			//Izquierda
			posSigu.x = (listaFichasNe[i]->posicion.x - 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);
			this->setPosSig(posSigu);
			
			t = this->movDiagUnitN();
			int h = 1;
			if (t== true) {
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);				
			}
			//POSIBLE COMER PARA LA DERECHA
			posSigu.x = (listaFichasNe[i]->posicion.x + 2);
			posSigu.y = (listaFichasNe[i]->posicion.y + 2);
			this->setPosSig(posSigu);
			if (this->posibleComerFichaN() && this->diagDer[i])
			{

					str.idFichaComer = i;
					str.posSig.x = posSigu.x;
					str.posSig.y = posSigu.y;
					posibPosSiguientes.push_back(str);
					str.idFichaComer = 20;
				
			}

			/*if (this->posibleComerFichaN() && this->diagIzq[i]) {
				str.idFichaComer = i;
				str.posSigComer.x = posSigu.x;
				str.posSigComer.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}*/
		}
	}
}
  Jugada* ReglasBot::elegirMejorMov(void) {
	 Jugada str;
	
	posMismaPrioridad.erase(posMismaPrioridad.begin(), posMismaPrioridad.begin() + posMismaPrioridad.size());

	float min = 10.0;
	int elElegido = 0;
	int p = posibPosSiguientes.size();
	int o = 1;
	for (int i = 0; i < posibPosSiguientes.size(); i++) {

		Vector2D mejorJugada;
		if (posibPosSiguientes[i].posSig.y < min) {// mayor porque el eje y esta invertido(seleccionamos la mas lejana al borde de las blancas
			min = posibPosSiguientes[i].posSig.y;
		}

		for (int i = 0; i < posibPosSiguientes.size(); i++) {

			if (posibPosSiguientes[i].idFichaComer != 20) {
				for (int j = 0; j < posibPosSiguientes.size(); j++){
					if (posibPosSiguientes[j].idFichaComer == 20)
						posibPosSiguientes.erase(posibPosSiguientes.begin() +j);
				}

				posMismaPrioridad.push_back(posibPosSiguientes[i]);
				elElegido = 0;
				posibPosSiguientes[i].idFichaComer = 20;
			}
		}

		for (int i = 0; i < posibPosSiguientes.size(); i++) {
			if (posibPosSiguientes[i].posSig.y == min) {
				posMismaPrioridad.push_back(posibPosSiguientes[i]);
				elElegido = rand() % posMismaPrioridad.size();
				int k = 0;
			}
		}
	}

	posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());

	return &posMismaPrioridad[elElegido];
}

  ReglasBot::~ReglasBot() {
	 
  }