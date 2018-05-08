#include <cstdlib>
#include<iostream>
#include <string>
using namespace std;

#include "DoubList.h"

DoubList::DoubList() {
	this->begin = nullptr;  //Makes front and Rear points Null
	this->end = nullptr;
	this->size = 0;
};

DoubList::~DoubList() {
}

/* Inserts the node into the front
First checks if there is any nodes in the list
which if there is, align the links correctly
and if not creates a new node that connects the front
and back to that node*/

void DoubList::insert_front(int data) {
	//Creates tempoary node
	node *q = new node;
	//If empty creates the first node
	if (begin == nullptr) {
		q->next = nullptr;		//constraint
		q->previous = nullptr;	//Links front and rear point to the new node
		begin = q;
		end = q;
	}
	else {
		//If not empty creates a node and inserts it to the front
		q->next = begin;		//makes q point to front which points to the first node
		begin->previous = q;	//makes the now 2nd node point previous to q
		begin = q;				//makes begin point to q which is now in front spot
	}
	q->data = data;				//inserts data to the new node
	q->pointer = false;			//identifies an int node
	q->word = false;			//Identifies a pointer node
	size++;
}
void DoubList::insert_front(string data)
{
	//Creates tempoary node
	node *q = new node;
	//If empty creates the first node
	if (begin == nullptr) {
		q->next = nullptr;		//constraint
		q->previous = nullptr;	//Links front and rear point to the new node
		begin = q;
		end = q;
	}
	else {
		//If not empty creates a node and inserts it to the front
		q->next = begin;		//makes q point to front which points to the first node
		begin->previous = q;	//makes the now 2nd node point previous to q
		begin = q;				//makes begin point to q which is now in front spot
	}
	q->werd = data;				//inserts data to the new node
	q->pointer = false;			//identifies an int node
	q->word = true;			//Identifies a pointer node
	size++;
}
;

void DoubList::insert_front(void* data, dataType type) {
	//Creates tempoary node
	node *q = new node; //If empty creates the first node
	if (begin == nullptr) {
		q->next = nullptr;		//constraint
		q->previous = nullptr;	//Links front and rear point to the new node
		begin = q;
		end = q;
	}
	else {
		//If not empty creates a node and inserts it to the front
		q->next = begin;		//makes q point to front which points to the first node
		begin->previous = q;	//makes the now 2nd node point previous to q
		begin = q;				//makes begin point to q which is now in front spot
	}
	q->voidPointy = data;		//inserts data to the new node
	q->type = type;				//Flag for type of data
	q->pointer = true;			//Identifies a pointer node
	q->word = false;			//Identifies a pointer node
	size++;
};
/*Inserts a node at the rear of the list*/

void DoubList::insert_rear(int data) {
	node *p = new node;  //Create the node
	p->previous = nullptr; //makes front and back null and recieve the data
	p->data = data;
	p->next = nullptr;

	if (begin == nullptr) { //if there is no node create one
		begin = p;
		end = p;
		p->next = nullptr;
	}
	else {  //If ther eis more then one, insert at rear
		end->next = p;  //makes the next become the new node
		p->previous = end; //make sure the new node points back to the old
		end = p;		//now the end/ rear pointer is pointing at our node
		end->next = nullptr;  //constraint to reach the end
	}
	end->data = data; //add's the data to the newly created node
	end->pointer = false; //Identifies as an int
	end->word = false;			//Identifies a pointer node
	size++;
}
void DoubList::insert_rear(string data)
{
	node *p = new node;  //Create the node
	p->previous = nullptr; //makes front and back null and recieve the data
	p->werd = data;
	p->next = nullptr;

	if (begin == nullptr) { //if there is no node create one
		begin = p;
		end = p;
		p->next = nullptr;
	}
	else {  //If ther eis more then one, insert at rear
		end->next = p;  //makes the next become the new node
		p->previous = end; //make sure the new node points back to the old
		end = p;		//now the end/ rear pointer is pointing at our node
		end->next = nullptr;  //constraint to reach the end
	}
	end->werd = data; //add's the data to the newly created node
	end->pointer = false; //Identifies as an int
	end->word = true;			//Identifies a pointer node
	size++;
}
;

