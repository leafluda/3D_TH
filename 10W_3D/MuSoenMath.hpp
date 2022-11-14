#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

class Mat3 { // ��� Ŭ����

public:

	double mat3[3][3] // ��� �⺻��
	{
			{1,0,0},
			{0,1,0},
			{0,0,1}
	};

	Mat3() {}

	Mat3(double x, double y) { // �̵���� ������, �Ű������� �̵��� x��y���� ����

		mat3[2][0] = x;
		mat3[2][1] = y;
	}

	Mat3(double rad, string s) { // ȸ����� ������, �Ű������� ȸ���� ������ ȸ�������� ����

		if (s == "right") // ������ ȸ��
		{
			mat3[0][0] = cos(rad * (3.14 / 180));
			mat3[0][1] = -sin(rad * (3.14 / 180));
			mat3[1][0] = sin(rad * (3.14 / 180));
			mat3[1][1] = cos(rad * (3.14 / 180));
		}
		else if (s == "left") // ���� ȸ��
		{
			mat3[0][0] = cos(rad * (3.14 / 180));
			mat3[0][1] = sin(rad * (3.14 / 180));
			mat3[1][0] = -sin(rad * (3.14 / 180));
			mat3[1][1] = cos(rad * (3.14 / 180));
		}
	}

	Mat3(double s) { // ũ�⺯ȯ��� ������, �Ű������� ��ȯ�� ũ�⸦ ����
		mat3[0][0] = s;
		mat3[1][1] = s;
	}

};

class Vec3 {  // ���� Ŭ����

public:

	double vec3[1][3]  // ���Ͱ��� ����� �⺻ ������ �迭
	{
		{0,0,1}
	};

	double tempvec3[1][3]  // ����� ���� ������ ������ �迭
	{
		{0,0,1}
	};

	double temp = 0; // ����� ���� �ӽ� ���� ����

	Vec3() {}

	Vec3(double x, double y) { // ���� ������, �Ű������� x,y��ǥ�� ����
		vec3[0][0] = x;
		vec3[0][1] = y;
	}

	void Convert(double p[1][3]) { // ���Ͱ��� �̵��� p ���ͷ� ����
		for (int i = 0; i < 3; i++)
		{
			vec3[0][i] = p[0][i];
		}
	}

	Vec3 operator * (Mat3& m) // operator *, ���ϱ� ������ �����ϰ� Mat3&�� �Ű������� �޾ƿ� ��İ� ���
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp = temp + (vec3[0][k] * m.mat3[k][j]);
			}
			tempvec3[0][j] = temp;
			temp = 0;
		}
		for (int l = 0; l < 3; l++)
		{
			vec3[0][l] = tempvec3[0][l];
		}

		return Vec3(vec3[0][0], vec3[0][1]); // ��ü���� ������
	}

};
