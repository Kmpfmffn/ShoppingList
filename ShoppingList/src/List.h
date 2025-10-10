#pragma once
#include <wx/wx.h>

#include <vector>
#include <unordered_map>

#include "ListElement.h"

class ListManager;

class List : public wxPanel
{
public:
	List(wxPanel* listManager, wxString title);
	
	void addElement(unsigned int index, ListElement* element);
	void moveElement(unsigned int from, unsigned int to);
	void delElement(unsigned int index);

	void onButtonAddElementClicked(wxCommandEvent& evt);

	void onRender(wxPanel* mainFrame);
	void onUpdate(wxWindow* mainFrame);

	wxString getTitle() { return m_Title; }
	unsigned int getLength() { return m_Length; }

	ListElement* at(unsigned int index) { return m_ElementMap.at(index); }
private:
	wxString m_Title;
	unsigned int m_Length;
	std::unordered_map<unsigned int, ListElement*> m_ElementMap;
	ListManager* m_ListManager;
};