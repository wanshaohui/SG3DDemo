#pragma once


// 三维向量
struct SGVector3
{
	float x;
	float y;
	float z;
};

// 四维向量
struct SGVector4
{
	float x;
	float y;
	float z;
	float w;
};

//
struct SGMatrix
{
	union 
	{
		struct 
		{
			float _11,_12,_13,_14;
			float _21,_22,_23,_24;
			float _31,_32,_33,_34;
			float _41,_42,_43,_44;
		};

	};
	float m[4][4];
};