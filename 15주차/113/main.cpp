#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

    int N;
    cin >> N;

    stack<int> s;
    string cmd;
    int item;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> item;
            s.push(item);
        }

        else if (cmd == "pop") {
            if (s.empty()) cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }

        else if (cmd == "size") {
            cout << s.size() << endl;
        }

        else if (cmd == "empty") {
            cout << s.empty() << endl;
        }
    }
}