void DoubList::insert_rear(void* data, dataType type) {
	node *p = new node;  //Create the node
	p->previous = nullptr; //makes front and back null and recieve the data
	p->voidPointy = data;
	p->next = nullptr;

	if (begin == nullptr) { //if there is no node create one
		begin = p;
		end = p;
		p->next = nullptr;
	}
	else {  //If there is more then one, insert at rear
		end->next = p;  //makes the next become the new node
		p->previous = end; //make sure the new node points back to the old
		end = p;		//now the end/ rear pointer is pointing at our node
		p->next = nullptr;  //constraint to reach the end
	}
	end->voidPointy = data; //add's the data to the newly created node
	end->type = type;	//flag for type of data
	end->pointer = true; //Marks a pointer node
	end->word = false;			//Identifies a pointer node
	size++;
};

/*Removes a node that is in the front*/

int DoubList::remove_front_i() {
	int returnValue = NULL;
	node *p = nullptr;  //creates node pointer
	if (begin == nullptr) {
		//do nothing because there is no nodes
	}
	else if (begin == end) { //Only 1 node
		p = begin;			//p is pointing to the only node
		begin = nullptr;	//make the front and rear pointers null
		end = nullptr;
		p->next = nullptr;  //make sure p next is null
		returnValue = p->data; //put the value into returnValue
		size--;
	}
	else {						//general case when there is more then 1 node;
		p = begin;				//node p is pointing to the first node
		begin = p->next;		//make the new front node the next node in line
		returnValue = p->data;	//make the data in the front node assigned to returnValue
		p->next = nullptr;		//make sure to null the front of the node
		size--;
	}

	delete p;					//delete the node
	return returnValue;			//returns the data
}
string DoubList::remove_front_s()
{
	string returnValue = "";
	node *p = nullptr;  //creates node pointer
	if (begin == nullptr) {
		//do nothing because there is no nodes
	}
	else if (begin == end) { //Only 1 node
		p = begin;			//p is pointing to the only node
		begin = nullptr;	//make the front and rear pointers null
		end = nullptr;
		p->next = nullptr;  //make sure p next is null
		returnValue = p->werd; //put the value into returnValue
		size--;
	}
	else {						//general case when there is more then 1 node;
		p = begin;				//node p is pointing to the first node
		begin = p->next;		//make the new front node the next node in line
		returnValue = p->werd;	//make the data in the front node assigned to returnValue
		p->next = nullptr;		//make sure to null the front of the node
		size--;
	}

	delete p;					//delete the node
	return returnValue;			//returns the data
}
;

void* DoubList::remove_front_p() {
	void* returnValue = NULL;
	node *p = nullptr;  //creates node pointer
	if (begin == nullptr) {
		//do nothing because there is no nodes
	}
	else if (begin == end) { //Only 1 node
		p = begin;			//p is pointing to the only node
		begin = nullptr;	//make the front and rear pointers null
		end = nullptr;
		p->next = nullptr;  //make sure p next is null
		returnValue = p->voidPointy; //put the value into returnValue
		size--;
	}
	else {						//general case when there is more then 1 node;
		p = begin;				//node p is pointing to the first node
		begin = p->next;		//make the new front node the next node in line
		returnValue = p->voidPointy;	//make the data in the front node assigned to returnValue
		p->next = nullptr;		//make sure to null the front of the node
		size--;
	}

	delete p;					//delete the node
	return returnValue;			//returns the data
};

/*Removes a node from the rear*/

