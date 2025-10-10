#pragma once

#include <wx/wx.h>

#include "ListControl.h"
#include "ListManager.h"
#include "List.h"
#include "ListElement.h"

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	List* getList() { return m_List; }
private:
	ListControl* m_ListControl;
	ListManager* m_ListManager;
	List* m_List;
};