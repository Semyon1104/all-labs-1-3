#ifndef _MY_VECTOR_
#define _MY_VECTOR_

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

    //��������� ����� � ������

    bool IsFull();
    bool IsEmpty();

    TStack& operator=(const TStack<T>& stack);
};


//template <class T1>
//ostream& operator<< (ostream& ostr, const Vector<T1> &A) {
//  for (int i = 0; i < A.length; i++) {
//    ostr << A.x[i] << endl;
//  }
//  return ostr;
//}
//
//template <class T1>
//istream& operator >> (istream& istr, Vector<T1> &A) {
//  for (int i = 0; i < A.length; i++) {
//    istr >> A.x[i];
//  }
//  return istr;
//}

#endif