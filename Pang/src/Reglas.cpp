#include "Reglas.h"
Reglas::Reglas()
{
	turno = 1;//empiezan blancas (turno 1)
	//incializacion de las listas de fichas (no se si es necesario)
	int i, j;
	for (i = 0; i < 4; i++) {

		for (j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {

				listaFichasB.push_back(new FichaBlanca(i, j));
			}
		}
	}
	//negras

	for (i = 6; i < 10; i++) {

		for (j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasN.push_back(new FichaNegra(i, j));
			}
		}
	}
}

bool Reglas::cambiarTurno() {
	//cada vez que se invoca esta función se cambia el turno
	if (turno == 1) {
		turno = 0;
		return 0;
	}
	else {
		turno = 1;
		return 0;
	}
}

bool Reglas::movDiagUnit() {
	int i;
	bool aux = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal
	//el primer if funciona (solo devuelve true cuando has movido una diagonal unitaria a la derecha o a la izquierda
	if (((posicionSiguiente.x == (posicionActual.x + 1)) && (posicionSiguiente.y == (posicionActual.y - 1)))|| ((posicionSiguiente.x == (posicionActual.x - 1)) && (posicionSiguiente.y == (posicionActual.y - 1)))) {
		//ahora comprobamos que no haya ninguna ficha ahi (esta parte no funciona)
		for (i = 0; i < 20; i++) {
			int h;
			if ((posicionSiguiente = listaFichasB[i]->posicion) || (posicionSiguiente = listaFichasN[i]->posicion))
				return false;
			else
				aux = true;
		}
		return aux;
	}
	else
		return false;


}
bool Reglas::getTurno() {
	return turno;

}
void Reglas::setPosAct(Vector2D v) {
	posicionActual.x = v.x;
	posicionActual.y = v.y;
}
void Reglas::setPosSig(Vector2D v) {
	posicionSiguiente.x = v.x;
	posicionSiguiente.y = v.y;
}
void Reglas::setListaFichas(std::vector <Ficha*> listaB, std::vector <Ficha*> listaN) {	
	int i = 0;
	for (i = 0; i < 20; i++) {
		listaFichasB[i]->posicion.x = listaB[i]->posicion.x;
		listaFichasN[i]->posicion.x = listaN[i]->posicion.x;

		listaFichasB[i]->posicion.y = listaB[i]->posicion.y;
		listaFichasN[i]->posicion.y = listaN[i]->posicion.y;	
	}
}

Reglas::~Reglas()
{

}