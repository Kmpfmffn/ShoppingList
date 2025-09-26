#pragma once
#include <wx/wx.h>

#include <vector>

#include "ListElement.h"

class List : public wxPanel
{
public:
	List(wxWindow* mainFrame, wxString title);
	
	void addElement(ListElement* element);
	void moveElement(int from, int to);
	wxWindow* getMainFrame() { return m_MainFrame; }

	void onRender(wxWindow* mainFrame);
	void onUpdate(wxWindow* mainFrame);
private:
	wxWindow* m_MainFrame;
	wxWindow* m_ListPanel;
	wxBoxSizer* m_ListSizer;
	wxString m_Title;
	std::vector<ListElement*> m_Elements;
};