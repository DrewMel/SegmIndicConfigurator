
// ComboBoxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ComboBox.h"
#include "ComboBoxDlg.h"
#include "afxdialogex.h"

#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComboBoxDlg dialog



CComboBoxDlg::CComboBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBOBOX_DIALOG, pParent)
{
	for (char i = 0; i < SEGMENT_NUM; i++)
	{
		chck_Segment[i] = FALSE;
	}
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO3, ccb_SelectPort[0]);
	DDX_Control(pDX, IDC_COMBO4, ccb_SelectPin[0]);
	DDX_Control(pDX, IDC_COMBO5, ccb_SelectPort[1]);
	DDX_Control(pDX, IDC_COMBO6, ccb_SelectPin[1]);
	DDX_Control(pDX, IDC_COMBO7, ccb_SelectPort[2]);
	DDX_Control(pDX, IDC_COMBO8, ccb_SelectPin[2]);
	DDX_Control(pDX, IDC_COMBO9, ccb_SelectPort[3]);
	DDX_Control(pDX, IDC_COMBO10, ccb_SelectPin[3]);
	DDX_Control(pDX, IDC_COMBO11, ccb_SelectPort[4]);
	DDX_Control(pDX, IDC_COMBO12, ccb_SelectPin[4]);
	DDX_Control(pDX, IDC_COMBO13, ccb_SelectPort[5]);
	DDX_Control(pDX, IDC_COMBO14, ccb_SelectPin[5]);
	DDX_Control(pDX, IDC_COMBO15, ccb_SelectPort[6]);
	DDX_Control(pDX, IDC_COMBO16, ccb_SelectPin[6]);
	DDX_Control(pDX, IDC_COMBO17, ccb_SelectPort[7]);
	DDX_Control(pDX, IDC_COMBO18, ccb_SelectPin[7]);
	DDX_Control(pDX, IDC_BUTTON1, button_SaveConfigs);
	DDX_Control(pDX, IDC_RADIO1, radiobut_Anode);
	DDX_Control(pDX, IDC_RADIO2, radiobut_Cathode);
	DDX_Control(pDX, IDC_EDIT_SYMBOL, m_edtwchSymbol);


	DDX_Check(pDX, IDC_CHECK_A, chck_Segment[0]);
	DDX_Check(pDX, IDC_CHECK_B, chck_Segment[1]);
	DDX_Check(pDX, IDC_CHECK_C, chck_Segment[2]);
	DDX_Check(pDX, IDC_CHECK_D, chck_Segment[3]);
	DDX_Check(pDX, IDC_CHECK_E, chck_Segment[4]);
	DDX_Check(pDX, IDC_CHECK_F, chck_Segment[5]);
	DDX_Check(pDX, IDC_CHECK_G, chck_Segment[6]);
	DDX_Check(pDX, IDC_CHECK_H, chck_Segment[7]);
	DDX_Control(pDX, IDC_LIST_APHABET, lstbx_Alphabet);

	DDX_Control(pDX, IDC_bu_A, buSegments[0].buSegment);
	DDX_Control(pDX, IDC_bu_B, buSegments[1].buSegment);
	DDX_Control(pDX, IDC_bu_C, buSegments[2].buSegment);
	DDX_Control(pDX, IDC_bu_D, buSegments[3].buSegment);
	DDX_Control(pDX, IDC_bu_E, buSegments[4].buSegment);
	DDX_Control(pDX, IDC_bu_F, buSegments[5].buSegment);
	DDX_Control(pDX, IDC_bu_G, buSegments[6].buSegment);
	DDX_Control(pDX, IDC_bu_H, buSegments[7].buSegment);
}

