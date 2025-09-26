#include "ListElement.h"
#include "List.h"

//ListElement::ListElement(wxWindow* parent, wxString title) : wxPanel(parent),
//	m_Parent(parent), m_Title(title), m_Done(0), m_Description("")
//{
//}
//
//ListElement::ListElement(wxWindow* parent, wxString title, wxString description) : wxPanel(parent),
//	m_Parent(parent), m_Title(title), m_Done(0), m_Description(description)
//{
//}

ListElement::ListElement(wxWindow* parent, List* list, wxString title, wxString description, bool done) : wxPanel(parent),
	m_Parent(parent), m_List(list), m_Title(title), m_Done(done), m_Description(description), m_Index(-1)
{
}


void ListElement::onCheckboxClicked(wxCommandEvent& evt)
{
	wxString msg = "Test";
	wxLogStatus(msg);
}

void ListElement::onButtonUpClicked(wxCommandEvent& evt)
{
	if (m_Index > 0) {
		m_List->moveElement(m_Index, m_Index-1);
		m_List->onUpdate(m_Parent);
	}
}

void ListElement::onButtonDownClicked(wxCommandEvent& evt)
{
}



void ListElement::onRender(wxWindow* mainFrame, wxBoxSizer* listSizer) {
	wxPanel* elementPanel = new wxPanel(mainFrame, wxID_ANY);

	// Done box
	wxCheckBox* doneBox = new wxCheckBox(elementPanel, wxID_ANY, "", wxDefaultPosition, wxSize(15, 15), wxALIGN_RIGHT);
	doneBox->SetValue(m_Done);
	doneBox->Bind(wxEVT_CHECKBOX, &ListElement::onCheckboxClicked, this);

	// Title text
	wxStaticText* titleText = new wxStaticText(elementPanel, wxID_ANY, m_Title, wxDefaultPosition, wxSize(100, -1));

	// Delete button
	wxButton* delButton = new wxButton(elementPanel, wxID_ANY, "X", wxDefaultPosition, wxSize(25, 25));

	// Move buttons
	wxPanel* moverPanel = new wxPanel(elementPanel, wxID_ANY);
	wxBoxSizer* moveSizer = new wxBoxSizer(wxVERTICAL);
	wxButton* upButton   = new wxButton(moverPanel, wxID_ANY, "/\\", wxDefaultPosition, wxSize(20, 15));
	wxButton* downButton = new wxButton(moverPanel, wxID_ANY, "\\/", wxDefaultPosition, wxSize(20, 15));
	upButton->Bind(wxEVT_BUTTON, &ListElement::onButtonUpClicked, this);
	downButton->Bind(wxEVT_BUTTON, &ListElement::onButtonDownClicked, this);
	moveSizer->Add(upButton);
	moveSizer->Add(downButton);
	moverPanel->SetSizer(moveSizer);

	// Box sizer
	wxBoxSizer* elementSizer = new wxBoxSizer(wxHORIZONTAL);
	elementSizer->Add(doneBox,    wxSizerFlags(0).Centre().Border(wxALL, 1));
	elementSizer->Add(titleText,  wxSizerFlags(1).Centre().Border(wxALL, 1));
	elementSizer->Add(delButton,  wxSizerFlags(0).Centre().Border(wxALL, 1));
	elementSizer->Add(moverPanel, wxSizerFlags(0).Centre().Border(wxALL, 1));
	elementPanel->SetSizer(elementSizer);

	listSizer->Add(elementPanel, wxSizerFlags().Expand().Border(wxALL, 3));
}