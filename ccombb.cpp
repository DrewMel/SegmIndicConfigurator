#include "pch.h"
#include "framework.h"
#include "ComboBox.h"
#include "ComboBoxDlg.h"
#include "afxdialogex.h"

const wchar_t port_letter[] = PORTLETTERS;

void CComboBoxDlg::OnCbnSelchangeList(const char segm_idx)
{
	//const int port_idx = ccb_SelectPort[segm_idx].GetCurSel();


	const int port_idx = cb_segm.get_segm_port(segm_idx);
	ccb_SelectPin[segm_idx].ResetContent(); //clear list
	ccb_SelectPin[segm_idx].InsertString(0, L"(empty)");// first list item (empty)
	ccb_SelectPin[segm_idx].SetCurSel(0);
	//ccb_SelectPin[segm_idx].SetCueBanner(L"(empty)");
	cb_segm.release_segment_buisy_pin(segm_idx);
	if (AVR_PORTS_NUM > port_idx)
	{
		CString cstext;
		for (char i = 0; i < PINS_IN_PORT_NUM; i++)
		{

			if (cb_segm.pin_isnt_sized(port_idx, i) /*|| (cb_segm.get_segm_pin(segm_idx)==i) && (port_idx==cb_segm.get_segm_port(segm_idx))*/)
			{
				cstext.Format(_T("PORT%c%d"), port_letter[port_idx], i);
				ccb_SelectPin[segm_idx].AddString(cstext);

			}
		}
		//cb_segm.set_segment_port(segm_idx, port_idx);
	}
	UpdateData(FALSE);
}

void CComboBoxDlg::OnCbnSelchangePin(const char segm_idx)
{
	cb_segm.set_segment_pin(segm_idx, ccb_SelectPin[segm_idx].GetCurSel());
}

void CComboBoxDlg::resetPinBoxContent(char segm_idx)
{
	int curselport = ccb_SelectPort[segm_idx].GetCurSel();
	if (CB_ERR != curselport)
	{
		cb_segm.set_segment_port(segm_idx, ccb_SelectPort[segm_idx].GetCurSel());
		cb_segm.set_segment_pin(segm_idx, EMPTY_IDX);
		ccb_SelectPin[segm_idx].SetCurSel(0);
		UpdateData(FALSE);
	}

}


void CComboBoxDlg::OnCbnSelchangePin_A()
{
	OnCbnSelchangePin(0);
}

void CComboBoxDlg::OnCbnDropdownPin_A()
{
	OnCbnSelchangeList(0);
}




void CComboBoxDlg::OnCbnSelchangePin_B()
{
	OnCbnSelchangePin(1);
}

void CComboBoxDlg::OnCbnDropdownPin_B()
{
	OnCbnSelchangeList(1);
}




void CComboBoxDlg::OnCbnSelchangePin_C()
{
	OnCbnSelchangePin(2);
}

void CComboBoxDlg::OnCbnDropdownPin_C()
{
	OnCbnSelchangeList(2);
}



void CComboBoxDlg::OnCbnSelchangePin_D()
{
	OnCbnSelchangePin(3);
}

void CComboBoxDlg::OnCbnDropdownPin_D()
{
	OnCbnSelchangeList(3);
}




void CComboBoxDlg::OnCbnSelchangePin_E()
{
	OnCbnSelchangePin(4);
}

void CComboBoxDlg::OnCbnDropdownPin_E()
{
	OnCbnSelchangeList(4);
}




void CComboBoxDlg::OnCbnSelchangePin_F()
{
	OnCbnSelchangePin(5);
}

void CComboBoxDlg::OnCbnDropdownPin_F()
{
	OnCbnSelchangeList(5);
}




void CComboBoxDlg::OnCbnSelchangePin_G()
{
	OnCbnSelchangePin(6);
}

void CComboBoxDlg::OnCbnDropdownPin_G()
{
	OnCbnSelchangeList(6);
}




void CComboBoxDlg::OnCbnSelchangePin_H()
{
	OnCbnSelchangePin(7);
}

void CComboBoxDlg::OnCbnDropdownPin_H()
{
	OnCbnSelchangeList(7);
}




afx_msg void CComboBoxDlg::OnCbnSelchangePort_A()
{
	resetPinBoxContent(0);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_B()
{
	resetPinBoxContent(1);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_C()
{
	resetPinBoxContent(2);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_D()
{
	resetPinBoxContent(3);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_E()
{
	resetPinBoxContent(4);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_F()
{
	resetPinBoxContent(5);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_G()
{
	resetPinBoxContent(6);
}

afx_msg void CComboBoxDlg::OnCbnSelchangePort_H()
{
	resetPinBoxContent(7);
}
