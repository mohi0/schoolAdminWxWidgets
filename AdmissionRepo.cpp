#include<string>  

class NewAdmissionRepo {

private:
    int rollnumber;
    std::string studentName, motherName, fatherName;
public:
    NewAdmissionRepo(std::string StudentName, std::string MotherName, std::string FatherName){
        studentName = StudentName;
        motherName = MotherName;
        fatherName = FatherName;
        rollnumber = this->generateRollNumber();
    }

    ~NewAdmissionRepo();

    int generateRollNumber(){
        return rand() % 100;
    }

    std::string getDetailsStr(){ 
        return "{\n"
            "\"Name\": \"" + this->studentName + "\""
            ",\n\"Roll Number\": " + std::to_string(this->rollnumber) +
            ",\n\"Father Name\": \""+this->fatherName + "\"" 
            ",\n\"Mother Name\": \""+this->motherName + "\""
            "\n}";
    }
};
