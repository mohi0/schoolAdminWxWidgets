// wxWidgets "wxWidgetsschoolAdmin" Program
 
// For compilers that support precompilation, includes "wx/wx.h".


//to compile this program g++ Main.cpp `wx-config --libs` `wx-config --cxxflags` -o wxWidgetsschoolAdmin 

#include <wx/wxprec.h>
#include <wx-3.1/wx/button.h>
#include <wx-3.1/wx/notebook.h>
#include <wx-3.1/wx/window.h>
#include <wx-3.1/wx/withimages.h>
#include <wx-3.1/wx/stattext.h>
#include <wx-3.1/wx/textctrl.h>

#include "NewAdmission.cpp"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame();
 
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void newAdmissionBtnClick(wxCommandEvent& event);
};
 
enum
{
    ID_Hello = 1,
    BUTTON_Simple = wxID_HIGHEST + 1,
    ID_mNoteBook = wxID_HIGHEST + 1,
    ID_mWindow = wxID_HIGHEST + 1,

    ID_nameTextInput = wxID_HIGHEST + 1
};
 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
 
MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Hello World")
{


    wxButton *btn = new wxButton(this, wxID_ANY, _T("new admission"), wxDefaultPosition, wxDefaultSize, 0);
    btn->Bind(wxEVT_BUTTON, &MyFrame::newAdmissionBtnClick, this); 
  
}
 
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}


void MyFrame::newAdmissionBtnClick(wxCommandEvent& event){
    std::cout << "Openned New Admission Window \n";
    NewAdmissionFrame *newAdmissionFrame = new NewAdmissionFrame();
    newAdmissionFrame->Show(true);
}


