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