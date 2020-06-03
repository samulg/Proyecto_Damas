#include "ReglasBot.h"
#include "math.h"

void ReglasBot::calcularPosicionesPosibles() {
	Vector2D posSigu;
	struct posActSigu str;

	for (int i = 0; i < 12; i++) {
		if (listaFichasN[i]->estado == 0) { //si la ficha esta viva
			this->setPosAct(listaFichasN[i]->posicion);
			posSigu.x = (listaFichasN[i]->posicion.x + 1);
			posSigu.y = (listaFichasN[i]->posicion.y + 1);

			

			this->setPosSig(posSigu);



			if (this->movDiagUnit()) { //devuelve true si el mov a la posicion indicada por posSiguDer es posible (no hay ficha
				str.idFicha = i;
				str.posSig = posSigu;
				posibPosSiguientes.push_back(str);
			}

			posSigu.x = (listaFichasN[i]->posicion.x - 1);
			posSigu.y = (listaFichasN[i]->posicion.y + 1);
			this->setPosSig(posSigu);
			if (this->movDiagUnit()) {
				str.idFicha = i;
				str.posSig = posSigu;
				posibPosSiguientes.push_back(str);
			}
		}
	}
}
  ReglasBot::posActSigu ReglasBot::elegirMejorMov(void) {
	 posActSigu str;

	int min = 10;
	int elElegido = 0;

	for (int i = 0; i < sizeof(posibPosSiguientes); i++) {

		Vector2D mejorJugada;
		if (posibPosSiguientes[i].posSig.y < min) {// mayor porque el eje y esta invertido(seleccionamos la mas lejana al borde de las blancas
			min = posibPosSiguientes[i].posSig.y;
		}


	}

	for (int i = 0; i < sizeof(posibPosSiguientes); i++) {
		if (posibPosSiguientes[i].posSig.y == min)
			posMismaPrioridad.push_back(posibPosSiguientes[i]);
	}
	elElegido = rand() % sizeof(posMismaPrioridad);
	

	return posMismaPrioridad[elElegido];
}