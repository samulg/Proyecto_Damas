#include "Tablero.h"

Tablero::Tablero()
{
	bot.mode = 0;

	cont1 = 0;
	cont2 = 0;
	//reservamos memoria para la matriz de punteros del trablero
	controlSeleccion = 0;
	n = 8, m = 8;
	c = new Casilla *[n];		//filas
	for (i = 0; i < n; i++) {
		c[i] = new Casilla[m];     //columnas
	}

	//asignamos a listaFichas los valores de posici�n inicial (solo se debe llamar una vez)

	//blancas
	int p = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasB.push_back(new FichaBlanca(i, j));
				p++;
			}
		}
	}

	//negras
	for (i = 5; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasN.push_back(new FichaNegra(i, j));
			}
		}
	}
}

void Tablero::dibujarTablero() {
	//si declaro un segundo objeto de tablero (llamado desde OnDrawn) el constructor se vuelve a llamar y se dibujan las fichas iniciales otra vez
	//Tablero tabler1;
	graf.Turn = regla.getTurno();//Le mandamos el turno a Graficos para que redibuje el tablero.
	graf.DibTab();


	for (i = 0; i < 8; i++) {	//cada i es una fila del tablero
		for (j = 0; j < 8; j++) { //cada j es una columna del tablero
			c[i][j].dibujarCasilla(i, j);
		}
	}
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

	//las posiciones de las fichas se cambian en otros m�todos, �ste solo invoca el dibujode las 20 fichas
	for (i = 0; i < 3; i++) {  //colocamos las fichas iniciales en aquellos que i+j sea par, de las 4 primeras filas
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {

				listaFichasB[nb]->dibujarFicha();
				nb++;

			}
		}
	}

	//negras
	for (i = 5; i < 8; i++) {  //colocamos las fichas iniciales en aquellos que i+j sea par, de las 4 primeras filas
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {

				listaFichasN[nn]->dibujarFicha();
				nn++;

			}
		}
	}
	regla.delListaFichas(listaFichasB, listaFichasN);
	if (graf.Turn == true)
		hand.dibujarManoBlanca();
	else if (bot.mode == 0)  ///////////////////////////////////bottttt
		hand.dibujarManoNegra();
}
void Tablero::moverMano(unsigned char tecla) {
	//Tablero t1;
	bool fichaComida = false;
	Vector2D posSiguiente;//vector auxiliar para regla.setPosSig() la posicion siguiente (a donde voy)
	Vector2D posActual;//vector auxiliar para pasar a regla.setPosAct() la posicion anterior (de donde vengo)
	bool turno = false;//variable local para recoger el turno de Reglas
	int i;
	static int aux = 0; //para guardar la i del vector de fichas
	//sin estatic se pierde el valor (dentro de la misma funcion)
	//int aux2 = 0;//variable de control para evitar que los if se ejecuten instantaneamente�si la declaro aqu� cada vez que pulso vale 0?

	turno = 1;
	float x, y;

	//Adaptamos el control al punto de vista de cada jugador.
	//Para Blancas
	turno = regla.getTurno();
	if (turno == 1) {
		if (tecla == 'w' && hand.fm < 7) {
			(hand.fm)++;
		}

		if (tecla == 'a' && hand.cm > 0) {
			(hand.cm)--;
		}

		if (tecla == 'd' && hand.cm < 7) {
			(hand.cm)++;
		}

		if (tecla == 's' && hand.fm > 0) {
			(hand.fm)--;
		}
	}

	//Para Negras. Comprobar la gesti�n de las negras en funci�n del modo.
	if ((turno == 0) && (bot.mode == 0)) {
		if ((tecla == 'w') && (hand.fm > 0)) {
			(hand.fm)--;
		}

		if ((tecla == 'a') && (hand.cm < 7)) {
			(hand.cm)++;
		}

		if ((tecla == 'd') && (hand.cm > 0)) {
			(hand.cm)--;
		}

		if ((tecla == 's') && (hand.fm < 7)) {
			(hand.fm)++;
		}
	}

	//Punto de vista a�reo.
	if (tecla == 'q') {
		if (graf.vis == 2)
			graf.vis = 0;
		else
			graf.vis = 2;
	}


	//Accedemos al 1vs1.
	if ((tecla == '1') && (graf.Escena == 0))
	{
		graf.Escena = 5;
	}

	//Accedemos al 1vsBot. 
	if ((tecla == '2') && (graf.Escena == 0))
	{
		bot.mode = 1;
		graf.Escena = 5;
	
	}

	//Accedemos a las instrucciones.
	if ((tecla == '3') && (graf.Escena != 1))
	{
		if (graf.Escena == 2)
			graf.Escena = 0;
		else if (graf.Escena == 0)
			graf.Escena = 2;
		else if (graf.Escena == 4)
			graf.Escena = 3;
		else if (graf.Escena == 3)
			graf.Escena = 4;

	}

	//Gesti�n de pausa.

	if ((tecla == 'p') && ((graf.Escena == 3) || (graf.Escena == 1)))
	{
		if (graf.Escena == 3)
			graf.Escena = 1;
		else
			graf.Escena = 3;
	}

	//Salimos del programa
	if ((tecla == '4') && ((graf.Escena == 0) || (graf.Escena == 3)))
	{
		exit(-1);
	}

	if (tecla == ' ') {
		turno = regla.getTurno();
		if (turno == 1) {
			for (i = 0; i < 12; i++) {
				//codigo para iluminar la casilla seleccionada (comprobamos que est� ocupada por una casilla blanca)
				if (listaFichasB[i]->posicion.x == (-hand.cm) && listaFichasB[i]->posicion.y == (-hand.fm)) {

					aux = i;
					hand.seleccionada = true;
					hand.fichaSeleccionada.x = hand.cm;
					hand.fichaSeleccionada.y = hand.fm;
				}
			}
		}

		if ((turno == 0)&&(bot.mode == 0)) {
			for (i = 0; i < 12; i++) {
				//codigo para iluminar la casilla seleccionada (comprobamos que est� ocupada por una casilla negra)
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

		if (turno == 1) {
			//aqu� entra con el primer espacio que pulsa , pero no vuelve a entrar(a reactualizar los valores de posicion) hasta que no pulso espacio por
			//segunda vez
			posActual.x = -(hand.fichaSeleccionada.x);
			posActual.y = -(hand.fichaSeleccionada.y);
			regla.setPosAct(posActual);//fichaSeleccionada guarda la posicion inicial de la ficha (de donde viene)

			//si no pongo "controlSeleccion", cada espacio que d� cambia de turno, y lo que quiero es que cambie de turno al
			//segundo espacio (el primero selecciona ficha, el segundo la coloca y despu�s cambia el turno)
			//el mismo cambio de turno pone controlSeleccion a 0;
			controlSeleccion++;//si el movimiento es legal y ha finiquitado controlSeleccion= a cambiarTurno
			//sino controlSeleccion = 1;

			if (controlSeleccion == 2) {
				posSiguiente.x = (-hand.cm);
				posSiguiente.y = (-hand.fm);
				regla.setPosSig(posSiguiente);

				if (regla.posibleComerFicha() || (regla.posibleComerConReina())) {//posibleComerFicha da positivo cuando hay una ficha negra adyacente (no comprueba que una casilla m�s all� este libre)
																													//Incluyo tambien la posible comida de las reinas hacia atras
					int h = 1;
					if (regla.fichaComida() || (regla.fichaComidaConReina())) {

						//era posible comer y ha comido
						listaFichasB[aux]->posicion.x = (-hand.cm);//estas dos instrucciones
						listaFichasB[aux]->posicion.y = (-hand.fm);//son las que redibujan la ficha (actualizando su posicion
						hand.seleccionada = false;
						regla.delListaFichas(listaFichasB, listaFichasN);//Nos devuelve los estados de las fichas
						regla.hacerReina();
						dibujarCementerio(); //Actualizamos la posicion de las fichas para que no obligue a comer a otra ficha cuando ya se ha comido y se ha mandado al cementerio
										//los usamos para cuando una ficha blanca come a una negra saber que ficha negra es la que se ha comido y mandarla al cementerio
						graf.ContBlancas++;//cuando ya hemos actualizado el estado de la �ltima comida, contamos muertas
						printf("%d", graf.ContBlancas);
						///////////////////////////////////////////////////////////////////
						regla.setListaFichas(listaFichasB, listaFichasN);

						int m = 0;
						int n = 1;
						n = m;
						if (regla.posibleComerFicha() == false && (regla.posibleComerConReina() == false)) {
							controlSeleccion = regla.cambiarTurno();
							hand.seleccionada = false;
						}
						else {
							controlSeleccion = 1;
						}
					}

					else {
						controlSeleccion = 1;
					}
				}
				//si no es posible comer ficha implemento los movimientos normales, tanto para las fichas normales
				//como para la reina (esta adicionalmente tiene que comprobar que la ficha en cuestion sea reina)
				else if (regla.movDiagUnit() || (regla.moverReina() && listaFichasB[aux]->estado == 1)) {
					listaFichasB[aux]->posicion.x = (-hand.cm);
					listaFichasB[aux]->posicion.y = (-hand.fm);
					hand.seleccionada = false;
					controlSeleccion = regla.cambiarTurno();
					regla.hacerReina();
				}
				else
					controlSeleccion = 1;


			}

		}
		////////////////////////////////////////////////////
		//negras
		else if (bot.mode == 0) {//turno de negras y bot desactivado

			posActual.x = -(hand.fichaSeleccionada.x);
			posActual.y = -(hand.fichaSeleccionada.y);
			regla.setPosAct(posActual);//fichaSeleccionada guarda la posicion inicial de la ficha (de donde viene)

			//si no pongo "controlSeleccion", cada espacio que d� cambia de turno, y lo que quiero es que cambie de turno al
			//segundo espacio (el primero selecciona ficha, el segundo la coloca y despu�s cambia el turno)
			//el mismo cambio de turno pone controlSeleccion a 0;
			controlSeleccion++;//si el movimiento es legal y ha finiquitado controlSeleccion= a cambiarTurno
			//sino controlSeleccion = 1;

			if (controlSeleccion == 2) {
				posSiguiente.x = (-hand.cm);
				posSiguiente.y = (-hand.fm);
				regla.setPosSig(posSiguiente);
				if ((regla.posibleComerFichaN()) || (regla.posibleComerConReinaN())) {//da falsos positivos cuando no es posible comer
					int h = 1;
					if ((regla.fichaComidaN()) || (regla.fichaComidaConReinaN())) {

						//era posible comer y ha comido
						listaFichasN[aux]->posicion.x = (-hand.cm);
						listaFichasN[aux]->posicion.y = (-hand.fm);
						hand.seleccionada = false;
						regla.delListaFichas(listaFichasB, listaFichasN);
						regla.hacerReinaN();
						dibujarCementerio();
						graf.ContNegras++;
						printf("%d", graf.ContNegras);
						///////////////////////////////////////////////////////////////////
						regla.setListaFichas(listaFichasB, listaFichasN);

						int m = 0;
						int n = 1;
						n = m;
						if ((regla.posibleComerFichaN() == false) && (regla.posibleComerConReinaN() == false)) {
							controlSeleccion = regla.cambiarTurno();
							hand.seleccionada = false;
						}
						else {
							controlSeleccion = 1;
						}
					}

					else {
						controlSeleccion = 1;
					}
				}

				else if (regla.movDiagUnitN() || (regla.moverReina() && listaFichasN[aux]->estado == 1)) {
					listaFichasN[aux]->posicion.x = (-hand.cm);
					listaFichasN[aux]->posicion.y = (-hand.fm);
					hand.seleccionada = false;
					controlSeleccion = regla.cambiarTurno();
					regla.hacerReinaN();
				}
				else
					controlSeleccion = 1;


			}
		}
		


	}
	

}



void Tablero::dibujarCementerio() {
	regla.delListaFichas(listaFichasB, listaFichasN);//cada funcion de tablero debe actualizar las fichas con Reglas
												//de manera independiente
	int contN = -1;
	int contB = -8;
	int contSaltoN = 0;
	int contSaltoB = 0;
	int auxN = 0;
	int auxB = 0;
	for (int i = 0; i < 12; i++) {

		if (listaFichasN[i]->estado == -1) {
			contN++;
			listaFichasN[i]->posicion.x = 2 + auxN;
			listaFichasN[i]->posicion.y = -(contN + 0.2);
			contSaltoN++;
		}
		if (contSaltoN == 3)
		{
			auxN++;
			contN = -1;
			contSaltoN = 0;
		}

	}
	for (int i = 0; i < 12; i++) {

		if (listaFichasB[i]->estado == -1) {
			contB++;
			listaFichasB[i]->posicion.x = -9 + auxB;
			listaFichasB[i]->posicion.y = contB + 0.2;
			contSaltoB++;
		}
		if (contSaltoB == 3)
		{
			auxB--;
			contB = -8;
			contSaltoB = 0;
		}

	}
}

void Tablero::Animacion() {

	//Contador de transici�n de la primera escena.
	if ((graf.Escena == 5)) {
		cont1 += 0.1;
		if (cont1 > 6)
			graf.Escena = 1;
	}

	if ((graf.Escena == 6)) {
		cont2 += 0.1;
		if (cont2 > 12)
			exit(-1);
	}
	//Omitidas por ahora.
	/*bool T;
	T = regla.getTurno();
	//Punto de vista blancas.

	if ((T == 1) && (graf.vis != 2) && (graf.ojo_y < 10.5))
	{
		graf.DibTab();
		graf.ojo_y += 0.1;
	}
	// Punto de vista negras.
	else if ((T == 0) && (graf.vis != 2) && (graf.ojo_y > -20.5))
	{
		graf.DibTab();
		graf.ojo_y -= 0.1;
	}

	//Debugueo manual. Eliminar cuando todo funcione correctamente.
	printf("%f", graf.ojo_y);*/
}
void Tablero::jugarBot() {
	bool turno = regla.getTurno();
	Jugada *jugada;
	if ((bot.mode == 1) && (turno == 0)) {
		int j = 0;
		
		bot.calcularPosicionesPosibles();
		////////////////////////////////////////error
		///jugada no recoge los valores (posSigu vale 0). bot si esta enviando valores. Probar con punteros
		jugada = bot.elegirMejorMov();
		listaFichasN[jugada->idFicha]->posicion.x = (jugada->posSig.x);
		listaFichasN[jugada->idFicha]->posicion.y = (jugada->posSig.y);
		bot.setListaFichas(listaFichasB, listaFichasN);
		int k = 0;
		regla.cambiarTurno();
	}
}
Tablero::~Tablero()
{


}