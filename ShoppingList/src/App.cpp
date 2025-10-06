#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	initLogger();
	MainFrame* mainFrame = new MainFrame("List App");
	mainFrame->SetClientSize(WIN_WIDTH, WIN_HEIGHT);
	mainFrame->Center();
	mainFrame->Show();

	return true;
}