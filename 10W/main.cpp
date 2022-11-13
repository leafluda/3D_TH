#include <iostream>
#include <cmath>
#include <stdio.h>
#include "MuSoenMath.hpp"

using namespace std;


void main() {
	
	bool mat_vec_cal = true;
	int page = 0;
	int detail_page = 0;

	Mat3 m1;
	Mat3 m2(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Mat3 m3(3, 5);
	Mat3 m4(30, "right");
	Mat3 m5(2);
	Mat4 m6;
	Mat4 m7(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Mat4 m8(3, 5, 2);
	Mat4 m9(30, 'y', "right");
	Mat4 m10(2);
	Vec3 v1;
	Vec3 v2(1,1,1);
	Vec4 v3;
	Vec4 v4(1, 1, 1, 1);
	Mat3 m11(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Mat3 m12(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Mat4 m13(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Mat4 m14(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Vec3 v5(3,2,1);
	Vec3 v6(3, 2, 1);
	Vec4 v7(4, 3, 2, 1);
	Vec4 v8(4, 3, 2, 1);
	Vec3 v9(3,5,1);
	Vec3 v10(9, 2, 1);
	Vec4 v11(8,4,2,1);
	Vec4 v12(9, 6, 3, 1);


	while (mat_vec_cal)
	{
		switch (page)
		{
		case 0 :
			cout << "계산 예시" << endl;
			cout << "1. 행렬 생성" << endl;
			cout << "2. 벡터 생성" << endl;
			cout << "3. 행렬 계산" << endl;
			cout << "4. 벡터 계산" << endl;
			cout << "5. 끝내기" << endl;
			cout << "입력(입력후 엔터) : ";
			cin >> page;
			cout << "\n";
			break;
		case 1:
			cout << "=====================================================================================" << endl;
			cout << "1. 행렬 생성" << endl;
			cout << "=====================================================================================" << endl;
			cout << "1) Mat3" << endl;
			cout << "=====================================================================================" << endl;
			cout << "-1 Mat3 기본 행렬 형태 : Mat3 m1" << endl;
			m1.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 Mat3 기본 행렬 생성 : Mat3 m2(1,2,3,4,5,6,7,8,9)" << endl;
			m2.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-3 Mat3 이동 행렬 생성 : Mat3 m3(3,5)" << endl;
			m3.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-4 Mat3 회전 행렬 생성 : Mat3 m4(30,''right'')" << endl;
			m4.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-5 Mat3 크기변환 행렬 생성 : Mat3 m5(2)" << endl;
			m5.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat3 m11(1,2,3,4,5,6,7,8,9)" << endl;
			m11.print();
			cout << "-6 Mat3 단위행렬 초기화 : m11.identity_matrix(m11.length)" << endl;
			m11.identity_matrix(m11.length);
			m11.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat3 m12(1,2,3,4,5,6,7,8,9)" << endl;
			m12.print();
			cout << "-7 Mat3 전치 행렬 변환 : m12.transpose_matrix(m11.length)" << endl;
			m12.transpose_matrix(m11.length);
			m12.print();
			cout << "=====================================================================================" << endl;
			cout << "2) Mat4" << endl;
			cout << "=====================================================================================" << endl;
			cout << "-1 Mat4 기본 행렬 형태 : Mat4 m6" << endl;
			m6.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 Mat4 기본 행렬 생성 : Mat4 m7(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)" << endl;
			m7.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-3 Mat4 이동 행렬 생성 : Mat4 m8(3, 5, 2)" << endl;
			m8.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-4 Mat4 회전 행렬 생성 : Mat4 m9(30, 'y', ''right'')" << endl;
			m9.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-5 Mat4 크기변환 행렬 생성 : Mat4 m10(2)" << endl;
			m10.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat4 m13(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)" << endl;
			m13.print();
			cout << "-6 Mat4 단위행렬 초기화 : m13.identity_matrix(m13.length)" << endl;
			m13.identity_matrix(m13.length);
			m13.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat4 m12(1,2,3,4,5,6,7,8,9)" << endl;
			m14.print();
			cout << "-7 Mat4 전치 행렬 변환 : m14.transpose_matrix(m14.length)" << endl;
			m14.transpose_matrix(m14.length);
			m14.print();
			cout << "=====================================================================================" << endl;
			cout << "뒤로가기(0 입력후 엔터) : ";
			cin >> page;
			cout << "\n";
			break;
		case 2:
			cout << "=====================================================================================" << endl;
			cout << "2. 벡터 생성" << endl;
			cout << "=====================================================================================" << endl;
			cout << "1) Vec3" << endl;
			cout << "=====================================================================================" << endl;
			cout << "-1 Vec3 기본 행렬 생성자 초기값 : Vec3 v1" << endl;
			v1.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 Vec3 기본 행렬 생성 : Vec3 v2(1,1,1)" << endl;
			v2.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v5(3,2,1)" << endl;
			v5.print();
			cout << "-3 Vec3 단위 벡터 초기화 : v5.identity_vector(v5.length)" << endl;
			v5.identity_vector(v5.length);
			v5.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v6(3,2,1)" << endl;
			v6.print();
			cout << "-4 Vec3 전치 벡터 변환: v6.transpose_matrix(v6.length)" << endl;
			v6.transpose_matrix(v6.length);
			v6.print();
			cout << "=====================================================================================" << endl;
			cout << "2) Vec4" << endl;
			cout << "=====================================================================================" << endl;
			cout << "-1 Vec4 기본 행렬 생성자 초기값 : Vec4 v3" << endl;
			v3.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 Vec4 기본 행렬 생성 : Vec4 v4(1,1,1,1)" << endl;
			v4.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec4 v7(4,3,2,1)" << endl;
			v7.print();
			cout << "-3 Vec4 단위 벡터 초기화 : v7.identity_vector(v7.length)" << endl;
			v7.identity_vector(v7.length);
			v7.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec4 v8(4,3,2,1)" << endl;
			v8.print();
			cout << "-4 Vec4 전치 벡터 변환: v8.transpose_vector(v8.length)" << endl;
			v8.transpose_vector(v8.length);
			v8.print();
			cout << "=====================================================================================" << endl;
			cout << "뒤로가기(0 입력후 엔터) : ";
			cin >> page;
			cout << "\n";
			break;
		case 3:
			cout << "=====================================================================================" << endl;
			cout << "3. 행렬 계산" << endl;
			cout << "=====================================================================================" << endl;
			cout << "1) Mat3" << endl;
			cout << "=====================================================================================" << endl;
			cout << "Mat3 m3(3,5)" << endl;
			m3.print();
			cout << "Mat3 m5(2)" << endl;
			m5.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-1 Mat3 * Mat3 : m3.multifly_matrix(m3, m5)" << endl;
			m3.multifly_matrix(m3, m5);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 (Mat3 * Mat3)t : m3.multifly_transpose_matrix(m3, m5)" << endl;
			m3.multifly_transpose_matrix(m3, m5);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat3 m3(3,5)" << endl;
			m3.print();
			cout << "Vec3 v2(1,1,1)" << endl;
			v2.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-3 Mat3 * Vec3 : v2.multifly_matrix(m3, v2)" << endl;
			v2.multifly_matrix(m3, v2);
			cout << "(Vec3가 전치되어있지 않으면 예외 처리)\n" << endl;
			cout << "Vec3 v2 전치 벡터 변환: v2.transpose_vector(v2.length)" << endl;
			v2.transpose_vector(v2.length);
			v2.print();
			cout << "Mat3 * Vec3 : v2.multifly_matrix(m3, v2)" << endl;
			v2.multifly_matrix(m3, v2);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-4 (Mat3 * Vec3)t : v2.multifly_transpose_matrix(m3, v2)" << endl;
			v2.multifly_transpose_matrix(m3, v2);
			cout << "Vec3 v2 전치 벡터 변환: v2.transpose_vector(v2.length)" << endl;
			v2.transpose_vector(v2.length);
			v2.print();
			cout << "(Vec3가 전치되어있지 않으면 예외 처리)\n" << endl;
			cout << "Mat3 * Vec3 : v2.multifly_transpose_matrix(m3, v2)" << endl;
			v2.multifly_transpose_matrix(m3, v2);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat3 m3(3,5)" << endl;
			m3.print();
			cout << "-5 Mat3 * double : m3.multifly_const_matrix(m3, 4)" <<endl;
			m3.multifly_const_matrix(m3, 4);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-6 Mat3 / double : m3.division_const_matrix(m3, 4)" << endl;
			m3.division_const_matrix(m3, 4);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat3 m3(3, 5, 2)" << endl;
			m3.print();
			cout << "Mat3 m5(2)" << endl;
			m5.print();
			cout << "-7 Mat3 * double : m3.plus_matrix(m3, m5)" << endl;
			m3.plus_matrix(m3, m5);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-8 Mat3 * double : m3.minus_matrix(m3, m5)" << endl;
			m3.minus_matrix(m3, m5);
			cout << "=====================================================================================" << endl;
			cout << "2) Mat4" << endl;
			cout << "=====================================================================================" << endl;
			cout << "Mat4 m8(3,5,2)" << endl;
			m8.print();
			cout << "Mat4 m7(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)" << endl;
			m7.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-1 Mat4 * Mat4 : m8.multifly_matrix(m8, m7)" << endl;
			m8.multifly_matrix(m8, m7);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 (Mat4 * Mat4)t : m8.multifly_transpose_matrix(m8, m7)" << endl;
			m8.multifly_transpose_matrix(m8, m7);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat4 m8(3,5,2)" << endl;
			m8.print();
			cout << "Vec4 v4(1,1,1,1)" << endl;
			v4.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-3 Mat4 * Vec4 : v4.multifly_matrix(m8, v4)" << endl;
			v4.multifly_matrix(m8, v4);
			cout << "(Vec4가 전치되어있지 않으면 예외 처리)\n" << endl;
			cout << "Vec4 v4 전치 벡터 변환: v4.transpose_vector(v4.length)" << endl;
			v4.transpose_vector(v4.length);
			v4.print();
			cout << "Mat4 * Vec4 : v4.multifly_matrix(m8, v4)" << endl;
			v4.multifly_matrix(m8, v4);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-4 (Mat4 * Vec4)t : v4.multifly_transpose_matrix(m8, v4)" << endl;
			v4.multifly_transpose_matrix(m8, v4);
			cout << "Vec4 v2 전치 벡터 변환: v4.transpose_vector(v4.length)" << endl;
			v4.transpose_vector(v4.length);
			v4.print();
			cout << "(Vec4가 전치되어있지 않으면 예외 처리)\n" << endl;
			cout << "(Mat4 * Vec4)t : v4.multifly_transpose_matrix(m8, v4)" << endl;
			v4.multifly_transpose_matrix(m8, v4);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat4 m8(3,5,2)" << endl;
			m8.print();
			cout << "-5 Mat4 * double : m8.multifly_const_matrix(m8, 4)" << endl;
			m8.multifly_const_matrix(m8, 4);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-6 Mat3 / double : m3.division_const_matrix(m8, 4)" << endl;
			m8.division_const_matrix(m8, 4);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Mat4 m8(3, 5, 2)" << endl;
			m8.print();
			cout << "Mat4 m10(2)" << endl;
			m10.print();
			cout << "-7 Mat4 * double : m3.plus_matrix(m8, m10)" << endl;
			m8.plus_matrix(m8, m10);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-8 Mat4 * double : m3.minus_matrix(m8, m10)" << endl;
			m8.minus_matrix(m8, m10);
			cout << "=====================================================================================" << endl;
			cout << "뒤로가기(0 입력후 엔터) : ";
			cin >> page;
			cout << "\n";
			break;
		case 4:
			cout << "=====================================================================================" << endl;
			cout << "4. 벡터 계산" << endl;
			cout << "=====================================================================================" << endl;
			cout << "1) Vec3" << endl;
			cout << "=====================================================================================" << endl;
			cout << "Vec3 v9(3,5,1)" << endl;
			v9.print();
			cout << "Vec3 v10(9,2,1)" << endl;
			v10.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-1 Vec3 * Vec3 : v9.multifly_vector(v9, v10)" << endl;
			v9.multifly_vector(v9, v10);
			cout << "(Vec3둘중 하나라도 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v9 전치 벡터 변환: v9.transpose_vector(v9.length)" << endl;
			v9.transpose_vector(v9.length);
			v9.print();
			cout << "Vec3 * Vec3 : v9.multifly_vector(v9, v10)" << endl;
			v9.multifly_vector(v9, v10);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 (Vec3 * Vec3)t : v9.multifly_transpose_vector(v9, v10)" << endl;
			v9.multifly_transpose_vector(v9, v10);
			cout << "(Vec3둘중 하나라도 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v9 전치 벡터 변환: v9.transpose_vector(v9.length)" << endl;
			v9.transpose_vector(v9.length);
			v9.print();
			cout << "(Vec3 * Vec3)t : v9.multifly_transpose_vector(v9, v10)" << endl;
			v9.multifly_transpose_vector(v9, v10);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v9(3,5,1)" << endl;
			v9.print();
			cout << "Mat3 m3(3,5)" << endl;
			m3.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-3 Vec3 * Mat3 : v9.multifly_vector(v9, m3)" << endl;
			v9.multifly_vector(v9, m3);
			cout << "(Vec3가 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v9 전치 벡터 변환: v9.transpose_vector(v9.length)" << endl;
			v9.transpose_vector(v9.length);
			v9.print();
			cout << "Vec3 * Mat3 : v9.multifly_vector(v9, m3)" << endl;
			v9.multifly_vector(v9, m3);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-4 (Vec3 * Mat3)t : v9.multifly_transpose_vector(v9, m3)" << endl;
			v9.multifly_transpose_vector(v9, m3);
			cout << "(Vec3가 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v9 전치 벡터 변환: v9.transpose_vector(v9.length)" << endl;
			v9.transpose_vector(v9.length);
			v9.print();
			cout << "(Vec3 * Mat3)t : v9.multifly_transpose_vector(v9, m3)" << endl;
			v9.multifly_transpose_vector(v9, m3);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v9(3,5,1)" << endl;
			v9.print();
			cout << "Vec3 v10(9,2,1)" << endl;
			v10.print();
			cout << "Vec3 v10 전치 벡터 변환: v10.transpose_vector(v10.length)" << endl;
			v10.transpose_vector(v10.length);
			v10.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-5 Vec3 * double : v9.multifly_const_vector(v9, 3)" << endl;
			v9.multifly_const_vector(v9, 3);
			cout << "Vec3가 전치되어 있을경우에는 전치된 상태로 값이 출력\n" << endl;
			cout << "Vec3 * double : v10.multifly_const_vector(v10, 3)" << endl;
			v10.multifly_const_vector(v10, 3);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v9(3,5,1)" << endl;
			v9.print();
			v10.transpose_vector(v10.length);
			cout << "Vec3 v10(9,2,1)" << endl;
			v10.print();
			cout << "Vec3 v10 전치 벡터 변환: v10.transpose_vector(v10.length)" << endl;
			v10.transpose_vector(v10.length);
			v10.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-6 Vec3 / double : v9.division_const_vector(v9, 3)" << endl;
			v9.division_const_vector(v9, 3);
			cout << "Vec3가 전치되어 있을경우에는 전치된 상태로 값이 출력\n" << endl;
			cout << "Vec3 / double : v10.division_const_vector(v10, 3)" << endl;
			v10.division_const_vector(v10, 3);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v9(3,5,1)" << endl;
			v9.print();
			v10.transpose_vector(v10.length);
			cout << "Vec3 v10(9,2,1)" << endl;
			v10.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-7 Vec3 + Vec3 : v9.plus_vector(v9, v10)" << endl;
			v9.plus_vector(v9, v10);
			cout << "(Vec3가 둘중 하나라도 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v10 전치 벡터 변환: v10.transpose_vector(v10.length)" << endl;
			v10.transpose_vector(v10.length);
			v10.print();
			cout << "Vec3 + Vec3 : v9.plus_vector(v9, v10)" << endl;
			v10.plus_vector(v9, v10);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec3 v9(3,5,1)" << endl;
			v9.print();
			v10.transpose_vector(v10.length);
			cout << "Vec3 v10(9,2,1)" << endl;
			v10.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-8 Vec3 + Vec3 : v9.minus_vector(v9, v10)" << endl;
			v9.minus_vector(v9, v10);
			cout << "(Vec3가 둘중 하나라도 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v10 전치 벡터 변환: v10.transpose_vector(v10.length)" << endl;
			v10.transpose_vector(v10.length);
			v10.print();
			cout << "Vec3 + Vec3 : v9.minus_vector(v9, v10)" << endl;
			v10.minus_vector(v9, v10);
			cout << "=====================================================================================" << endl;
			cout << "2) Vec4" << endl;
			cout << "=====================================================================================" << endl;
			cout << "Vec4 v11(8,4,2,1)" << endl;
			v11.print();
			cout << "Mat4 m8(3,5,2)" << endl;
			m8.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-1 Vec4 * Mat4 : v11.multifly_vector(v11, m8)" << endl;
			v11.multifly_vector(v11, m8);
			cout << "(Vec4가 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec4 v11 전치 벡터 변환: v11.transpose_vector(v11.length)" << endl;
			v11.transpose_vector(v11.length);
			v11.print();
			cout << "Vec4 * Mat4 : v11.multifly_vector(v11, m8)" << endl;
			v11.multifly_vector(v11, m8);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-2 (Vec4 * Mat4)t : v11.multifly_transpose_vector(v11, m8)" << endl;
			v11.multifly_transpose_vector(v11, m8);
			cout << "(Vec4가 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec4 v9 전치 벡터 변환: v11.transpose_vector(v11.length)" << endl;
			v11.transpose_vector(v11.length);
			v11.print();
			cout << "(Vec4 * Mat4)t : v11.multifly_transpose_vector(v11, m8)" << endl;
			v11.multifly_transpose_vector(v11, m8);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec4 v11(8,4,2,1)" << endl;
			v11.print();
			cout << "Vec4 v12(9,6,3,1)" << endl;
			v12.print();
			cout << "Vec4 v12 전치 벡터 변환: v12.transpose_vector(v12.length)" << endl;
			v12.transpose_vector(v12.length);
			v12.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-3 Vec4 * double : v11.multifly_const_vector(v11, 2)" << endl;
			v11.multifly_const_vector(v11, 2);
			cout << "Vec4가 전치되어 있을경우에는 전치된 상태로 값이 출력\n" << endl;
			cout << "Vec4 * double : v12.multifly_const_vector(v12, 3)" << endl;
			v12.multifly_const_vector(v12, 3);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec4 v11(8,4,2,1)" << endl;
			v11.print();
			v12.transpose_vector(v12.length);
			cout << "Vec4 v12(9,6,3,1)" << endl;
			v12.print();
			cout << "Vec4 v12 전치 벡터 변환: v12.transpose_vector(v12.length)" << endl;
			v12.transpose_vector(v12.length);
			v12.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-4 Vec4 / double : v11.division_const_vector(v11, 2)" << endl;
			v11.division_const_vector(v11, 2);
			cout << "Vec4가 전치되어 있을경우에는 전치된 상태로 값이 출력\n" << endl;
			cout << "Vec4 / double : v12.division_const_vector(v12, 3)" << endl;
			v12.division_const_vector(v12, 3);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec4 v11(8,4,2,1)" << endl;
			v11.print();
			v12.transpose_vector(v12.length);
			cout << "Vec4 v12(9,6,3,1)" << endl;
			v12.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-5 Vec4 + Vec4 : v11.plus_vector(v11, v12)" << endl;
			v11.plus_vector(v11, v12);
			cout << "(Vec3가 둘중 하나라도 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v10 전치 벡터 변환: v10.transpose_vector(v10.length)" << endl;
			v12.transpose_vector(v12.length);
			v12.print();
			cout << "Vec4 + Vec4 : v11.plus_vector(v11, v12)" << endl;
			v12.plus_vector(v11, v12);
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "Vec4 v11(8,4,2,1)" << endl;
			v11.print();
			v12.transpose_vector(v12.length);
			cout << "Vec4 v12(9,6,3,1)" << endl;
			v12.print();
			cout << "-------------------------------------------------------------------------------------" << endl;
			cout << "-6 Vec4 - Vec4 : v11.minus_vector(v11, v12)" << endl;
			v11.minus_vector(v11, v12);
			cout << "(Vec3가 둘중 하나라도 전치되어있으면 예외 처리)\n" << endl;
			cout << "Vec3 v10 전치 벡터 변환: v10.transpose_vector(v10.length)" << endl;
			v12.transpose_vector(v12.length);
			v12.print();
			cout << "Vec4 - Vec4 : v11.minus_vector(v11, v12)" << endl;
			v12.minus_vector(v11, v12);
			cout << "=====================================================================================" << endl;
			cout << "뒤로가기(0 입력후 엔터) : ";
			cin >> page;
			cout << "\n";
			break;
		case 5:
			mat_vec_cal = false;
			break;
		default :
			cout << "1~5사이의 정수만 입력해주세요\n" << endl;
			cout << "계산 예시" << endl;
			cout << "1. 행렬 생성" << endl;
			cout << "2. 벡터 생성" << endl;
			cout << "3. 행렬 계산" << endl;
			cout << "4. 벡터 계산" << endl;
			cout << "5. 끝내기" << endl;
			cout << "입력(입력후 엔터) : ";
			cin >> page;
			cout << "\n";
			break;
		}
	}
}