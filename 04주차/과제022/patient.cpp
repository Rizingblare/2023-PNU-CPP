#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <algorithm>

#include "patient.h"

using namespace std;

void PrintPatientInfo (vector <unique_ptr<PatientInfo>> &vec){
    sort(vec.begin(), vec.end(), [](unique_ptr<PatientInfo> &a, unique_ptr<PatientInfo> &b){return a->BMI > b->BMI;});

    cout << "Information for all patients:" << endl;
    for (auto &i : vec) {
        cout << fixed << setprecision(2) << i->name << "  " << i->age << "  " << i->weight << "  " << i->height << "  " << i->BMI <<endl;
    }

}

void FindPatientWithName(vector<unique_ptr<PatientInfo>> &vec){
    cout << "Enter the name: ";

    string name;
    cin >> name;

    auto result = find_if(vec.begin(), vec.end(), [name](const unique_ptr<PatientInfo> &a) {return a->name == name;});

    if (result == vec.end())
        cout << "There's no patient by that name." << endl;
    else {
        cout << "Patient found:" << endl;
        cout << (*result)->name << "  " << (*result)->age << "  " << (*result)->weight << "  " << (*result)->height << "  " << (*result)->BMI << endl;
    }
}


void GetPatientWithHighBMI(vector<unique_ptr<PatientInfo>> &vec){
    cout << "Enter the BMI threshold:" << endl;

    double threshold;
    cin >> threshold;

    cout << fixed << setprecision(2) << "Patients with BMI more than " << threshold << ":" << endl;

    for_each(vec.begin(), vec.end(),
        [threshold](const unique_ptr<PatientInfo> &a) {
        if((a->BMI) > threshold)
            cout << a->name << "  " << a->age << "  " << a->weight << "  " << a->height << "  " << a->BMI << endl;
    });
}

void DeletePatientWithLowBMI(vector<unique_ptr<PatientInfo>> &vec){
    cout << "Enter the BMI threshold:" << endl;

    int threshold;
    cin >> threshold;

    vec.erase(remove_if(vec.begin(), vec.end(),
             [threshold](const unique_ptr<PatientInfo> &a) { return a->BMI < threshold;}),vec.end());

    PrintPatientInfo(vec);
}