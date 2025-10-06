#include "List.h"
#include "ListManager.h"

#include "Logger.h"


List::List(wxPanel* listManager, wxString title) : wxPanel(listManager, wxID_ANY),
	m_ListManager((ListManager*)listManager), m_Title(title), m_Length(0)
{
}


void List::addElement(unsigned int index, ListElement* element) {
	m_ElementMap[index] = element;
	m_Length++;
	log("Added element '" + (std::string)element->getTitle() + "' to list at index " + std::to_string(index), logLevel::TRACE);
}

void List::moveElement(unsigned int from, unsigned int to) {
	if (m_ElementMap.find(from) == m_ElementMap.end() ||
		m_ElementMap.find(to) == m_ElementMap.end()) {
		// Handle the error: one of the keys is missing
		return;
	}

	//std::swap(m_ElementMap.at(to), m_ElementMap.at(from));
	ListElement* temp     = m_ElementMap.at(to);
	m_ElementMap.at(to)   = m_ElementMap.at(from);
	m_ElementMap.at(from) = temp;
	m_ElementMap.at(to)  ->setIndex(to);
	m_ElementMap.at(from)->setIndex(from);
}

// render the list to the mainFrame
void List::onRender(wxPanel* parent) {
	wxBoxSizer* listSizer = new wxBoxSizer(wxVERTICAL);
	ListElement* element = nullptr;
	for (unsigned int i = 0; i < m_Length; i++) {
		element = m_ElementMap[i];
		element->onRender(m_ListManager->getHandle(), listSizer);
	}
	m_ListManager->getHandle()->SetSizerAndFit(listSizer);
}

void List::onUpdate(wxWindow* mainFrame) {
	m_ListManager->update();
	//onRender(mainFrame);
}