#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;


class Mumath {

public:

	double mat3[3][3]{ // 3x3행렬 기본 다차원 배열

			{0,0,0},
			{0,0,0},
			{0,0,0}
	};

	double tempmat3[3][3]{ // 3x3행렬의 계산시 사용하는 임시 다차원 배열

			{0,0,0},
			{0,0,0},
			{0,0,0}
	};

	double mat4[4][4]{ // 4x4행렬 기본 다차원 배열

			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
	};

	double tempmat4[4][4]{ // 4x4행렬의 계산시 사용하는 임시 다차원 배열

			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
	};

	double vec3[1][3]{  // Vec3 벡터값이 저장될 기본 다차원 배열

		{0,0,1}
	};

	double vec31[3][1]{  // 전치된 Vec3 벡터값이 저장될 기본 다차원 배열

		{0},
		{0},
		{1}
	};

	double tempvec31[3][1]{  // Vec3의 계산시 사용될 임시 다차원 배열

		{0},
		{0},
		{1}
	};

	double tempvec3[1][3]{  // Vec3의 계산시 사용될 임시 다차원 배열

		{0,0,1}
	};

	double vec4[1][4]{ // Vec4 벡터값이 저장될 기본 다차원 배열

		{0,0,0,1}
	};

	double vec41[4][1]{ // Vec4 벡터값이 저장될 기본 다차원 배열
		{0},
		{0},
		{0},
		{1}
	};

	double tempvec41[4][1]{ // Vec4의 계산시 사용될 임시 다차원 배열
		{0},
		{0},
		{0},
		{1}
	};

	double tempvec4[1][4]{ // Vec4의 계산시 사용될 임시 다차원 배열
		{0,0,0,1}
	};

	double temp = 0; // 계산된 값을 임시 저장할 변수

	bool transpose = false; // 해당 벡터가 전치되어있는지 아닌지 저장하는 변수

	void transpose_matrix(int length) { // 행렬을 전치시켜주는 함수
		if (length == 3) { // 3x3 행렬을 전치해주는   for문
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == 0 && j > 0) {
						temp = mat3[i][j];
						mat3[i][j] = mat3[j][i];
						mat3[j][i] = temp;
						temp = 0;
					}
					if (i == 1 && j == 2)
					{
						temp = mat3[i][j];
						mat3[i][j] = mat3[j][i];
						mat3[j][i] = temp;
						temp = 0;
					}
				}

			}
		}
		else if (length == 4) { // 4x4 행렬을 전치해주는 for문
			for (int i = 0; i < 3; i++)
			{
				switch (i)
				{
				case 0:
					for (int j = 1; j < 4; j++)
					{
						temp = mat4[i][j];
						mat4[i][j] = mat4[j][i];
						mat4[j][i] = temp;
						temp = 0;
					}
					break;
				case 1:
					for (int j = 2; j < 4; j++)
					{
						temp = mat4[i][j];
						mat4[i][j] = mat4[j][i];
						mat4[j][i] = temp;
						temp = 0;
					}
					break;
				case 2:
					temp = mat4[i][3];
					mat4[i][3] = mat4[3][i];
					mat4[3][i] = temp;
					temp = 0;
					break;
				}
			}
		}

		if (transpose == false) // 전치되어있지 않은 객체라면 전치됨으로 표시, 되어있는 객체라면 전치안됨으로 표시
		{
			transpose = true;
		}
		else {
			transpose = false;
		}
	}

	void transpose_vector(int length) { // 벡터를 전치시켜주는 함수
		if (length == 3) { // Vec3 벡터값을 전치해주는   for문
			for (int j = 0; j < 3; j++)
			{
				temp = vec3[0][j];
				vec3[0][j] = vec31[j][0];
				vec31[j][0] = temp;
				temp = 0;
			}
		}
		else if (length == 4) { // Vec4 벡터값을 전치해주는 for문
			for (int j = 0; j < 4; j++)
			{
				temp = vec4[0][j];
				vec4[0][j] = vec41[j][0];
				vec41[j][0] = temp;
				temp = 0;
			}
		}
		if (transpose == false) // 전치되어있지 않은 객체라면 전치됨으로 표시, 되어있는 객체라면 전치안됨으로 표시
		{
			transpose = true;
		}
		else {
			transpose = false;
		}
	}

	void identity_matrix(int length) { // 단위행렬로 초기화해주는 함수
		if (length == 3) { //3x3행렬을 단위행렬로 초기화 해주는 for문
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == j) {
						mat3[i][j] = 1;
					}
					else {
						mat3[i][j] = 0;
					}
				}
			}
		}
		else if (length == 4) { //4x4행렬을 단위행렬로 초기화 해주는 for문
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (i == j) {
						mat4[i][j] = 1;
					}
					else {
						mat4[i][j] = 0;
					}
				}
			}
		}
	}

	void identity_vector(int length) { // 단위벡터로 초기화해주는 함수
		if (length == 3) { //Vec3 벡터값을 단위행렬로 초기화 해주는 for문
			for (int i = 0; i < 3; i++)
			{
				vec3[0][i] = 1;
				vec31[i][0] = 1;
			}
		}
		else if (length == 4) { //Vec4 벡터값을 단위행렬로 초기화 해주는 for문
			for (int i = 0; i < 4; i++)
			{
				vec4[0][i] = 1;
				vec41[i][0] = 1;
			}
		}
	}
};

