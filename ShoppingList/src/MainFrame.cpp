#include "MainFrame.h"


static List* loadList(wxWindow* mainFrame, std::string filepath);


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	CreateStatusBar();

	m_ListPanel = new wxPanel(this, wxID_ANY);
	m_ListSizer = new wxBoxSizer(wxVERTICAL);
	m_List = loadList(m_ListPanel, "List.mfn");
	m_List->onRender(m_ListPanel);
	m_ListSizer->Add(m_ListPanel, wxSizerFlags(1).Expand());
	this->SetSizerAndFit(m_ListSizer);
}


static List* loadList(wxWindow* mainFrame, std::string filename) {
	// if save file doesn't exist
	if (!std::filesystem::exists(filename)) {
		wxLogStatus("File doesn't exist");
		std::ofstream file(filename);
		file.close();
		return new List(mainFrame, "New List");
	}
	// if save file exists
	else {
		std::ifstream iStream(filename);
		std::string listTitle;
		std::getline(iStream, listTitle);
		List* list = new List(mainFrame, listTitle);
		int index = 0;
		std::string line, title, description;
		bool done;
		int pos;
		ListElement* element;
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
			element = new ListElement(list, list, title, description, done);
			element->setIndex(index);
			index++;
			list->addElement(element);
		}
		iStream.close();
		return list;
	}
}

static void saveList(std::string filename) {
	std::ofstream oStream(filename);

	oStream.close();
}