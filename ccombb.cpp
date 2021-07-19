#include "pch.h"
#include "framework.h"
#include "ComboBox.h"
#include "ComboBoxDlg.h"
#include "afxdialogex.h"

const wchar_t port_letter[] = PORTLETTERS;

void CComboBoxDlg::_OnCbnSelchangeList(const char segm_idx)
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

void CComboBoxDlg::_OnCbnSelchangePin(const char segm_idx)
{
	cb_segm.set_segment_pin(segm_idx, ccb_SelectPin[segm_idx].GetCurSel());
}

void CComboBoxDlg::_resetPinBoxContent(char segm_idx)
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

