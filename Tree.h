#pragma once
#pragma comment(linker, "/STACK:500000")
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
	void OutputTree(Tree_Node<std::string>* OutputPointer, uint8_t TreeLevel);
	string FindKey(string KeyFinding);
	void DeleteElement(OurKey DeletingKey);

private:
	Tree_Node<OurKey>* DFSPointer = NULL;
	Tree_Node<OurKey>* BFSPointer = NULL;
	Tree_Node<OurKey>* FreeSpacePointer = NULL;
	set<int> visitedNodes;
	set<int> DeletedIndexes;
	bool FlagOneTimeDelete = false;

	bool IsEmpty();
	Tree_Node<OurKey>* DFS(Tree_Node<OurKey>* DynamicDFSPointer, OurKey FindingKey);
	Tree_Node<OurKey>* DFSi(Tree_Node<OurKey>* DynamicDFSPointer, int index);
	void deleteTree_Node(Tree_Node<OurKey>* ClearPointer);
	Tree_Node <OurKey>* FindFreeSpaceCh(Tree_Node<OurKey>* DynamicDFSPointer, uint16_t ParrentChildNum);
	int get_index();
};

template<typename OurKey>
inline Tree<OurKey>::Tree()
{
	size = 0; 
}

template<typename OurKey>
inline Tree<OurKey>::Tree(OurKey Key)
{
	Root = new Tree_Node <OurKey>(Key);
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
			Current->Sibling->KeyField = rand_string();
			Current = Current->Sibling;
			size--;
		}
		Current = Current->Parrent;
		for (int i = 0, RandToChild = rand() % Current->ChildNum; i <= RandToChild; ++i) {
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
			Current->Sibling->KeyField = rand() % 12345 + rand() % 6789;
			Current = Current->Sibling;
			size--;
		}
		Current = Current->Parrent;
		for (int i = 0, RandToChild = rand() % Current->ChildNum; i <= RandToChild; ++i) {
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
			Current->Sibling->KeyField = rand() % 12345 + rand() % 6789;
			Current = Current->Sibling;
			size--;
		}
		Current = Current->Parrent;
		for (int i = 0, RandToChild = rand() % Current->ChildNum; i <= RandToChild; ++i) {
			if (i == 0) Current = Current->Child;
			else Current = Current->Sibling;
		}
	}
}

template<typename OurKey>
inline void Tree<OurKey>::addIndex(OurKey AddingKey, int index)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return; }
	DFSPointer = this->DFSi(Root, index);
	if (DFSPointer == NULL) { cerr << "Adding error: Invalid key\n"; return; }
	if (DFSPointer->ChildNum == 4) { cerr << "Adding error: ChildNum can't be more than 4\n"; return; }
	if (DFSPointer->ChildNum == 0 && DFSPointer->Child == NULL) {
		DFSPointer->Child = new Tree_Node <OurKey>;
		DFSPointer->ChildNum++;
		DFSPointer->Child->KeyField = AddingKey;
		DFSPointer->Child->Parrent = DFSPointer;
		DFSPointer->Child->index = get_index();
		this->size++;
	}
	else {
		DFSPointer->ChildNum++;
		DFSPointer = DFSPointer->Child;
		for (; DFSPointer->Sibling != NULL; DFSPointer = DFSPointer->Sibling);
		DFSPointer->Sibling = new Tree_Node <OurKey>;
		DFSPointer->Sibling->KeyField = AddingKey;
		DFSPointer->Sibling->Parrent = DFSPointer->Parrent;
		DFSPointer->Sibling->index = get_index();
		this->size++;
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
		DFSPointer->Child->index = get_index();
		this->size++;
	}
	else {
		DFSPointer->ChildNum++;
		DFSPointer = DFSPointer->Child;
		for (; DFSPointer->Sibling != NULL; DFSPointer = DFSPointer->Sibling);
		DFSPointer->Sibling = new Tree_Node <OurKey>;
		DFSPointer->Sibling->KeyField = AddingKey;
		DFSPointer->Sibling->Parrent = DFSPointer->Parrent;
		DFSPointer->Sibling->index = get_index();
		this->size++;
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
	DFSPointer = this->DFSi(Root, index);
	if (DFSPointer == NULL) { cerr << "GetKey error: Not Found\n"; return NULL; }
	return DFSPointer->KeyField;
}

template<typename OurKey>
inline void Tree<OurKey>::SetKeyIndex(int index, OurKey ChangedKey)
{
	if (this->IsEmpty()) { cerr << "List is empty \n"; return; }
	DFSPointer = this->DFSi(Root, index);
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
	size = 0;
}
//Придумывающийся алгоритм