class Mat3 : public Mumath {// 행렬 클래스

public:

	int length = 3;

	Mat3() {}

	Mat3(double x, double y) { // 이동행렬 생성자, 매개변수로 이동할 x값y값을 받음
		mat3[2][0] = x;
		mat3[2][1] = y;
		mat3[0][0] = 1;
		mat3[1][1] = 1;
		mat3[2][2] = 1;
	}

	Mat3(double rad, string s) { // 회전행렬 생성자, 매개변수로 회전할 각도와 회전방향을 받음

		if (s == "right") // 오른쪽 회전
		{
			mat3[0][0] = cos(rad * (3.14 / 180));
			mat3[0][1] = -sin(rad * (3.14 / 180));
			mat3[1][0] = sin(rad * (3.14 / 180));
			mat3[1][1] = cos(rad * (3.14 / 180));
			mat3[2][2] = 1;
		}
		else if (s == "left") // 왼쪽 회전
		{
			mat3[0][0] = cos(rad * (3.14 / 180));
			mat3[0][1] = sin(rad * (3.14 / 180));
			mat3[1][0] = -sin(rad * (3.14 / 180));
			mat3[1][1] = cos(rad * (3.14 / 180));
			mat3[2][2] = 1;
		}
	}

	Mat3(double s) { // 크기변환행렬 생성자, 매개변수로 변환될 크기를 받음
		mat3[0][0] = s;
		mat3[1][1] = s;
		mat3[2][2] = 1;
	}

	Mat3(double m0, double m1, double m2, double m3, double m4, double m5, double m6, double m7, double m8)
	{
		mat3[0][0] = m0; mat3[0][1] = m1; mat3[0][2] = m2;
		mat3[1][0] = m3; mat3[1][1] = m4; mat3[1][2] = m5;
		mat3[2][0] = m6; mat3[2][1] = m7; mat3[2][2] = m8;
	}

	void print()
	{
		cout << "\n{";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << " " << mat3[i][j];
			}
			if (i < 2) cout << "\n ";
		}
		cout << " }\n" << endl;
	}

	Mat3 multifly_matrix(Mat3& m, Mat3& m1);

	Mat3 multifly_transpose_matrix(Mat3& m, Mat3& m1);

	Mat3 multifly_const_matrix(Mat3& m, double a);

	Mat3 division_const_matrix(Mat3& m, double a);

	Mat3 plus_matrix(Mat3& m, Mat3& m1);

	Mat3 minus_matrix(Mat3& m, Mat3& m1);

	Mat3 operator * (Mat3& m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					tempmat3[i][j] = tempmat3[i][j] + (mat3[i][k] * m.mat3[k][j]);
				}
			}
		}
		return Mat3(
			tempmat3[0][0], tempmat3[0][1], tempmat3[0][2],
			tempmat3[1][0], tempmat3[1][1], tempmat3[1][2],
			tempmat3[2][0], tempmat3[2][1], tempmat3[2][2]); // 객체값을 내보냄
	}

	Mat3 operator * (double a)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = mat3[i][j] * a;
			}
		}
		return Mat3(tempmat3[0][0], tempmat3[0][1], tempmat3[0][2], tempmat3[1][0], 
			tempmat3[1][1], tempmat3[1][2], tempmat3[2][0], tempmat3[2][1], tempmat3[2][2]);
	}

	Mat3 operator / (double a)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = mat3[i][j] / a;
			}
		}
		return Mat3(tempmat3[0][0], tempmat3[0][1], tempmat3[0][2], tempmat3[1][0], 
			tempmat3[1][1], tempmat3[1][2], tempmat3[2][0], tempmat3[2][1], tempmat3[2][2]);
	}

	Mat3 operator + (Mat3& m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = 0;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				tempmat3[j][k] = tempmat3[j][k] + (mat3[j][k] + m.mat3[j][k]);
			}
		}
		return Mat3(tempmat3[0][0], tempmat3[0][1], tempmat3[0][2], tempmat3[1][0], 
			tempmat3[1][1], tempmat3[1][2], tempmat3[2][0], tempmat3[2][1], tempmat3[2][2]);
	}

	Mat3 operator - (Mat3& m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				tempmat3[i][j] = 0;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				tempmat3[j][k] = tempmat3[j][k] + (mat3[j][k] - m.mat3[j][k]);
			}
		}
		return Mat3(tempmat3[0][0], tempmat3[0][1], tempmat3[0][2], tempmat3[1][0], 
			tempmat3[1][1], tempmat3[1][2], tempmat3[2][0], tempmat3[2][1], tempmat3[2][2]);
	}
};

