#ifndef _LAYOUT_INIT_H_
#define _LAYOUT_INIT_H_

#include "CLayout.h"

void InitLayoutCad(CLayout& layout, CWnd* parent)
{
	layout.Initial(parent);
	layout.RegisterControl(IDC_STATIC_CAD_CHOOSE, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_BUTTON_CAD_OPEN, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_EDIT_CAD_PATH, CLayout::e_stretch_all);
	
	layout.RegisterControl(IDC_BUTTON_CAD_DRAW, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_STATIC_CAD_DRAW, CLayout::e_stretch_all);
	
	layout.RegisterControl(IDC_STATIC_CAD_PIC, CLayout::e_stretch_all);

	layout.RegisterControl(IDC_STATIC_CAD_LOC, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_LIST_CAD_LOC, CLayout::e_stretch_all);
	
	layout.RegisterControl(IDC_BUTTON_CAD_SEND, CLayout::e_stretch_all);

	layout.RegisterControl(IDC_CAD_BTN_OPMON, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_CAD_BTN_OPVS, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_CAD_BTN_OPDATA, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_CAD_BTN_OPMOD, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_CAD_BTN_OPCAD, CLayout::e_stretch_all);

	layout.RegisterControl(IDC_CAD_STATIC_NAME, CLayout::e_stretch_all);
	layout.RegisterControl(IDC_CAD_PIC_LOGO, CLayout::e_stretch_all);
}

#endif