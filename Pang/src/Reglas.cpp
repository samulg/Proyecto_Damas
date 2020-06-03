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
		//ahora comprobamos que no haya ninguna ficha ahi 
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
bool Reglas::fichaComida() {
	int i;
	bool aux = false;
	bool diagIzq = false;
	bool diagDer = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal doble
	//el primer if funciona (solo devuelve true cuando has movido una doble diagonal unitaria a la izquierda
	if ((posicionSiguiente.x == (posicionActual.x + 2)) && (posicionSiguiente.y == (posicionActual.y - 2))) {
		for (i = 0; i < 20; i++) {
			int h;
			//Comprobamos que no haya ninguna ficha ahi
			if ((posicionSiguiente = listaFichasB[i]->posicion) || (posicionSiguiente = listaFichasN[i]->posicion)) {
				diagIzq = false;
				break;
			}
			//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
			else if (((posicionActual.x + 1) == listaFichasN[i]->posicion.x) && ((posicionActual.y - 1) == listaFichasN[i]->posicion.y)) {
				diagIzq = true;
				break;
			}
			else
				diagIzq = false;
		}
	
	}
		
	else
		diagIzq = false;

	
	//diagonal derecha 
	if ( ((posicionSiguiente.x == (posicionActual.x - 2)) && (posicionSiguiente.y == (posicionActual.y - 2)))) {
		for (i = 0; i < 20; i++) {
			int h;
			//Comprobamos que no haya ninguna ficha ahi
			if ((posicionSiguiente = listaFichasB[i]->posicion) || (posicionSiguiente = listaFichasN[i]->posicion)) {
				diagDer = false;
				break;
			}
			//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
			else if (((posicionActual.x - 1) == listaFichasN[i]->posicion.x) && ((posicionActual.y - 1) == listaFichasN[i]->posicion.y)) {
				diagDer = true;
				break;
			}
			else
				diagDer = false;
		
		}
		
	}
	else
		diagDer = false;
	return (diagDer || diagIzq);
}
bool Reglas::movComerAdicional() {
	//esta funcion devuelve true si es posible comer otra vez
	//en un principio (cuando la función toma la decisión) actual y siguiente no están actualizados
	//cuando pulse el primer espacio actualizo posActual
	//en el segundo espacio actualizo posSiguiente (hasta entonces posSiguiente estaba almacenando la posicion actual de este movimiento)
	int i;
	bool aux1 = false;
	bool diagIzq = false;
	bool diagDer = false;
	for (i = 0; i < 20; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda

		//izquierda
		//primero comprobamos que haya una ficha en la casilla adyacente
		if (((posicionSiguiente.x + 1) == listaFichasN[i]->posicion.x) && ((posicionSiguiente.y - 1) == listaFichasN[i]->posicion.y)) {
			diagIzq = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
		//si hay una ficha en la segunda casilla diagonal
			if ((((posicionSiguiente.x + 2) == listaFichasB[i]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasB[i]->posicion.y)) || (((posicionSiguiente.x + 2) == listaFichasN[i]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasN[i]->posicion.y)))
				diagIzq = false; //funciona correctamente, similar a la anterior
		//Problema: diagIzq devuelve true aunque 
		}

		//derecha
		if (((posicionSiguiente.x - 1) == listaFichasN[i]->posicion.x) && ((posicionSiguiente.y - 1) == listaFichasN[i]->posicion.y)) {
			diagDer = true;
				//si hay una ficha en la segunda casilla diagonal
				if ((((posicionSiguiente.x - 2) == listaFichasB[i]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasB[i]->posicion.y)) || (((posicionSiguiente.x - 2) == listaFichasN[i]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasN[i]->posicion.y)))
					diagDer = false;
		}



		return (diagDer || diagIzq);

	}
}
bool Reglas::posibleComerFicha() {
	//esta funcion devuelve true si es posible comer otra vez
	//en un principio (cuando la función toma la decisión) actual y siguiente no están actualizados
	//cuando pulse el primer espacio actualizo posActual
	//en el segundo espacio actualizo posSiguiente (hasta entonces posSiguiente estaba almacenando la posicion actual de este movimiento)
	
	int aux1 =0;
	int aux2 = 0;
	int aux3 = 0;
	int aux4 = 0;
	bool diagIzq = false;
	bool diagDer = false;
	//comprobamos para cada blanca todas las negras
	for (int i = 0; i < 20; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		for (int j = 0; j < 20; j++) {
			//izquierda
			//primero comprobamos que haya una ficha en la casilla adyacente
			if (((listaFichasB[i]->posicion.x + 1) == listaFichasN[j]->posicion.x) && ((listaFichasB[i]->posicion.y - 1) == listaFichasN[j]->posicion.y)) {
				diagIzq = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
				aux1 = i;
				aux2 = j;
				int a;
				a = i;
				for (int v = 0; v < 20; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
											  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasB[i]->posicion.x + 2) == listaFichasN[v]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[v]->posicion.y)) || (((listaFichasB[i]->posicion.x + 2) == listaFichasN[v]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[v]->posicion.y))) {
						diagIzq = false; //funciona correctamente, similar a la anterior				
						aux4 = v;
						int b;
						b = i;
					}

				}
			}
		}
	}
			//else
			//	diagIzq = false;
			
	for (int i = 0; i < 20; i++) {
				//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
				//separamos entre diagonal derecha e izquierda
				for (int j = 0; j < 20; j++) {
					//derecha
					if (((listaFichasB[i]->posicion.x - 1) == listaFichasN[j]->posicion.x) && ((listaFichasB[i]->posicion.y - 1) == listaFichasN[j]->posicion.y)) {
						diagDer = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
						aux1 = i;
						aux2 = j;
						int c;
						c = i;
						for (int z = 0; z < 20; z++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
													  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
							//si hay una ficha en la segunda casilla diagonal
							if ((((listaFichasB[i]->posicion.x - 2) == listaFichasN[z]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[z]->posicion.y)) || (((listaFichasB[i]->posicion.x - 2) == listaFichasN[z]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[z]->posicion.y))) {
								diagDer = false; //funciona correctamente, similar a la anterior	
								aux4 = z;
								int d;
								d = i;
							}
						}
					}
					//else
					//	diagDer = false;

				}
			}
		
	
 	return (diagDer || diagIzq);
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