class Mat4 : public Mumath {

public:

	int length = 4;

	Mat4() {}

	Mat4(double x, double y, double z)
	{
		mat4[3][0] = x;
		mat4[3][1] = y;
		mat4[3][2] = z;
		mat4[0][0] = 1;
		mat4[1][1] = 1;
		mat4[2][2] = 1;
		mat4[3][3] = 1;
	}

	Mat4(double rad, char c, string s) { // 회전행렬 생성자, 매개변수로 회전할 각도와 회전축, 회전방향을 받음

		switch (c)
		{
		case 'x':
			if (s == "right") // 오른쪽 회전
			{
				mat4[0][0] = 1;
				mat4[1][1] = cos(rad * (3.14 / 180));
				mat4[1][2] = -sin(rad * (3.14 / 180));
				mat4[2][1] = sin(rad * (3.14 / 180));
				mat4[2][2] = cos(rad * (3.14 / 180));
				mat4[3][3] = 1;
			}
			else if (s == "left") // 왼쪽 회전
			{
				mat4[0][0] = 1;
				mat4[1][1] = cos(rad * (3.14 / 180));
				mat4[1][2] = sin(rad * (3.14 / 180));
				mat4[2][1] = -sin(rad * (3.14 / 180));
				mat4[2][2] = cos(rad * (3.14 / 180));
				mat4[3][3] = 1;
			}
			break;
		case 'y':
			if (s == "right") // 오른쪽 회전
			{
				mat4[0][0] = cos(rad * (3.14 / 180));
				mat4[1][1] = 1;
				mat4[0][2] = sin(rad * (3.14 / 180));
				mat4[2][0] = -sin(rad * (3.14 / 180));
				mat4[2][2] = cos(rad * (3.14 / 180));
				mat4[3][3] = 1;
			}
			else if (s == "left") // 왼쪽 회전
			{
				mat4[0][0] = cos(rad * (3.14 / 180));
				mat4[1][1] = 1;
				mat4[0][2] = -sin(rad * (3.14 / 180));
				mat4[2][0] = sin(rad * (3.14 / 180));
				mat4[2][2] = cos(rad * (3.14 / 180));
				mat4[3][3] = 1;
			}
			break;
		case 'z':
			if (s == "right") // 오른쪽 회전
			{
				mat4[0][0] = cos(rad * (3.14 / 180));
				mat4[0][1] = -sin(rad * (3.14 / 180));
				mat4[1][0] = sin(rad * (3.14 / 180));
				mat4[1][1] = cos(rad * (3.14 / 180));
				mat4[2][2] = 1;
				mat4[3][3] = 1;
			}
			else if (s == "left") // 왼쪽 회전
			{
				mat4[0][0] = cos(rad * (3.14 / 180));
				mat4[0][1] = sin(rad * (3.14 / 180));
				mat4[1][0] = -sin(rad * (3.14 / 180));
				mat4[1][1] = cos(rad * (3.14 / 180));
				mat4[2][2] = 1;
				mat4[3][3] = 1;
			}
			break;
		}
	}

	Mat4(double s)
	{
		mat4[0][0] = s;
		mat4[1][1] = s;
		mat4[2][2] = s;
		mat4[2][2] = s;
		mat4[3][3] = 1;
	}

	Mat4(double m0, double m1, double m2, double m3, double m4, double m5, double m6, double m7,
		double m8, double m9, double m10, double m11, double m12, double m13, double m14, double m15)
	{
		mat4[0][0] = m0; mat4[0][1] = m1; mat4[0][2] = m2; mat4[0][3] = m3;
		mat4[1][0] = m4; mat4[1][1] = m5; mat4[1][2] = m6; mat4[1][3] = m7;
		mat4[2][0] = m8; mat4[2][1] = m9; mat4[2][2] = m10; mat4[2][3] = m11;
		mat4[3][0] = m12; mat4[3][1] = m13; mat4[3][2] = m14; mat4[3][3] = m15;
	}

