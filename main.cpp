#include "headerinc.h"
#include "tree_node.h"
#include "Tree.h"
#include "stringrandom.h"
#include <Windows.h>

Tree <string>* Tree_;
bool tree_initFlag = false;

void print_menu() {
	cout << "\n---------------Menu---------------\n";
	cout << "1.������������� ��������� ������\n";
	cout << "2.�������� ���� �� �����\n";
	cout << "3.�������� ���� �� �������\n";
	cout << "4.�������� ���� �� �������\n";
	cout << "5.�������� ������ �� �����\n";
	cout << "6.����� ����\n";
	cout << "7.������� ������\n";
	cout << "8.�������� ������\n";
	cout << "9.������� ����\n";
	cout << "10.������ ������\n";
	cout << "11.�������� ���� \n";
	cout << "12.�������� ���� �� ������� \n";
}

void SW_OP() {
	int operation, index;
	bool flag = false;
	string Key, AddingKey;
	print_menu();
	do
	{
		cout << "������� ����� ��������\n";
		cin >> operation;
		switch (operation)
		{
		case 1: {
			uint16_t size;
			if (tree_initFlag == false) {
				while (true)
				{
					cout << "������� ���������� �����\n";
					cin >> size;
					if (cin) break;
				}
				Tree_ = new Tree <string>(size);
				Tree_->OutputTree(Tree_->_Root(), 0);
				tree_initFlag = true;
			}
			else {
				cout << "������ ��� �������������������\n";
			}
			flag = false;;
			break;
		}
		case 2:
			if (tree_initFlag == true) {
				cout << "������� ���� � �������� ����� �����������\n";
				do{
					getline(cin, Key);
				} while (Key.empty());
				cout << "������� ����������� ����\n";
				do {
					getline(cin, AddingKey);
				} while (AddingKey.empty());
				Tree_->addElement(Key, AddingKey);
				Tree_->OutputTree(Tree_->_Root(), 0);
			}
			else {
				cout << "������ ������\n";
				cout << "������� ����������� ����\n";
				do {
					getline(cin, AddingKey);
				} while (AddingKey.empty());
				Tree_ = new Tree<string>(AddingKey);
				Tree_->OutputTree(Tree_->_Root(), 0);
				tree_initFlag = true;
			}
			flag = false;;
			break;
		case 3:
			if (tree_initFlag == true) {
				cout << "������� ������ � �������� ����� �����������\n";
				cin >> index;
				cout << "������� ����������� ����\n";
				do {
					getline(cin, AddingKey);
				} while (AddingKey.empty());
				Tree_->addIndex(AddingKey, index);
				Tree_->OutputTree(Tree_->_Root(), 0);
			}
			else {
				cout << "������ ������\n";
				cout << "������� ����������� ����\n";
				do {
					getline(cin, AddingKey);
				} while (AddingKey.empty());
				Tree_ = new Tree<string>(AddingKey);
				Tree_->OutputTree(Tree_->_Root(), 0);
				tree_initFlag = true;
			}
			flag = false;
			break;
		case 4:
			cout << "������� ������\n";
			cin >> index;
			cout << "���������: " << Tree_->GetKey(index) << '(' << index << ')';
			flag = false;
			break;
		case 5:
			cout << "������� ����\n";
			do {
				getline(cin, Key);
			} while (Key.empty());
			cout << "���������: " << Tree_->GetIndex(Key) << ' ' << Key << endl;
			flag = false;
			break;
		case 6:
			cout << "������� ����\n";
			do {
				getline(cin, Key);
			} while (Key.empty());
			cout << "���������: " << Tree_->FindKey(Key) << endl;
			flag = false;
			break;
		case 7:
			Tree_->OutputTree(Tree_->_Root(), 0);
			cout << endl;
			flag = false;
			break;
		case 8:
			Tree_->ClearTree();
			Tree_->OutputTree(Tree_->_Root(), 0);
			cout << endl;
 			flag = false;
			break;
		case 9:
			cout << "������� ����\n";
			do {
				getline(cin, Key);
			} while (Key.empty());
			Tree_->DeleteElement(Key);
			Tree_->OutputTree(Tree_->_Root(), 0);
			cout << endl;
			flag = false;
			break;
		case 10:
			cout << "������: " << Tree_->_Root()->KeyField << '(' << Tree_->_Root()->index << ')' << endl;
			flag = false;
			break;
		case 11: 
			cout << "������� ���� � ������� ����� ����������\n";
			do {
				getline(cin, Key);
			} while (Key.empty());
			cout << "������� ���������� ����\n";
			do {
				getline(cin, AddingKey);
			} while (AddingKey.empty());
			Tree_->SetKey(Key, AddingKey);
			Tree_->OutputTree(Tree_->_Root(), 0);
			flag = false; 
			break;
		case 12:
			cout << "������� ������\n";
			cin >> index;
			cout << "������� ���������� ����\n";
			do {
				getline(cin, AddingKey);
			} while (AddingKey.empty());
			Tree_->SetKeyIndex(index, AddingKey);
			Tree_->OutputTree(Tree_->_Root(), 0);
			flag = true;
			break;
		default:
			cout << "������ �����. ���������� ���.\n";
			flag = true;
			break;
		}
	} while (flag);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int exit = 0;
	do {
		SW_OP();
		while (true)
		{
			cout << "������ ����������: 1.YES 2.NO \n";
			cin >> exit;
			if (exit == 1 || exit == 2) break;
			cout << "������. ��������� ����\n";
		}
	} while (exit!=2);
	return 0;
}