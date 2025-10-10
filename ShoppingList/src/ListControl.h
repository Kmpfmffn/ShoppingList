#pragma once

#include <wx/wx.h>

class ListControl : public wxPanel
{
public:
	ListControl(wxFrame* parent);
private:
	wxFrame* m_MainFrame;
};