
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "ConvexHullModelBase.h"
#include "ConvexHullModelFabric.h"
#include "ConvexHullRendrer.h"
#include "SceneInMemory.h"



// CChildView window

class CChildView : public CWnd, public IViewObserver, public IRenderStyleObserver
{
// Construction
public:
	CChildView();
	virtual ~CChildView();
	virtual void OnModelChanged(const ConvexHullModelBase* p_model);
	virtual void OnRenderStyleChanged(const ConvexHullRenderer* p_renderer);


// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT, int, int);
	afx_msg void OnLButtonDblClk( UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	ConvexHullModelBase* p_model;
	ConvexHullRenderer renderer;
	SceneInMemory mem_scn;
	void ImmediateViewUpdate();
	void UpdateWindowTitle();
	ConvexHullAlg cur_alg_type;
public:
	afx_msg void OnOptionsBackgroundcolor();
	afx_msg void OnOptionsPointscolor();
	afx_msg void OnOptionsConvexhullcolor();
	afx_msg void OnOptionsClearall();
	afx_msg void OnOptionsChoosealgorithm();
};

