#pragma once

#include <wx/wx.h>

#include <fstream>
#include <filesystem>

#include "List.h"
#include "ListElement.h"

class ListManager : public wxPanel
{
public:
	ListManager(wxFrame* parent);
	void render();
	void update();
	
	void loadList(wxString filepath);
	void saveList(wxString filepath);

	wxPanel* getHandle() { return (wxPanel*)this; }
	List* getList() { return m_List; }
private:
	wxFrame* m_MainFrame;
	List* m_List;
	wxBoxSizer* m_Sizer;
};

