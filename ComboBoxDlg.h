
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
	void _OnCbnSelchangeList(const char idx);
	void _OnCbnSelchangePin(const char idx);
	void _resetPinBoxContent(const char idx);

public:

	CComboBox ccb_SelectPort[SEGMENT_NUM];
	CComboBox ccb_SelectPin[PINS_IN_PORT_NUM];

	typedef void (CComboBoxDlg::*calldlgitembyindex) (const char idx);

	template  <UINT botttomID, UINT topID, calldlgitembyindex callback>
	afx_msg void multyIDhndr (UINT nID)
	{
		assert((nID >= botttomID) && (nID <= topID));
		UINT idx = nID - botttomID;
		(this->*callback)(idx);

		UpdateData(FALSE);
	}

	CButton button_SaveConfigs;
	
	// select alternative - indicator has common Anod
	CButton radiobut_Anode;
	afx_msg void OnBnClickedRadioAnode();
	afx_msg void OnBnClickedRadioSelCathod();
	CButton radiobut_Cathode;


	afx_msg void OnBnClickedButtPushSymbol();
	afx_msg void OnBnClickedButtDeleteSelectedSymbol();

	CEdit m_edtwchSymbol;
	
	CListBox lstbx_Alphabet;
	afx_msg void OnLbnSelchangeListAphabet();
	afx_msg void OnBnSegClicked(UINT nID);

	struct _buSegment{
		CMFCButton buSegment;
		bool tggl;
		void ToggleSegment(void)
		{
			if (tggl = (!tggl) == TRUE)
			{
				buSegment.SetFaceColor(RGB(255, 0, 0), true);
			}
			else
			{
				buSegment.SetFaceColor(RGB(255, 255, 255), true);
			}
		}
	}buSegments[SEGMENT_NUM];
	afx_msg void OnBnClickedButMakeHeader();
};
