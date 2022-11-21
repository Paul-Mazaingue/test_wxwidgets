#pragma once

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// Fenêtre principale
class MainFrame : public wxFrame
{
public:
	// Le constructeur qui prend le titre de la fenêtre en paramètre
	MainFrame(const wxString& title);
};

// Une classe qui représente l'app
class App : public wxApp {
public:
	bool OnInit();
};