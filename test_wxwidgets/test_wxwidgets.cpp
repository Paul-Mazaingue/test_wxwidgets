#include "test_wxwidgets.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

// wxFrame(Parent de la fenêtre, une id, le titre, la position, la taille en prenant en compte les bordures)
// Code du constructeur
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {

	// Quand il n'y a qu'un enfant de mainframe, il va obligatoirement prendre toute la place (même si on définit sa taille)
	// donc on créé un panneau qui va prendre toute la place et on va venir placer nos boutons/textes ect... dessus
	wxPanel* panel = new wxPanel(this);

	// wxButton(le parent du bouton, une id, le texte du bouton, position du coin en haut à gauche, la taille du bouton, style)
	// On place un bouton / On utilise un style qui centre le texte à gauche du bouton
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);

	// On place une checkbox / ici on utilise 2 styles (qui ajoute un état en plus), pour les combiner on utilise '|'
	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Checkbox", wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	// On place un texte statique non modifiable / style pour centrer le texte
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable", wxPoint(0, 150), wxSize(400,-1), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	// -1 : valeur par défaut
	// la label : "TextCtrl - editable" est la valeur qui s'affiche avant que l'utilisateur ne tape quelque chose
	// on place une entrée de texte
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1));

	//wxSlider(le parent du bouton, une id,valeur initiale, valeur min, valeur max, position, taille)
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));

	// wxGauge(le parent du bouton, une id,valeur initiale, valeur max, position, taille)
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	// on met la valeur à 50 (elle n'est modifiable que dans le code)
	gauge->SetValue(50);

	// On stocke les différents choix possible
	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");
	// On affiche le choix multiple
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	// On en choisi un par défaut
	choice->Select(0);

	// on doit include <wx/spinctrl.h>
	// On peut également set un max/min
	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));

	// Ressemble aux différents choix possibles
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	// RadioBox
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);
	
}

// Pour dire à wxwidget quelle classe représente notre application
wxIMPLEMENT_APP(App);

bool App::OnInit() {
	// On créé une instance de notre fenêtre principale qui par défaut est cachée
	MainFrame* mainFrame = new MainFrame("C++ GUI");

	// On définit la taille de la fenêtre sans compter les bordures
	mainFrame->SetClientSize(800, 600);

	// On centre la fenêtre au milieu de l'écran
	mainFrame->Center();

	// On utilise la méthode show qui affiche la fenêtre
	mainFrame->Show();

	// true : on continue l'exécution
	// false : on stop l'exécution
	return true;
}