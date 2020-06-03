#include "ETSIDI.h"
#include "Graficos.h"

Graficos::Graficos(){
	ojo_y = 10.5;
	Escena = 0;
	ContBlancas = 0;
	ContNegras = 0;
}

void Graficos::DibTab() {

	//Las transiciones de la animaci�n en Tablero.cpp

	//AJUSTAR TODOS LOS PUNTOS DE VISTA, los ojos y de cada if hay que quitarlos para poder realizar las animaciones.
	//Escena Pantalla Inicio. OK
	if ((Escena == 0))
	{
		gluLookAt(15, -4.5, 10, 15, -4.5, 0.0, 0.0, -1.0, 1.0);
	}
	//Escena reglas. OK
	else if ((Escena == 2))
	{
		gluLookAt(-24, -4.5, 10, -24, -4.5, 0.0, 0.0, -1.0, 1.0);
	}
	//Escena reglas desde pausa. OK
	else if ((Escena == 4))
	{
		gluLookAt(-24, -4.5, 10, -24, -4.5, 0.0, 0.0, -1.0, 1.0);
	}
	//Escena pausa. OK
	else if ((Escena == 3))
	{
		gluLookAt(-24, 15, 10, -24, 15, 0.0, 0.0, -1.0, 1.0);
	}
	//Escena AAE. OK
	else if ((Escena == 5))
	{
		gluLookAt(-24, -15, 10, -24, -15, 0.0, 0.0, -1.0, 1.0);
	}
	//Escena VVV. OK
	else if ((Escena == 6))
	{
		gluLookAt(23.5, -15, 10, 23.5, -15, 0.0, 0.0, -1.0, 1.0);
	}
	//Punto de vista blancas. OK
	else if ((Turn == 1) && (vis != 2) && (Escena == 1))
	{
		ojo_y = 10.5;
		gluLookAt(-3.5, ojo_y, 15, -3.5, -3.5, 0.0, 0.0, -1.0, 1.0);
	}
	// Punto de vista negras. OK
	else if ((Turn == 0) && (vis != 2) && (Escena == 1))
	{
		ojo_y = -20.5;
		gluLookAt(-3.5, ojo_y, 15, -3.5, -3.5, 0.0, 0.0, -1.0, 1.0);
	}
	//Punto vista aereo. OK
	else if ((vis == 2) && (Escena == 1))
	{
		gluLookAt(-3.5, -3.5, 25, -3.5, -3.5, 0.0, 0.0, -1.0, 1.0);
	}

	//Pintamos el marco del tablero
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Marco.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 1);		glVertex3f(1.6, 1.6, -0.01);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(-8.6, 1.6, -0.01);// Inferior Derecha
	glTexCoord2d(1, 0);		glVertex3f(-8.6, -8.6, -0.01);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(1.6, -8.6, -0.01);// Superior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Pintamos el suelo del tablero.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/suelomarmol.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 1);		glVertex3f(20, 20, -0.03);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(-29, 20, -0.03);// Inferior Derecha
	glTexCoord2d(1, 0);		glVertex3f(-29, -29, -0.03);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(20, -29, -0.03);// Superior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Pintamos el men� inicial.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MenuInicial.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 0);		glVertex3f(18, -7.5, 0.03);// Superior Izquierda
	glTexCoord2d(1, 0);		glVertex3f(12, -7.5, 0.03);// Superior Derecha
	glTexCoord2d(1, 1);		glVertex3f(12, -2, 0.03);// Inferior Derecha
	glTexCoord2d(0, 1);		glVertex3f(18, -2, 0.03);// Inferior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Pintamos las reglas.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Reglas.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 0);		glVertex3f(-20, -7.7, 0.03);// Superior Izquierda
	glTexCoord2d(1, 0);		glVertex3f(-28, -7.7, 0.03);// Superior Derecha
	glTexCoord2d(1, 1);		glVertex3f(-28, -1.8, 0.03);// Inferior Derecha
	glTexCoord2d(0, 1);		glVertex3f(-20, -1.8, 0.03);// Inferior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Pintamos la pausa.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Pausa.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 0);		glVertex3f(-20, 13, 0.03);// Superior Izquierda
	glTexCoord2d(1, 0);		glVertex3f(-28, 13, 0.03);// Superior Derecha
	glTexCoord2d(1, 1);		glVertex3f(-28, 17, 0.03);// Inferior Derecha
	glTexCoord2d(0, 1);		glVertex3f(-20, 17, 0.03);// Inferior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Pintamos el mensaje VVV
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/VVV.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 0);		glVertex3f(28, -17, 0.03);// Superior Izquierda
	glTexCoord2d(1, 0);		glVertex3f(20, -17, 0.03);// Superior Derecha
	glTexCoord2d(1, 1);		glVertex3f(20, -13, 0.03);// Inferior Derecha
	glTexCoord2d(0, 1);		glVertex3f(28, -13, 0.03);// Inferior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Pintamos el mensaje AAE.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/AAE.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);


	glTexCoord2d(0, 0);		glVertex3f(-20, -17, 0.03);// Superior Izquierda
	glTexCoord2d(1, 0);		glVertex3f(-28, -17, 0.03);// Superior Derecha
	glTexCoord2d(1, 1);		glVertex3f(-28, -13, 0.03);// Inferior Derecha
	glTexCoord2d(0, 1);		glVertex3f(-20, -13, 0.03);// Inferior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Contador de fichas capturadas por el jugador de blancas.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Cement.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(0, 1);		glVertex3f(4.6, 4.6, -0.01);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(0.6, 4.6, -0.01);// Inferior Derecha
	glTexCoord2d(1, 0);		glVertex3f(0.6, 0.6, -0.01);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(4.6, 0.6, -0.01);// Superior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Gr�ficos de n�meros.
	glEnable(GL_TEXTURE_2D);

	if (ContBlancas == 1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/1.png").id);
	else if (ContBlancas == 2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/2.png").id);
	else if (ContBlancas == 3)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/3.png").id);
	else if (ContBlancas == 4)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/4.png").id);
	else if (ContBlancas == 5)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/5.png").id);
	else if (ContBlancas == 6)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/6.png").id);
	else if (ContBlancas == 7)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/7.png").id);
	else if (ContBlancas == 8)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/8.png").id);
	else if (ContBlancas == 9)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/9.png").id);
	else if (ContBlancas == 10)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/10.png").id);
	else if (ContBlancas == 11)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/11.png").id);
	else if (ContBlancas == 12)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/12.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(0, 1);		glVertex3f(4.2, 4.1, 0.01);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(1, 4.1, 0.01);// Inferior Derecha
	glTexCoord2d(1, 0);		glVertex3f(1, 0.9, 0.01);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(4.2, 0.9, 0.01);// Superior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Contador de fichas capturadas por el jugador de negras.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Cement.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(1, 0);		glVertex3f(-7.6, -7.6, -0.01);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(-11.6, -7.6, -0.01);// Superior Izquierda
	glTexCoord2d(0, 1);		glVertex3f(-11.6, -11.6, -0.01);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(-7.6, -11.6, -0.01);// Inferior Derecha

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Gr�ficos de n�meros.
	glEnable(GL_TEXTURE_2D);

	if (ContNegras == 1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/1.png").id);
	else if (ContNegras == 2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/2.png").id);
	else if (ContNegras == 3)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/3.png").id);
	else if (ContNegras == 4)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/4.png").id);
	else if (ContNegras == 5)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/5.png").id);
	else if (ContNegras == 6)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/6.png").id);
	else if (ContNegras == 7)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/7.png").id);
	else if (ContNegras == 8)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/8.png").id);
	else if (ContNegras == 9)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/9.png").id);
	else if (ContNegras == 10)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/10.png").id);
	else if (ContNegras == 11)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/11.png").id);
	else if (ContNegras == 12)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/12.png").id);


	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(1, 0);		glVertex3f(-8, -7.9, 0.01);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(-11.2, -7.9, 0.01);// Superior Izquierda
	glTexCoord2d(0, 1);		glVertex3f(-11.2, -11.1, 0.01);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(-8, -11.1, 0.01);// Inferior Derecha

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Salida del juego.
	if ((ContNegras == 12) || (ContBlancas == 12))
	{
		Escena = 6;
	}
	/*//Jugador Negras.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/PensNegr.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(0, 1);		glVertex3f(-2.2, -7.7, 0);// Inferior Izquierda
	glTexCoord2d(1, 1);		glVertex3f(-4.8, -7.7, 0);// Inferior Derecha
	glTexCoord2d(1, 0);		glVertex3f(-4.8, -10.7, 3);// Superior Derecha
	glTexCoord2d(0, 0);		glVertex3f(-2.2, -10.7, 3);// Superior Izquierda

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Jugador Blancas.
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/PensBlanc.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(0, 0);		glVertex3f(-2.3, 4, 3);
	glTexCoord2d(1, 0);		glVertex3f(-4.6, 4, 3);
	glTexCoord2d(1, 1);		glVertex3f(-4.6, 0.8, 0);
	glTexCoord2d(0, 1);		glVertex3f(-2.3, 0.8, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);*/

}


Graficos::~Graficos() {

}