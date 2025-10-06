#include "ListElement.h"
#include "List.h"
#include "ListManager.h"

#include "Logger.h"

ListElement::ListElement(ListManager* listManager, wxString title, bool done, wxString description, int index) : wxPanel(listManager),
	m_ListManager(listManager), m_Title(title), m_Done(done), m_Description(description), m_Index(index)
{
}


void ListElement::onCheckboxClicked(wxCommandEvent& evt){
	bool done = m_DoneBox->GetValue();
	m_Done = done;
	log("Checkbox checked [Index:" + std::to_string(m_Index) + " Title:" + (std::string)m_Title + "]");
}

void ListElement::onButtonDelClicked(wxCommandEvent& evt) {
	log("Button del clicked [Index:" + std::to_string(m_Index) + " Title:" + (std::string)m_Title + "]");
}

void ListElement::onButtonUpClicked(wxCommandEvent& evt){
	log("Button up clicked [Index:" + std::to_string(m_Index) + " Title:" + (std::string)m_Title + "]");
	if (m_Index > 0) {
		m_ListManager->getList()->moveElement(m_Index, m_Index - 1);
		m_ListManager->update();
	}
}

void ListElement::onButtonDownClicked(wxCommandEvent& evt){
	log("Button down clicked [Index:" + std::to_string(m_Index) + " Title:" + (std::string)m_Title + "]");
	if (m_Index < m_ListManager->getList()->getLength()) {
		m_ListManager->getList()->moveElement(m_Index, m_Index + 1);
		m_ListManager->update();
	}
}



void ListElement::onRender(wxWindow* mainFrame, wxBoxSizer* listSizer) {
	wxPanel* elementPanel = new wxPanel(mainFrame, wxID_ANY);

	// Done box
	m_DoneBox = new wxCheckBox(elementPanel, wxID_ANY, "", wxDefaultPosition, wxSize(15, 15), wxALIGN_RIGHT);
	m_DoneBox->SetValue(m_Done);
	m_DoneBox->Bind(wxEVT_CHECKBOX, &ListElement::onCheckboxClicked, this);

	// Title text
	wxStaticText* titleText = new wxStaticText(elementPanel, wxID_ANY, m_Title, wxDefaultPosition, wxSize(100, -1));

	// Delete button
	m_DelButton = new wxButton(elementPanel, wxID_ANY, "X", wxDefaultPosition, wxSize(25, 25));
	m_DelButton->Bind(wxEVT_BUTTON, &ListElement::onButtonDelClicked, this);

	// Move buttons
	wxPanel* moverPanel = new wxPanel(elementPanel, wxID_ANY);
	wxBoxSizer* moveSizer = new wxBoxSizer(wxVERTICAL);
	m_UpButton   = new wxButton(moverPanel, wxID_ANY, "/\\", wxDefaultPosition, wxSize(20, 15));
	m_DownButton = new wxButton(moverPanel, wxID_ANY, "\\/", wxDefaultPosition, wxSize(20, 15));
	m_UpButton->Bind(wxEVT_BUTTON, &ListElement::onButtonUpClicked, this);
	m_DownButton->Bind(wxEVT_BUTTON, &ListElement::onButtonDownClicked, this);
	moveSizer->Add(m_UpButton);
	moveSizer->Add(m_DownButton);
	moverPanel->SetSizer(moveSizer);

	// Box sizer
	wxBoxSizer* elementSizer = new wxBoxSizer(wxHORIZONTAL);
	elementSizer->Add(m_DoneBox,    wxSizerFlags(0).Centre().Border(wxALL, 1));
	elementSizer->Add(titleText,  wxSizerFlags(1).Centre().Border(wxALL, 1));
	elementSizer->Add(m_DelButton,  wxSizerFlags(0).Centre().Border(wxALL, 1));
	elementSizer->Add(moverPanel, wxSizerFlags(0).Centre().Border(wxALL, 1));
	elementPanel->SetSizer(elementSizer);

	listSizer->Add(elementPanel, wxSizerFlags().Expand().Border(wxALL, 3));
}

// Test_Element_Nr._0 0 This_is_a_test_element.
std::string ListElement::getSaveString() {
	std::stringstream saveString;
	std::string title = m_Title.ToStdString();
	std::string desc = m_Description.ToStdString();
	std::string done = std::to_string(m_Done);

	std::replace(title.begin(), title.end(), ' ', '_');
	std::replace(desc.begin(),  desc.end(), ' ', '_');

	saveString << title << " " << m_Done << " " << desc;
	return saveString.str();
}