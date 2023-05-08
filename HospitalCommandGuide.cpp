//
// Created by ssutt on 4/21/2023.
//

#include "HospitalCommandGuide.h"
using namespace std;
HospitalCommandGuide::HospitalCommandGuide() {
    text = "=========================================================\n";
    text += "Welcome to the Hospital Console App\n";
    text +="Enter a number listed to run the following command\n";
    text +="0 Add a patient \n";
    text +="1 Treat a patient\n";
    text +="2 Print patient's report \n";
    text +="3 Print next patient to be treated \n";
    text +="4 Print out a report of all patients in Triage list\n";
    text +="5 Print out a report of all patients in Treated list\n";
    text +="6 Treat all patients \n";
    text +="7 Print out all patients by doctor \n";
    text +="8 Bulk add patients from a file \n";
    text +="9 Switch to debug mode \n";
    text +="10 Switch out of debug mode \n";
    text +="11 To exit system\n";
    text += "=========================================================";
}

std::string HospitalCommandGuide::getText() {
    return text;
}