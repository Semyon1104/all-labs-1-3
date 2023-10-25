#include <math.h>

#include "Mystack.h";
template<class T>
TStack<T>::TStack(int n = 0) {
	this->size = n;
	T* mas = new T[this->size];
	this->top = 0;
}
template<class T>
TStack<T>::TStack(TStack<T>& stack) {
	if (stack.IsEmpty()) {
		this->size = 0;
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
