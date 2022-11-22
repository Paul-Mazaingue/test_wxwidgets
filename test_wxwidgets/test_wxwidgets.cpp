#include "test_wxwidgets.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

/*
// -------------- GESTION DES CONTROLLERS ---------------
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
*/

/*
// -------------- GESTION DES EVENTS STATIQUES ---------------
// Nous avons besoin d'id custom, elle doivent suivre certaines règles :
// - Doivent être positives
// - Ne peuvent pas être 0 et 1
// - Ne peuvent pas être comprise entre wxID_LOWEST(4999) et wxID_HIGHEST(5999)
enum IDs {
	BUTTON_ID = 2,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

// On start la table des events, avec comme paramètre la classe ou l'on a defini la table des events et sa classe de base
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	// On relie OnButtonClicked et BUTTON_ID
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	// On relie OnSliderChanged et SLIDER_ID
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
	// On relie OnTextChanged et TEXT_ID
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
// On ferme la table
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	// Bouton avec l'id 2
	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));

	// On ajoute un slider avec l'id 3
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));

	// On affiche une entrée de texte avec l'id 4
	wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

	// affiche une barre de status en bas de la fenêtre ou nous pouvons mettre du texte
	CreateStatusBar();
}

// Lorsque l'on clique sur le bouton
void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	// Quand le bouton est cliqué on affiche dans la bare de status "Button Clicked"
	wxLogStatus("Button Clicked");
}

// Lorsque l'on modifie le slider
void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	// On récupère la valeur du slider et on la formate en string
	wxString str = wxString::Format("Slider Valeur: %d", evt.GetInt());
	// On l'affiche
	wxLogStatus(str);
}

// Lorsque l'on modifie le texte
void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	// On récupère le texte et on le formate en string
	wxString str = wxString::Format("Text: %s", evt.GetString());
	// On l'affiche
	wxLogStatus(str);
}
*/

/*
// -------------- GESTION DES EVENTS DYNAMIQUE ---------------
// Nous n'avons pas besoin d'id prédéfinie
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

	// On relie le bouton à OnButtonClicked / Bind(l'event déclencheur, pointeur sur la méthode, l'objet qui va s'occuper de l'event)
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	// Pour retirer un lien
	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button Clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Slider Valeur: %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}
*/

// -------------- EVENT PROPAGATION ---------------

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	//button1->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this); // Seul le bouton 1 marche
	//panel->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this); // Les deux boutons marchent
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this); // Les deux boutons marchent

	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	// On relie l'event de fermeture de la fenêtre et la méthode OnClose
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

	CreateStatusBar();
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
	// Fait apparaitre un popup
	wxLogMessage("Button Clicked");
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 1 Clicked");

	// Pour pouvoir continuer la propagation des évents et donc OnAnyButtonClicked
	evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 2 Clicked");

	// Pour pouvoir continuer la propagation des évents et donc OnAnyButtonClicked
	evt.Skip();
}

void MainFrame::OnClose(wxCloseEvent& evt) {
	wxLogMessage("Frame Closed");

	// Pour pouvoir fermer la fenêtre
	evt.Skip();
}

// -------------- CREATION DE L'APP ---------------
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