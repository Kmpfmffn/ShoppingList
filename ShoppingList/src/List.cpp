#include "List.h"
#include "ListManager.h"

#include "Logger.h"


List::List(wxPanel* listManager, wxString title) : wxPanel(listManager, wxID_ANY),
	m_ListManager((ListManager*)listManager), m_Title(title), m_Length(0)
{
}


/*
	Add new element to the list
*/
void List::addElement(unsigned int index, ListElement* element) {
	m_ElementMap[index] = element;
	m_Length++;
	log("Added element '" + (std::string)element->getTitle() + "' to list at index " + std::to_string(index), logLevel::TRACE);
}


/*
	Move element in list from 'from' to 'to'
*/
void List::moveElement(unsigned int from, unsigned int to) {
	ListElement* eFrom = m_ElementMap.at(from);
	log("Move element '" + (std::string)eFrom->getTitle() + "' from " + std::to_string(from) + " to " + std::to_string(to), logLevel::TRACE);
	if (m_ElementMap.find(from) == m_ElementMap.end() ||
		m_ElementMap.find(to) == m_ElementMap.end()) {
		return;
	}
	ListElement* temp     = m_ElementMap.at(to);
	m_ElementMap.at(to)   = m_ElementMap.at(from);
	m_ElementMap.at(from) = temp;
	m_ElementMap.at(to)  ->setIndex(to);
	m_ElementMap.at(from)->setIndex(from);
}


/*
	Delete element at 'index'
*/
void List::delElement(unsigned int index) {
	ListElement* element = m_ElementMap.at(index);
	std::string title = (std::string)element->getTitle();
	for (unsigned int i = index; i < m_Length-1; i++) {
		m_ElementMap.at(i) = m_ElementMap.at(i + 1);
		m_ElementMap.at(i)->setIndex(i);
	}
	m_ElementMap.erase(m_Length);
	m_Length--;
	log("Deleted element '" + title + "' from list at index " + std::to_string(index), logLevel::TRACE);
}


/*
	Render the list to wxPanel ListManager
*/
void List::onRender(wxPanel* parent) {
	wxBoxSizer* listSizer = new wxBoxSizer(wxVERTICAL);
	ListElement* element = nullptr;
	for (unsigned int i = 0; i < m_Length; i++) {
		element = m_ElementMap[i];
		element->onRender(m_ListManager->getHandle(), listSizer);
	}
	m_ListManager->getHandle()->SetSizerAndFit(listSizer);
}


/*
	Update the rendered List
*/
void List::onUpdate(wxWindow* mainFrame) {
	m_ListManager->update();
}