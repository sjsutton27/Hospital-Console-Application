//
// Created by ssutt on 4/21/2023.
//

#include "Patient.h"
Patient::Patient(){

}

// Constructor with parameters
Patient::Patient(string &first_name, string &middle_name, string &last_name, string &suffix, vector<string> &ailments,string &doctor,int treated, int priority):
        first_name(first_name),middle_name(middle_name),last_name(last_name),suffix(suffix),ailments(ailments),doctor(doctor),treated(treated),priority(priority){
}

// getter methods
string Patient::getFirstName() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's First Name ");
    return first_name;
}

string Patient::getMiddleName() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's Middle Name ");
    return middle_name;
}

string Patient::getLastName() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's Last Name ");
    return last_name;
}
string Patient::getSuffix() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's Suffix ");
    return suffix;
}

vector<string> Patient::getAilments() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's Ailment(s) ");
    return ailments;
}

string Patient::getDoctor() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's Doctor ");
    return doctor;
}

int Patient::getTreated() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting if patient was treated ");
    return treated;
}

int Patient::getPriority() const {
    Logger& logger = Logger::getInstance();
    logger.log("Getting Patient's Priority ");
    return priority;
}

// setter methods
void Patient::setFirstName(const string &first_name) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's First Name ");
    Patient::first_name = first_name;
}

void Patient::setMiddleName(const string &middle_name) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's Middle Name ");
    Patient::middle_name = middle_name;
}

void Patient::setLastName(const string &last_name) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's Last Name ");
    Patient::last_name = last_name;
}
void Patient::setSuffix(const string &suffix) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's Suffix ");
    Patient::suffix = suffix;
}
void Patient::setAilments(const vector<string> &ailments) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's Ailment(s) ");
    Patient::ailments = ailments;
}

void Patient::setDoctor(const string &doctor) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's Doctor ");
    Patient::doctor = doctor;
}

void Patient::setTreated(int treated) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's if patient was treated or not ");
    Patient::treated = treated;
}

void Patient::setPriority(int priority) {
    Logger& logger = Logger::getInstance();
    logger.log("Setting Patient's Priority ");
    Patient::priority = priority;
}