inline void Tree<std::string>::OutputTree(Tree_Node<std::string>* OutputPointer, uint8_t TreeLevel)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return;  }
	for (int i = 0; i < 5 * TreeLevel; ++i) cout << ' ';
	cout << OutputPointer->KeyField<< '(' << OutputPointer->index << ')'<< endl;
	if (OutputPointer->Child != NULL) {
		OutputTree(OutputPointer->Child, TreeLevel + 1);
	}
	if (OutputPointer->Sibling != NULL) {
		OutputTree(OutputPointer->Sibling, TreeLevel);
	}
	return;

}


//Раскомментровать, если не придумается алгоритм лучше.
//template<typename OurKey>
//inline void Tree<OurKey>::OutputTree(Tree_Node<OurKey>* DynamicBFSPointer)
//{
//	/*if (DynamicBFSPointer == Root) {
//		cout << "Root:\t" << DynamicBFSPointer->KeyField << endl;
//	}*/
//	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return; }
//		cout << DynamicBFSPointer->KeyField << "(" << DynamicBFSPointer->index << ")" << endl;
//	if (DynamicBFSPointer->Sibling != NULL) {
//		cout << "Child:\t";
//		OutputTree(DynamicBFSPointer->Sibling);
//	}
//	if (DynamicBFSPointer->Child != NULL) {
//		cout << "Parent:\t" << DynamicBFSPointer->KeyField <<"("<< DynamicBFSPointer->index << ")" << "\nChild:";;
//		OutputTree(DynamicBFSPointer->Child);
//	}
//	return;
//}


inline string Tree<string>::FindKey(string KeyFinding)
{
	if (this->IsEmpty()) { cerr << "Tree is empty\n"; return "-1"; }
	DFSPointer = DFS(Root, KeyFinding);
	if (DFSPointer == NULL) { cout << "NotFound\n"; return "-1"; }
	return DFSPointer->KeyField;
}

