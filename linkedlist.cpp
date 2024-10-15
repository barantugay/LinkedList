#include "linkedlist.h"

Node::Node(int value){
		this->value = value;
}

LinkedList::LinkedList(int value) {
	Node* newNode = new Node(value);
	head = newNode;
	tail = newNode;
	count = 1;

	
}

LinkedList::~LinkedList() {
	Node* tmp = head;
	while (head) {
		head = head->next;
		delete tmp;
		tmp = head;
		count--;
	}
}

void LinkedList::printList() {
	while (head) {
		cout << head->value << "  ";
		head = head->next;
	}
	cout << endl;
}

void LinkedList::appendNode(int value) {
	Node* newNode = new Node(value);
	if (count == 0) {
		head = newNode;
		tail = newNode;
		count = 1;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
		count++;
	}
}

void LinkedList::delLastNode() {

	if (count == 0) {
		cout << "\nThere is no element\n";
	}
	else if (count >= 1) {
		Node* tmp = head;
		if (count == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			while (tmp->next != tail) {
				tmp = tmp->next;
			}
			delete tail;
			tmp->next = nullptr;
			tail = tmp;
		}
		count--;
	}
}

void LinkedList::addFirstNode(int value) {
	Node* newNode = new Node(value);
	if (count == 0) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}

	count++;
}

void LinkedList::delFirstNode() {
	if (count == 0) {
		cout << "\nThere is no element\n";
	}
	else {
		Node* tmp = head;
		if (count == 1) {
			delete tmp;
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
			delete tmp;
		}
		count--;
	}
}

Node* LinkedList::getIndex(int index) {
	int num = 0;
	Node* tmp = head;
	while (tmp) {
		if (num == index) {
			return tmp;
		}
		else if (num < 0) {
			break;
		}
		tmp = tmp->next;
		num++;
		
	}
	return NULL;
}

bool LinkedList::setValue(int newValue, int index) {
	Node* tmp = getIndex(index);
	if (tmp) {
		tmp->value = newValue;
		return true;
	}
	else {
		return false;
	}
}

bool LinkedList::insertNode(int value, int index) {
	if (index == 0) {
		LinkedList::addFirstNode(value);
		return true;
	}
	else if (index == count) {
		LinkedList::appendNode(value);
		return true;
	}
	else
	{
		Node* tmp = getIndex(index - 1);
		Node* newNode = new Node(value);
		if (tmp) {
			newNode->next = tmp->next;
			tmp->next = newNode;
			return true;
		}
	}
	return false;
}

bool LinkedList::delNode(int index) {
	if (index == 0) {
		LinkedList::delFirstNode();
		return true;
	}
	else if (index == count-1) {
		LinkedList::delLastNode();
		return true;
	}
	else
	{
		Node* tmp1 = getIndex(index - 1);
		Node* tmp2 = getIndex(index);
		if (tmp2) {
			tmp1->next = tmp2->next;
			delete tmp2;
			return true;
		}
	}
	return false;
}

void LinkedList::delAllNode() {
	while (head) {
		LinkedList::delFirstNode();
	}
}