﻿#pragma once

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// Fenêtre principale
class MainFrame : public wxFrame
{
public:
	// Le constructeur qui prend le titre de la fenêtre en paramètre
	MainFrame(const wxString& title);
private:
	/*
	// -------------- GESTION DES EVENTS STATIQUES ---------------
	// Méthode pour quand l'on clique sur le bouton
	void OnButtonClicked(wxCommandEvent& evt);
	// Méthode pour quand l'on bouge le slider
	void OnSliderChanged(wxCommandEvent& evt);
	// Méthode pour quand l'on change le texte
	void OnTextChanged(wxCommandEvent& evt);
	// Macro pour lier la méthode et le bouton
	wxDECLARE_EVENT_TABLE();
	*/

	// -------------- GESTION DES EVENTS DYNAMIQUE ---------------
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChanged(wxCommandEvent& evt);

};

// Une classe qui représente l'app
class App : public wxApp {
public:
	bool OnInit();
};