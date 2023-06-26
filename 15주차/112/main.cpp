#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // ifstream, ofstream 은 자동으로 연 파일을 닫는다.
    ifstream fin;
    fin.exceptions(ios_base::failbit | ios_base::badbit);

    try {
        fin.open("config.ini"); //default   is   ios_base::in
    } catch (const ios::failure &e) {cerr << e.what() << endl;}


    ofstream fout;
    fout.exceptions(ios_base::failbit | ios_base::badbit);
    try {
        fout.open("config/config.ini");   //default   is   ios_base::out
        fout << "This is an example for the exception in C++!" << endl;
    } catch (const ios::failure &e) {cerr << e.what() << endl;}

    return 0;
}