template<typename OurKey>
inline void Tree<OurKey>::DeleteElement(OurKey DeletingKey)
{
	if (this->IsEmpty()) { cerr << "Tree is empty \n"; return; }
	DFSPointer = DFS(Root,DeletingKey);
	if (DFSPointer == NULL) { cerr << "Not found: Invalid key\n"; return; }
	FlagOneTimeDelete = true;
	if (DFSPointer == Root) {
		DeletedIndexes.insert(DFSPointer->Child->index);
		DFSPointer->Child->index = 0;
		if (DFSPointer->Child->Child == NULL) {
			Root = DFSPointer->Child;
			Root->Parrent = NULL;
			Root->Child = Root->Sibling;
			Root->Sibling = NULL;
			Root->Child->Parrent = Root;
			Root->ChildNum = DFSPointer->ChildNum - 1;
			for (Tree_Node <OurKey>* Iter = Root->Child; Iter->Sibling != NULL; Iter = Iter->Sibling) Iter->Sibling->Parrent = Iter->Parrent;
			size--;
			delete DFSPointer;
		}
		else {
			Tree_Node <OurKey>* tempChildPointer = Root->Child->Child;
			uint16_t tempChildNum = Root->Child->ChildNum;
			Root = DFSPointer->Child;
			Root->Child = Root->Sibling;
			Root->Sibling = NULL;
			Root->Parrent = NULL;
			Root->Child->Parrent = Root;
			Root->ChildNum = DFSPointer->ChildNum - 1;
			for (Tree_Node <OurKey>* Iter = Root->Child; Iter->Sibling != NULL; Iter = Iter->Sibling) Iter->Sibling->Parrent = Iter->Parrent;
			FreeSpacePointer = FindFreeSpaceCh(Root, tempChildNum);
			if (FreeSpacePointer->Child != NULL) {
				FreeSpacePointer->ChildNum += tempChildNum;
				Tree_Node <OurKey>* tempItr = FreeSpacePointer->Child;
				for (; tempItr->Sibling != NULL; tempItr = tempItr->Sibling);
				tempItr->Sibling = tempChildPointer;
				tempChildPointer->Parrent = tempItr->Parrent;
				for (Tree_Node <OurKey>* FindSibling = tempChildPointer; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
					FindSibling->Sibling->Parrent = FindSibling->Parrent;
				}
			}
			else {
				FreeSpacePointer->ChildNum = tempChildNum;
				FreeSpacePointer->Child = tempChildPointer;
				tempChildPointer->Parrent = FreeSpacePointer;
				for (Tree_Node <OurKey>*  FindSibling = tempChildPointer; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
					FindSibling->Sibling->Parrent = FindSibling->Parrent;
				}
			}
			size--;
			delete DFSPointer;
		}
		return;
	}
	if (DFSPointer->Child == NULL && DFSPointer->Sibling == NULL) {
		DeletedIndexes.insert(DFSPointer->index);
		Tree_Node <OurKey>* FindSibling = DFSPointer->Parrent->Child;
		for (; FindSibling != NULL && FindSibling->Sibling != DFSPointer; FindSibling = FindSibling->Sibling);
		if (FindSibling == NULL) {
			DFSPointer->Parrent->ChildNum--;
			DFSPointer->Parrent->Child = NULL;
			delete DFSPointer;
		}
		else {
			FindSibling->Sibling = NULL;
			DFSPointer->Parrent->ChildNum--;
			delete DFSPointer;
		}
		size--;
		return;
	}
	if (DFSPointer->Child == NULL && DFSPointer->Sibling != NULL) {
		DeletedIndexes.insert(DFSPointer->index);
		Tree_Node <OurKey>* FindSibling = DFSPointer->Parrent->Child;
		for (; FindSibling != NULL && FindSibling->Sibling != DFSPointer; FindSibling = FindSibling->Sibling);
		if (DFSPointer->Parrent->Child == DFSPointer) {
			DFSPointer->Parrent->Child = DFSPointer->Sibling;
			DFSPointer->Parrent->ChildNum--;
			delete DFSPointer;
		}
		else {
			FindSibling->Sibling = DFSPointer->Sibling;
			DFSPointer->Parrent->ChildNum--;
			delete DFSPointer;
		}
		return;
	}
	if (DFSPointer->Child != NULL) {
		if (DFSPointer->Child->Child == NULL) {
			DeletedIndexes.insert(DFSPointer->index);
			Tree_Node <OurKey>* FindSibling = DFSPointer->Parrent;
			if (FindSibling->Child == DFSPointer) {
				FindSibling->Child = DFSPointer->Child;
				FindSibling->Child->Child = FindSibling->Child->Sibling;
				FindSibling->Child->Sibling = DFSPointer->Sibling;
				FindSibling->Child->ChildNum = DFSPointer->ChildNum - 1;
				FindSibling->Child->Parrent = FindSibling;
				for (FindSibling = FindSibling->Child; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
					FindSibling->Sibling->Parrent = FindSibling->Parrent;
				}
				size--;
				delete DFSPointer;
				return;
			}
			else {
				FindSibling = FindSibling->Child;
				for (; FindSibling != NULL && FindSibling->Sibling != DFSPointer; FindSibling = FindSibling->Sibling);
				DFSPointer->Child->Child = DFSPointer->Child->Sibling;
				DFSPointer->Child->Sibling = DFSPointer->Sibling;
				FindSibling->Sibling = DFSPointer->Child;
				FindSibling->Sibling->Parrent = FindSibling->Parrent;
				DFSPointer->Child->ChildNum = DFSPointer->ChildNum - 1;
				DFSPointer->Child->Child->Parrent = FindSibling->Sibling;
				for (FindSibling = FindSibling->Sibling->Child; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
					FindSibling->Sibling->Parrent = FindSibling->Parrent;
				}
				size--; 
				delete DFSPointer;
				return;
			}
		}
		else {
			if (DFSPointer->Sibling == NULL) {
				DeletedIndexes.insert(DFSPointer->index);
				DFSPointer->Parrent->Child = DFSPointer->Child;
				DFSPointer->Child->Parrent = DFSPointer->Parrent;
				for (Tree_Node<OurKey>* FindSibling = DFSPointer->Child; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
					FindSibling->Sibling->Parrent = FindSibling->Parrent;
				}
				size--;
				delete DFSPointer;
				return;
			}
			DeletedIndexes.insert(DFSPointer->index);
			Tree_Node <OurKey>* FindSibling = DFSPointer->Parrent;
			if (FindSibling->Child == DFSPointer) {
				FindSibling->Child = DFSPointer->Child;
				Tree_Node <OurKey>* tempChildPointer = FindSibling->Child->Child;
				uint16_t tempChildNum = FindSibling->Child->ChildNum;
				FindSibling->Child->Child = FindSibling->Child->Sibling;
				FindSibling->ChildNum = DFSPointer->ChildNum - 1;
				FindSibling->Child->Sibling = DFSPointer->Sibling;
				FindSibling->Child->Parrent = FindSibling;
				for (Tree_Node <OurKey>* Find = FindSibling->Child; Find->Sibling != NULL; Find = Find->Sibling) {
					Find->Sibling->Parrent = Find->Parrent;
				}
				FreeSpacePointer = FindFreeSpaceCh(FindSibling->Child, tempChildNum);
				if (FreeSpacePointer->Child != NULL) {
					FreeSpacePointer->ChildNum += tempChildNum;
					Tree_Node <OurKey>* tempItr = FreeSpacePointer->Child;
					for (; tempItr->Sibling != NULL; tempItr = tempItr->Sibling);
					tempItr->Sibling = tempChildPointer;
					tempChildPointer->Parrent = tempItr->Parrent;
					for (FindSibling = tempChildPointer; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
						FindSibling->Sibling->Parrent = FindSibling->Parrent;
					}
				}
				else {
					FreeSpacePointer->ChildNum = tempChildNum;
					FreeSpacePointer->Child = tempChildPointer;
					tempChildPointer->Parrent = FreeSpacePointer;
					for (FindSibling = tempChildPointer; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
						FindSibling->Sibling->Parrent = FindSibling->Parrent;
					}
				}
				size--;
				delete DFSPointer;
				return;
			}
			else {
				
				FindSibling = FindSibling->Child;
				for (; FindSibling->Sibling != DFSPointer; FindSibling = FindSibling->Sibling);
				Tree_Node <OurKey>* tempChildPointer = DFSPointer->Child->Child;
				uint16_t tempChildNum = DFSPointer->Child->ChildNum;
				DFSPointer->Child->Child = DFSPointer->Child->Sibling;
				DFSPointer->Child->Sibling = DFSPointer->Sibling;
				FindSibling->Sibling = DFSPointer->Child;
				DFSPointer->Child->ChildNum = DFSPointer->ChildNum - 1;
				DFSPointer->Child->Child->Parrent = DFSPointer->Child;
				DFSPointer->Child->Parrent = DFSPointer->Parrent;
				for (Tree_Node <OurKey>* Find = FindSibling->Sibling->Child; Find->Sibling != NULL; Find = Find->Sibling) {
					Find->Sibling->Parrent = Find->Parrent;
				}
				FreeSpacePointer = FindFreeSpaceCh(FindSibling->Sibling, tempChildNum);
				if (FreeSpacePointer->Child != NULL) {
					FreeSpacePointer->ChildNum += tempChildNum;
					Tree_Node <OurKey>* tempItr = FreeSpacePointer->Child;
					for (; tempItr->Sibling != NULL; tempItr = tempItr->Sibling);
					tempItr->Sibling = tempChildPointer;
					tempChildPointer->Parrent = tempItr->Parrent;
					for (FindSibling = tempChildPointer; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
						FindSibling->Sibling->Parrent = FindSibling->Parrent;
					}
				}
				else {
					FreeSpacePointer->ChildNum = tempChildNum;
					FreeSpacePointer->Child = tempChildPointer;
					tempChildPointer->Parrent = FreeSpacePointer;
					for (FindSibling = tempChildPointer; FindSibling->Sibling != NULL; FindSibling = FindSibling->Sibling) {
						FindSibling->Sibling->Parrent = FindSibling->Parrent;
					}
				}
				size--;
				delete DFSPointer;
			}
		}
	}
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
		DFSPointer = DFSi(DynamicDFSPointer->Child, index);
		if (DFSPointer != NULL) return DFSPointer;

	}
	if (DynamicDFSPointer->Sibling != NULL) {
		DFSPointer = DFSi(DynamicDFSPointer->Sibling, index);
		return DFSPointer;
	}
	if (DynamicDFSPointer->Child == NULL || DynamicDFSPointer->Sibling == NULL) return NULL;
}

