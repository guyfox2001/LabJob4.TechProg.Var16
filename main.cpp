#include "headerinc.h"
#include "tree_node.h"
#include "Tree.h"
#include "stringrandom.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tree <string> a(20);
	cout << a.FindKey("��������������") << endl;
	a.OutputTree(a.Root);
	a.addElement("����", "��������");
	a.addElement("����", "�������� 2");
	cout << "------------------------------------------------------\n";
	a.OutputTree(a.Root);
	a.ClearTree();
	a.OutputTree(a.Root);
	return 0;
}