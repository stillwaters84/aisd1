#include <iostream>
#include "mylist.h"

//files in "лабы аисд/лаба1/Lab1Tests & Лаба1Список
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