#include "FichaNegra.h"
#include "glut.h"


FichaNegra::FichaNegra(int f, int c)
{
	posicion.x = (-c);
	posicion.y = (-f);
	estado = 0;

}

void FichaNegra::dibujarFicha(void) {

	if (estado == 0) {
  		//damos por sentado que ya estamos situados en la esquina inferior izquierda
		glColor3ub(0, 0, 255);
		//posicion.x = (-c);
		//posicion.y = (-f);
		glTranslatef((posicion.x), (posicion.y), 0);
		glutSolidCube(0.5);
		glTranslatef((-posicion.x), (-posicion.y), 0);
	}
	if (estado == -1) {
		
		//esta funcion se encarga de dibujar las fichas iniciales y de asignar su posición central a un vector fichas
		//damos por sentado que ya estamos situados en la esquina inferior izquierda
		float pos_y=0;
		static int contador = 0;

		pos_y += (contador+0.2);
		glColor3ub(0, 0, 255);
		//posicion.x = (-c);
		//posicion.y = (-f);
		glTranslatef((2), (pos_y), 0);
		glutSolidCube(0.5);
		glTranslatef((-2), (-pos_y), 0);

	}
	

}

FichaNegra::~FichaNegra()
{
}