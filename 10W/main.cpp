#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.hpp"

using namespace std;


void main() {
													// 10Line 변경된 벡터값을 저장할 객체
	Mat3 translate(3, 5);										// 11Line 이동행렬값을 저장할 객체
	Mat3 rotate(30,"right");									// 12Line 회전행렬값을 저장할 객체
	Mat3 scale(2);											// 13Line 크기변환행렬값을 저장할 객체
	Vec3 v(1, 1);											// 14Line 기존 벡터값을 저장할 객체

	cout << "translate matrix\n{";

	for (int i = 0; i < 3; i++)									// 18Line 이동행렬 출력
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << translate.mat3[i][j];
		}
		if (i < 2) cout << "\n ";
	}
	cout << " }\n\nrotate matrix\n{";

	for (int i = 0; i < 3; i++)									// 28Line 회전행렬 출력
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << rotate.mat3[i][j];
		}
		if (i < 2) cout << "\n ";
	}

	cout << " }\n\nscale matrix\n{";

	for (int i = 0; i < 3; i++)									// 39Line 크기변환행렬 출력
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << scale.mat3[i][j];
		}
		if (i < 2) cout << "\n ";
	}

	cout << " }\n\nv vector\n( ";

	for (int j = 0; j < 3; j++)									// 50Line 기존벡터 출력
	{
		cout << v.vec3[0][j];
		if (j < 2) cout << ", ";
	};

	cout << " )\n\nP = v * Translate * Rotate * Scale\n\n";

	Vec3 p = v * translate * rotate * scale;							// 58Line operator *를 사용해서 p 계산
										
	cout << "P = ( ";

		for (int j = 0; j < 3; j++)								// 62Line P 벡터 출력
		{
			cout << p.vec3[0][j];
			if (j < 2) cout << ", ";
		}
		v.Convert(p.vec3);									// 67Line v 벡터값을 계산한 p값으로 바꿔줌

	cout << " )\n\nv = P\n\nv vector(convert)\n( ";

	for (int j = 0; j < 3; j++)									// 71Line 변경된 v 벡터 출력
	{
		cout << v.vec3[0][j];
		if (j < 2) cout << ", ";
	}

	cout << " )\n";
}
