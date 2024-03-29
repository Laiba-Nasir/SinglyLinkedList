#include "LinkedList.h"

int main(void) {
	LinkedList objLL; 
	objLL.insertFirst(10); 
	objLL.insertFirst(20); 
	objLL.insertFirst(30); 

	cout <<"\n"<< objLL.toString() << endl;

	// nullPtr = false, anything else = true 
	bool found = objLL.find(9999);
	if (found)cout << "\n\n======>>>>>>> I found it!\n"; 
	else
		cout << "\n\n======>>>>>>> I DID NOT found it!\n";
	//cout<<nodePtr->toString()



}