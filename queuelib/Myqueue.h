#pragma once
#ifndef _MY_QUEUE_
#define _MY_QUEUE_

#include <iostream>

using namespace std;
template <class T>
class TQueue{
protected:
    int size;
    int ind;
    int end;
    int count;
    T* mas;

public:
    TQueue(int n = 0);
    TQueue(TQueue <T>& q);
    ~TQueue();
    TQueue GetBot();
    void Push(T a);
    T Get();

    bool IsFull();
    bool IsEmpty();

    friend ostream& operator << (ostream& ostr, const TQueue<T>& A) {
        if (A.count == 0) {
            throw "queue is empty";
        }
        cout << "Your queue is ";
        if (A.ind < A.end){
            for (int i = A.ind; i <= A.end; i++) {
                if (A.mas[i] == -1) {
                    ostr << " " << " ";
                }
                else {
                    ostr << A.mas[i] << " ";
                }
            }
        }
        if (A.ind > A.end) {
            for (int i = 0; i < A.size; i++) {
                if (A.mas[i] == -1) {
                    ostr <<" " << " ";
                }
                else{ 
                    ostr << A.mas[i] << " "; 
                }
                
            }
        }
        if (A.ind == A.end) {
            for (int i = 0; i < A.size; i++) {
                if (A.mas[i] == -1) {
                    ostr << " " << " ";
                }
                else {
                    ostr << A.mas[i] << " ";
                }
            }
        }
        
        ostr << endl;
        return ostr;
    }
    friend istream& operator >> (istream& istr, TQueue<T>& A) {
        for (int i = 0; i < A.count; i++) {
            istr >> A.mas[i];
        }
        return istr;
    }
};

#endif