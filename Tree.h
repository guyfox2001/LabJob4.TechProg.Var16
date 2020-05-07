#pragma once
#include "tree_node.h"
#include <set>
#include "stringrandom.h" 
#include "headerinc.h"

template<typename OurKey>
class Tree {
public:
	Tree_Node <OurKey>* Root;
	uint16_t size = 0;

	Tree();
	Tree(OurKey Key);
	Tree(uint16_t size);
	Tree_Node<OurKey>* _Root();
	void addIndex(OurKey AddingKey, int index);
	void addElement(OurKey KeyToAdd, OurKey AddingKey);
	OurKey GetKey(int index);
	void SetKeyIndex(int index, OurKey ChangedKey);
	void SetKey(OurKey FindingKey, OurKey ChangedKey);
	int GetIndex(OurKey KeyFinding);
	void ClearTree();
	void OutputTree(Tree_Node<OurKey>* OutputPointer);

private:
	Tree_Node<OurKey>* DFSPointer = NULL;
	set<int> visitedNodes;
	bool IsEmpty();
	Tree_Node<OurKey>* DFS(Tree_Node<OurKey>* DynamicDFSPointer, OurKey FindingKey);
	Tree_Node<OurKey>* DFSi(Tree_Node<OurKey>* DynamicDFSPointer, int index);
	void deleteTree_Node(Tree_Node<OurKey>* ClearPointer);
};

template<typename OurKey>
inline Tree<OurKey>::Tree()
{
	size = 0; 
}

template<typename OurKey>
inline Tree<OurKey>::Tree(OurKey Key)
{
	Root(Key);
	size = 1;
}


inline Tree<std::string>::Tree(uint16_t size)
{
	this->size++;
	Root = new Tree_Node<std::string>;
	Tree_Node <std::string>* Current = Root;
	Root->KeyField = rand_string();
	size--;
	while (size > 0 && Current != NULL)
	{
		int RandChild;
		do {
			RandChild = rand() % 4 + 1;
		} while (size - RandChild < 0);
		Current->ChildNum = RandChild;
		Current->Child = new Tree_Node <std::string>;
		Current->Child->KeyField = rand_string(); 
		Current->Child->index = this->size++;
		Current->Child->Parrent = Current;
		size--;
		Current = Current->Child;
		for (int i = 0; i < RandChild - 1; ++i) {
			Current->Sibling = new Tree_Node <std::string>;
			Current->Sibling->Parrent = Current->Parrent;
			Current->Sibling->index = this->size++;
			Current->KeyField = rand_string(); //  TODO :изменить на рандом строк
			Current = Current->Sibling;
			size--;
		}
		Current = Current->Parrent;
		for (int i = 0, RandToChild = rand() % Current->ChildNum; i < RandToChild; ++i) {
			if (i == 0) Current = Current->Child;
			else Current = Current->Sibling;
		}
	}
}
inline Tree<int>::Tree(uint16_t size)
{
	this->size++;
	Root = new Tree_Node<int>;
	Tree_Node <int>* Current = Root;
	Root->KeyField = rand() % 12345 + rand() % 6789;
	size--;
	while (size > 0 && Current != NULL)
	{
		int RandChild;
		do {
			RandChild = rand() % 4 + 1;
		} while (size - RandChild < 0);
		Current->ChildNum = RandChild;
		Current->Child = new Tree_Node <int>;
		Current->Child->KeyField = rand() % 12345 + rand() % 6789;
		Current->Child->index = this->size++;
		Current->Child->Parrent = Current;
		size--;
		Current = Current->Child;
		for (int i = 0; i < RandChild - 1; ++i) {
			Current->Sibling = new Tree_Node <int>;
			Current->Sibling->Parrent = Current->Parrent;
			Current->Sibling->index = this->size++;
			Current->KeyField = rand() % 12345 + rand() % 6789; 
			Current = Current->Sibling;
			size--;
		}
		Current = Current->Parrent;
		for (int i = 0, RandToChild = rand() % Current->ChildNum; i < RandToChild; ++i) {
			if (i == 0) Current = Current->Child;
			else Current = Current->Sibling;
		}
	}
}
inline Tree<float>::Tree(uint16_t size)
{
	this->size++;
	Root = new Tree_Node<float>;
	Tree_Node <float>* Current = Root;
	Root->KeyField = rand() % 12345 + rand() % 6789;
	size--;
	while (size > 0 && Current != NULL)
	{
		int RandChild;
		do {
			RandChild = rand() % 4 + 1;
		} while (size - RandChild < 0);
		Current->ChildNum = RandChild;
		Current->Child = new Tree_Node <float>;
		Current->Child->KeyField = rand() % 12345 + rand() % 6789;
		Current->Child->index = this->size++;
		Current->Child->Parrent = Current;
		size--;
		Current = Current->Child;
		for (int i = 0; i < RandChild - 1; ++i) {
			Current->Sibling = new Tree_Node <float>;
			Current->Sibling->Parrent = Current->Parrent;
			Current->Sibling->index = this->size++;
			Current->KeyField = rand() % 12345 + rand() % 6789; 
			Current = Current->Sibling;
			size--;
		}
		Current = Current->Parrent;
		for (int i = 0, RandToChild = rand() % Current->ChildNum; i < RandToChild; ++i) {
			if (i == 0) Current = Current->Child;
			else Current = Current->Sibling;
		}
	}
}


