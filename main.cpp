#include "headerinc.h"
#include "tree_node.h"
#include "Tree.h"
#include "stringrandom.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tree <string> a(20);
	cout << a.FindKey("выстригающийся") << endl;
	a.OutputTree(a.Root);
	a.addElement("блюз", "Проверка");
	a.addElement("блюз", "Проверка 2");
	cout << "------------------------------------------------------\n";
	a.OutputTree(a.Root);
	a.ClearTree();
	a.OutputTree(a.Root);
	return 0;
}