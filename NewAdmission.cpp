#include <wx/wxprec.h>
#include <wx-3.1/wx/string.h>
#include <wx-3.1/wx/button.h>
#include <wx-3.1/wx/notebook.h>
#include <wx-3.1/wx/window.h>
#include <wx-3.1/wx/withimages.h>
#include <wx-3.1/wx/stattext.h>
#include <wx-3.1/wx/textctrl.h>
#include <wx-3.1/wx/msgdlg.h>
#include <wx-3.1/wx/arrstr.h>

#include <algorithm>
#include <regex>

#include "AdmissionRepo.cpp"


#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class NewAdmissionFrame : public wxFrame {
    private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void enterDetailsBtn_Click(wxCommandEvent& event);


    void onComboBox(wxCommandEvent& event);


    wxArrayString courceList, kinderGardenCourseList, prePrimaryCourseList, primaryCourseList, secondaryCourseList, highSchoolCourseList;

    public: 
    wxTextCtrl *fatherNameTextInput, *motherNameTextInput, *nameTextInput;
    wxStaticText *headingLabel, *nameLabel, *motherNameLabel, *fatherNameLabel;
    wxBoxSizer *mainVbox, *detailsHbox, *labelVerticalBox, *inputVerticalBox;
    wxButton *enterBtn;
    wxComboBox *courcesComboBox, *kinderGardenCourseComboBox, *prePrimaryCourseComboBox, *primaryCourseComboBox, *secondaryCourseComboBox, *highCourseComboBox;

    wxFont headingFont;

    wxArrayString strArrToWxArrStr(std::string array[]);
    
    NewAdmissionFrame() : wxFrame(NULL, wxID_ANY, "New Admission"){

        courceList.Add(wxT("Pre Primary School"));
        courceList.Add(wxT("Primary School"));
        courceList.Add(wxT("Secondary School"));

        kinderGardenCourseList.Add(wxT("LKG"));
        kinderGardenCourseList.Add(wxT("UKG"));

        prePrimaryCourseList.Add(wxT("1"));
        prePrimaryCourseList.Add(wxT("2"));
        prePrimaryCourseList.Add(wxT("3"));
        
        primaryCourseList.Add(wxT("4"));
        primaryCourseList.Add(wxT("5"));
        primaryCourseList.Add(wxT("6"));

        secondaryCourseList.Add(wxT("7"));
        secondaryCourseList.Add(wxT("8"));
        secondaryCourseList.Add(wxT("9"));
        secondaryCourseList.Add(wxT("10"));

        headingFont = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

        mainVbox = new wxBoxSizer(wxVERTICAL);

        detailsHbox = new wxBoxSizer(wxHORIZONTAL);

        labelVerticalBox = new wxBoxSizer(wxVERTICAL);
        inputVerticalBox = new wxBoxSizer(wxVERTICAL);

        headingLabel = new wxStaticText(this, wxID_ANY, "New Admission", wxDefaultPosition, wxDefaultSize, 0, "NewAdmissionLabel");
        headingLabel->SetFont(headingFont);
        mainVbox->Add(headingLabel, 0, wxTOP | wxLEFT | wxRIGHT, 15);

        nameLabel = new wxStaticText(this, wxID_ANY, "Name: ", wxDefaultPosition, wxDefaultSize, 0, "NameLabel");
        nameTextInput = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(100, 22), 0, wxDefaultValidator, "NameTxtCtrl");
        labelVerticalBox->Add(nameLabel, 0, wxTOP, 15);
        inputVerticalBox->Add(nameTextInput, 0, wxEXPAND | wxTOP, 10);
    
        motherNameLabel = new wxStaticText(this, wxID_ANY, "Mother's Name: ", wxDefaultPosition, wxDefaultSize, 0, "MotherNameLabel");
        motherNameTextInput = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(100, 22), 0, wxDefaultValidator, "MotherNameTxtCtrl");
        labelVerticalBox->Add(motherNameLabel, 0, wxTOP, 15);
        inputVerticalBox->Add(motherNameTextInput, 0, wxEXPAND | wxTOP, 10);

        fatherNameLabel = new wxStaticText(this, wxID_ANY, "Father's Name: ", wxDefaultPosition, wxDefaultSize, 0, "FatherNameLabel");
        fatherNameTextInput = new wxTextCtrl(this, wxID_ANY, " ", wxDefaultPosition, wxSize(100, 22), 0, wxDefaultValidator, "FatherNameTxtCtrl");
        labelVerticalBox->Add(fatherNameLabel, 0, wxTOP, 15);
        inputVerticalBox->Add(fatherNameTextInput, 0, wxEXPAND | wxTOP, 10);

        courcesComboBox = new wxComboBox(this, wxID_ANY, _T("Select One"), wxDefaultPosition, wxDefaultSize, courceList, 0, wxDefaultValidator, "CB");
        courcesComboBox->SetEditable(false);
        courcesComboBox->Bind(wxEVT_COMBOBOX, &NewAdmissionFrame::onComboBox, this);
        inputVerticalBox->Add(courcesComboBox, 0, wxEXPAND | wxTOP, 10);

        prePrimaryCourseComboBox = new wxComboBox(this, wxID_ANY, _T("Select One"), wxDefaultPosition, wxDefaultSize, prePrimaryCourseList, 0, wxDefaultValidator, "CBpreprimary");
        prePrimaryCourseComboBox->SetEditable(false);
        inputVerticalBox->Add(prePrimaryCourseComboBox, 0, wxEXPAND | wxTOP, 10);
        inputVerticalBox->Show(prePrimaryCourseComboBox, false, false);

        primaryCourseComboBox = new wxComboBox(this, wxID_ANY, _T("Select One"), wxDefaultPosition, wxDefaultSize, primaryCourseList, 0, wxDefaultValidator, "CBprimary");
        primaryCourseComboBox->SetEditable(false);
        inputVerticalBox->Add(primaryCourseComboBox, 0, wxEXPAND | wxTOP, 10);
        inputVerticalBox->Show(primaryCourseComboBox, false, false);

        secondaryCourseComboBox = new wxComboBox(this, wxID_ANY, _T("Select One"), wxDefaultPosition, wxDefaultSize, secondaryCourseList, 0, wxDefaultValidator, "CBsecondary");
        secondaryCourseComboBox->SetEditable(false);
        inputVerticalBox->Add(secondaryCourseComboBox, 0, wxEXPAND | wxTOP, 10);
        inputVerticalBox->Show(secondaryCourseComboBox, false, false);

        enterBtn = new wxButton(this, wxID_ANY, _T("Enetr details"), wxDefaultPosition, wxDefaultSize, 0);
        enterBtn->Bind(wxEVT_BUTTON, &NewAdmissionFrame::enterDetailsBtn_Click, this);
        inputVerticalBox->Add(enterBtn, 0, wxTOP, 10);

        detailsHbox->Add(labelVerticalBox, 0, wxALL, 8);
        detailsHbox->Add(inputVerticalBox, 1, wxEXPAND | wxTOP | wxRIGHT, 10);
        
        mainVbox->Add(detailsHbox, 1, wxEXPAND | wxTOP | wxRIGHT, 0);

        this->SetSizerAndFit(mainVbox);
    }

};

