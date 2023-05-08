#include "HospitalCommandGuide.h"
#include "HospitalSystem.h"
#include "Patient.h"
#include "Logger.h"

int main() {
    HospitalCommandGuide guide;
    HospitalSystem hospitalSystem;
    Patient patient;
    auto &logger = Logger::getInstance();
    int command_number = -1;
    do {
        cout << guide.getText() << endl;
        cout << "Enter a command number: " << endl;
        cin >> command_number;
        //checks if they enter a string or special character
        if (cin.fail()) {
            cout << "Incorrect Input, please put a number 0-11" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (command_number == 0) {
            logger.log("Adding Patient.");
            hospitalSystem.addPatient(patient);
        }
        else if(command_number == 1) {
            logger.log("Moving Patient from triage to treated.");
            hospitalSystem.triageToTreated();
        }
        else if(command_number == 2){
            logger.log("Printing Patient's Report.");
            hospitalSystem.printPatientReport();

        }
        else if(command_number == 3){
            logger.log("Next Patient to be treated.");
            hospitalSystem.getNextPatient();
        }
        else if(command_number == 4){
            logger.log("Patient's in Triage List.");
            hospitalSystem.allPatientsInTriageReport();
        }else if(command_number == 5){
            logger.log("Printing all patients who have been treated");
            hospitalSystem.allTreatedPatientsReport();
        }
        else if(command_number == 6){
            logger.log("Treating all patients in Triage List.");
            hospitalSystem.treatAllPatients();
        }
        else if(command_number == 7){
            logger.log("Listing Patients by Doctors.");
            hospitalSystem.printPatientByDoctor();
        }
        else if(command_number == 8){
            logger.log("Adding File to System.");
            string file_name;
            cout << "Enter file name with directory: ";
            cin >> file_name;
            hospitalSystem.addPatientsFromAFile(file_name);
        }else if(command_number == 9){
            logger.log("Switching into Debug Mode");
            cout<<"Debug Mode"<<endl;
            Logger::getInstance().debug(true);
        }
        else if(command_number == 10){
            cout<<"Normal Mode"<<endl;
            Logger::getInstance().debug(false);
            logger.log("Switching out of Debug Mode");
        }
        else if (command_number == 11) {
                logger.log("Log: Exit code 0");
                cout<<"Exiting Hospital Console App, Goodbye :)"<<endl;
        }
        else {
            //checks if they put an int greater than 11 or less than 0
            cout << "Incorrect Input, please put a number 0-11" << endl;
        }
    }while(command_number != 11);
    return 0;
}
