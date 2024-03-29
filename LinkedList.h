#pragma once
#include "Node.h"

class LinkedList {
private:
	Node* headPtr; // poins to the head of LList  
	int size; // size of linked linked list 
public:
	// NO setters 

	// getters
	Node* getHeadPtr() const { return headPtr; }
	int getSize() const { return size; }

	// toString
	// constructor
	LinkedList() {
		headPtr = nullptr;
		size = 0;
	}
	// Destructor 
	~LinkedList() {
		cout << "Linked List Address = " << this << " Linked List DESTRUCTOR CALLED\n";
		Node* ptr1 = headPtr;

		while (ptr1 != nullptr) {
			Node* ptr2 = ptr1->next; // traversing through linked list 
			delete ptr1;
			ptr1 = ptr2;
		}
	}
	// 1st Insert
	void insertFirst(int dataVal) {
		Node* newPtr = new Node(dataVal);
		newPtr->next = headPtr;
		headPtr = newPtr;
		size++;
	}
	// toString
	string toString() {
		stringstream sout;
		sout << "\n\n==================== LINKED LIST DATA ===================\n";
		sout << "LinkedList Address = " << this
			<< " LinkedList [ Size = " << getSize() << ", headPtr = " << getHeadPtr() << "]";
		Node* nPtr = headPtr;
		sout << "\n\n==================== NODE DATA ===================\n";
		while (nPtr != nullptr) {
			sout << nPtr->toString() << endl;
			nPtr = nPtr->next;
		}
		return sout.str();
	}


	// find 
	Node* find(int dataVal) {
		Node* nodePtr = headPtr;

		while (nodePtr != nullptr) {
			if (nodePtr->data == dataVal) {
				return nodePtr;
			}
			else {
				nodePtr = nodePtr->next;
			}
		}
		return nullptr;
	}

	bool erase(int dataVal) {
		// case1 - list is empty 
		if (headPtr == nullptr) {
			return false; 
		}

		// case2 - node to be removed is the first node 
		if (headPtr->data == dataVal) {
			Node* nodePtr = headPtr; 
			headPtr = headPtr->next; 
			delete nodePtr; 
			size--; 
			return true; 
		}
		// case3 - reconnecting trailing node with following node 
		Node* visitingPtr = headPtr; //current / front 
		Node* trailingPtr = nullptr; // previosu / back
		while (visitingPtr != nullptr) {

			if (visitingPtr->data == dataVal) {
				trailingPtr->next = visitingPtr->next; 
				size--; 
				delete visitingPtr; 
				return true; 
			}
			else {
				trailingPtr = visitingPtr; 
				visitingPtr = visitingPtr->next; 
			}
		}
		return false; 
	}

	// update 
	bool update(int oldValue, int newVal) {
		Node* p = find(oldValue); 
		if (p == nullptr) return false; 
		p->data = newVal; 
		return true; 
	}
};

