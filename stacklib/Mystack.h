#pragma once
#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>

using namespace std;
template <class T>
class TStack {
protected:
    int size;
    int top;
    T* mas;
public:
    TStack(int n = 0);
    TStack(TStack<T>& stack);
    ~TStack();
    void Push(T a);
    T Get();
    T TopView();
    int GetSize();
    int GetTop();
    bool IsFull();
    bool IsEmpty();

    TStack& operator=(const TStack<T>& stack);
    friend ostream& operator << (ostream& ostr, const TStack<T> &A) {
        cout << "Your stack is ";
        for (size_t i = 0; i < A.top; i++) {
            ostr << A.mas[i] << " ";
        }
        ostr << endl;
        return ostr;
    }
    friend istream& operator >> (istream& istr, TStack<T> &A) {
        for (int i = 0; i < A.top; i++) {
            istr >> A.mas[i];
        }
        return istr;
    }

};
#endif