#include <GL/glut.h>
#include <iostream>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;


void timer(int);
void display();
void reshape(int, int);
void keyboard(int, int, int);

void init()
{
	glClearColor(51 / 255, 255 / 255, 153 / 255, 255 / 255);
	initGrid(COLUMNS, ROWS);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(320, 320);
	glutInitWindowSize(500, 500);
	glutCreateWindow("U L O O");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if (gameOver)
	{
		MessageBox(NULL, (LPCTSTR) L"End", (LPCTSTR) L"GAME OVER",0);
		exit(0);
	}
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer,0);
}



void keyboard(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;
	}
}