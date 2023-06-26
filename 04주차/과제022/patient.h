#include <string>
#include <vector>
#include <memory>

using namespace std;

struct PatientInfo {
    string name;
    int age;
    double weight;
    double height;
    double BMI;
};

void PrintPatientInfo (vector<unique_ptr<PatientInfo>> &);

void FindPatientWithName(vector<unique_ptr<PatientInfo>> &);

void GetPatientWithHighBMI(vector<unique_ptr<PatientInfo>> &);

void DeletePatientWithLowBMI(vector<unique_ptr<PatientInfo>> &);