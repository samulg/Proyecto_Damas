#include "ReglasBot.h"
#include "math.h"
using namespace std;
bool ReglasBot::calcularPosicionesPosibles() {
	Vector2D posSigu;
	Jugada str;
	bool t = true;
	bool aux = false;
	for (int i = 0; i < 12; i++) {
		if (listaFichasNe[i]->estado == 0) { //si la ficha esta viva
			this->setPosAct(listaFichasNe[i]->posicion);
			/////derecha
			posSigu.x = (listaFichasNe[i]->posicion.x + 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);

			

			this->setPosSig(posSigu);



			if (this->movDiagUnitN()) { //devuelve true si el mov a la posicion indicada por posSiguDer es posible (no hay ficha
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}

			////////izquierda
			posSigu.x = (listaFichasNe[i]->posicion.x - 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);
			this->setPosSig(posSigu);
			///////////////////////////////////////////////////////////////////error
			//movDiagUnit no tiene en cuenta si la ficha se sale del tablero (eso lo tiene en cuenta la misma mano, que aqui no existe)
			 t = this->movDiagUnitN();
			int h = 1;
			if (t== true) {
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);

				
			}
		}
	}
	if (this->posibleComerFichaN()) //this->diagDer[i])
	{
		//Si es posible comer ficha primero borramos el vector
		posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
		//luego guardamos en el vector que ficha negra(idFicha) puede comer la ficha blanca (idFichaComer) tras desplazarse a posSig
		for (int i = 0; i < 12; i++) {
			if (this->diagDer[i]&& fichaAComerDer[i]!=20) {
				posSigu.x = (listaFichasNe[i]->posicion.x + 2);
				posSigu.y = (listaFichasNe[i]->posicion.y + 2);

				str.idFicha = i;
				str.idFichaComer = this->fichaAComerDer[i];
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
				int k = 1;
			}
			if (this->diagIzq[i] && fichaAComerIzq[i] != 20) {
				posSigu.x = (listaFichasNe[i]->posicion.x - 2);
				posSigu.y = (listaFichasNe[i]->posicion.y + 2);

				str.idFicha = i;
				str.idFichaComer = this->fichaAComerIzq[i];
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
				int k = 0;
			}
			aux = true;
		}	
	}
	return aux;
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
	}

	for (int i = 0; i < posibPosSiguientes.size(); i++) {
		if (posibPosSiguientes[i].posSig.y == min)
			posMismaPrioridad.push_back(posibPosSiguientes[i]);
	}
	elElegido = rand() % posMismaPrioridad.size();
	int k = 0;

	posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
	return &posMismaPrioridad[elElegido];
}

  ReglasBot::~ReglasBot() {
	 
  }