	void print()
	{
		cout << "\n{";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << " " << mat4[i][j];
			}
			if (i < 3) cout << "\n ";
		}
		cout << " }\n" << endl;
	}

	Mat4 operator * (Mat4& m)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					tempmat4[i][j] = tempmat4[i][j] + (mat4[i][k] * m.mat4[k][j]);
				}
			}
		}
		return Mat4(
			tempmat4[0][0], tempmat4[0][1], tempmat4[0][2], tempmat4[0][3],
			tempmat4[1][0], tempmat4[1][1], tempmat4[1][2], tempmat4[1][3],
			tempmat4[2][0], tempmat4[2][1], tempmat4[2][2], tempmat4[2][3],
			tempmat4[3][0], tempmat4[3][1], tempmat4[3][2], tempmat4[3][3]);
	}

	Mat4 operator * (double a)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = mat4[i][j] * a;
			}
		}
		return Mat4(
			tempmat4[0][0], tempmat4[0][1], tempmat4[0][2], tempmat4[0][3],
			tempmat4[1][0], tempmat4[1][1], tempmat4[1][2], tempmat4[1][3],
			tempmat4[2][0], tempmat4[2][1], tempmat4[2][2], tempmat4[2][3],
			tempmat4[3][0], tempmat4[3][1], tempmat4[3][2], tempmat4[3][3]);
	}

	Mat4 operator / (double a)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = mat4[i][j] / a;
			}
		}
		return Mat4(
			tempmat4[0][0], tempmat4[0][1], tempmat4[0][2], tempmat4[0][3],
			tempmat4[1][0], tempmat4[1][1], tempmat4[1][2], tempmat4[1][3],
			tempmat4[2][0], tempmat4[2][1], tempmat4[2][2], tempmat4[2][3],
			tempmat4[3][0], tempmat4[3][1], tempmat4[3][2], tempmat4[3][3]);
	}

	Mat4 operator + (Mat4& m)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = 0;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				tempmat4[j][k] = tempmat4[j][k] + (mat4[j][k] + m.mat4[j][k]);
			}
		}
		return Mat4(
			tempmat4[0][0], tempmat4[0][1], tempmat4[0][2], tempmat4[0][3],
			tempmat4[1][0], tempmat4[1][1], tempmat4[1][2], tempmat4[1][3],
			tempmat4[2][0], tempmat4[2][1], tempmat4[2][2], tempmat4[2][3],
			tempmat4[3][0], tempmat4[3][1], tempmat4[3][2], tempmat4[3][3]);
	}

	Mat4 operator - (Mat4& m)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				tempmat4[i][j] = 0;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				tempmat4[j][k] = tempmat4[j][k] + (mat4[j][k] - m.mat4[j][k]);
			}
		}
		return Mat4(
			tempmat4[0][0], tempmat4[0][1], tempmat4[0][2], tempmat4[0][3],
			tempmat4[1][0], tempmat4[1][1], tempmat4[1][2], tempmat4[1][3],
			tempmat4[2][0], tempmat4[2][1], tempmat4[2][2], tempmat4[2][3],
			tempmat4[3][0], tempmat4[3][1], tempmat4[3][2], tempmat4[3][3]);
	}

	Mat4 multifly_matrix(Mat4& m, Mat4& m1);

	Mat4 multifly_transpose_matrix(Mat4& m, Mat4& m1);

	Mat4 multifly_const_matrix(Mat4& m, double a);

	Mat4 division_const_matrix(Mat4& m, double a);

	Mat4 plus_matrix(Mat4& m, Mat4& m1);

	Mat4 minus_matrix(Mat4& m, Mat4& m1);
};

class Vec3 : public Mumath {  // 벡터 클래스

public:

	int length = 3;

	Vec3() {}

	Vec3(double x, double y, double z) { // 벡터 생성자, 매개변수로 x,y좌표를 받음
		vec3[0][0] = x;
		vec3[0][1] = y;
		vec3[0][2] = z;
	}

	void print()
	{
		if (!transpose) {
			cout << "\n{ ";
			for (int j = 0; j < 3; j++)
			{
				cout << vec3[0][j];
				if (j < 2) cout << ", ";
			}
			cout << " }\n" << endl;
		}
		else {
			cout << "\n{ ";
			for (int j = 0; j < 3; j++)
			{
				cout << vec31[j][0];
				if (j < 2) cout << ",\n  ";
			}
			cout << " }\n" << endl;
		}
	}

