#include "headerinc.h"
#include "Tree.h"
#include "stringrandom.h"
template<typename OurKey>
inline void Tree<OurKey>::addIndex(OurKey AddingKey, int index)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return; }
	DFSPointer = this->DFS(Root, index);
	if (DFSPointer == NULL) { cerr << "Adding error: Invalid key\n"; return; }
	if (DFSPointer->ChildNum == 4) { cerr << "Adding error: ChildNum can't be more than 4\n"; return; }
	if (DFSPointer->ChildNum == 0 && DFSPointer->Child == NULL) {
		DFSPointer->Child = new Tree_Node <OurKey>;
		DFSPointer->ChildNum++;
		DFSPointer->Child->KeyField = AddingKey;
		DFSPointer->Child->Parrent = DFSPointer;
		DFSPointer->Child->index = this->size++;
	}
	else {
		DFSPointer->ChildNum++;
		DFSPointer = DFSPointer->Child;
		for (; DFSPointer->Sibling != NULL; DFSPointer = DFSPointer->Sibling);
		DFSPointer->Sibling = new Tree_Node <OurKey>;
		DFSPointer->Sibling->KeyField = AddingKey;
		DFSPointer->Sibling->Parrent = DFSPointer->Parrent;
		DFSPointer->Sibling->index = this->size++;
	}
}
template<typename OurKey>
inline void Tree<OurKey>::addElement(OurKey KeyToAdd, OurKey AddingKey)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return; }
	DFSPointer = this->DFS(Root, KeyToAdd);
	if (DFSPointer == NULL) { cerr << "Adding error: Invalid key\n"; return; }
	if (DFSPointer->ChildNum == 4) { cerr << "Adding error: ChildNum can't be more than 4\n"; return; }
	if (DFSPointer->ChildNum == 0 && DFSPointer->Child == NULL) {
		DFSPointer->Child = new Tree_Node <OurKey>;
		DFSPointer->ChildNum++;
		DFSPointer->Child->KeyField = AddingKey;
		DFSPointer->Child->Parrent = DFSPointer;
		DFSPointer->Child->index = this->size++;
	}
	else {
		DFSPointer->ChildNum++;
		DFSPointer = DFSPointer->Child;
		for (; DFSPointer->Sibling != NULL; DFSPointer = DFSPointer->Sibling);
		DFSPointer->Sibling = new Tree_Node <OurKey>;
		DFSPointer->Sibling->KeyField = AddingKey;
		DFSPointer->Sibling->Parrent = DFSPointer->Parrent;
		DFSPointer->Sibling->index = this->size++;
	}
}

template<typename OurKey>
inline Tree_Node<OurKey>* Tree<OurKey>::_Root()
{
	return this->Root;
}



template<typename OurKey>
inline OurKey Tree<OurKey>::GetKey(int index)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return NULL; }
	DFSPointer = this->DFS(Root, index);
	if (DFSPointer == NULL) { cerr << "GetKey error: Not Found\n"; return NULL; }
	return DFSPointer->KeyField;
}

template<typename OurKey>
inline void Tree<OurKey>::SetKeyIndex(int index, OurKey ChangedKey)
{
	if (this->IsEmpty()) { cerr << "List is empty \n"; return; }
	DFSPointer = this->DFS(Root, index);
	if (DFSPointer == NULL) { cerr << "SetKey error: Not Found\n"; return; }
	DFSPointer->KeyField = ChangedKey;
}

template<typename OurKey>
inline void Tree<OurKey>::SetKey(OurKey FindingKey, OurKey ChangedKey)
{
	if (this->IsEmpty()) { cerr << "List is empty \n"; return; }
	DFSPointer = this->DFS(Root, FindingKey);
	if (DFSPointer == NULL) { cerr << "SetKey error: Not Found\n"; return; }
	DFSPointer->KeyField = ChangedKey;
}

template<typename OurKey>
inline int Tree<OurKey>::GetIndex(OurKey KeyFinding)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return NULL; }
	DFSPointer = this->DFS(Root, KeyFinding);
	if (DFSPointer == NULL) { cerr << "GetKey error: Not Found\n"; return NULL; }
	return DFSPointer->index;
}

template<typename OurKey>
inline void Tree<OurKey>::ClearTree()
{
	if (this->IsEmpty()) { cerr << "Clear: Tree is clear \n"; return; }
	deleteTree_Node(Root);
	Root = NULL;
}

template<typename OurKey>
inline void Tree<OurKey>::OutputTree(Tree_Node<OurKey>* OutputPointer)
{


}

template<typename OurKey>
inline bool Tree<OurKey>::IsEmpty()
{
	if (this->size == 0)return true;
	else return false;
}

template<typename OurKey>
Tree_Node<OurKey>* Tree<OurKey>::DFS(Tree_Node<OurKey>* DynamicDFSPointer, OurKey FindingKey)
{
	if (this->IsEmpty()) return NULL;
	if (FindingKey == DynamicDFSPointer->KeyField) return DynamicDFSPointer;
	if (DynamicDFSPointer->Child != NULL) {
		DFSPointer = DFS(DynamicDFSPointer->Child, FindingKey);
		if (DFSPointer != NULL) return DFSPointer;

	}
	if (DynamicDFSPointer->Sibling != NULL) {
		DFSPointer = DFS(DynamicDFSPointer->Sibling, FindingKey);
		return DFSPointer;
	}
	if (DynamicDFSPointer->Child == NULL || DynamicDFSPointer->Sibling == NULL) return NULL;
}

template<typename OurKey>
inline Tree_Node<OurKey>* Tree<OurKey>::DFSi(Tree_Node<OurKey>* DynamicDFSPointer, int index)
{
	if (this->IsEmpty()) return NULL;
	if (index == DynamicDFSPointer->index) return DynamicDFSPointer;
	if (DynamicDFSPointer->Child != NULL) {
		DFSPointer = DFS(DynamicDFSPointer->Child, index);
		if (DFSPointer != NULL) return DFSPointer;

	}
	if (DynamicDFSPointer->Sibling != NULL) {
		DFSPointer = DFS(DynamicDFSPointer->Sibling, index);
		return DFSPointer;
	}
	if (DynamicDFSPointer->Child == NULL || DynamicDFSPointer->Sibling == NULL) return NULL;
}

template<typename OurKey>
inline void Tree<OurKey>::deleteTree_Node(Tree_Node<OurKey>* ClearPointer){
	if (ClearPointer == NULL) return;
	deleteTree_Node(ClearPointer->Child);
	deleteTree_Node(ClearPointer->Sibling);
	delete ClearPointer;
}

