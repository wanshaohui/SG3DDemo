#include "stdafx.h"
#include "SG3DModelAPI.h"

enum SG3DModelType
{
	SG3DModel_Cube,
	SG3DModel_Tube,
	SG3DModel_Sphere,
	SG3DModel_Cone,
	SG3DModel_Segment,
	SG3DModel_Torus,
};

#define TP_QUADRANG_ROW_NUM              2
#define TP_QUADRANG_COLUMN_NUM           2
#define TP_QUADRANG_LAYER_NUM            2

const int g_nQuad_FrontBackVertex_Num    = TP_QUADRANG_LAYER_NUM * TP_QUADRANG_COLUMN_NUM;
const int g_nQuad_RightLeftVertex_Num    = TP_QUADRANG_LAYER_NUM * TP_QUADRANG_ROW_NUM;
const int g_nQuad_BaseTopVertex_Num      = TP_QUADRANG_ROW_NUM   * TP_QUADRANG_COLUMN_NUM;

#define QUAD_MATERIAL_COUNT 6

const SGSubModel g_stuCubeSubs[QUAD_MATERIAL_COUNT] = 
{
	{ 0,                                                                                             g_nQuad_FrontBackVertex_Num, 0,                                                                                                  g_nQuad_FrontBackVertex_Num + 2, SG_TRIANGLE_LIST, ( g_nQuad_FrontBackVertex_Num + 2 ) / 3, 0 },
	{ g_nQuad_FrontBackVertex_Num,                                                                   g_nQuad_RightLeftVertex_Num, g_nQuad_FrontBackVertex_Num + 2,                                                                    g_nQuad_RightLeftVertex_Num + 2, SG_TRIANGLE_LIST, ( g_nQuad_RightLeftVertex_Num + 2 ) / 3, 0 },
	{ g_nQuad_FrontBackVertex_Num + g_nQuad_RightLeftVertex_Num,                                     g_nQuad_FrontBackVertex_Num, g_nQuad_FrontBackVertex_Num + g_nQuad_RightLeftVertex_Num + 4,                                      g_nQuad_FrontBackVertex_Num + 2, SG_TRIANGLE_LIST, ( g_nQuad_FrontBackVertex_Num + 2 ) / 3, 0 },
	{ 2 * g_nQuad_FrontBackVertex_Num + g_nQuad_RightLeftVertex_Num,                                 g_nQuad_RightLeftVertex_Num, 2 * g_nQuad_FrontBackVertex_Num + g_nQuad_RightLeftVertex_Num + 6,                                  g_nQuad_RightLeftVertex_Num + 2, SG_TRIANGLE_LIST, ( g_nQuad_RightLeftVertex_Num + 2 ) / 3, 0 },
	{ 2 * g_nQuad_FrontBackVertex_Num + 2 * g_nQuad_RightLeftVertex_Num,                             g_nQuad_BaseTopVertex_Num,   2 * g_nQuad_FrontBackVertex_Num + 2 * g_nQuad_RightLeftVertex_Num + 8,                              g_nQuad_BaseTopVertex_Num + 2,   SG_TRIANGLE_LIST, ( g_nQuad_BaseTopVertex_Num + 2 ) / 3,   0 },
	{ 2 * g_nQuad_FrontBackVertex_Num + 2 * g_nQuad_RightLeftVertex_Num + g_nQuad_BaseTopVertex_Num, g_nQuad_BaseTopVertex_Num,   2 * g_nQuad_FrontBackVertex_Num + 2 * g_nQuad_RightLeftVertex_Num + g_nQuad_BaseTopVertex_Num + 10, g_nQuad_BaseTopVertex_Num + 2,   SG_TRIANGLE_LIST, ( g_nQuad_BaseTopVertex_Num + 2 ) / 3,   0 },
};

//
#define TP_SEGMENT_ROW_NUM               2
#define TP_SEGMENT_COLUMN_NUM            2

const int g_nSegment_Vertex_Num          = TP_SEGMENT_ROW_NUM * TP_SEGMENT_COLUMN_NUM;//总的顶点个数
const int g_nSegment_Index_Num           = ( TP_SEGMENT_ROW_NUM - 1 ) * ( TP_SEGMENT_COLUMN_NUM - 1 ) * 6;//总的顶点个数

#define SEGMENT_MATERIAL_COUNT			 1
const SGSubModel g_stuSegmentSubs[SEGMENT_MATERIAL_COUNT] = 
{
	{ 0, g_nSegment_Vertex_Num, 0, g_nSegment_Index_Num, SG_TRIANGLE_LIST, g_nSegment_Index_Num / 3, 0 },
};

//
enum TP3D_PLANE_INDEX_TYPE
{
	TP3DPLANE_ROW_FIRST = 0,
	TP3DPLANE_COLUMN_FIRST,
};

