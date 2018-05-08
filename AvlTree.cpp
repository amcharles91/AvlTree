#include <cstdlib>
#include<iostream>
#include "DoubList.h"
#include "AvlTree.h"
#include <string>
using namespace std;

void AvlTree::insert(Avlnode ** T, string word, int line)
{
	if (*T == NULL) {
		*T = new Avlnode;
		(*T)->left = NULL;
		(*T)->right = NULL;
		(*T)->data = word;//the word
		((*T)->words).insert_front(line);//line was found
		if (*T == NULL)
		{
			cout << "Out of Space\n" << endl;
		}
	}
	else if (word < (*T)->data)
	{
		insert((&(*T)->left), word, line);
		if (node_height((*T)->left) - node_height((*T)->right) == 2) {
			if (word < (*T)->left->data) {
				S_Rotate_Left(&(*T));
			}
			else {
				D_Rotate_Left(&(*T));
			}
		}
		else calculate_height(*T);
	}
	else if (word >(*T)->data)//data is greater or equal
	{
		insert((&(*T)->right), word, line);
		if (node_height((*T)->right) - node_height((*T)->left) == 2) {
			if (word > (*T)->right->data) {
				S_Rotate_Right(&(*T));
			}
			else {
				D_Rotate_Right(&(*T));
			}
		}
		else calculate_height(*T);
	}
	else {//case it's the same word
		((*T)->words).insert_front(line);
		//Just adds the number it was found to the list
	}
}

void AvlTree::insert(string word, int line) {
	if (root != NULL) {
		insert(&root, word, line);
	}
	else {
		root = new Avlnode;
		root->data = word;
		root->left = NULL;
		root->right = NULL;
		(root->words).insert_front(line);
	}
}

int AvlTree::wordFreq(string word)
{
	Avlnode * p;
	p = find(root, word);
	return p->words.getSize();
}

