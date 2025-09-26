#include "List.h"

List::List(wxWindow* mainFrame, wxString title) : wxPanel(mainFrame),
	m_MainFrame(mainFrame), m_Title(title)
{
}


void List::addElement(ListElement* element) {
	m_Elements.push_back(element);
}

// switch two positions in m_Elements vector
void List::moveElement(int from, int to) {
	ListElement* temp = m_Elements[to];
	m_Elements[to] = m_Elements[from];
	m_Elements[from] = temp;
	m_Elements[from]->setIndex(from);
	m_Elements[to]->setIndex(to);
}

// render the list to the mainFrame
void List::onRender(wxWindow* mainFrame) {
	wxBoxSizer* listSizer = new wxBoxSizer(wxVERTICAL);
	for (ListElement* element : m_Elements) {
		element->onRender(m_MainFrame, listSizer);
	}
	m_MainFrame->SetSizerAndFit(listSizer);
}

void List::onUpdate(wxWindow* mainFrame) {
	m_MainFrame->Destroy();
	onRender(mainFrame);
}