#pragma once


// DialogAlgorithm dialog

class DialogAlgorithm : public CDialog
{
	DECLARE_DYNAMIC(DialogAlgorithm)

public:
	DialogAlgorithm(CWnd* pParent = NULL);   // standard constructor
	virtual ~DialogAlgorithm();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int RadioButtonSelector;
	afx_msg void OnBnClickedGraham();
};