BEGIN_MESSAGE_MAP(CComboBoxDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_CBN_SELCHANGE(IDC_COMBO3, &CComboBoxDlg::OnCbnSelchangePort_A)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CComboBoxDlg::OnCbnSelchangePort_B)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CComboBoxDlg::OnCbnSelchangePort_C)
	ON_CBN_SELCHANGE(IDC_COMBO9, &CComboBoxDlg::OnCbnSelchangePort_D)
	ON_CBN_SELCHANGE(IDC_COMBO11, &CComboBoxDlg::OnCbnSelchangePort_E)
	ON_CBN_SELCHANGE(IDC_COMBO13, &CComboBoxDlg::OnCbnSelchangePort_F)
	ON_CBN_SELCHANGE(IDC_COMBO15, &CComboBoxDlg::OnCbnSelchangePort_G)
	ON_CBN_SELCHANGE(IDC_COMBO17, &CComboBoxDlg::OnCbnSelchangePort_H)
	

	ON_CBN_SELCHANGE(IDC_COMBO4, &CComboBoxDlg::OnCbnSelchangePin_A)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CComboBoxDlg::OnCbnSelchangePin_B)
	ON_CBN_SELCHANGE(IDC_COMBO8, &CComboBoxDlg::OnCbnSelchangePin_C)
	ON_CBN_SELCHANGE(IDC_COMBO10, &CComboBoxDlg::OnCbnSelchangePin_D)
	ON_CBN_SELCHANGE(IDC_COMBO12, &CComboBoxDlg::OnCbnSelchangePin_E)
	ON_CBN_SELCHANGE(IDC_COMBO14, &CComboBoxDlg::OnCbnSelchangePin_F)
	ON_CBN_SELCHANGE(IDC_COMBO16, &CComboBoxDlg::OnCbnSelchangePin_G)
	ON_CBN_SELCHANGE(IDC_COMBO18, &CComboBoxDlg::OnCbnSelchangePin_H)


	ON_CBN_DROPDOWN(IDC_COMBO4, &CComboBoxDlg::OnCbnDropdownPin_A)
	ON_CBN_DROPDOWN(IDC_COMBO6, &CComboBoxDlg::OnCbnDropdownPin_B)
	ON_CBN_DROPDOWN(IDC_COMBO8, &CComboBoxDlg::OnCbnDropdownPin_C)
	ON_CBN_DROPDOWN(IDC_COMBO10, &CComboBoxDlg::OnCbnDropdownPin_D)
	ON_CBN_DROPDOWN(IDC_COMBO12, &CComboBoxDlg::OnCbnDropdownPin_E)
	ON_CBN_DROPDOWN(IDC_COMBO14, &CComboBoxDlg::OnCbnDropdownPin_F)
	ON_CBN_DROPDOWN(IDC_COMBO16, &CComboBoxDlg::OnCbnDropdownPin_G)
	ON_CBN_DROPDOWN(IDC_COMBO18, &CComboBoxDlg::OnCbnDropdownPin_H)
	ON_BN_CLICKED(IDC_BUTTON1, &CComboBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CComboBoxDlg::OnBnClickedRadioAnode)
	ON_BN_CLICKED(IDC_RADIO2, &CComboBoxDlg::OnBnClickedRadioSelCathod)
	ON_BN_CLICKED(IDC_BUTT_PUSH, &CComboBoxDlg::OnBnClickedButtPushSymbol)
	ON_BN_CLICKED(IDC_BUTT_DELETE, &CComboBoxDlg::OnBnClickedButtDeleteSelectedSymbol)
	ON_LBN_SELCHANGE(IDC_LIST_APHABET, &CComboBoxDlg::OnLbnSelchangeListAphabet)
	ON_COMMAND_RANGE(IDC_bu_A, IDC_bu_H, &CComboBoxDlg::OnBnSegClicked)
END_MESSAGE_MAP()




// CComboBoxDlg message handlers

BOOL CComboBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	/*
	cccbx.Create(
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST,
		CRect(10, 10, 200, 100), this, 1);
		*/
	
	
	radiobut_Anode.SetCheck(TRUE);
	//radiobut_Anode.SetCheck(FALSE);

	for (char i = 0; i < SEGMENT_NUM; i++)
	{
		for (char j = 0; j < AVR_PORTS_NUM; j++)
		{
			CString csText = L"PORT";
			csText += port_letter[j];
			ccb_SelectPort[i].AddString(csText);
		}
		ccb_SelectPort[i].SetCueBanner(L"(empty)");
		ccb_SelectPin[i].SetCueBanner(L"(empty)");
	}

	if (!cb_segm.load_configs())
	{
		for (char i = 0; i < SEGMENT_NUM; i++)
		{
			int segm_port = cb_segm.get_segm_port(i);
			ccb_SelectPort[i].SetCurSel(segm_port);

			int segm_pin = cb_segm.get_segm_pin(i);

			if (segm_pin < PINS_IN_PORT_NUM)
			{
				CString cstext;
				cstext.Format(_T("PORT%c%d"), port_letter[segm_port], segm_pin);
				ccb_SelectPin[i].SetCueBanner(cstext);
			}

		}
	}
	else
	{
		for (char i = 0; i < SEGMENT_NUM; i++)
		{
			cb_segm.set_segment_port(i, AVR_PORTS_NUM);
			cb_segm.set_segment_pin(i, PINS_IN_PORT_NUM);
		}
	}

	for (UINT i = 0; i < SEGMENT_NUM; i++)
	{
		buSegments[i].buSegment.EnableWindowsTheming(FALSE);
		buSegments[i].buSegment.SetFaceColor(RGB(255, 255, 255), true);
		buSegments[i].buSegment.SetTextColor(RGB(0, 0, 0));
		buSegments[i].tggl = FALSE;
	}

	UpdateData(FALSE);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComboBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CComboBoxDlg::OnBnClickedButton1()
{

	cb_segm.save_configs();

	// TODO: Add your control notification handler code here
}