//
bool NewVertexIndex(IN OUT SGModel* pModel,SG3DModelType eType,int nLevel = 1)
{
	int nSubPartCount = 0, nVertexCount = 0, nIndexCount = 0;
	const SGSubModel* pSubDes = NULL;
	switch (eType)
	{
	case SG3DModel_Cube:
		nSubPartCount = QUAD_MATERIAL_COUNT;
		pSubDes       = g_stuCubeSubs;
		break;
	case SG3DModel_Segment:
		nSubPartCount = SEGMENT_MATERIAL_COUNT;
		pSubDes       = g_stuSegmentSubs;
		break;
	}

	if (pModel->nviewsub != 0)
	{
		int oldSubCount = pModel->nviewsub;
		int* hMaterial = new int[oldSubCount];
		for (int i = 0; i < oldSubCount;i++)
		{
			hMaterial[i] = pModel->viewsub[i].hMaterial;
		}
		pModel->nviewsub = nSubPartCount;//子部分
		pModel->viewsub  = new SGSubModel[pModel->nviewsub];
		memset( pModel->viewsub, 0, pModel->nviewsub * sizeof(SGSubModel) );
		for (int i = 0; i < pModel->nviewsub;i++)
		{
			memcpy( &pModel->viewsub[i], &pSubDes[i], sizeof(SGSubModel) );
			pModel->viewsub[i].hMaterial = hMaterial[i % oldSubCount] ;

			nVertexCount += pModel->viewsub[i].vCount;
			nIndexCount  += pModel->viewsub[i].iCount;
		}
		delete [] hMaterial;
		hMaterial = NULL;
	}
	else
	{
		pModel->nviewsub = nSubPartCount;//子部分
		pModel->viewsub  = new SGSubModel[pModel->nviewsub];
		memset( pModel->viewsub, 0, pModel->nviewsub * sizeof(SGSubModel) );
		for ( int i = 0; i < nSubPartCount; i++ )
		{
			memcpy( &pModel->viewsub[i], &pSubDes[i], sizeof(SGSubModel) );
			nVertexCount += pModel->viewsub[i].vCount;
			nIndexCount  += pModel->viewsub[i].iCount;
		}
	}

	pModel->vcount = nVertexCount;
	pModel->v      = new SGVertex3D[pModel->vcount];
	memset( pModel->v, 0, pModel->vcount * sizeof(SGVertex3D) );
	pModel->icount = nIndexCount;//总的索引数
	pModel->indecs = new DWORD[pModel->icount];
	memset( pModel->indecs, 0, pModel->icount * sizeof(DWORD) );

	return true;
}

//
void SetPlaneIndexAndUV( IN OUT SGModel* pMod, IN int nIndexSt, IN int nVertexSt, IN int nRowNum, IN int nColumnNum, IN int nType )
{
	int nTriIndex = 0;
	//01
	//23
	if ( nType == TP3DPLANE_ROW_FIRST )
	{
		for ( int i = 1; i < nRowNum; i++ )
		{
			for ( int j = 1; j < nColumnNum; j++ )
			{
				nTriIndex = ( i - 1 ) * ( nColumnNum - 1 ) + ( j - 1 );

				pMod->indecs[ nIndexSt + 6 * nTriIndex + 0 ] = ( i - 1 ) * nColumnNum + ( j - 1 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 1 ] = ( i - 0 ) * nColumnNum + ( j - 1 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 2 ] = ( i - 1 ) * nColumnNum + ( j - 0 ) + nVertexSt;

				pMod->indecs[ nIndexSt + 6 * nTriIndex + 3 ] = ( i - 1 ) * nColumnNum + ( j - 0 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 4 ] = ( i - 0 ) * nColumnNum + ( j - 1 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 5 ] = ( i - 0 ) * nColumnNum + ( j - 0 ) + nVertexSt;
			}
		}

		for ( int i = 0; i < nRowNum; i++ )
		{
			for ( int j = 0; j < nColumnNum; j++ )
			{
				pMod->v[ nVertexSt + i * nColumnNum + j ].tu  = (float)j / ( nColumnNum - 1 );
				pMod->v[ nVertexSt + i * nColumnNum + j ].tv  = (float)i / ( nRowNum - 1 );
			}
		}
	}
	//02
	//13
	else if ( nType == TP3DPLANE_COLUMN_FIRST )
	{
		for ( int j = 1; j < nColumnNum; j++ )
		{
			for ( int i = 1; i < nRowNum; i++ )
			{
				nTriIndex = ( j - 1 ) * ( nRowNum - 1 ) + ( i - 1 );

				pMod->indecs[ nIndexSt + 6 * nTriIndex + 0 ] = ( j - 1 ) * nRowNum + ( i - 1 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 1 ] = ( j - 0 ) * nRowNum + ( i - 1 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 2 ] = ( j - 1 ) * nRowNum + ( i - 0 ) + nVertexSt;

				pMod->indecs[ nIndexSt + 6 * nTriIndex + 3 ] = ( j - 1 ) * nRowNum + ( i - 0 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 4 ] = ( j - 0 ) * nRowNum + ( i - 1 ) + nVertexSt;
				pMod->indecs[ nIndexSt + 6 * nTriIndex + 5 ] = ( j - 0 ) * nRowNum + ( i - 0 ) + nVertexSt;
			}
		}

		for ( int j = 0; j < nColumnNum; j++ )
		{
			for ( int i = 0; i < nRowNum; i++ )
			{
				pMod->v[ nVertexSt + j * nRowNum + i ].tu  = (float)j / ( nColumnNum - 1 );
				pMod->v[ nVertexSt + j * nRowNum + i ].tv  = (float)i / ( nRowNum - 1 );
			}
		}
	}
};

//
BOOL  SG3D_CreateCube( IN OUT SGModel* pMod,
					  IN float fBase_Width/* = 0.f*/,
					  IN float fBase_Height/* = 0.f*/,
					  IN float fHeight/* = 0.f*/,
					  IN float fTop_Width/* = 0.f*/,
					  IN float fTop_Height/* = 0.f*/ )
{
	return TRUE;
}

//
BOOL SG3D_CreateSegment(IN OUT SGModel* pMod)
{
	if ( pMod->indecs == NULL )
	{
		NewVertexIndex( pMod, SG3DModel_Segment );
		SetPlaneIndexAndUV( pMod, g_stuSegmentSubs[0].iStart, g_stuSegmentSubs[0].vStart, TP_SEGMENT_ROW_NUM, TP_SEGMENT_COLUMN_NUM, 
			TP3DPLANE_ROW_FIRST );
	}
	return TRUE;
}