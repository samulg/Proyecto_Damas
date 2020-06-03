#include "Casilla.h"
Casilla::Casilla()
{
	fm = 5;
	cm = 5;
	seleccionada = false;
}
void Casilla::dibujarCasilla(int f, int c) {
	int color;
	posicion.x = (-c - 0.5);
	posicion.y = (-f - 0.5);

	color = (f + c) % 2;
	if ( color == 0)
		glColor3ub(30, 20, 0);//negro

	if (color == 1)
		glColor3ub(255, 255, 255);//blanco

	glTranslatef((posicion.x), (posicion.y), 0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);      //pintamos una casilla cuadrada de lado uno
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();
	glTranslatef((-posicion.x), (-posicion.y), 0);
}
void Casilla::dibujarMano(void) {
	glColor3ub(0, 200, 100);
	mano.x = (-cm - 0.5);
	mano.y = (-fm - 0.5);
	glTranslatef((mano.x), (mano.y), 0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.01f);      //pintamos una casilla cuadrada de lado uno
	glVertex3f(1.0f, 0.0f, 0.01f);
	glVertex3f(1.0f, 1.0f, 0.01f);
	glVertex3f(0.0f, 1.0f, 0.01f);
	glEnd();
	glTranslatef((-mano.x), (-mano.y), 0);

}
void Casilla::dibujarSeleccion(void) {
	Vector2D coordenadas;
	if (seleccionada == true) {
		glColor3ub(255, 255, 0);
		coordenadas.x = (-fichaSeleccionada.x - 0.5);
		coordenadas.y = (-fichaSeleccionada.y - 0.5);
	
		glTranslatef((coordenadas.x), (coordenadas.y), 0);
		glBegin(GL_POLYGON);
		glVertex3f(0.0f, 0.0f, 0.01f);      //pintamos una casilla cuadrada de lado uno
		glVertex3f(1.0f, 0.0f, 0.01f);
		glVertex3f(1.0f, 1.0f, 0.01f);
		glVertex3f(0.0f, 1.0f, 0.01f);
		glEnd();
		glTranslatef((-coordenadas.x), (-coordenadas.y), 0);
	}
}
Casilla::~Casilla()
{

}