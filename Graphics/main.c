#define _CRT_SECURE_NO_WARNINGS

#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>

typedef struct M M;
struct M
{
	double max;
	double min;
};

int H = 480, W = 640, camX = 0, camY = 0;
float zoom = 0.1;

void Textout(char* str, int x, int y, float red, float green, float blue)
{
	int i = 0;

	glColor3f(red, green, blue);
	glRasterPos2f(x, y);

	while (str[i] != '\0')
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, str[i]);
		i++;
		glRasterPos2f(x + i * 5, y);
	}
}

void keyboard(unsigned char Key, int X, int Y)
{
	static int fullscr = 0;

	if (Key == 27)
		exit(0);
	else if (Key == '+')
		zoom += 0.005;
	else if ((Key == '-') && (zoom > 0.015))
		zoom -= 0.005;
	else if (Key == 'f')
		if (fullscr == 0)
		{
			glutFullScreen();
			fullscr = 1;
		}
		else
		{
			glutReshapeWindow(640, 480);
			glutInitWindowPosition(100, 100);
			fullscr = 0;
		}
	else if (Key == 'w')
		camY += 5;
	else if (Key == 's')
		camY -= 5;
	else if (Key == 'a')
		camX -= 5;
	else if (Key == 'd')
		camX += 5;
}

void DrawDSC()
{
	float i, k = 0, step = 0.5, stepX = 1.57;

	if (zoom > 0.2)
	{
		step = 0.25;
		stepX = 0.785;
	}

	if (zoom >= 0.05)
	{
		Textout("1", -15, 1 * H * zoom, 0, 1, 0);
		Textout("-1", -15, -1 * H * zoom, 0, 1, 0);
	}

	if (zoom < 0.05)
	{
		step = 1.0;
		stepX = 3.1415;
	}
	
	if (zoom < 0.02)
	{
		step = 2.0;
		stepX = 6.2831;
	}

	glColor3f(0, 0, 0);

	glBegin(GL_LINES);

	glVertex2f(-W / 2 + camX, 0.0);
	glVertex2f(W / 2 + camX, 0.0);
	glVertex2f(0.0, H / 2 + camY);
	glVertex2f(0.0, -H / 2 + camY);
	glVertex2f(0, H / 2 + camY);
	glVertex2f(-10, H / 2 + camY - 10);
	glVertex2f(0, H / 2 + camY);
	glVertex2f(10, H / 2 + camY - 10);
	glVertex2f(W / 2 + camX, 0);
	glVertex2f(W / 2 + camX - 10, 10);
	glVertex2f(W / 2 + camX, 0);
	glVertex2f(W / 2 + camX - 10, -10);

	glEnd();

	Textout("y", -15, H / 2 + camY - 20, 0, 1, 0);
	Textout("x", W / 2 + camX - 20, -15, 0, 1, 0);

	for (i = 0; i < W / 2; i += stepX)
	{
		char coord[100] = {'p', 'i', '\0' }, Multip[10];

		if (k == 0)
			Textout("0", -10, 10, 0, 1, 0);
		else
		{
			if (round(k + 0.4) == k)
				sprintf(Multip, "%.0f", k);
			else
				sprintf(Multip, "%.2f", k);

			strcat(Multip, coord);
			Textout(Multip, W * zoom * i, -15, 0, 1, 0);
		}
			
		k += step;
	}

	k = -step;

	for (i = -stepX; i > -W / 2; i -= stepX)
	{
		char coord[100] = { 'p', 'i', '\0' }, Multip[10];


		if (round(k + 0.4) == k)
			sprintf(Multip, "%.0f", k);
		else
			sprintf(Multip, "%.2f", k);

		strcat(Multip, coord);
		Textout(Multip, W * zoom * i, -15, 0, 1, 0);

		k -= step;
	}
}

void DrawFunc()
{
	double x = -W / 2, y;

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	while (x <= (W / 2))
	{
		x += 0.01;
		y = pow(sin(x), 3) - pow(cos(x), 2);
		glVertex2f(W * zoom * x, H * zoom * y);
	}
	glEnd();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camX, camY, 50, camX, camY, 0, 0, 1, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-W / 2, W / 2, -H / 2, H / 2, -50.0, 50.0);

	DrawDSC();
	DrawFunc();

	glFlush();
	glutPostRedisplay();
}

void reshape(int width, int height) 
{
	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);

	H = height;
	W = width;
}

M FindMax()
{
	double i, y;
	M Result;
	
	Result.max = Result.min = 0;

	for (i = 6.28; i < 25.14; i += 0.001)
	{
		y = pow(sin(i), 3) - pow(cos(i), 2);

		if (y > Result.max)
			Result.max = y;
		if(y < Result.min)
			Result.min = y;
	}

	return Result;
}

void MenuHandle(int Value)
{
	char Res[100] = { '\0' };
	M R;
	int Max, Min;

	R = FindMax();

	Max = round(R.max);
	Min = round(R.min);

	sprintf(Res, "Max value: %d\n Min value: %d", Max, Min);

	switch (Value)
	{
	case 1:
		MessageBox(NULL, Res, "Result", MB_OK);
		break;
	}
}

void init()
{
	int menu;

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);

	menu = glutCreateMenu(MenuHandle);
	glutSetMenu(menu);
	glutAddMenuEntry("Find max", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OEVM_Lab3");
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);

	init();

	glutMainLoop();
	return 0;
}