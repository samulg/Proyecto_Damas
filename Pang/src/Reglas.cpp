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
	int v;
	int k;
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
				listaFichasN[v]->estado = 0;
				break;
			}
			else {
				for (v = 0; v < 20; v++)
				{
					//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
					if (((posicionActual.x + 1) == listaFichasN[v]->posicion.x) && ((posicionActual.y - 1) == listaFichasN[v]->posicion.y)) {
						diagIzq = true;
						listaFichasN[v]->estado = -1;
						break;
						int a;
					}
					else
						diagIzq = false;
				}
			}
			
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
				listaFichasN[k]->estado = 0;
				break;
			}
			else
			{
				for (k = 0; k < 20; k++)
				{

					//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
					if (((posicionActual.x - 1) == listaFichasN[k]->posicion.x) && ((posicionActual.y - 1) == listaFichasN[k]->posicion.y)) {
						diagDer = true;
						listaFichasN[k]->estado = -1; //si hemos comido cambiamos el estado de la ficha comida(se le pasa
													//a tablero en delListaFichas
						break;
					}
					else
						diagDer = false;
				}
			}						
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
			for (int v = 0; v < 20; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
											  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
				if ((((posicionSiguiente.x + 2) == listaFichasB[v]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasB[v]->posicion.y)) || (((posicionSiguiente.x + 2) == listaFichasN[v]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasN[v]->posicion.y)))
					diagIzq = false; 
			
			}
		}

		//derecha
		if (((posicionSiguiente.x - 1) == listaFichasN[i]->posicion.x) && ((posicionSiguiente.y - 1) == listaFichasN[i]->posicion.y)) {
			diagDer = true;
				//si hay una ficha en la segunda casilla diagonal
			for (int v = 0; v < 20; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
											  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
				if ((((posicionSiguiente.x - 2) == listaFichasB[v]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasB[v]->posicion.y)) || (((posicionSiguiente.x - 2) == listaFichasN[v]->posicion.x) && ((posicionSiguiente.y - 2) == listaFichasN[v]->posicion.y)))
					diagDer = false;
			}
		}
		return (diagDer || diagIzq);
	}
}
bool Reglas::posibleComerFicha() {
	//esta funcion devuelve true si es posible comer otra vez
	//en un principio (cuando la función toma la decisión) actual y siguiente no están actualizados
	//cuando pulse el primer espacio actualizo posActual
	//en el segundo espacio actualizo posSiguiente (hasta entonces posSiguiente estaba almacenando la posicion actual de este movimiento)
	bool auxdig = true;
	//comprobamos para cada blanca todas las negras
	for (int i = 0; i < 20; i++) {
		diagIzq[i] = false;
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		for (int j = 0; j < 20; j++) {
			//izquierda
			//primero comprobamos que haya una ficha en la casilla adyacente
			if (((listaFichasB[i]->posicion.x + 1) == listaFichasN[j]->posicion.x) && ((listaFichasB[i]->posicion.y - 1) == listaFichasN[j]->posicion.y)) {
				diagIzq[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
				int aux = 0;
				aux = i;
				int j;
				j = i;
				if (((listaFichasB[i]->posicion.x + 2) > 0) || ((listaFichasB[i]->posicion.y - 2) < -9)) {
					diagIzq[i] = false;
					j = i;
				}

				for (int v = 0; v < 20; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
											  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasB[i]->posicion.x + 2) == listaFichasN[v]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[v]->posicion.y)) || (((listaFichasB[i]->posicion.x + 2) == listaFichasN[v]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[v]->posicion.y))) {
						diagIzq[i] = false; //funciona correctamente, similar a la anterior				
					}
				}
			}
		}
	}

	for (int i = 0; i < 20; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		diagDer[i] = false;
		for (int j = 0; j < 20; j++) {
			//derecha
			if (((listaFichasB[i]->posicion.x - 1) == listaFichasN[j]->posicion.x) && ((listaFichasB[i]->posicion.y - 1) == listaFichasN[j]->posicion.y)) {
				diagDer[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
				int aux1 = 0;
				aux1 = i;
				int j1;
				j1 = i;
				if (((listaFichasB[i]->posicion.x - 2) < -9) || ((listaFichasB[i]->posicion.y - 2) < -9)) {
					diagDer[i] = false;
					aux1 = i;
				}

				for (int z = 0; z < 20; z++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
					 //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if	
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasB[i]->posicion.x - 2) == listaFichasN[z]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[z]->posicion.y)) || (((listaFichasB[i]->posicion.x - 2) == listaFichasN[z]->posicion.x) && ((listaFichasB[i]->posicion.y - 2) == listaFichasN[z]->posicion.y))) {
						diagDer[i] = false; //funciona correctamente, similar a la anterior	
					}
				}
			}
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (diagDer[i] || diagIzq[i])
			return true;
		else
			auxdig = false;
	}
	return auxdig;
 	
}
void Reglas::hacerReina() {
	
	for (int i = 0; i < 20; i++) {
		if (((posicionSiguiente.y +1 == listaFichasB[i]->posicion.y)||(posicionSiguiente.y + 2 == listaFichasB[i]->posicion.y)) && (posicionSiguiente.y == -9))
			listaFichasB[i]->estado = 1;
	
	}
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

void Reglas::delListaFichas(std::vector <Ficha*> listaB, std::vector <Ficha*> listaN) {
	int i = 0;
	for (i = 0; i < 20; i++) {
		//listaN[i]->posicion.x = listaFichasN[i]->posicion.x;
		//listaN[i]->posicion.y = listaFichasN[i]->posicion.y;
		listaB[i]->estado = listaFichasB[i]->estado;
		listaN[i]->estado = listaFichasN[i]->estado;
	}
}

Reglas::~Reglas()
{

}