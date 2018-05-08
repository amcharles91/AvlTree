#ifndef DoubList_h
#define DoubList_h

#include <cstdlib>
#include <iostream>

using namespace std;

enum dataType
{
	INT,
	String
};
/*Node Struct Creation*/
struct node {
	bool pointer = false;
	bool word = false;
	dataType type;
	int data = NULL;      //Integer value
	void* voidPointy = NULL;  //Pointer Value
	string werd = "";
	node* next;		//Next pointer
	node* previous;	//Previous
};

class DoubList {
private:
	node * begin; // Front
	node *end; // Rear
	int size;

public:
	DoubList();//initialize private variables
	~DoubList();

	void insert_front(int);
	void insert_front(string);
	void insert_front(void*, dataType);

	void insert_rear(int);
	void insert_rear(string);
	void insert_rear(void*, dataType);

	int remove_front_i();
	string remove_front_s();
	void* remove_front_p();

	int remove_rear_i();
	string remove_rear_s();
	void* remove_rear_p();

	void remove_rear();
	void remove_front();

	void printList();
	int getSize();
	void makeEmpty();
	bool isEmpty();
};
#endif