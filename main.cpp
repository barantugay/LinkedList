#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
	LinkedList* linkedlist = new LinkedList(1);
	linkedlist->addFirstNode(0);
	linkedlist->appendNode(2);
	linkedlist->appendNode(3);
	linkedlist->appendNode(4);
	//linkedlist->delLastNode();
	//linkedlist->delFirstNode();
	//linkedlist->setValue(16, 0);
	//linkedlist->insertNode(16, 3);
	//linkedlist->delNode(3);
	//linkedlist->delAllNode();

	/*Node* node = linkedlist->getIndex(1);
	if (node != nullptr) {
		cout << node->value << endl;
	}
	else {
		cout << "There is no element\n";
	}*/
	

	linkedlist->printList();

	delete linkedlist;
	cout << endl;
	return 0;
}