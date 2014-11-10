
// SG3DTestDoc.cpp : implementation of the CSG3DTestDoc class
//

#include "stdafx.h"
#include "SG3DTest.h"

#include "SG3DTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSG3DTestDoc

IMPLEMENT_DYNCREATE(CSG3DTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CSG3DTestDoc, CDocument)
END_MESSAGE_MAP()


// CSG3DTestDoc construction/destruction

CSG3DTestDoc::CSG3DTestDoc()
{
	// TODO: add one-time construction code here

}

CSG3DTestDoc::~CSG3DTestDoc()
{
}

BOOL CSG3DTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSG3DTestDoc serialization

void CSG3DTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CSG3DTestDoc diagnostics

#ifdef _DEBUG
void CSG3DTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSG3DTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSG3DTestDoc commands
