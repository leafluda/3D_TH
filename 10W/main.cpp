#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.hpp"

using namespace std;


void main() {

	Mat3 p;

	Translate translate(3, 5);
	Rotate rotate(30);
	Scale scale(2);

	Vec vec(1, 1);

	cout << "translate" << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << translate.Translate_Mat3[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "rotate" << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << rotate.Rotate_Mat3[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "scale" << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << scale.Scale_Mat3[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "V" << "\n";
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << vec.Vec_v[i][j] << " ";
		};
	}
	cout << "\n";
	cout << "\n";
	cout << "P" << "\n";
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << p.P_v[i][j] << " ";
		};
	}
	cout << "\n";
	cout << "\n";
	cout << "P = v * Translate * Rotate * Scale" << "\n";
	cout << "\n";
	p.multiply(vec.Vec_v, translate.Translate_Mat3, rotate.Rotate_Mat3, scale.Scale_Mat3);
	cout << "P" << "\n";
	cout << "( ";
		for (int j = 0; j < 3; j++)
		{
			cout << p.P_v[0][j] << "  ";
		}
	cout << " )";
	cout << "\n";

}