void CComboBoxDlg::OnBnClickedRadioAnode()
{
	cb_segm.set_indicator_type_anode();
	// TODO: Add your control notification handler code here
}


void CComboBoxDlg::OnBnClickedRadioSelCathod()
{
	cb_segm.set_indicator_type_cathode();
	// TODO: Add your control notification handler code here
}

//кнопка <<
void CComboBoxDlg::OnBnClickedButtPushSymbol() 
{
	UpdateData(TRUE);
	char symbol = 0;
	for (char i = 0; i < SEGMENT_NUM; i++)
	{
		if (chck_Segment[i]) symbol |= 1 << i;
	}

	CString symbol_name;
	
	m_edtwchSymbol.GetWindowTextW(symbol_name.GetBuffer(MAX_ALPABET_SYMBOL_LEN), MAX_ALPABET_SYMBOL_LEN);
	//map_alphabet.insert(std::make_pair(symbol_name, symbol));
	symbol_name.ReleaseBuffer();
	if ((symbol_name.GetLength()!=0)&&(LB_ERR == lstbx_Alphabet.FindStringExact(0, symbol_name.GetBuffer(MAX_ALPABET_SYMBOL_LEN))))
	{
		//symbol_name.Format(L"%d - size", symbol_name.GetLength());
		map_alphabet.SetAt(symbol_name, symbol);
		lstbx_Alphabet.AddString(symbol_name);
	}

}



	//кнопка delete
void CComboBoxDlg::OnBnClickedButtDeleteSelectedSymbol()
{
	UpdateData(TRUE);
	int SelString = lstbx_Alphabet.GetCurSel();
	if (LB_ERR  != SelString)
	{
		CString removedstr;
		lstbx_Alphabet.GetText(SelString, removedstr);
		lstbx_Alphabet.DeleteString(SelString);
		map_alphabet.RemoveKey(removedstr);
		m_edtwchSymbol.SetSel(0, TRUE);
		m_edtwchSymbol.Clear();

		for (char i = 0; i < SEGMENT_NUM; i++)
		{
			chck_Segment[i] = FALSE;
		}

		UpdateData(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void CComboBoxDlg::OnLbnSelchangeListAphabet()
{
	UpdateData(TRUE);
	int SelString = lstbx_Alphabet.GetCurSel();
	CString symbol_name;
	lstbx_Alphabet.GetText(SelString, symbol_name);

	if (!symbol_name.IsEmpty())
	{
		char symbol;
		map_alphabet.Lookup(symbol_name, symbol);

		for (char i = 0; i < SEGMENT_NUM; i++)
		{
			chck_Segment[i] = (symbol & (1 << i))? TRUE: FALSE;
		}

		m_edtwchSymbol.SetWindowTextW(symbol_name.GetBuffer(MAX_ALPABET_SYMBOL_LEN));

		UpdateData(FALSE);
	}
	


	// TODO: добавьте свой код обработчика уведомлений
}


afx_msg void CComboBoxDlg::OnBnSegClicked(UINT nID)
{
	assert((nID>=IDC_bu_A)&&(nID<=IDC_bu_H));
	UINT segm = nID - IDC_bu_A;

	if (buSegments[segm].tggl = !buSegments[segm].tggl == TRUE)
	{
		buSegments[segm].buSegment.SetFaceColor(RGB(255, 0, 0), true);
		//buSegments[segm].buSegment.SetTextColor(RGB(255, 255, 255));
	}
	else
	{
		buSegments[segm].buSegment.SetFaceColor(RGB(255, 255, 255), true);
		//buSegments[segm].buSegment.SetTextColor(RGB(255, 255, 255));
	}
	
	UpdateData(FALSE);
}
