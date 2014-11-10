#include "stdafx.h"
#include "SGXVector3.h"


SGXVecor3::SGXVecor3(const float* pf)
{
	if(!pf)
		return ;
	x = pf[0];
	y = pf[0];
	z = pf[0];
}

//
SGXVecor3::SGXVecor3(SGVector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

//
SGXVecor3::SGXVecor3(float _x,float _y,float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

//
SGXVecor3::operator float*()
{
	return (float*)(&x);
}

//
SGXVecor3& SGXVecor3::operator += (SGXVecor3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

//
SGXVecor3& SGXVecor3::operator -= (SGXVecor3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

//
SGXVecor3& SGXVecor3::operator *= (float f)
{
	x *= f;
	y *= f;
	z *= f;

	return *this;
}

//
SGXVecor3& SGXVecor3::operator /= (float f)
{
	float fInv = 1.f / f;
	x *= fInv;
	y *= fInv;
	z *= fInv;

	return *this;
}

//
SGXVecor3 SGXVecor3::operator +()
{
	return *this;
}

//
SGXVecor3 SGXVecor3::operator - ()
{
	return SGXVecor3(-x,-y,-z);
}

//
SGXVecor3& SGXVecor3::operator + (SGXVecor3& v)
{
	return SGXVecor3(x + v.x,y + v.y,z + v.z);
}

//
SGXVecor3& SGXVecor3::operator - (SGXVecor3& v)
{
	return SGXVecor3(x = v.x,y - v.y,z - v.z);
}

//
SGXVecor3& SGXVecor3::operator * (float f)
{
	return SGXVecor3(x * f,y * f,z * f);
}

//
SGXVecor3& SGXVecor3::operator / (float f)
{
	float fInv = 1.f/ f;
	return SGXVecor3(x * fInv,y * fInv,z * fInv);
}

//
BOOL SGXVecor3::operator == (const SGXVecor3& v)
{
	return x == v.x && y == v.y && z == v.z;
}

//
BOOL SGXVecor3::operator != (const SGXVecor3& v)
{
	return x != v.x || y != v.y || z != v.z;
}

