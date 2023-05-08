//
// Created by ssutt on 4/21/2023.
//

#ifndef HOSPITAL_ADMIN_CONSOLE_APP_HOSPITALSYSTEM_H
#define HOSPITAL_ADMIN_CONSOLE_APP_HOSPITALSYSTEM_H
#include "Patient.h"
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <thread>
#include <chrono>
class LessThanPriority{
public:
    bool operator() (const Patient &lhs, const Patient &rhs) const;
};
class HospitalSystem {
public:
    HospitalSystem(); //Constructor
    ~HospitalSystem(); //Destructor

    void addPatient(Patient patient);

    void triageToTreated();

    void printPatientReport();

    void getNextPatient();

    void allPatientsInTriageReport();

    void allTreatedPatientsReport();

    void treatAllPatients();

    void printPatientByDoctor();

    void addPatientsFromAFile(const string &file_name);


private:
    priority_queue<Patient,vector<Patient>, LessThanPriority> triage_list;
    vector<Patient> treated_list;

    bool debug_mode;
};
#endif //HOSPITAL_ADMIN_CONSOLE_APP_HOSPITALSYSTEM_H
