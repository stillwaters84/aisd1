#include <iostream>
#include "mylist.h"

//files in "���� ����/����1/Lab1Tests & ����1������
using namespace std;
int main() {
    MyList<int> *myList = new MyList<int>;
    myList->addfirst(5);
    myList->push_back(3);
    myList->push_front(1);
	myList->insert(0, 17);
	cout << myList->at(0) << endl;
    return 0;
}