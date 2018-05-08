#ifndef AvlTree_h
#define AvlTree_h

#include <iostream>
#include "DoubList.h"

using namespace std;

/*Node Struct Creation*/
struct Avlnode {
	string data;		//data
						//when comparing Strings A-Z Z being highest A being lowest
						//Linked list that carriers the same isntance
	DoubList words;

	int height = 0;		//node height
	struct Avlnode *right;
	struct Avlnode *left;
};

class AvlTree {
private:
	Avlnode * root;
	//rotations S= single D= Double
	void S_Rotate_Left(Avlnode **T);
	void S_Rotate_Right(Avlnode **T);
	void D_Rotate_Left(Avlnode **T);
	void D_Rotate_Right(Avlnode **T);
	void calculate_height(Avlnode *T);
	void preOrder(Avlnode * print);
	void PostOrderPrint(Avlnode * T);
	void inOrder(Avlnode *T);
	void insert(Avlnode **T, string word, int line);
	void remove(Avlnode *T, string word);
	//void make_empty(Avlnode *T);
	int node_height(Avlnode *T);
	Avlnode *find_min(Avlnode *T);
	Avlnode *find_max(Avlnode *T);
	Avlnode *find(Avlnode *T, string word);
	void frequency(Avlnode * T);
	int max(int a, int b);

public:
	AvlTree();
	// ~AvlTree();
	void printPostOrder();
	void printPreOrder();
	void printInOrder();
	void insert(string word, int line);
	int wordFreq(string word);
	void printwords();
};

#endif

