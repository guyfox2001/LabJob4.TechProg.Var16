#pragma once
#include "headerinc.h"



template <typename OurKey>
class Tree_Node {
public:
	OurKey KeyField;
	int index;
	int ChildNum;
	Tree_Node<OurKey>* Parrent;
	Tree_Node<OurKey>* Sibling;
	Tree_Node<OurKey>* Child;

	Tree_Node();
	Tree_Node(OurKey Key);
};

template<typename OurKey>
inline Tree_Node<OurKey>::Tree_Node()
{
	index = 0;	
	ChildNum = 0;
	Parrent = NULL;
	Sibling = NULL;
	Child = NULL;
}

template<typename OurKey>
inline Tree_Node<OurKey>::Tree_Node(OurKey Key)
{
	this = new Tree_Node<OurKey>;
	KeyField = Key;
	index = 0;
	ChildNum = 0;
	Parrent = NULL;
	Sibling = NULL;
	Child = NULL;
}
