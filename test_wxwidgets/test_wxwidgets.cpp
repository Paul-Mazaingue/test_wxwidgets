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
	// on place une entrée de texte / avec un style password
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

	//wxSlider(le parent du bouton, une id,valeur initiale, valeur min, valeur max, position, taille) // style qui affiche la valeur
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

	// wxGauge(le parent du bouton, une id,valeur initiale, valeur max, position, taille) / style vertical
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(590, 205), wxSize(-1, 125), wxGA_VERTICAL);
	// on met la valeur à 50 (elle n'est modifiable que dans le code)
	gauge->SetValue(50);

	// On stocke les différents choix possible
	wxArrayString choices;
	choices.Add("Item C");
	choices.Add("Item B");
	choices.Add("Item A");
	// On affiche le choix multiple / style qui trie de manière  alphabétique
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	// On en choisi un par défaut
	choice->Select(0);

	// on doit include <wx/spinctrl.h>
	// On peut également set un max/min   / Style qui fait que si on décrémente la val min on arrive à la val max
	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);

	// Ressemble aux différents choix possibles / style qui accepte la sélection multiple
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices, wxLB_MULTIPLE);

	// RadioBox / style, on peut choisir le nombre de choix par ligne
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(555, 450), wxDefaultSize, choices,2);
	
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