#include "ListManager.h"

#include "Logger.h"

ListManager::ListManager(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(WIN_WIDTH, WIN_HEIGHT)),
	m_MainFrame(parent), m_List(nullptr)
{
}


void ListManager::render() {
	m_Sizer = new wxBoxSizer(wxVERTICAL);
	m_Sizer->Add(this, wxSizerFlags(1).Expand());
	m_List->onRender(this);
	m_MainFrame->SetSizer(m_Sizer);
	this->Layout();
	m_MainFrame->Layout();
	//this->Fit();
	//m_MainFrame->Fit();
}

void ListManager::update() {
	saveList("List.mfn");
	m_MainFrame->SetSizer(NULL);
	this->DestroyChildren();
	loadList("List.mfn");
	render();
}


/*
	Load list from file at 'path'
*/
void ListManager::loadList(wxString path) {
	std::string filepath = path.ToStdString();
	// if save file doesn't exist
	if (!std::filesystem::exists(filepath)) {
		wxLogStatus("File doesn't exist");
		std::ofstream file(filepath);
		file.close();
		m_List = new List(this, "New List");
		log("Created new list save file");
	}
	// if save file exists
	else {
		std::ifstream iStream(filepath);
		std::string listTitle;
		std::string line;
		std::string title;
		std::string description;
		bool done;
		unsigned int index = 0;
		int pos;
		ListElement* element;

		std::getline(iStream, listTitle);
		m_List = new List(this, listTitle);
		m_MainFrame->SetTitle(listTitle);

		while (std::getline(iStream, line)) {
			// Save format is:
			//	title  done  description
			pos = line.find(' ');
			title = line.substr(0, pos);
			line.erase(0, title.length() + 1);
			done = std::stoi(line.substr(0));
			line.erase(0, 2);
			description = line;
			std::replace(title.begin(), title.end(), '_', ' ');
			std::replace(description.begin(), description.end(), '_', ' ');

			element = new ListElement(this, title, done, description, index);
			m_List->addElement(index, element);
			index++;
		}
		iStream.close();
		log("Loaded '" + listTitle + "' from '" + filepath + "'", logLevel::INFO);
	}
}


/*
	Save list to file at 'path'
*/
void ListManager::saveList(wxString path) {
	std::string filepath = path.ToStdString();
	std::ofstream oStream;
	{ // clear save file
		oStream.open(filepath);
		oStream.clear();
		oStream.close();
	}
	oStream.open(filepath, std::ios_base::app);
	std::stringstream saveStr;

	List* list = m_List;
	oStream << m_List->getTitle().ToStdString() << std::endl;
	for (unsigned int i = 0; i < list->getLength(); i++) {
		oStream << list->at(i)->getSaveString() << std::endl;
	}
	oStream.close();
	log("Saved  '" + m_List->getTitle().ToStdString() + "' to   '" + filepath, logLevel::INFO);
}