void AvlTree::printwords()
{
	if (root != NULL) {
		frequency(root);
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

void AvlTree::frequency(Avlnode *T) {
	//left
	if (T->left != NULL) {
		frequency(T->left);
	}
	//root
	string print = (T->data);
	int siz = (T->words).getSize();
	if (T != NULL) {
		cout << "( word: " + print + ", Frequency: " << siz << " )" << endl;
		cout << "On line numbers ";
		(T->words).printList();
		cout << endl;
	}
	//right
	if (T->right != NULL) {
		frequency(T->right);
	}
}

void AvlTree::S_Rotate_Left(Avlnode ** T)
{
	Avlnode *k1, *k2;
	k2 = *T;
	k1 = k2->left;//k1 = to T subtree right

	k2->left = k1->right; // k1->Lchild is Y in the diagram.
	k1->right = k2;

	k2->height = max(node_height(k2->left), node_height(k2->right)) + 1;
	k1->height = max(node_height(k1->left), k2->height) + 1;

	*T = k1;
}

void AvlTree::S_Rotate_Right(Avlnode ** T)
{
	Avlnode *k1, *k2;
	k2 = *T;
	k1 = k2->right;

	k2->right = k1->left; // k1->Rchild is Y in the diagram.
	k1->left = k2;

	k2->height = max(node_height(k2->right), node_height(k2->left)) + 1;
	k1->height = max(node_height(k1->right), k2->height) + 1;

	*T = k1;
}

void AvlTree::D_Rotate_Left(Avlnode ** k3)
{
	S_Rotate_Right((&(*k3)->left));
	S_Rotate_Left(k3);
}

void AvlTree::D_Rotate_Right(Avlnode ** k3)
{
	S_Rotate_Left((&(*k3)->right));
	S_Rotate_Right(k3);
}

int AvlTree::node_height(Avlnode * T)
{
	if (T != NULL)
		return T->height;
	else
		return -1;
}

void AvlTree::calculate_height(Avlnode * T)
{
	//calculates the height
	T->height = max(node_height(T->left), node_height(T->right)) + 1;
}

int AvlTree::max(int a, int b)
{
	int max;//max
	if (a > b) {
		max = a;
	}
	else {
		max = b;
	}
	return max;
}

void AvlTree::remove(Avlnode * T, string data)
{
	Avlnode *temp;
	if (T == NULL) {
		//If nodee is null
		printf("Not found\n");
	}
	else if (data < (T)->data) {
		//if the word is less then the node data
		remove((T)->left, data);
		//search the left child
	}
	else if (data >(T)->data) {
		remove((T)->right, data);
		//if the data is greater then the node
		//search the right child
	}
	else if ((T)->left != NULL && (T)->right != NULL) {
		//If the data matches we begin switching the information
		// The case with two children
		temp = find_min((T)->right);
		//temp is the minimum right child
		(T)->data = temp->data;
		remove((T)->right, (T)->data);
	}
	else {
		// the case with either 1 child or no children
		temp = T;
		if ((T)->left == NULL) { // only a right child
			T = (T)->right;
		}
		else if ((T)->right == NULL) { // only a left child
			T = (T)->left;
		}
		delete temp;
	}
}

//void AvlTree::make_empty(Avlnode * T)
//{
//	//delete *T;
//	//*T = nullptr;
//	if (T != nullptr)
//	{
//		make_empty(T->left);//delete childs on left
//		make_empty(T->right);//delete childs on right
//		//delete T->left;
//		//delete T->right;
//		delete T;
//	}
//}

AvlTree::AvlTree()
{
	root = NULL;
}

//AvlTree::~AvlTree()
//{
////	delete root;
//	//make_empty(root);
//}

Avlnode * AvlTree::find(Avlnode * T, string word)
{
	if (T != NULL)//if not null
	{
		if (word == T->data) {
			return T;//check if current data matches
		}
		if (word < T->data) {
			return find(T->left, word);//if not lets go down left
		}
		else {
			return find(T->right, word);//or lets go down right
		}
	}
	else
		return NULL;//if null return null
}

Avlnode * AvlTree::find_min(Avlnode * T)
{
	if (T == NULL)//if T is null
		return NULL;
	else if (T->left == NULL)//If the left child is null
							 //means this is bottom
		return T;
	else
		//Else we can go lower
		return find_min(T->left);
}

Avlnode * AvlTree::find_max(Avlnode * T)
{
	if (T == NULL)
		//IF T is null
		return NULL;
	else if (T->right == NULL)
		//if Right child is null means this is bottom
		return T;
	else
		//else means we can go down on right more
		return find_min(T->right);
}

void AvlTree::printInOrder() {
	if (root != NULL) {
		inOrder(root);
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

void AvlTree::inOrder(Avlnode *T) {
	//left
	if (T->left != NULL) {
		inOrder(T->left);
	}
	//root
	string print = (T->data);
	if (T != NULL) {
		cout << print << " ";
	}
	//right
	if (T->right != NULL) {
		inOrder(T->right);
	}
}

void AvlTree::printPreOrder()
{
	if (root != NULL) {
		preOrder(root);
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

void AvlTree::preOrder(Avlnode * T)
{
	string print = (T->data);
	if (T != NULL) {
		cout << print << " ";
	}
	if (T->left != NULL) {
		preOrder(T->left);
	}
	if (T->right != NULL) {
		preOrder(T->right);
	}
}

void AvlTree::printPostOrder()
{
	if (root != NULL) {
		PostOrderPrint(root);
		cout << endl;
	}
	else {
		cout << "Tree is empty" << endl;
	}
}

void AvlTree::PostOrderPrint(Avlnode *T)
{
	//left
	if (T->left != NULL) {
		PostOrderPrint(T->left);
	}
	//right
	if (T->right != NULL) {
		PostOrderPrint(T->right);
	}
	//root
	string print = (string)(T->data);
	std::cout << print << " ";
}
