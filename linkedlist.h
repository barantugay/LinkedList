#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value);
	
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int count = 0;
public:
	LinkedList(int value);
	~LinkedList();

	void printList();
	void appendNode(int value);
	void delLastNode();
	void addFirstNode(int value);
	void delFirstNode();
	Node* getIndex(int index);
	bool setValue(int newValue, int index);
	bool insertNode(int value, int index);
	bool delNode(int index);
	void delAllNode();

};