	Vec3 operator * (Mat3& m) // operator *, 곱하기 연산을 정의하고 Mat3&를 매개변수로 받아와곱 계산
	{
		for (int l = 0; l < 3; l++)
		{
			tempvec3[0][l] = 1;
		}
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				temp = temp + (vec3[0][k] * m.mat3[k][j]);
			}
			tempvec3[0][j] = temp;
			temp = 0;
		}
		return Vec3(tempvec3[0][0], tempvec3[0][1], tempvec3[0][2]); // 객체값을 내보냄
	}

	Vec3 operator * (Vec3& v) // operator *, 곱하기 연산을 정의하고 Vec3 v&를 매개변수로 받아와 벡터곱 계산
	{
		for (int i = 0; i < 3; i++)
		{
			tempvec3[0][i] = 1;
		}
		for (int j = 0; j < 3; j++)
		{
			switch (j)
			{
			case 0:
				temp = (vec3[0][1] * v.vec3[0][2]) - (vec3[0][2] * v.vec3[0][1]);
				break;
			case 1:
				temp = (vec3[0][2] * v.vec3[0][0]) - (vec3[0][0] * v.vec3[0][2]);
				break;
			case 2:
				temp = (vec3[0][0] * v.vec3[0][1]) - (vec3[0][1] * v.vec3[0][0]);
				break;
			}
			tempvec3[0][j] = temp;
			temp = 0;
		}
		return Vec3(tempvec3[0][0], tempvec3[0][1], tempvec3[0][2]); // 객체값을 내보냄
	}

	Vec3 operator * (double a)
	{
		if (transpose) {
			for (int i = 0; i < 3; i++)
			{
				tempvec31[i][0] = 0;
			}
			for (int i = 0; i < 3; i++) {
				tempvec31[i][0] = vec31[i][0] * a;
			}
			return Vec3(tempvec31[0][0], tempvec31[1][0], tempvec31[2][0]);
		}
		else {
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = vec3[0][i] * a;
			}
			return Vec3(tempvec3[0][0], tempvec3[0][1], tempvec3[0][2]);
		}
	}

	Vec3 operator / (double a)
	{
		if (transpose) {
			for (int i = 0; i < 3; i++)
			{
				tempvec31[i][0] = 0;
			}
			for (int i = 0; i < 3; i++) {
				tempvec31[i][0] = vec31[i][0] / a;
			}
			return Vec3(tempvec31[0][0], tempvec31[1][0], tempvec31[2][0]);
		}
		else {
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = vec3[0][i] / a;
			}
			return Vec3(tempvec3[0][0], tempvec3[0][1], tempvec3[0][2]);
		}
	}

	Vec3 operator + (Vec3& v)
	{
		if (transpose == true && v.transpose == true) {
			for (int i = 0; i < 3; i++)
			{
				tempvec31[i][0] = 0;
			}
			for (int i = 0; i < 3; i++) {
				tempvec31[i][0] = vec31[i][0] + v.vec31[i][0];
			}
			return Vec3(tempvec31[0][0], tempvec31[1][0], tempvec31[2][0]);
		}
		else if (transpose == false && v.transpose == false) {
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = vec3[0][i] + v.vec3[0][i];
			}
			return Vec3(tempvec3[0][0], tempvec3[0][1], tempvec3[0][2]);
		}
	}

	Vec3 operator - (Vec3& v)
	{
		if (transpose == true && v.transpose == true) {
			for (int i = 0; i < 3; i++)
			{
				tempvec31[i][0] = 0;
			}
			for (int i = 0; i < 3; i++) {
				tempvec31[i][0] = vec31[i][0] - v.vec31[i][0];
			}
			return Vec3(tempvec31[0][0], tempvec31[1][0], tempvec31[2][0]);
		}
		else if (transpose == false && v.transpose == false) {
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				tempvec3[0][i] = vec3[0][i] - v.vec3[0][i];
			}
			return Vec3(tempvec3[0][0], tempvec3[0][1], tempvec3[0][2]);
		}
	}

	Vec3 multifly_matrix(Mat3& m, Vec3& v);

	Vec3 multifly_vector(Vec3& v, Mat3& m);

	Vec3 multifly_vector(Vec3& v, Vec3& v1);

	Vec3 multifly_transpose_matrix(Mat3& m, Vec3& v);

	Vec3 multifly_transpose_vector(Vec3& v, Mat3& m);

	Vec3 multifly_transpose_vector(Vec3& v, Vec3& v1);

	Vec3 multifly_const_vector(Vec3& v, double a);

	Vec3 division_const_vector(Vec3& v, double a);

	Vec3 plus_vector(Vec3& v, Vec3& v1);

	Vec3 minus_vector(Vec3& v, Vec3& v1);
};

class Vec4 : public Mumath {

public:

	int length = 4;

	Vec4() {}

	Vec4(double x, double y, double z, double w) { // 벡터 생성자, 매개변수로 x,y,z좌표를 받음
		vec4[0][0] = x;
		vec4[0][1] = y;
		vec4[0][2] = z;
		vec4[0][3] = w;
	}

