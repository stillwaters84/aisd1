#include <iostream>
#include "mylist.h"

using namespace std;
int main() {
	MyList<int>* myList;
	myList->addfirst(5);
	myList->push_back(3);
	myList->push_front(1);


	return 0;
}