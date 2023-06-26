#include <iostream>
#include <vector>
#include <memory>

#include "patient.h"

using namespace std;

int main(){

    int n;
    cin >> n;

    vector <unique_ptr<PatientInfo>> vec;

    string name;
    int age;
    double weight;
    double height;
    double BMI;

    for (int i = 0; i < n; i++) {
        cin >> name >> age >> weight >> height;
        BMI = weight / ( height * height);

        unique_ptr<PatientInfo> newPatient (new PatientInfo{name, age, weight, height, BMI});
        vec.push_back(move(newPatient));
    }

    PrintPatientInfo(vec);

    FindPatientWithName(vec);

    GetPatientWithHighBMI(vec);

    DeletePatientWithLowBMI(vec);

    return 0;
}