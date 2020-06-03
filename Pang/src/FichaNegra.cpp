#include "FichaNegra.h"
#include "glut.h"


FichaNegra::FichaNegra(int f, int c)
{
	posicion.x = (-c);
	posicion.y = (-f);
}

void FichaNegra::dibujarFicha(void) {


	//esta funcion se encarga de dibujar las fichas iniciales y de asignar su posición central a un vector fichas
	//damos por sentado que ya estamos situados en la esquina inferior izquierda
	glColor3ub(0, 0, 255);
	//posicion.x = (-c);
	//posicion.y = (-f);
	glTranslatef((posicion.x), (posicion.y), 0);
	glutSolidCube(0.5);
	glTranslatef((-posicion.x), (-posicion.y), 0);


}

FichaNegra::~FichaNegra()
{
}