template<typename OurKey>
inline void Tree<OurKey>::deleteTree_Node(Tree_Node<OurKey>* ClearPointer) {
	if (ClearPointer == NULL) return;
	deleteTree_Node(ClearPointer->Child);
	deleteTree_Node(ClearPointer->Sibling);
	delete ClearPointer;
}

template<typename OurKey>
inline Tree_Node<OurKey>* Tree<OurKey>::FindFreeSpaceCh(Tree_Node<OurKey>* DynamicDFSPointer, uint16_t ParrentChildNum)
{
	if (this->IsEmpty()) return NULL;
	if (DynamicDFSPointer->Child == NULL || DynamicDFSPointer->ChildNum + ParrentChildNum <= 4) return DynamicDFSPointer;
	if (DynamicDFSPointer->Sibling != NULL) {
		FreeSpacePointer = FindFreeSpaceCh(DynamicDFSPointer->Sibling, ParrentChildNum);
		if (FreeSpacePointer != NULL) return FreeSpacePointer;
	}
	if (DynamicDFSPointer->Child != NULL) {
		FreeSpacePointer = FindFreeSpaceCh(DynamicDFSPointer->Child, ParrentChildNum);
		return FreeSpacePointer;
	}
	return NULL;
}

template<typename OurKey>
inline int Tree<OurKey>::get_index()
{
	int index;
	if (FlagOneTimeDelete != false) {
		index = *DeletedIndexes.begin();
		DeletedIndexes.erase(index);
		if (DeletedIndexes.empty())
			FlagOneTimeDelete = false;
		return index;
	}
	else {
		return size;
	}
}


