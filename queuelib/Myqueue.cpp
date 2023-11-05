#include <math.h>

#include "Myqueue.h"

template<class T>
TQueue<T>::TQueue(int n = 0) {
	if (n < 0) {
		throw "size is less then 0";
	}
	if (n == 0) {
		this->ind = -1;
	}
	this->size = n;
	this->ind = 0;
	this->end = n - 1;
	mas = new T[this->size];
	this->count = n;
}
template<class T>
TQueue<T>::TQueue(TQueue<T>& q) {
	delete[] this->mas;
	this->size = q.size;
	this->mas = new T[this->size];
	this->ind = q.ind;
	this->end = q.end;
	this->count = q.count;
	for (size_t i = 0; i < size; i++) {
		mas[i] = q.mas[i];
	}
}
template<class T>
void TQueue<T>::Push(T a) {
	if (IsFull()) {
		throw "stack is full";
	}
	if (this->end >= this->size - 1) {
		this->end = 0;
		this->mas[end] = a;
		//this->end++;
		this->count++;
	}
	else{
		this->end++;
		this->mas[end] = a;
		this->count++;
	}
	
}
template<class T>
T TQueue<T>::Get() {
	if (IsEmpty()) {
		throw "stack is empty";
	}
	return this->mas[ind];
}
template<class T>
TQueue<T>::~TQueue() {
	this->ind = -1;
	this->end = 0;
	this->count = 0;
	delete[] this->mas;
	this->size = 0;
}

template<class T>
bool TQueue<T>::IsFull() {
	if (this->count == this->size) {
		return true;
	}
	return false;
}
template<class T>
bool TQueue<T>::IsEmpty() {
	if (this->count == 0) {
		return true;
	}
	return false;
}
template<class T>
TQueue<T> TQueue<T>::GetBot() {
	if (IsEmpty()) {
		throw "queue is empty";
	}
	if (this->ind > this->size - 1) {
		this->ind = 0;
	}

	this->count--;
	ind++;
	cout << this->mas[ind - 1] << " " << " - Extracted element from bottom" << endl;
	this->mas[ind - 1] = -1;
	return *this;
}
template<class T>
T TQueue<T>::GetBot_for_tests() {
	if (IsEmpty()) {
		throw "queue is empty";
	}
	if (this->ind > this->size - 1) {
		this->ind = 0;
	}

	this->count--;
	ind++;
	return this->mas[ind - 1];
}
