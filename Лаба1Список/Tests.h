//
// Created by Kendrick on 19.03.2019.
//

#ifndef PROJECT_TESTS_H
#define PROJECT_TESTS_H

#include "assert.h"
#include "mylist.h"

void test_push_back() {
    List<int> *list = new List<int>();

    list->push_back(2);
    assert(list->at(0) == 2)
}

void test_all() {
    test_push_back();
}

#endif //PROJECT_TESTS_H