	void print()
	{
		if (!transpose) {
			cout << "\n{ ";
			for (int j = 0; j < 4; j++)
			{
				cout << vec4[0][j];
				if (j < 3) cout << ", ";
			}
			cout << " }\n" << endl;
		}
		else {
			cout << "{ ";
			for (int j = 0; j < 4; j++)
			{
				cout << vec41[j][0];
				if (j < 3) cout << ",\n  ";
			}
			cout << " }\n" << endl;
		}
	}

	Vec4 operator * (Mat4& m) // operator *, 곱하기 연산을 정의하고 Mat4&를 매개변수로 받아와 행렬곱 계산
	{
		for (int l = 0; l < 4; l++)
		{
			tempvec4[0][l] = 1;
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				temp = temp + (vec4[0][k] * m.mat4[k][j]);
			}
			tempvec4[0][j] = temp;
			temp = 0;
		}
		return Vec4(tempvec4[0][0], tempvec4[0][1], tempvec4[0][2], tempvec4[0][3]);
	}

	Vec4 operator * (double a)
	{
		if (transpose) {
			for (int i = 0; i < 4; i++)
			{
				tempvec41[i][0] = 0;
			}
			for (int i = 0; i < 4; i++) {
				tempvec41[i][0] = vec41[i][0] * a;
			}
			return Vec4(tempvec41[0][0], tempvec41[1][0], tempvec41[2][0], tempvec41[3][0]);
		}
		else {
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = vec4[0][i] * a;
			}
			return Vec4(tempvec4[0][0], tempvec4[0][1], tempvec4[0][2], tempvec4[0][3]);
		}
	}

	Vec4 operator / (double a)
	{
		if (transpose) {
			for (int i = 0; i < 4; i++)
			{
				tempvec41[i][0] = 0;
			}
			for (int i = 0; i < 4; i++) {
				tempvec41[i][0] = vec41[i][0] / a;
			}
			return Vec4(tempvec41[0][0], tempvec41[1][0], tempvec41[2][0], tempvec41[3][0]);
		}
		else {
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = vec4[0][i] / a;
			}
			return Vec4(tempvec4[0][0], tempvec4[0][1], tempvec4[0][2], tempvec4[0][3]);
		}
	}

	Vec4 operator + (Vec4& v)
	{
		if (transpose == true && v.transpose == true) {
			for (int i = 0; i < 4; i++)
			{
				tempvec41[i][0] = 0;
			}
			for (int i = 0; i < 4; i++) {
				tempvec41[i][0] = vec41[i][0] + v.vec41[i][0];
			}
			return Vec4(tempvec41[0][0], tempvec41[1][0], tempvec41[2][0], tempvec41[3][0]);
		}
		else if (transpose == false && v.transpose == false) {
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = vec4[0][i] + v.vec4[0][i];
			}
			return Vec4(tempvec4[0][0], tempvec4[0][1], tempvec4[0][2], tempvec4[0][3]);
		}
	}

	Vec4 operator - (Vec4& v)
	{
		if (transpose == true && v.transpose == true) {
			for (int i = 0; i < 4; i++)
			{
				tempvec41[i][0] = 0;
			}
			for (int i = 0; i < 4; i++) {
				tempvec41[i][0] = vec41[i][0] - v.vec41[i][0];
			}
			return Vec4(tempvec41[0][0], tempvec41[1][0], tempvec41[2][0], tempvec41[3][0]);
		}
		else if (transpose == false && v.transpose == false) {
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = 0;
			}
			for (int i = 0; i < 4; i++)
			{
				tempvec4[0][i] = vec4[0][i] - v.vec4[0][i];
			}
			return Vec4(tempvec4[0][0], tempvec4[0][1], tempvec4[0][2], tempvec4[0][3]);
		}
	}

	Vec4 multifly_matrix(Mat4& m, Vec4& v);

	Vec4 multifly_vector(Vec4& v, Mat4& m);

	Vec4 multifly_transpose_matrix(Mat4& m, Vec4& v);

	Vec4 multifly_transpose_vector(Vec4& v, Mat4& m);

	Vec4 multifly_const_vector(Vec4& v, double a);

	Vec4 division_const_vector(Vec4& v, double a);

	Vec4 plus_vector(Vec4& v, Vec4& v1);

	Vec4 minus_vector(Vec4& v, Vec4& v1);

};

Vec3 operator * (Mat3& m, Vec3& v)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			m.tempmat3[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m.temp = m.temp + (m.mat3[i][j] * v.vec31[j][0]);
		}
		m.tempmat3[i][0] = m.temp;
		m.temp = 0;
	}
	return Vec3(m.tempmat3[0][0], m.tempmat3[1][0], m.tempmat3[2][0]);
}

