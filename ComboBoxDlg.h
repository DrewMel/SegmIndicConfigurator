
#include "ConfiguratorAppTypes.h"
#include "cboxmgr.h"
// ComboBoxDlg.h : header file
//

#pragma once


// CComboBoxDlg dialog
class CComboBoxDlg : public CDialogEx
{
private:
	
	cboxmgr cb_segm;

	//symbol_1 alphabet[64];

	CMap <CString, LPCTSTR, char, char> map_alphabet;

// Construction
public:
	CComboBoxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBOBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void OnCbnSelchangeList(const char idx);
	void OnCbnSelchangePin(const char idx);
	void resetPinBoxContent(const char idx);

public:

	CComboBox ccb_SelectPort[SEGMENT_NUM];
	CComboBox ccb_SelectPin[PINS_IN_PORT_NUM];

	afx_msg void OnCbnSelchangePin_A();
	afx_msg void OnCbnSelchangePin_B();
	afx_msg void OnCbnSelchangePin_C();
	afx_msg void OnCbnSelchangePin_D();
	afx_msg void OnCbnSelchangePin_E();
	afx_msg void OnCbnSelchangePin_F();
	afx_msg void OnCbnSelchangePin_G();
	afx_msg void OnCbnSelchangePin_H();

	afx_msg void OnCbnDropdownPin_A();
	afx_msg void OnCbnDropdownPin_B();
	afx_msg void OnCbnDropdownPin_C();
	afx_msg void OnCbnDropdownPin_D();
	afx_msg void OnCbnDropdownPin_E();
	afx_msg void OnCbnDropdownPin_F();
	afx_msg void OnCbnDropdownPin_G();
	afx_msg void OnCbnDropdownPin_H();

	afx_msg void OnCbnSelchangePort_A();
	afx_msg void OnCbnSelchangePort_B();
	afx_msg void OnCbnSelchangePort_C();
	afx_msg void OnCbnSelchangePort_D();
	afx_msg void OnCbnSelchangePort_E();
	afx_msg void OnCbnSelchangePort_F();
	afx_msg void OnCbnSelchangePort_G();
	afx_msg void OnCbnSelchangePort_H();


	CButton button_SaveConfigs;
	afx_msg void OnBnClickedButton1();
	// select alternative - indicator has common Anod
	CButton radiobut_Anode;
	afx_msg void OnBnClickedRadioAnode();
	afx_msg void OnBnClickedRadioSelCathod();
	CButton radiobut_Cathode;


	afx_msg void OnBnClickedButtPushSymbol();
	afx_msg void OnBnClickedButtDeleteSelectedSymbol();

	BOOL chck_Segment[SEGMENT_NUM];
	CEdit m_edtwchSymbol;
	
	CListBox lstbx_Alphabet;
	afx_msg void OnLbnSelchangeListAphabet();
	afx_msg void OnBnClickedbuA();
	CMFCButton buSegments[SEGMENT_NUM];
};
