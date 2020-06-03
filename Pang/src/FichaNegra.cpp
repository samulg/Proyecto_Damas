#include "FichaNegra.h"
#include "glut.h"


FichaNegra::FichaNegra(int f, int c)
{
	posicion.x = (-c);
	posicion.y = (-f);
	estado = 0;

}
int FichaNegra::contador = 0;
void FichaNegra::dibujarFicha(void) {

		if ((estado == 0) || (estado == -1)) {
			//esta funcion se encarga de dibujar las fichas iniciales y de asignar su posición central a un vector fichas
			//damos por sentado que ya estamos situados en la esquina inferior izquierda
			glColor3ub(0, 0, 255);
			glTranslatef((posicion.x), (posicion.y), 0);
			glutSolidCube(0.5);
			glTranslatef((-posicion.x), (-posicion.y), 0);
		}
		if (estado == 1) {
			glColor3ub(0, 100, 100);
			glTranslatef((posicion.x), (posicion.y), 0);
			glutSolidCube(0.75);
			glTranslatef((-posicion.x), (-posicion.y), 0);
		}
}

FichaNegra::~FichaNegra()
{
}