int DoubList::remove_rear_i() {
	node *h = nullptr;			//temporary pointer node to be used
	int returnValue = NULL;		//returnValue placeholder
	if (begin == nullptr) {
		//do nothing
	}
	else if (begin == end) {	//only 1 node available
		h = begin;
		begin = end = nullptr;	//nulls front and end
		returnValue = h->data;	//store the data
		h->next = h->previous = nullptr;//nulls next and previous on node p
		size--;
		delete h;
	}
	else {						//more then 1 node
		h = end;				//makes p point to last node
		end = end->previous;	//assign the new end to the previous node
		end->next = nullptr;	//end next becomes null
		returnValue = h->data;	//store the value
		h->next = h->previous = nullptr;	//Make p next and previous both null
		size--;
		delete h;
	}							//returns p to memory;
	return returnValue;			//returns the data
}
string DoubList::remove_rear_s()
{
	node *h = nullptr;			//temporary pointer node to be used
	string returnValue = "";		//returnValue placeholder
	if (begin == nullptr) {
		//do nothing
	}
	else if (begin == end) {	//only 1 node available
		h = begin;
		begin = end = nullptr;	//nulls front and end
		returnValue = h->werd;	//store the data
		h->next = h->previous = nullptr;//nulls next and previous on node p
		size--;
		delete h;
	}
	else {						//more then 1 node
		h = end;				//makes p point to last node
		end = end->previous;	//assign the new end to the previous node
		end->next = nullptr;	//end next becomes null
		returnValue = h->werd;	//store the value
		h->next = h->previous = nullptr;	//Make p next and previous both null
		size--;
		delete h;
	}							//returns p to memory;
	return returnValue;			//returns the data
}
;

void* DoubList::remove_rear_p() {
	node *p = nullptr;					//temporary pointer to be used
	void*returnValue = nullptr;			//returnValue placeholder
	if (begin == nullptr) {
		//do nothing
	}

	else if (begin == end) {	//only 1 node available
		p = begin;
		begin = end = nullptr;	//nulls front and end
		returnValue = p->voidPointy;	//store the data
		p->next = p->previous = nullptr;//nulls next and previous on node p
		size--;
	}
	else {						//more then 1 node
		p = end;				//makes p point to last node
		end = p->previous;	//assign the new end to the previous node
		end->next = nullptr;	//end next becomes null
		returnValue = p->voidPointy;	//store the value
		p->next = p->previous = nullptr;	//Make p next and previous both null
		size--;
	}
	delete p;					//returns p to memory;
	return returnValue;			//returns the data
};

void DoubList::remove_front() {
	node *f;
	f = begin;

	if (begin == nullptr) {
		return;
	};
	if (f->pointer) {			//If identified as a pointer
		remove_front_p();		//removes front pointer node
	}
	else if (f->word) {			//if it is a string node
		remove_front_s();
	}
	else {
		remove_front_i();		//removes front int node
	}
	f->next = f->previous = nullptr;
	//f->data = NULL;				//null's data
	//f->voidPointy = NULL;		//null's voidPointy
	//f->werd = "";				//null's string
	f = nullptr;
};

void DoubList::remove_rear() {
	node *r;
	r = end;
	if (begin == nullptr) {
		return;
	};
	if (r->pointer) {			//If identified as a pointer
		remove_rear_p();		//removes front pointer node
	}
	else if (r->word) {			//if it is a string node
		remove_rear_s();
	}
	else {
		remove_rear_i();		//removes front int node
	}
	r->next = r->previous = nullptr;
	//r->data = NULL;				//null's data
	//r->voidPointy = NULL;		//null's voidPointy
	//r->werd = "";				//null's string
	r = nullptr;				//null's r completey
};

void DoubList::printList() {
	node* print;
	print = begin;	//points to front node
	cout << "Node List :  ";
	while (print != nullptr) {	//while the pointer is not null
		if ((!(print->pointer)) && (!(print->word))) {
			cout << " " << print->data;	//print out the node data
		}
		else if (print->word) {
			cout << " " << print->werd;
		}
		else {
			int *i;
			string *s;
			switch (print->type) {
			case INT:
				i = (int*)(print->voidPointy);
				cout << " " << *i;
				i = NULL;
				delete i;
				break;
			case String:
				s = (string*)(print->voidPointy);
				cout << " " << *s;
				s = NULL;
				delete s;
				break;
			default:
				break;
			}
		}
		print = print->next;	//assign the next value to pointer to iterate
								//Null's a
								//releases a
	}

	cout << "" << endl;
	print = NULL;				//null print
	delete print;				//release print
}

int DoubList::getSize()
{
	return size;
}

void DoubList::makeEmpty() {
	while (begin != nullptr) {		//Just iterates through all the nodes removing them
		remove_front();
	}
};

bool DoubList::isEmpty() {
	if (begin == nullptr) {				//checks if there's no node
		cout << "It is empty" << endl;
		return true;
	}
	else {
		cout << "It is not empty" << endl;
		return false;
	}
};
