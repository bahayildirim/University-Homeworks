#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
class ConvertableLinkedList {
	private:
		LinkedList<T> list;
		LLNode<LinkedList<T>> current;
		void convertToCircular() {
			list.getTail()->next = list.getHead();
		}
		void convertToSingly() {
			list.getTail()->next = NULL;
		}
	public:
		void insertToLast(const T& val) {
			this->list.insertLast(val);
		}
		void insertAtIndex(const T& val, int i) {
			this->list.insertAt(i, val);
		}
		int findNext(const T& val) {
			this->convertToCircular();
			LLNode<int>* result = this->list.search(val);
			this->convertToSingly();
			return result->;
		}
		void display() {
			if(this->list.isEmpty()) {
				return;
			}
			cout << this->list;
		}
};

int main() {
	int option, value, index;
	ConvertableLinkedList<int> list;
	cout << "Case 1-Insert value to last" << endl;
	cout << "Case 2-Insert value to the Index" << endl;
	cout << "Case 3-Find the value" << endl;
	cout << "Case 4-Display" << endl;
	cout << "Case 5-Exit" << endl << endl;
	while(true) {
		cout << "Select a case: ";
		cin >> option;
		switch(option){
			case 1:
				cout << "Enter the value: ";
				cin >> value;
				list.insertToLast(value);
				break;
				
			case 2:                   
				cout << "Enter the value: ";
				cin >> value;
				cout << "Enter the index: ";
				cin >> index;
				list.insertAtIndex(value, index);
				break;
				
			case 3:
				cout << "Enter the value you want to search: ";
				cin >> value;
				cout << "Your value is found in index " << list.findNext(value) << endl;
				break;
				
			case 4:
				list.display();
				cout << endl;
				break;
				
			case 5:
				cout << "Goodbye";
				return 0;
		}
	}
}