#pragma once

#include <wx/wx.h>

#include <fstream>
#include <filesystem>

#include "ListControl.h"
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
	ListControl* m_ListControl;
	List* m_List;
	wxBoxSizer* m_Sizer;
};

