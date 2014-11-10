#pragma once

//
//
//

// 定点
typedef struct tag_sgvertex3d
{
	union 
	{
		struct { float x,y,z,w;};
		SGVector4   vDyn;
	};

	union 
	{
		struct {float nx,ny,nz,nw;};
		SGVector4 vNormal;
	};

	float tu,tv;
	union 
	{
		struct {float vox,voy,voz;};
		SGVector3 vOrgin;
	};
}SGVertex3D,*LPSGVertex3D;

//
typedef struct tag_sgcolorvertex3D
{
	SGVector4 vDyn;
	DWORD     dwColor;
}SGColorVertex3D,*LPSGColorVertex3D;

//
enum SG_TRIANGLE_TYPE
{
	SG_TRIANGLE_LIST,
	SG_TRIANGLE_FAN,
	SG_TRIANGLE_TRIP
};


// 面
typedef struct tag_sgsubmodel
{
	DWORD vStart;
	DWORD vCount;
	DWORD iStart;
	DWORD iCount;
	int   nTri_Type;
	int   nTriNum;
	int   hMaterial;
}SGSubModel,*LPSGSubModel;

// Mesh结构
typedef struct tag_sgmodel
{
	int				vcount;				// vertex
	LPSGVertex3D	v;

	int		 	    nSeqCount;			// global sequences
	int*		    pnSeq;

	DWORD*		    pdwBoneIndex;		// bone indexes for each vertexes, the array size is "vcount"
	DWORD*		    pdwBoneWeight;		// weight indexes for each vertexes, the array size is "vcount"

	int			    icount;				// triangle surfaces indexes
	DWORD*		    indecs;

	//CArray		    bonearray;			//骨骼信息

	int			    nBoneGroupCount;	// bone group definition
	DWORD*		    pdwBoneGroup;		// 4 bytes of one cell, each byte indicates a bone index

	int			    nBoneIndexCount;	// bone indexes definition
	WORD*		    pwBoneIndex;

	int				nviewsub;
	LPSGSubModel	viewsub;

	SGMatrix*		pboneoffVMatrix;
	SGMatrix*		pboneoffNMatrix;

} SGModel, *LPSGMODEL;