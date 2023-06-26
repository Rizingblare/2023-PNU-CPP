#ifndef EXCEPTION_STACK_H
#define EXCEPTION_STACK_H

#include "StackException.h"
#include <iostream>

template <typename T>
class Stack {
public:
    Stack(int sz) ;                    //객체 초기화 및 필요한 자원을 획득하시오
    ~Stack() noexcept ;             //사용한 자원을 해제하시오

    // 복사 생성자와 복사 대입 연산자를 삭제하시오
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(T c) {
        if (top < size)
            s[top++] = c;
        else throw StackException("Stack is full!",__FILE__, __LINE__);
    }    //예외 발생 시 StackException 던지시오

    T pop() {
        if (top == 0)
            throw StackException("Stack is empty!",__FILE__, __LINE__);
        else {
            T r = s[--top];
            return r;
        }
    } //예외 발생 시 StackException 던지시오

    void print() const ;     //스택의 모든 원소를 '\n' 으로 구분하여 출력하시오

private:
    int size = 0;   int top = 0;
    T* s = nullptr;

} ;

template <typename T>
Stack<T>::Stack(int sz) {
    s = new T [size=sz];
}

template <typename T>
Stack<T>::~Stack() noexcept {
    if (s) delete[] s;
}

template <typename T>
void Stack<T>::print() const {
    for (int i = 0; i < top; i++) {
        std::cout << s[i] << std::endl;
    }
}

#endif //EXCEPTION_STACK_H