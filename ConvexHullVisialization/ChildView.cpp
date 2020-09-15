
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "ConvexHullVisialization.h"
#include "ChildView.h"
#include "ConvexHullModelFabric.h"
#include "ConvexHullRendrer.h"
#include "DialogAlgorithm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	cur_alg_type = GRAHAM;
	p_model = ConvexHullModelFabric::CreateModel(cur_alg_type);
	p_model->SetObserver(this);
	renderer.SetObserver(this);
}

CChildView::~CChildView()
{
	delete p_model;
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_OPTIONS_BACKGROUNDCOLOR, &CChildView::OnOptionsBackgroundcolor)
	ON_COMMAND(ID_OPTIONS_POINTSCOLOR, &CChildView::OnOptionsPointscolor)
	ON_COMMAND(ID_OPTIONS_CONVEXHULLCOLOR, &CChildView::OnOptionsConvexhullcolor)
	ON_COMMAND(ID_OPTIONS_CLEARALL, &CChildView::OnOptionsClearall)
	ON_COMMAND(ID_OPTIONS_CHOOSEALGORITHM, &CChildView::OnOptionsChoosealgorithm)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	int ret = CWnd::OnCreate(lpCreateStruct);
	mem_scn.CreateCompatibleDC(*GetDC());
	return ret;
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	mem_scn.SetDirty(true);
	CWnd::OnSize(nType, cx, cy);

}

void CChildView::ImmediateViewUpdate()
{
	CRect cli_rect;
	GetClientRect(&cli_rect);
	InvalidateRect(&cli_rect);
	UpdateWindow();
}

void CChildView::OnModelChanged(const ConvexHullModelBase* p_model)
{
	mem_scn.SetDirty(true);
	UpdateWindowTitle();
	ImmediateViewUpdate();

}

void CChildView::OnRenderStyleChanged(const ConvexHullRenderer* p_renderer)
{
	mem_scn.SetDirty(true);
	ImmediateViewUpdate();
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	p_model->AddPoint(Point2D(point.x, point.y));
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect cli_rect;
	GetClientRect(&cli_rect);
	if (mem_scn.IsDirty())
	{
		mem_scn.PrepareBitmap(cli_rect, dc);
		renderer.Draw(mem_scn.GetMemoryDC(), cli_rect, *p_model);
		mem_scn.SetDirty(false);
	}
	mem_scn.DrawScene(dc, dc.m_ps.rcPaint);
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnOptionsBackgroundcolor()
{
	// TODO: Add your command handler code here
	CColorDialog dlg(renderer.GetBackgroundColor(), CC_ANYCOLOR | CC_FULLOPEN | CC_RGBINIT, this);
	INT_PTR res = dlg.DoModal();
	switch (res) // Как было закрыто окно диалога
	{
	case IDOK:
	{// Кнопкой OK
		COLORREF new_color = dlg.GetColor();
		if (new_color != renderer.GetBackgroundColor())
			renderer.SetBackgroundColor(new_color);
	}
	break;
	case IDCANCEL: // Кнопкой Cancel
		//AfxMessageBox(L"CANCEL");
		break;
	}
}


void CChildView::OnOptionsPointscolor()
{
	// TODO: Add your command handler code here
	CColorDialog dlg(renderer.GetPointsColor(), CC_ANYCOLOR | CC_FULLOPEN | CC_RGBINIT, this);
	INT_PTR res = dlg.DoModal();
	switch (res) // Как было закрыто окно диалога
	{
	case IDOK:
	{// Кнопкой OK
		COLORREF new_color = dlg.GetColor();
		if (new_color != renderer.GetPointsColor())
			renderer.SetPointsColor(new_color);
	}
	break;
	case IDCANCEL: // Кнопкой Cancel
		//AfxMessageBox(L"CANCEL");
		break;
	}
}


void CChildView::OnOptionsConvexhullcolor()
{
	// TODO: Add your command handler code here
	CColorDialog dlg(renderer.GetConvexHullColor(), CC_ANYCOLOR | CC_FULLOPEN | CC_RGBINIT, this);
	INT_PTR res = dlg.DoModal();
	switch (res) // Как было закрыто окно диалога
	{
	case IDOK:
	{// Кнопкой OK
		COLORREF new_color = dlg.GetColor();
		if (new_color != renderer.GetConvexHullColor())
			renderer.SetConvexHullColor(new_color);
	}
	break;
	case IDCANCEL: // Кнопкой Cancel
		//AfxMessageBox(L"CANCEL");
		break;
	}
}


void CChildView::OnOptionsClearall()
{
	// TODO: Add your command handler code here
	p_model->ClearAll();
}


void CChildView::OnOptionsChoosealgorithm()
{
	DialogAlgorithm dlgAlg;
	INT_PTR nRet;
	dlgAlg.RadioButtonSelector = int(cur_alg_type);
	nRet = dlgAlg.DoModal(); // Создание окна диалога
	switch (nRet) // Как было закрыто окно диалога
	{
	case IDOK: // Кнопкой OK
		if (dlgAlg.RadioButtonSelector == int(cur_alg_type))
			return;
		p_model->ClearAll();
		delete p_model;
		p_model = NULL;
		cur_alg_type = ConvexHullAlg(dlgAlg.RadioButtonSelector);
		p_model = ConvexHullModelFabric::CreateModel(cur_alg_type);
		p_model->SetObserver(this);
		UpdateWindowTitle();
		break;
	case IDCANCEL: // Кнопкой Cancel
		//AfxMessageBox(L"CANCEL");
		break;
		//AfxMessageBox(L"Cancel");
	}
}

/*
bool CChildView::IsAlgorithmChanged()
{
	if (p_model = ConvexHullModelFabric::CreateModel(GRAHAM))
		return true;
}
*/
static const char* alg_names[LAST_VALUE] = { "Graham algorithm", "Jarvis algorithm", "Quick algorithm" };
void CChildView::UpdateWindowTitle()
{
	char buff[256];
	sprintf(buff, "%s", alg_names[cur_alg_type]);
	wchar_t w_buff[256];

	MultiByteToWideChar(
		CP_ACP,
		MB_PRECOMPOSED,
		buff,
		256,
		w_buff,
		256
		);

	GetParentFrame()->SetWindowTextW(w_buff);

}