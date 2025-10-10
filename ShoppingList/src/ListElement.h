#pragma once

#include <wx/wx.h>

class List;
class ListManager;

class ListElement : public wxPanel
{
public:
	ListElement(wxWindow* parent, List* list, wxString title, wxString description, bool done);
	ListElement(ListManager* listManager, wxString title, bool done, wxString description, int index);

	wxString getTitle() { return m_Title; }
	void setIndex(unsigned int index) { m_Index = index; }

	void onCheckboxClicked(wxCommandEvent& evt);
	void onButtonDelClicked(wxCommandEvent& evt);
	void onButtonUpClicked(wxCommandEvent& evt);
	void onButtonDownClicked(wxCommandEvent& evt);

	void onRender(wxPanel* listManage, wxBoxSizer* listSizer);

	std::string getSaveString();
private:
	wxString m_Title;
	bool m_Done;
	wxString m_Description;
	unsigned int m_Index;
	ListManager* m_ListManager;

	wxCheckBox* m_DoneBox;
	wxButton* m_DelButton;
	wxButton* m_UpButton;
	wxButton* m_DownButton;
};

/*
ListManager:
	List*
	getHandle(), render(), update()

List:
	Title, Length, ElementMap, ListManager*
	getHandle(), render()

Element:
	Title, Done, Description, Index, ListManager*
	render()
*/