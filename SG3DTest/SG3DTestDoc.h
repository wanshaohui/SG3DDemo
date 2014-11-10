
// SG3DTestDoc.h : interface of the CSG3DTestDoc class
//


#pragma once


class CSG3DTestDoc : public CDocument
{
protected: // create from serialization only
	CSG3DTestDoc();
	DECLARE_DYNCREATE(CSG3DTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSG3DTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


