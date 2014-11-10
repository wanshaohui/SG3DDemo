#pragma once
//
//
//

// 立方体
AFX_EXT_API BOOL  SG3D_CreateCube( IN OUT SGModel* pMod,
								   IN float fBase_Width = 0.f,
								   IN float fBase_Height = 0.f,
								   IN float fHeight = 0.f,
								   IN float fTop_Width = 0.f,
								   IN float fTop_Height = 0.f );

// 面片
AFX_EXT_API BOOL SG3D_CreateSegment(IN OUT SGModel* pMod);