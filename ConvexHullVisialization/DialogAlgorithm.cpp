// DialogAlgorithm.cpp : implementation file
//

#include "stdafx.h"
#include "ConvexHullVisialization.h"
#include "DialogAlgorithm.h"
#include "afxdialogex.h"


// DialogAlgorithm dialog

IMPLEMENT_DYNAMIC(DialogAlgorithm, CDialog)

DialogAlgorithm::DialogAlgorithm(CWnd* pParent /*=NULL*/)
	: CDialog(DialogAlgorithm::IDD, pParent)
	, RadioButtonSelector(0)
{

}

DialogAlgorithm::~DialogAlgorithm()
{
}

void DialogAlgorithm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_GRAHAM, RadioButtonSelector);
}


BEGIN_MESSAGE_MAP(DialogAlgorithm, CDialog)
	ON_BN_CLICKED(IDC_GRAHAM, &DialogAlgorithm::OnBnClickedGraham)
END_MESSAGE_MAP()


// DialogAlgorithm message handlers




void DialogAlgorithm::OnBnClickedGraham()
{
	// TODO: Add your control notification handler code here
}
