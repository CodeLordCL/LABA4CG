#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <math.h>

double f1(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * p1 * (1 - t) * (1 - t) + 3 * t * t * p2 * (1 - t) + t * t * t * p3;
}

double f2(double p0, double p1, double p2, double p3, double t)
{
	return p0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * p1 * (1 - t) * (1 - t) + 3 * t * t * p2 * (1 - t) + t * t * t * p3; 
}

double f3(double p1, double p4, double r1, double r4, double t)
{
	return p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}

double f4(double p1, double p4, double r1, double r4, double t)
{
	return p1 * (2 * t * t * t - 3 * t * t + 1) + p4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}



double t_max = 0;

void Render(double delta_time)
{

	t_max += delta_time / 5; 

	if (t_max > 1)
	{
		t_max = 0;
	}


	double Vec1[] = { 5,5,5 };
	double Vec2[] = { 8,-6,3 };
	double Vec3[] = { 3,-6,-2 };
	double Vec4[] = { 8,-1,-3 };
	double Vec[3];


	glBegin(GL_LINE_STRIP);
	glVertex3dv(Vec1);
	glVertex3dv(Vec2);
	glVertex3dv(Vec3);
	glVertex3dv(Vec4);
	glEnd();

	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		Vec[0] = f1(Vec1[0], Vec2[0], Vec3[0], Vec4[0], t);
		Vec[1] = f1(Vec1[1], Vec2[1], Vec3[1], Vec4[1], t);
		Vec[2] = f1(Vec1[2], Vec2[2], Vec3[2], Vec4[2], t);
		glVertex3dv(Vec);
	}

	glEnd();

	
	glColor3d(1, 0, 1);
	glLineWidth(1); 


	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(Vec);
	glEnd();

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(Vec1);
	glVertex3dv(Vec2);
	glVertex3dv(Vec3);
	glEnd();

	//--------------------------
	
	double Vec50[] = { 1,1,1 };
	double Vec60[] = { 3,3,3 };
	double Vec70[] = { 3,6,3 };
	double Vec80[] = { -5,6,3 };
	double VecV[3];


	glBegin(GL_LINE_STRIP);
	glVertex3dv(Vec50);
	glVertex3dv(Vec60);
	glVertex3dv(Vec70);
	glVertex3dv(Vec80);
	glEnd();

	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		VecV[0] = f2(Vec50[0], Vec60[0], Vec70[0], Vec80[0], t);
		VecV[1] = f2(Vec50[1], Vec60[1], Vec70[1], Vec80[1], t);
		VecV[2] = f2(Vec50[2], Vec60[2], Vec70[2], Vec80[2], t);
		glVertex3dv(VecV);
	}

	glEnd();


	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(Vec50);
	glVertex3dv(Vec60);
	glVertex3dv(Vec70);
	glEnd();

	///

	double r1[] = { 0,4,0 }; 
	double r2[] = { 0,2,6 };

	double r3[] = { 4,-7,3 };
	double r4[] = { 0,0,0 };

	double P5[] = { 0,4,0 };;
	double P6[] = { 4,6,3 };

	double R1[] = { 0,-2,6 };
	double R2[] = { 4, 2, 5 };

	double P[3];

	glBegin(GL_LINES);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();


	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		P[0] = f3(P5[0], P6[0], R1[0], R2[0], t);
		P[1] = f3(P5[1], P6[1], R1[1], R2[1], t);
		P[2] = f3(P5[2], P6[2], R1[2], R2[2], t);
		glVertex3dv(P);  
	}
	glEnd();

	
	glColor3d(1, 0, 1);
	glLineWidth(1);  

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();


	///

	double r5[] = { 3,2,3 };
	double r6[] = { 1,0,1 };

	double r7[] = { 5,3,3 };
	double r8[] = { 8,2,4 };

	double P7[] = { 3,2,3 };;
	double P8[] = { 5,3,3 };

	double R3[] = { -2, -2, -2 };
	double R4[] = { 3, -1, 1 };

	double PP[3];

	glBegin(GL_LINES);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();


	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		PP[0] = f4(P7[0], P8[0], R3[0], R4[0], t);
		PP[1] = f4(P7[1], P8[1], R3[1], R4[1], t);
		PP[2] = f4(P7[2], P8[2], R3[2], R4[2], t);
		glVertex3dv(PP);
	}
	glEnd();


	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();


	glLineWidth(1);

}