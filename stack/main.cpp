#include "C:\сема\1курс\основы проги\lab stack_queue\all-labs-1-3\stacklib\Mystack.cpp"
#include "C:\сема\1курс\основы проги\lab stack_queue\all-labs-1-3\queuelib\Myqueue.cpp"
#include <iostream>
using namespace std;
void start() {
	cout << "Press 1, to create Stack" << endl;
	cout << "Press 2, to create Queue" << endl;
}
void Stack() {
	cout << "Press 1, to find out the size of stack" << endl;
	cout << "Press 2, to find out the element in top of stack" << endl;
	cout << "Press 3, to extract the element" << endl;
	cout << "Press 4, to push the element" << endl;
}
void Queue() {
	cout << "Press 1, to extract the element" << endl;
	cout << "Press 2, to push the element in queue" << endl;
}
int main()
{
	bool flag = true;
	while (flag) {
		int a, size;
		start();
		cin >> a;
		if (a == 1) {
			cout << "input size of stack" << endl;
			cin >> size;
			TStack<int> stack1(size);
			cin >> stack1;
			cout << stack1 << endl;
			bool flag1 = true;
			while (flag1) {
				Stack();
				cin >> a;
				switch (a) {
				case 1:
					cout << "Size of stack - " << stack1.GetSize() << endl;
					break;
				case 2:
					cout << "element in top of stack - " << stack1.TopView() << endl;
					break;
				case 3:
					try { cout << "extracted element in top of stack - " << stack1.GetTop() << endl << stack1; }
					catch (...) {
						cout << "stack is empty" << endl;
					}
					break;
				case 4:
					cout << "Input element to push in stack - ";
					int el;
					cin >> el;
					try { stack1.Push(el); }
					catch (...) {
						cout << "stack is full" << endl;
					}
					cout << stack1;
					break;
				default:
					flag1 = false;
					break;
				}
			}

		}
		if (a == 2) {
			cout << "input size of queue" << endl;
			cin >> size;
			TQueue<int> queue1(size);
			cin >> queue1;
			cout << queue1 << endl;
			bool flag1 = true;
			while (flag1) {
				Queue();
				cin >> a;
				switch (a) {
				case 1:
					queue1.GetBot();
					try {
						cout << queue1 << endl;
					}
					catch (...) {
						cout << "queue is empty" << endl;
					}
					break;
				case 2:
					cout << "Input element to push in stack - ";
					int el;
					cin >> el;
					try { queue1.Push(el); }
					catch (...) {
						cout << "stack is full" << endl;
					}
					cout << queue1;
					break;
				default:
					flag1 = false;
					break;
				}
			}
		}
		/*if (a == 1) {
			cout << "input size of stack"<<endl;
			cin >> size;
			TStack<int> stack1(size);
			cin>> stack1;
			cout << stack1<<endl;
			cout<<"Extract element from top - "<<stack1.GetTop() << endl;
			cout << stack1 << endl;
			cout << "Input element to push in stack - ";
			int el;
			cin >> el;
			stack1.Push(el);
			cout << stack1 << endl;
			cout << "size of stack - " << stack1.GetSize() << endl;
			cout << "Extract element from top - " << stack1.GetTop() << endl;
			cout << stack1 << endl;
			cout << "size of stack - " << stack1.GetSize() << endl;
			cout << "Extract element from top - " << stack1.GetTop() << endl;
			cout << stack1 << endl;
			cout << "size of stack - " << stack1.GetSize() << endl;
			cout << "Input element to push in stack - ";
			cin >> el;
			stack1.Push(el);
			cout << stack1 << endl;
		}
		if (a == 2) {
			cout << "input size of queue" << endl;
			cin >> size;
			TQueue<int> queue1(size);
			cin >> queue1;
			cout << queue1 << endl;
			queue1.GetBot();
			cout << queue1 << endl;
			cout << "Input element to push in queue - ";
			int el;
			cin >> el;
			queue1.Push(el);
			cout << queue1 << endl;
			queue1.GetBot();
			cout << queue1 << endl;
			queue1.GetBot();
			cout << queue1 << endl;
			cout << "Input element to push in queue - ";
			cin >> el;
			queue1.Push(el);
			cout << queue1 << endl;
		}
		else {
			break;
		}*/

	}

}
