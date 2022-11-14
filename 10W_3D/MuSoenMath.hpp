#pragma once
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

class Mat3 { // 행렬 클래스

public:

	double mat3[3][3] // 행렬 기본값
	{
			{1,0,0},
			{0,1,0},
			{0,0,1}
	};

	Mat3() {}

	Mat3(double x, double y) { // 이동행렬 생성자, 매개변수로 이동할 x값y값을 받음

		mat3[2][0] = x;
		mat3[2][1] = y;
	}

	Mat3(double rad, string s) { // 회전행렬 생성자, 매개변수로 회전할 각도와 회전방향을 받음

		if (s == "right") // 오른쪽 회전
		{
			mat3[0][0] = cos(rad * (3.14 / 180));
			mat3[0][1] = -sin(rad * (3.14 / 180));
			mat3[1][0] = sin(rad * (3.14 / 180));
			mat3[1][1] = cos(rad * (3.14 / 180));
		}
		else if (s == "left") // 왼쪽 회전
		{
			mat3[0][0] = cos(rad * (3.14 / 180));
			mat3[0][1] = sin(rad * (3.14 / 180));
			mat3[1][0] = -sin(rad * (3.14 / 180));
			mat3[1][1] = cos(rad * (3.14 / 180));
		}
	}

	Mat3(double s) { // 크기변환행렬 생성자, 매개변수로 변환될 크기를 받음
		mat3[0][0] = s;
		mat3[1][1] = s;
	}

};

class Vec3 {  // 벡터 클래스

public:

	double vec3[1][3]  // 벡터값이 저장될 기본 다차원 배열
	{
		{0,0,1}
	};

	double tempvec3[1][3]  // 곱계산 값을 저장할 다차원 배열
	{
		{0,0,1}
	};

	double temp = 0; // 계산을 위한 임시 저장 변수

	Vec3() {}

	Vec3(double x, double y) { // 벡터 생성자, 매개변수로 x,y좌표를 받음
		vec3[0][0] = x;
		vec3[0][1] = y;
	}

	void Convert(double p[1][3]) { // 벡터값을 이동한 p 벡터로 변경
		for (int i = 0; i < 3; i++)
		{
			vec3[0][i] = p[0][i];
		}
	}

	Vec3 operator * (Mat3& m) // operator *, 곱하기 연산을 정의하고 Mat3&를 매개변수로 받아와 행렬곱 계산
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

		return Vec3(vec3[0][0], vec3[0][1]); // 객체값을 내보냄
	}

};
