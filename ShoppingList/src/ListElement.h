#pragma once

#include <wx/wx.h>

class List;

class ListElement : public wxPanel
{
public:
	//ListElement(wxWindow* parent, wxString title);
	//ListElement(wxWindow* parent, wxString title, wxString description);
	ListElement(wxWindow* parent, List* list, wxString title, wxString description, bool done);

	wxString getTitle() { return m_Title; }
	void setIndex(int index) { m_Index = index; }
	void setList(List* list) { m_List = list; }

	void onCheckboxClicked(wxCommandEvent& evt);
	void onButtonUpClicked(wxCommandEvent& evt);
	void onButtonDownClicked(wxCommandEvent& evt);

	void onRender(wxWindow* parent, wxBoxSizer* listSizer);
private:
	wxWindow* m_Parent;
	wxString m_Title;
	bool m_Done;
	wxString m_Description;
	int m_Index;
	List* m_List;
};

