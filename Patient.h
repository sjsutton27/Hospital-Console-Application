//
// Created by ssutt on 4/21/2023.
//

#ifndef HOSPITAL_ADMIN_CONSOLE_APP_PATIENT_H
#define HOSPITAL_ADMIN_CONSOLE_APP_PATIENT_H
#include <string>
#include <vector>
#include "Logger.h"

using namespace std;
class Patient{

private:
    string first_name;
    string middle_name;
    string last_name;
    string suffix;
    vector<string> ailments;
    string doctor;
    int treated;
    int priority;

public:
    Patient();
    Patient(string &first_name, string &middle_name, string &last_name, string &suffix, vector<string> &ailments,string &doctor,int treated, int priority);

    //getters
    string getFirstName() const;
    string getMiddleName() const;
    string getLastName() const;
    string getSuffix() const;
    vector<string> getAilments() const;
    string getDoctor() const;
    int getTreated () const;
    int getPriority() const;

    //setters
    void setFirstName(const string &first_name);
    void setMiddleName(const string &middle_name);
    void setLastName(const string &last_name);
    void setSuffix(const string &suffix) ;
    void setAilments(const vector<string> &ailment);
    void setDoctor(const string &doctor);
    void setTreated(const int treated);
    void setPriority(const int priority);

};


#endif //HOSPITAL_ADMIN_CONSOLE_APP_PATIENT_H
