#include "FichaBlanca.h"
#include "glut.h"


FichaBlanca::FichaBlanca(int f, int c)
{
	posicion.x = (-c);
	posicion.y = (-f);
}

void FichaBlanca::dibujarFicha() {
	
	if (estado == 0) {
		//esta funcion se encarga de dibujar las fichas iniciales y de asignar su posición central a un vector fichas
		//damos por sentado que ya estamos situados en la esquina inferior izquierda
		glColor3ub(0, 255, 0);
		glTranslatef((posicion.x), (posicion.y), 0);
		glutSolidCube(0.5);
		glTranslatef((-posicion.x), (-posicion.y), 0);
	}
	if (estado == 1) {
		glColor3ub(100, 100,10);
		glTranslatef((posicion.x), (posicion.y), 0);
		glutSolidCube(0.75);
		glTranslatef((-posicion.x), (-posicion.y), 0);
	}
}

FichaBlanca::~FichaBlanca()
{
}