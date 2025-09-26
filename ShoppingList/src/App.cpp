#include "App.h"

#define WIN_HEIGHT 500
#define WIN_WIDHT 400

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("List App");
	mainFrame->SetClientSize(WIN_WIDHT, WIN_HEIGHT);
	mainFrame->Center();
	mainFrame->Show();

	return true;
}