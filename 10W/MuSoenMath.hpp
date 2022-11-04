#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

class Mat3 {

public:

	double P_v[1][3]
	{
		{0,0,0}
	};
	
	double temp = 0;

	Mat3() {

	}

	void multiply(double V[1][3], double T[3][3], double R[3][3], double S[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 0) // V*T
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						temp = temp +(V[0][k] * T[k][j]);
					}
					P_v[0][j] = temp;
					temp = 0;
				}
				for (int l = 0; l < 3; l++)
				{
					V[0][l] = P_v[0][l];
				}
			}
			if (i == 1) // VT*R
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						temp = temp + (V[0][k] * R[k][j]);
					}
					P_v[0][j] = temp;
					temp = 0;
				}
				for (int l = 0; l < 3; l++)
				{
					V[0][l] = P_v[0][l];
				}
			}
			if (i == 2) // VTR*S
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						temp = temp + (V[0][k] * S[k][j]);
					}
					P_v[0][j] = temp;
					temp = 0;
				}
			}
		}
	}

};

class Translate : Mat3{

private : 
	
public :

	double Translate_Mat3[3][3]
	{
			{1,0,0},
			{0,1,0},
			{0,0,1}
	};

	Translate() {

	}

	Translate(double x, double y) {

		Translate_Mat3[2][0] = x;
		Translate_Mat3[2][1] = y;
	}

};

class Rotate : Mat3 {

private:

public:


	double Rotate_Mat3[3][3]
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	Rotate() {

	}

	Rotate(double rad) {
		Rotate_Mat3[0][0] = cos(rad * (3.14 / 180));
		Rotate_Mat3[0][1] = -sin(rad * (3.14 / 180));
		Rotate_Mat3[1][0] = sin(rad * (3.14 / 180));
		Rotate_Mat3[1][1] = cos(rad * (3.14 / 180));
	}

};

class Scale : Mat3 {

private:

public:

	double Scale_Mat3[3][3]
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}

	};

	Scale() {
		
	}

	Scale(double s) {
		Scale_Mat3[0][0] = s;
		Scale_Mat3[1][1] = s;
	}

};

class Vec : Mat3 {

public:

	double Vec_v[1][3]
	{
		{0,0,1}
	};



	Vec() {

	}

	Vec(double x, double y) {
		Vec_v[0][0] = x;
		Vec_v[0][1] = y;
	}



};