Vec4 operator * (Mat4& m, Vec4& v)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			m.tempmat4[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m.temp = m.temp + (m.mat4[i][j] * v.vec41[j][0]);
		}
		m.tempmat4[i][0] = m.temp;
		m.temp = 0;
	}
	return Vec4(m.tempmat4[0][0], m.tempmat4[1][0], m.tempmat4[2][0], m.tempmat4[3][0]);
}

// 행렬 3 연산 함수

Mat3 Mat3::multifly_matrix(Mat3& m, Mat3& m1)
{
	Mat3 mat = m * m1;
	mat.print();
	return 0;
}

Mat3 Mat3::multifly_transpose_matrix(Mat3& m, Mat3& m1)
{
	Mat3 mat = m * m1;
	mat.transpose_matrix(mat.length);
	mat.print();
	return 0;
}

Vec3 Vec3::multifly_matrix(Mat3& m, Vec3& v)
{
	Vec3 vec;
	if (!v.transpose) {
		cout << "\n오류 : 벡터값이 전치되어있지 않아 곱셈 불가" << endl;
		return vec;
	}
	vec = m * v;
	vec.transpose_vector(vec.length);
	vec.print();
	return vec;
}

Vec3 Vec3::multifly_transpose_matrix(Mat3& m, Vec3& v)
{
	Vec3 vec;
	if (!v.transpose) {
		cout << "\n오류 : 벡터값이 전치되어있지 않아 곱셈 불가" << endl;
		return vec;
	}
	vec = m * v;
	vec.print();
	return vec;;
}

Mat3 Mat3::multifly_const_matrix(Mat3& m, double a)
{
	Mat3 mat = m * a;
	mat.print();
	return 0;
}

Mat3 Mat3::division_const_matrix(Mat3& m, double a)
{
	Mat3 mat = m / a;
	mat.print();
	return 0;
}

Mat3 Mat3::plus_matrix(Mat3& m, Mat3& m1)
{
	Mat3 mat = m + m1;
	mat.print();
	return 0;
}

Mat3 Mat3::minus_matrix(Mat3& m, Mat3& m1)
{
	Mat3 mat = m - m1;
	mat.print();
	return 0;
}

// 벡터 3 연산 함수

Vec3 Vec3::multifly_vector(Vec3& v, Mat3& m)
{
	Vec3 vec;
	if (v.transpose)
	{
		cout << "\n오류 : 벡터값이 전치되어있어 곱셈 불가" << endl;
	}
	else {
		vec = v * m;
		vec.print();
	}
	return vec;
}

Vec3 Vec3::multifly_transpose_vector(Vec3& v, Mat3& m)
{
	Vec3 vec;
	if (v.transpose)
	{
		cout << "\n오류 : 벡터값이 전치되어있어 곱셈 불가" << endl;
	}
	else {
		vec = v * m;
		vec.transpose_vector(vec.length);
		vec.print();
	}
	return vec;
}

Vec3 Vec3::multifly_vector(Vec3& v, Vec3& v1)
{
	Vec3 vec;
	if (v.transpose == false && v1.transpose == false)
	{
		vec = v * v1;
		vec.print();
		return vec;
	}
	else {
		cout << "\n오류 : 벡터값이 전치되어있어 곱셈 불가\n" << endl;
	}
	return vec;
}

Vec3 Vec3::multifly_transpose_vector(Vec3& v, Vec3& v1)
{
	Vec3 vec;
	if (v.transpose == false && v1.transpose == false)
	{
		vec = v * v1;
		vec.transpose_vector(vec.length);
		vec.print();
		return vec;
	}
	else {
		cout << "\n오류 : 벡터값이 전치되어있어 곱셈 불가\n" << endl;
	}
	return vec;
}

Vec3 Vec3::multifly_const_vector(Vec3& v, double a)
{
	Vec3 vec = v * a;
	if (v.transpose == true)
	{
		vec.transpose_vector(vec.length);
		vec.print();
	}
	else
	{
		vec.print();
	}
	return vec;
}

Vec3 Vec3::division_const_vector(Vec3& v, double a)
{
	Vec3 vec = v / a;
	if (v.transpose == true)
	{
		vec.transpose_vector(vec.length);
		vec.print();
	}
	else
	{
		vec.print();
	}
	return vec;
}

Vec3 Vec3::plus_vector(Vec3& v, Vec3& v1)
{
	Vec3 vec;
	if (v.transpose == v1.transpose)
	{
		vec = v + v1;
		if (v.transpose == true)
		{
			vec.transpose_vector(vec.length);
			vec.print();
		}
		else
		{
			vec.print();
		}
		return vec;
	}
	else {
		cout << "\n벡터값의 형태가 다르게 전치되어있어 덧셈불가" << endl;
	}
	return vec;
}

