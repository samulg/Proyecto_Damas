#include "Tablero.h"

Tablero::Tablero()
{
	//reservamos memoria para la matriz de punteros del trablero
	controlSeleccion = 0;
	n = 10, m = 10;
	c = new Casilla *[n];		//filas
	for (i = 0; i < n; i++) {
		c[i] = new Casilla[m];     //columnas
	}

	//asignamos a listaFichas los valores de posición inicial (solo se debe llamar una vez)

	//blancas
	int p = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasB.push_back(new FichaBlanca(i,j));
				p++;
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

void Tablero::dibujarTablero() {
	//si declaro un segundo objeto de tablero (llamado desde OnDrawn) el constructor se vuelve a llamar y se dibujan las fichas iniciales otra vez
	//Tablero tabler1;
	gluLookAt(5, 10, 50,  // posicion del ojo
		5.0, 5.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 0.0, 1.0);      // definimos hacia arriba (eje Z) 

	for (i = 0; i < 10; i++) {	//cada i es una fila del tablero
		for (j = 0; j < 10; j++) { //cada j es una columna del tablero
			c[i][j].dibujarCasilla(i,j);
		}
	}
	hand.dibujarMano();
	hand.dibujarSeleccion();	
}
void Tablero::dibujarFichasIniciales() {
	//blancas
	//damos por sentado que ya estamos situados en la esquina inferior izquierda
	//fichB = new FichaBlanca();
	int nb = 0;
	int nn = 0;
	int i, j;
	int aux = 0;
	int aux2 = 0;

	//las posiciones de las fichas se cambian en otros métodos, éste solo invoca el dibujode las 20 fichas
	for (i = 0; i < 4; i++) {  //colocamos las fichas iniciales en aquellos que i+j sea par, de las 4 primeras filas
		for (j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasB[nb]->dibujarFicha();
				nb++;
			}
		}
	}

	//negras
	for (i = 6; i < 10; i++) {  //colocamos las fichas iniciales en aquellos que i+j sea par, de las 4 primeras filas
		for (j = 0; j < 10; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasN[nn]->dibujarFicha();
				nn++;
			}
		}
	}
	//regla.setListaFichas(listaFichasB, listaFichasN);

}
void Tablero::moverMano(unsigned char tecla) {
	Vector2D posSiguiente;//vector auxiliar para regla.setPosSig() la posicion siguiente (a donde voy)
	Vector2D posActual;//vector auxiliar para pasar a regla.setPosAct() la posicion anterior (de donde vengo)
	bool turno = false;//variable local para recoger el turno de Reglas
	int i;
	static int aux = 0; //para guardar la i del vector de fichas
	//sin estatic se pierde el valor (dentro de la misma funcion)
	//int aux2 = 0;//variable de control para evitar que los if se ejecuten instantaneamente¿si la declaro aquí cada vez que pulso vale 0?

	turno = 1;
	float x, y;
	if (tecla == 'w' && hand.fm < 9) {
		(hand.fm)++;
	}

	if (tecla == 'a' && hand.cm > 0) {
		(hand.cm)--;
	}

	if (tecla == 'd' && hand.cm < 9) {
		(hand.cm)++;
	}

	if (tecla == 's' && hand.fm > 0) {
		(hand.fm)--;
	}

	if (tecla == ' ') {
		turno = regla.getTurno();
		if (turno == 1) {
			for (i = 0; i < 20; i++) {
				//codigo para iluminar la casilla seleccionada (comprobamos que esté ocupada por una casilla blanca)
				if (listaFichasB[i]->posicion.x == (-hand.cm) && listaFichasB[i]->posicion.y == (-hand.fm)) {
					aux = i;
					hand.seleccionada = true;
					hand.fichaSeleccionada.x = hand.cm;
					hand.fichaSeleccionada.y = hand.fm;
				}
			}
		}

		if (turno == 0) {
			for (i = 0; i < 20; i++) {
				//codigo para iluminar la casilla seleccionada (comprobamos que esté ocupada por una casilla negra)
				if (listaFichasN[i]->posicion.x == (-hand.cm) && listaFichasN[i]->posicion.y == (-hand.fm)) {
					aux = i;
					hand.seleccionada = true;
					hand.fichaSeleccionada.x = hand.cm;
					hand.fichaSeleccionada.y = hand.fm;
				}
			}
		}
	}

	if (tecla == ' ' && hand.seleccionada == true) {
		regla.setListaFichas(listaFichasB, listaFichasN);//le pasamos a "Reglas.h" las posiciones de las fichas blancas y negras y
		//actualizamos dichas posiciones cada vez que se pulsa el espacio
		
		if (turno == 1 ) {
			//aquí entra con el primer espacio que pulsa , pero no vuelve a entrar(a reactualizar los valores de posicion) hasta que no pulso espacio por
			//segunda vez
			posActual.x = -(hand.fichaSeleccionada.x);
			posActual.y = -(hand.fichaSeleccionada.y);
			regla.setPosAct(posActual);//fichaSeleccionada guarda la posicion inicial de la ficha (de donde viene)

			//si no pongo "controlSeleccion", cada espacio que dé cambia de turno, y lo que quiero es que cambie de turno al
			//segundo espacio (el primero selecciona ficha, el segundo la coloca y después cambia el turno)
			//el mismo cambio de turno pone controlSeleccion a 0;
			controlSeleccion++;
			
			if (controlSeleccion == 2) {
				posSiguiente.x = (-hand.cm);
				posSiguiente.y = (-hand.fm);
				regla.setPosSig(posSiguiente);
				int h = 1;
				if ((regla.movDiagUnit()) == true) { //comprobamos que el movimiento es legal
					listaFichasB[aux]->posicion.x = (-hand.cm);//estas dos instrucciones
					listaFichasB[aux]->posicion.y = (-hand.fm);//son las que redibujan la ficha (actualizando su posicion)
					hand.seleccionada = false;//eliminamos la casilla seleccionada
					controlSeleccion = regla.cambiarTurno();//le pasamos el turno a las negras
				}
				else
					controlSeleccion = 1;
			}
		}
		else {
			//aquí entra con el segundo espacio
			//falta por duplicar el código de comprobacion del movimiento
			listaFichasN[aux]->posicion.x = (-hand.cm);
			listaFichasN[aux]->posicion.y = (-hand.fm);

			controlSeleccion++;

			if (controlSeleccion == 2) {
				hand.seleccionada = false;
				controlSeleccion = regla.cambiarTurno();
			}
		}
	}
}

Tablero::~Tablero()
{

}