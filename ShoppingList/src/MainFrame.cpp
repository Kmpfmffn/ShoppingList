#include "MainFrame.h"

#include "Logger.h"


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	log("Initializing MainFrame...");
	SetSize(wxSize(WIN_WIDTH, WIN_HEIGHT));
	m_ListManager = new ListManager(this);
	m_ListManager->loadList("List.mfn");
	m_ListManager->render();
	log("Initialized MainFrame");
}