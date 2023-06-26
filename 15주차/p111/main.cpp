#include "Stack.h"

using namespace std;

int main() {

// case 1 (입력 1일 때 실행되는 코드 예)
    Stack<char> stack1(1);
    stack1.push('a');
    stack1.pop();
    stack1.pop();
    stack1.print();
// ==> 출력 예: main.cpp:[라인번호]:Exception: Stack is empty

//case 2
    Stack<char> stack2(1);
    stack2.push('a');
    stack2.push('b');
    stack2.print();
//==> 출력 예: main.cpp:[라인번호]:Exception: Stack is full!

//case 3

    Stack<int> stack3(1);
    stack3.push(1);
    stack3.pop();
    stack3.push(2);
    stack3.print();      // 2 출력됨
    stack3.pop();
//==> 출력 예: 2

//case 4
    Stack<int> stack4(2);
    stack4.push(1); stack4.push(2);
    stack4.pop();    stack4.pop();
    stack4.push(3);
    stack4.print();    // 3 출력됨
//==> 출력 예: 3

}