void NewAdmissionFrame::OnExit(wxCommandEvent& event){
    Close(true);
}

void NewAdmissionFrame::enterDetailsBtn_Click(wxCommandEvent& event){
    std::string studentName = nameTextInput->GetValue().utf8_string();
    std::string motherName = motherNameTextInput->GetValue().utf8_string();
    std::string fatherName = fatherNameTextInput->GetValue().utf8_string();

    wxMessageDialog *msgDialog;

    if(regex_replace(studentName, std::regex("\\s"), "") == ""){
        msgDialog = new wxMessageDialog(this, wxT("Student Name cannot be blank"), wxT("Error"), wxOK | wxICON_ERROR);
        msgDialog->ShowModal();
    }else if(regex_replace(motherName, std::regex("\\s"), "")  == ""){
        msgDialog = new wxMessageDialog(this, wxT("Mother Name cannot be blank"), wxT("Error"), wxOK | wxICON_ERROR);
        msgDialog->ShowModal();
    }else if(regex_replace(fatherName, std::regex("\\s"), "")  == ""){
        msgDialog = new wxMessageDialog(this, wxT("Father Name cannot be blank"), wxT("Error"), wxOK | wxICON_ERROR);
        msgDialog->ShowModal();
    }else if(courcesComboBox->GetStringSelection() == "Select One" || courcesComboBox->GetStringSelection() == ""){
        msgDialog = new wxMessageDialog(this, wxT("Select Cource"), wxT("Error"), wxOK | wxICON_ERROR);
        msgDialog->ShowModal();
    }else {
        NewAdmissionRepo *repo = new NewAdmissionRepo(studentName, motherName, fatherName);
        std::cout << repo->getDetailsStr() << std::endl;
    }
}


void NewAdmissionFrame::onComboBox(wxCommandEvent& event){
    if(courcesComboBox->GetStringSelection() == "Pre Primary School"){
        inputVerticalBox->Show(prePrimaryCourseComboBox, true, false);
        inputVerticalBox->Layout();
    }else{
        inputVerticalBox->Show(prePrimaryCourseComboBox, false, false);
        inputVerticalBox->Layout();
    }

    if(courcesComboBox->GetStringSelection() == "Primary School"){
        inputVerticalBox->Show(primaryCourseComboBox, true, false);
        inputVerticalBox->Layout();
    }else{
        inputVerticalBox->Show(primaryCourseComboBox, false, false);
        inputVerticalBox->Layout();
    }

    if(courcesComboBox->GetStringSelection() == "Secondary School"){
        std::cout << "Show secondary combobox" << std::endl;
        inputVerticalBox->Show(secondaryCourseComboBox, true, false);
        inputVerticalBox->Layout();
    }else{
        inputVerticalBox->Show(secondaryCourseComboBox, false, false);
        inputVerticalBox->Layout();
    }
}