Vec3 Vec3::minus_vector(Vec3& v, Vec3& v1)
{
	Vec3 vec;
	if (v.transpose == v1.transpose)
	{
		vec = v - v1;
		if (v.transpose == true)
		{
			vec.transpose_vector(vec.length);
			vec.print();
		}
		else
		{
			vec.print();
		}
		return vec;
	}
	else {
		cout << "\n벡터값의 형태가 다르게 전치되어있어 뺄셈불가" << endl;
	}
	return vec;
}

// 행렬 4 연산 함수

Mat4 Mat4::multifly_matrix(Mat4& m, Mat4& m1)
{
	Mat4 mat = m * m1;
	mat.print();
	return 0;
}

Mat4 Mat4::multifly_transpose_matrix(Mat4& m, Mat4& m1)
{
	Mat4 mat = m * m1;
	mat.transpose_matrix(mat.length);
	mat.print();
	return 0;
}

Vec4 Vec4::multifly_matrix(Mat4& m, Vec4& v)
{
	Vec4 vec;
	if (!v.transpose) {
		cout << "\n오류 : 벡터값이 전치되어있지 않아 곱셈 불가" << endl;
		return vec;
	}
	vec = m * v;
	vec.print();
	return vec;
}

Vec4 Vec4::multifly_transpose_matrix(Mat4& m, Vec4& v)
{
	Vec4 vec;
	if (!v.transpose) {
		cout << "\n오류 : 벡터값이 전치되어있지 않아 곱셈 불가" << endl;
		return vec;
	}
	vec = m * v;
	vec.transpose_vector(vec.length);
	vec.print();
	return vec;;
}

Mat4 Mat4::multifly_const_matrix(Mat4& m, double a)
{
	Mat4 mat = m * a;
	mat.print();
	return 0;
}

Mat4 Mat4::division_const_matrix(Mat4& m, double a)
{
	Mat4 mat = m / a;
	mat.print();
	return 0;
}

Mat4 Mat4::plus_matrix(Mat4& m, Mat4& m1)
{
	Mat4 mat = m + m1;
	mat.print();
	return 0;
}

Mat4 Mat4::minus_matrix(Mat4& m, Mat4& m1)
{
	Mat4 mat = m - m1;
	mat.print();
	return 0;
}

// 벡터 4 연산 함수

Vec4 Vec4::multifly_vector(Vec4& v, Mat4& m)
{
	Vec4 vec;
	if (v.transpose)
	{
		cout << "\n오류 : 벡터값이 전치되어있어 곱셈 불가" << endl;
	}
	else {
		vec = v * m;
		vec.print();
	}
	return vec;
}

Vec4 Vec4::multifly_transpose_vector(Vec4& v, Mat4& m)
{
	Vec4 vec;
	if (v.transpose)
	{
		cout << "\n오류 : 벡터값이 전치되어있어 곱셈 불가" << endl;
	}
	else {
		vec = v * m;
		vec.transpose_vector(vec.length);
		vec.print();
	}
	return vec;
}

Vec4 Vec4::multifly_const_vector(Vec4& v, double a)
{
	Vec4 vec = v * a;
	if (v.transpose == true)
	{
		vec.transpose_vector(vec.length);
		vec.print();
	}
	else
	{
		vec.print();
	}
	return vec;
}

Vec4 Vec4::division_const_vector(Vec4& v, double a)
{
	Vec4 vec = v / a;
	if (v.transpose == true)
	{
		vec.transpose_vector(vec.length);
		vec.print();
	}
	else
	{
		vec.print();
	}
	return vec;
}

Vec4 Vec4::plus_vector(Vec4& v, Vec4& v1)
{
	Vec4 vec;
	if (v.transpose == v1.transpose)
	{
		vec = v + v1;
		if (v.transpose == true)
		{
			vec.transpose_vector(vec.length);
			vec.print();
		}
		else
		{
			vec.print();
		}
		return vec;
	}
	else {
		cout << "\n벡터값의 형태가 다르게 전치되어있어 덧셈불가" << endl;
	}
	return vec;
}

Vec4 Vec4::minus_vector(Vec4& v, Vec4& v1)
{
	Vec4 vec;
	if (v.transpose == v1.transpose)
	{
		vec = v - v1;
		if (v.transpose == true)
		{
			vec.transpose_vector(vec.length);
			vec.print();
		}
		else
		{
			vec.print();
		}
		return vec;
	}
	else {
		cout << "\n벡터값의 형태가 다르게 전치되어있어 뺄셈불가" << endl;
	}
	return vec;
}

