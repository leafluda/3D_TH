#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.hpp"

using namespace std;


void main() {
	// 10Line ����� ���Ͱ��� ������ ��ü
	Mat3 translate(3, 5);										// 11Line �̵���İ��� ������ ��ü
	Mat3 rotate(30, "right");									// 12Line ȸ����İ��� ������ ��ü
	Mat3 scale(2);											// 13Line ũ�⺯ȯ��İ��� ������ ��ü
	Vec3 v(1, 1);											// 14Line ���� ���Ͱ��� ������ ��ü

	cout << "translate matrix\n{";

	for (int i = 0; i < 3; i++)									// 18Line �̵���� ���
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << translate.mat3[i][j];
		}
		if (i < 2) cout << "\n ";
	}
	cout << " }\n\nrotate matrix\n{";

	for (int i = 0; i < 3; i++)									// 28Line ȸ����� ���
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << rotate.mat3[i][j];
		}
		if (i < 2) cout << "\n ";
	}

	cout << " }\n\nscale matrix\n{";

	for (int i = 0; i < 3; i++)									// 39Line ũ�⺯ȯ��� ���
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << scale.mat3[i][j];
		}
		if (i < 2) cout << "\n ";
	}

	cout << " }\n\nv vector\n( ";

	for (int j = 0; j < 3; j++)									// 50Line �������� ���
	{
		cout << v.vec3[0][j];
		if (j < 2) cout << ", ";
	};

	cout << " )\n\nP = v * Translate * Rotate * Scale\n\n";

	Vec3 p = v * translate * rotate * scale;							// 58Line operator *�� ����ؼ� p ���

	cout << "P = ( ";

	for (int j = 0; j < 3; j++)								// 62Line P ���� ���
	{
		cout << p.vec3[0][j];
		if (j < 2) cout << ", ";
	}
	v.Convert(p.vec3);									// 67Line v ���Ͱ��� ����� p������ �ٲ���

	cout << " )\n\nv = P\n\nv vector(convert)\n( ";

	for (int j = 0; j < 3; j++)									// 71Line ����� v ���� ���
	{
		cout << v.vec3[0][j];
		if (j < 2) cout << ", ";
	}

	cout << " )\n";
}