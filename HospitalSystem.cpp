//
// Created by ssutt on 4/21/2023.
//
#include "HospitalSystem.h"
#include "Patient.h"

//adds a single patient in the system
void HospitalSystem::addPatient(Patient patient) {
    string first_name, middle_name, last_name, suffix, ailment, doctor;
    int treated, priority, num_ailments;
    vector<string> ailments;
    Logger& logger = Logger::getInstance();
    logger.log("Log: Writing Patient's Information");
    cout << "Enter patient's information:"<<endl;
    cout << "First Name: "<<endl;
    cin >> first_name;
    cout << "Middle Name: "<<endl;
    cin >> middle_name;
    cout << "Last Name: "<<endl;
    cin >> last_name;
    cout << "Suffix (Type NONE if Necessary): "<<endl;
    cin >> suffix;
    if(suffix == "NONE"){
        suffix = "";
    }
    cout << "Number of Ailments: "<<endl;
    cin >> num_ailments;
    cin.ignore();
    for (int i = 0; i < num_ailments; i++) {
        cout << "Ailment #" << i + 1 << ": \n";
        getline(cin, ailment);
        ailments.push_back(ailment);
    }
    cout << "Doctor's Last Name: "<<endl;
    cin >> doctor;
    cout << "Treated (0 for no, 1 for yes): "<<endl;
    cin >> treated;
    cout << "Priority: "<<endl;
    cin >> priority;

    patient.setFirstName(first_name);
    patient.setMiddleName(middle_name);
    patient.setLastName(last_name);
    patient.setSuffix(suffix);
    patient.setAilments(ailments);
    patient.setDoctor(doctor);
    patient.setTreated(treated);
    patient.setPriority(priority);

    if (treated == 1) {
        treated_list.push_back(patient);
        cout<<"Patient put in treated list"<<endl;
        logger.log("Log: Added Patient to Treated list ");
    } else {
        triage_list.push(patient);
        cout<<"Patient put in triage list"<<endl;
        logger.log("Log: Added Patient to Triage list ");
    }
}
bool LessThanPriority::operator()(const Patient &lhs, const Patient &rhs) const {
    return (lhs.getPriority() > rhs.getPriority());
}
//Treats a person in the triage list
void HospitalSystem::triageToTreated() {
    Logger& logger = Logger::getInstance();

    if (triage_list.empty()) {
        logger.log("Log: no Patients to treat");
        cout<<"No patient to be treated"<<endl;
    } else{
        logger.log("Log: Remove Patient from triage list");
        const Patient& patient = triage_list.top();
        Patient treatedPatient = patient;
        treatedPatient.setTreated(1);
        treated_list.push_back(treatedPatient);
        srand(time(NULL));
        int sleepTime = (rand() % 3) + 1;
        this_thread::sleep_for(chrono::seconds(sleepTime));
        logger.log("Log: Added Patients from Triage list to Treated list");
        logger.log("Log: Patient " + treatedPatient.getFirstName() + " " + treatedPatient.getLastName() + " has been treated. \nTreatment Time " + to_string(sleepTime)+" seconds");
        triage_list.pop();

        cout<<"Treated: "+ treatedPatient.getFirstName() + " " + treatedPatient.getLastName()<<endl;
    } 
}
//Print's one patient's information
void HospitalSystem::printPatientReport() {
    Logger &logger = Logger::getInstance();
    bool found = false;
    string patient_report;
    if (triage_list.empty() && treated_list.empty()) {
            logger.log("Log: No patients in system");
            cout<<"No Patient in the system"<<endl;
    } else {
        string first_name, last_name;
        cout << "Enter Patient's Name (First and Last Name): " << endl;
        cin >> first_name >> last_name;


        priority_queue<Patient, vector<Patient>, LessThanPriority> triage_copy_list = triage_list;
        while (!triage_copy_list.empty()) {
            const Patient &patient = triage_copy_list.top();
            if (patient.getFirstName() == first_name && patient.getLastName() == last_name) {
                logger.log("Log: Found Patient " + first_name + " " + last_name);
                found = true;
                cout << "Patient's Report: " << endl;
                patient_report = "First Name: " + patient.getFirstName() + "\n";
                patient_report += "Middle Name: " + patient.getMiddleName() + "\n";
                patient_report += "Last Name: " + patient.getLastName() + "\n";
                patient_report += "Suffix: " + patient.getSuffix() + "\n";
                if (patient.getAilments().size() > 0) {
                    patient_report += "Ailments: ";
                    for (const auto &ailment: patient.getAilments()) {
                        patient_report += ailment + " ";
                    }
                    patient_report += "\n";
                }
                patient_report += "Doctor's Last Name: " + patient.getDoctor() + "\n";
                patient_report += "Treated Value(0 is no and 1 is yes): " + to_string(patient.getTreated()) + "\n";
                patient_report += "Priority Number: " + to_string(patient.getPriority());
                cout << patient_report << endl;
                break;
            }
            triage_copy_list.pop();
        }


        if (!found) {
            vector<Patient> treated_copy_list = treated_list;
            for (const auto &patient: treated_copy_list) {
                if (patient.getFirstName() == first_name && patient.getLastName() == last_name) {
                    logger.log("Log: Found Patient " + first_name + " " + last_name);
                    found = true;
                    cout << "Patient's Report: " << endl;
                    patient_report = "First Name: " + patient.getFirstName() + "\n";
                    patient_report += "Middle Name: " + patient.getMiddleName() + "\n";
                    patient_report += "Last Name: " + patient.getLastName() + "\n";
                    patient_report += "Suffix: " + patient.getSuffix() + "\n";
                    if (patient.getAilments().size() > 0) {
                        patient_report += "Ailments: ";
                        for (const auto &ailment: patient.getAilments()) {
                            patient_report += ailment + " ";
                        }
                        patient_report += "\n";
                    }
                    patient_report += "Doctor's Last Name: " + patient.getDoctor() + "\n";
                    patient_report += "Treated Value(0 is no and 1 is yes): " + to_string(patient.getTreated()) + "\n";
                    patient_report += "Priority Number: " + to_string(patient.getPriority());
                    cout << patient_report << endl;
                    break;
                }
            }
        }
        if (!found) {
            logger.log("Log: Patient " + first_name + " " + last_name + " not found in system");
            cout << "Patient not found in the system" << endl;
        }
    }
}

