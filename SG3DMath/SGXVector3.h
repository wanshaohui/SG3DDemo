#pragma once

//
//
//



struct SGXVecor3 : public SGVector3
{
public:
	SGXVecor3();
	SGXVecor3(const float*);
	SGXVecor3(SGVector3&);
	SGXVecor3(float _x,float _y,float _z);

	operator float*();

	SGXVecor3& operator += (SGXVecor3&);
	SGXVecor3& operator -= (SGXVecor3&);
	SGXVecor3& operator *= (float);
	SGXVecor3& operator /= (float);

	SGXVecor3 operator + ();
	SGXVecor3 operator - ();

	SGXVecor3& operator + (SGXVecor3&);
	SGXVecor3& operator - (SGXVecor3&);
	SGXVecor3& operator * (float);
	SGXVecor3& operator / (float);

	BOOL operator == (const SGXVecor3&);
	BOOL operator != (const SGXVecor3&);

};