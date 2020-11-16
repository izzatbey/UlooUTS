#include <GL/glut.h>
#include <ctime>
#include "game.h"

int gridX, gridY;
int snake_length2D = 3;
bool food = true;
int foodX, foodY;
short sDirection = UP;
extern bool gameOver;

void grid2D_t(int, int);
int posX[60] = { 20,20,20 }, posY[60] = { 20,19,18 };

void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

void drawGrid()
{
	for (int x = 0; x < gridX; x++) {
		for (int y = 0; y < gridY; y++) {
			grid2D_t(x, y);
		}
	}
}

void grid2D_t(int x, int y)
{
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
	{
		glLineWidth(3.0);
		glColor3f(255 / 255, 0 / 255, 0 / 255);
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(0 / 255, 0 / 255, 0 / 255);
	}

	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void drawFood()
{
	if (food)
		random(foodX, foodY);
	food = false;
	glColor3f(0.4, 0.3, 0.5);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void drawSnake() 
{

	for (int i = snake_length2D - 1; i > 0; i--)
	{
		posX[i] = posX[i - 1];
		posY[i] = posY[i - 1];
	}
	if (sDirection == UP)
		posY[0]++;
	else if (sDirection == DOWN)
		posY[0]--;
	else if (sDirection == RIGHT)
		posX[0]++;
	else if (sDirection == LEFT)
		posX[0]--;
	for (int i = 0; i < snake_length2D; i++) 
	{
		if (i == 0)
			glColor3f(0.0, 0.0, 1.0);
		else
			glColor3f(1.0, 0.0, 0.0);
		glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);

	}
	if (posX[0] == 0 || posX[0] == gridX - 1 || posY[0] == 0 || posY[0] == gridY - 1)
		gameOver = true;
	if (posX[0] == foodX && posY[0] == foodY)
	{
		snake_length2D++;
		if (snake_length2D > MAX)
			snake_length2D == MAX;
		food = true;
	}
		
}

void random(int& x, int& y)
{
	int maximumX = gridX - 2;
	int maximumY = gridY - 2;
	int minimum = 1;
	srand(time(NULL));
	x = minimum + rand() % (maximumX - minimum);
	y = minimum + rand() % (maximumY - minimum);
}