//Says the current and next patient to be treated
void HospitalSystem::getNextPatient() {
    Logger& logger = Logger::getInstance();
    if(triage_list.empty()){
        cout<<"No Patients in Triage List"<<endl;
    }else{
        if(triage_list.size() == 1){
            cout << "Only one patient to treat: " << endl;
            Patient currentPatient = triage_list.top();
            logger.log("Log: Found current patient");
            cout << "Current Patient: " << currentPatient.getFirstName() + " " + currentPatient.getLastName() << endl;
        }else{
            Patient currentPatient = triage_list.top();
            triage_list.pop();
            logger.log("Log: Found current patient");
            cout << "Current Patient: " << currentPatient.getFirstName() + " " + currentPatient.getLastName() << endl;
            Patient nextPatient = triage_list.top();
            logger.log("Log: Found next patient");
            cout << "Next Patient: " << nextPatient.getFirstName() + " " + nextPatient.getLastName() << endl;
            triage_list.push(currentPatient);
        }
    }
}
//A report on all patients in the triage
void HospitalSystem::allPatientsInTriageReport() {
    Logger& logger = Logger::getInstance();
    if(triage_list.empty()){
        cout<<"No Patients in Triage List"<<endl;
    }else{
        logger.log("Log: Getting Patients in Triage List");
        priority_queue<Patient,vector<Patient>, LessThanPriority> copy_list = HospitalSystem::triage_list;
        int i = 1;
        string name;
        while(!copy_list.empty()){
            Patient patient = copy_list.top();
            cout<<"Patient "<<i<<" in Triage List:"<<endl;
            name ="First Name: \n" + patient.getFirstName();
            name+="\nMiddle Name: \n" + patient.getMiddleName();
            name+="\nLast Name: \n"+patient.getLastName();
            name+="\nSuffix: \n"+patient.getSuffix();
            cout<<name+"\n"<<endl;
            copy_list.pop();
            i++;
        }
    }
}
//Prints all patients in a treated list
void HospitalSystem ::allTreatedPatientsReport() {
    Logger& logger = Logger::getInstance();
    if(treated_list.empty()){
        cout<<"No Patients in Treated List"<<endl;
    }else{
        logger.log("Log: Getting Patients in Treated List");
        vector<Patient> copy_list = HospitalSystem::treated_list;
        int i = 1;
        string name;
        while(!copy_list.empty()){
            Patient patient = copy_list.front();
            cout<<"Patient "<<i<<" in Treated List:"<<endl;
            name ="First Name: \n" + patient.getFirstName();
            name+="\nMiddle Name: \n" + patient.getMiddleName();
            name+="\nLast Name: \n"+patient.getLastName();
            name+="\nSuffix: \n"+patient.getSuffix();
            cout<<name+"\n"<<endl;
            copy_list.erase(copy_list.begin());
            i++;
        }
    }
}
//This Function Treats all patients in a triage order
void HospitalSystem::treatAllPatients() {
    Logger& logger = Logger::getInstance();
    if(triage_list.empty()){
        cout<<"No Patients to treat"<<endl;
    }else{
        logger.log("Log: Treating All Patients");
        string treatedPatient;
        while (!triage_list.empty()) {
            const Patient nextPatient = triage_list.top();
            srand(time(NULL));
            int sleepTime = (rand() % 3) + 1;
            this_thread::sleep_for(chrono::seconds(sleepTime));
            logger.log("Log: Remove Patients from triage list");
            Patient treatedPatient = nextPatient;
            treatedPatient.setTreated(1);
            treated_list.push_back(treatedPatient);
            logger.log("Log: Added Patients from Triage list to Treated list");
            logger.log("Log: Patient " + treatedPatient.getFirstName() + " " + treatedPatient.getLastName() + " has been treated. \nThread Time: " + to_string(sleepTime)+" seconds");
            triage_list.pop();

            cout<<"Treated: "+ treatedPatient.getFirstName() + " " + treatedPatient.getLastName()<<endl;
            cout<<"Treated Time: "+to_string(sleepTime)+" hours"<<endl;
        }
    }
}
//List all Doctors and their patients
void HospitalSystem::printPatientByDoctor() {
    Logger& logger = Logger::getInstance();
    if (triage_list.empty() && treated_list.empty()) {
        logger.log("Log: No patients in system");
        cout<<"No Patients in the system."<<endl;
    }else{
        logger.log("Log: Printing all patients in the system by Doctor");
        priority_queue<Patient,vector<Patient>, LessThanPriority> triage_copy_list = triage_list;
        vector<Patient> treated_copy_list = treated_list;
        map<string,vector<Patient>>patients_by_doctor;
        string full_name;
        while(!triage_copy_list.empty()){
            Patient patientTriage = triage_copy_list.top();
            patients_by_doctor[patientTriage.getDoctor()].push_back(patientTriage);
            triage_copy_list.pop();
        }

        while(!treated_copy_list.empty()){
            Patient patientTreated = treated_copy_list.front();
            patients_by_doctor[patientTreated.getDoctor()].push_back(patientTreated);
            treated_copy_list.erase(treated_copy_list.begin());
        }

        for (auto it = patients_by_doctor.begin(); it != patients_by_doctor.end(); ++it) {
            string doctor_name = it->first;
            vector<Patient> patients = it->second;
            cout << "Patients treated by Dr." << doctor_name << ":" << endl;
            for (auto patient : patients) {
                full_name = patient.getFirstName() + " " + patient.getMiddleName() + " " + patient.getLastName() + " " + patient.getSuffix();
                cout << full_name << endl;
            }

        }
    }
}
//Adds all patients in a file
void HospitalSystem::addPatientsFromAFile(const string& filename) {
    Logger& logger = Logger::getInstance();
    ifstream PatientsFile(filename);
    if (!PatientsFile) {
        logger.log("Log: File not found");
        cout <<"Error: cannot open file "<< filename << endl;
        return;
    }
    logger.log("Log: Loading Patient File Information");
    string line;
    stringstream ss(line);
    string category, patientData;
    while (!PatientsFile.eof()) {
        Patient patient;
        cout<<"Patient's information from file: "<<endl;
        while(getline(PatientsFile,line)) {
            int delim = line.find(':');
            category = line.substr(0, delim);
            patientData = line.substr(delim+1, line.length() - 1);
            cout << "Category: " << category << ", Data: " << patientData << endl;
            if (category == "firstName") {
                patient.setFirstName(patientData);
            } else if (category == "middleName") {
                patient.setMiddleName(patientData);
            } else if (category == "lastName") {
                patient.setLastName(patientData);
            } else if (category == "suffix") {
                if (patientData.empty()) {
                    patientData = "";
                }
                patient.setSuffix(patientData);
            } else if (category == "ailment") {
                vector<string> ailments;
                ailments.push_back(patientData);
                while (getline(ss, category, ':') && category != "doctor" && category != "treated" && category != "priority") {
                    ailments.push_back(patientData);
                }
                patient.setAilments(ailments);
            } else if (category == "doctor") {
                patient.setDoctor(patientData);
            } else if (category == "treated") {
                patient.setTreated(stoi(patientData));
            } else if (category == "priority") {
                patient.setPriority(stoi(patientData));
            }
            else {
                break;
            }

        }
        int treated = patient.getTreated();
        if (treated == 1) {
            treated_list.push_back(patient);
            logger.log("Log: Adding Patient to treated list");
            cout<<"Added Patient: "+ patient.getFirstName() + " " + patient.getLastName() +" to Treated List"<<endl;
        } else {
            triage_list.push(patient);
            logger.log("Log: Adding Patient to triage list");
            cout<<"Added Patient: "+ patient.getFirstName() + " " + patient.getLastName() +" to Triage List"<<endl;
        }
        logger.log("Log: Added patient " + patient.getFirstName() + " " + patient.getLastName() + " from file");
    }
    PatientsFile.close();
}

HospitalSystem::~HospitalSystem() = default;

HospitalSystem::HospitalSystem() = default;