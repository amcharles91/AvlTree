#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

using namespace std;

struct node {
	node * prev;
	int data;
	void *pointerData;
	node * next;

};

class LinkedList {

private:
	node * front;
	node * rear;
	int listSize;
public:
	LinkedList(); // Constructor to initialize private variables
	void printList();//Complete
	int getListSize(); //Complete
	void printListSize(); //Complete
	void insert_front(int data); // Complete
	void insert_front(void *data); //Complete
	void insert_rear(int data); // Complete
	void insert_rear(void *data); //Complete

	int remove_front_i(); // Complete
	void * remove_front_p(); //Complete
	int remove_rear_i(); //Complete
	void * remove_rear_p();  //Complete

	void emptyList();   //Complete
	bool isEmpty();    //Complete
};

#endif












