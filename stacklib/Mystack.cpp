#include "Mystack.h"

template<class T>
TStack<T>::TStack(int n = 0) {
	if (n < 0) {
		throw "size is less then 0";
	}
	this->size = n;
	mas = new T[size];
	this->top = n;
}
template<class T>
TStack<T>::TStack(TStack<T>& stack) {
	if (stack.IsEmpty()) {
		this->size = stack.size;
		delete[] this->mas;
		this->top = 0;
	}
	this->size = stack.size;
	this->top = stack.top;
	for (size_t i = 0; i < size; i++) {
		mas[i] = stack.mas[i];
	}
}
template<class T>
void TStack<T>::Push(T a) {
	if (IsFull()) {
		throw "stack is full";
	}
	mas[top] = a;
	top++;
}
template<class T>
T TStack<T>:: Get() {
	if (IsEmpty()) {
		throw "stack is empty";
	}
	this->top--;
	return this->mas[top];
}
template<class T>
TStack<T>::~TStack() {
	this->top = 0;
	delete[] this->mas;
	this->size = 0;
}
template<class T>
T TStack<T>::TopView() {
	if (IsEmpty()) {
		throw "stack is empty";
	}
	this->top--;
	return this->mas[this->top];
}
template<class T>
int TStack<T>::GetSize() {
	if (IsEmpty()) {
		return 0;
	}
	return this->size;
}
template<class T>
int TStack<T>::GetTop() {
	if (IsEmpty()) {
		throw "stack is empty";
	}
	top--;
	return this->mas[top];
}
template<class T>
bool TStack<T>::IsFull() {
	if (this->top == this->size) {
		return true;
	}
	return false;
}
template<class T>
bool TStack<T>::IsEmpty() {
	if (this->top == 0) {
		return true;
	}
	return false;
}
template<class T>
TStack<T>& TStack<T>:: operator=(const TStack<T>& stack) {
	this->size = stack.size;
	this->top = stack.top;
	for (int i = 0; i < size; i++) {
		this->mas[i] = stack.mas[i];
	}
	return *this;
	
}


