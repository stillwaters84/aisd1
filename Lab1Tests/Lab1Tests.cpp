#include "pch.h"
#include "CppUnitTest.h"
#include "../Лаба1Список/mylist.h"
#include <cassert>
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab1Tests
{
	TEST_CLASS(int_tests)
	{
	public:
		
		TEST_METHOD(push_back_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(11);
			list->push_back(-17);
			list->push_back(0);

			Assert::AreEqual(list->at(0), 11);
			Assert::AreEqual(list->at(1), -17);
			Assert::AreEqual(list->at(2), 0);

			delete list;
		}

		TEST_METHOD(push_front_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_front(11);
			list->push_front(-17);
			list->push_front(0);

			Assert::AreEqual(list->at(0), 0);
			Assert::AreEqual(list->at(1), -17);
			Assert::AreEqual(list->at(2), 11);

			delete list;
		}

		TEST_METHOD(pop_back_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(11);
			list->push_back(-17);
			list->push_back(0);

			list->pop_back();
			Assert::AreEqual(list->at(0), 11);
			Assert::AreEqual(list->at(1), -17);
			try {
				list->at(2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_back();
			Assert::AreEqual(list->at(0), 11);
			try {
				list->at(1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_back();
			try {
				list->pop_back();
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "List is empty");
			}

			delete list;
		}

		TEST_METHOD(pop_front_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(11);
			list->push_back(-17);
			list->push_back(0);

			list->pop_front();
			Assert::AreEqual(list->at(0), -17);
			Assert::AreEqual(list->at(1), 0);
			try {
				list->at(2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_front();
			Assert::AreEqual(list->at(0), 0);
			try {
				list->at(1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_front();
			try {
				list->at(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			try {
				list->pop_front();
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "List is empty");
			}

			delete list;
		}

		TEST_METHOD(insert_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(11);
			list->push_back(-17);
			list->push_back(0);

			list->insert(0, 123);
			Assert::AreEqual(list->at(0), 123);
			Assert::AreEqual(list->at(1), 11);

			list->insert(2, -89);
			Assert::AreEqual(list->at(2), -89);
			Assert::AreEqual(list->at(3), -17);

			try {
				list->insert(-2, -1);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			try {
				list->insert(25, -1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			delete list;
		}

		TEST_METHOD(at_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(13);
			list->push_back(22);
			list->push_back(-7);

			Assert::AreEqual(list->at(0), 13);
			Assert::AreEqual(list->at(1), 22);
			Assert::AreEqual(list->at(2), -7);

			try {
				list->at(-8);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			try {
				list->at(50);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			MyList<int>* emptylist = new MyList<int>();
			try {
				list->at(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			delete list;
			delete emptylist;
		}

		TEST_METHOD(remove_int)
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(13);
			list->push_back(22);
			list->push_back(-7);
			list->push_back(18);
			list->push_back(0);

			list->remove(0);
			Assert::AreEqual(list->at(0), 22);
			Assert::AreEqual(list->at(1), -7);

			list->remove(2);
			Assert::AreEqual(list->at(1), -7);
			Assert::AreEqual(list->at(2), 0);
			try {
				list->remove(55);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			try {
				list->remove(-7);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			MyList<int>* emptylist = new MyList<int>();
			try {
				emptylist->remove(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			delete list;
			delete emptylist;
		}

		TEST_METHOD(get_size_int)
		{
			MyList<int>* list = new MyList<int>;
			list->push_back(13);
			list->push_back(22);
			list->push_back(-7);

			Assert::AreEqual(list->get_size(), size_t(3));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(2));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(1));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(0));

			delete list;
		}

		TEST_METHOD(clear_int)
		{
			MyList<int>* list = new MyList<int>();
			MyList<int>* emptylist = new MyList<int>();
			list->push_back(13);
			list->push_back(22);
			list->push_back(-7);
			list->clear();
			emptylist->clear();
			Assert::IsTrue(list->isEmpty());
			Assert::IsTrue(emptylist->isEmpty());

			delete list;
			delete emptylist;
		}

		TEST_METHOD(set_int)
		{
			MyList<int>* list = new MyList<int>;
			list->push_back(13);
			list->push_back(22);
			list->push_back(-7);

			list->set(0, -11);
			Assert::AreEqual(list->at(0), -11);

			list->set(1, 79);
			Assert::AreEqual(list->at(1), 79);

			list->set(2, -66);
			Assert::AreEqual(list->at(2), -66);

			try {
				list->set(-2, -2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "There's no this index");
			}

			try {
				list->set(47, 8);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "There's no this index");
			}

			delete list;
		}

		TEST_METHOD(isEmpty_int) 
		{
			MyList<int>* list = new MyList<int>();
			list->push_back(13);
			list->push_back(22);
			list->push_back(-7);

			MyList<int>* emptylist = new MyList<int>();

			Assert::IsFalse(list->isEmpty());
			Assert::IsTrue(emptylist->isEmpty());

			delete list;
			delete emptylist;
		}
	};

	TEST_CLASS(char_tests)
	{
	public:

		TEST_METHOD(push_back_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			Assert::AreEqual(list->at(0), 'b');
			Assert::AreEqual(list->at(1), 'c');
			Assert::AreEqual(list->at(2), 'k');

			delete list;
		}

		TEST_METHOD(push_front_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_front('b');
			list->push_front('c');
			list->push_front('k');

			Assert::AreEqual(list->at(0), 'k');
			Assert::AreEqual(list->at(1), 'c');
			Assert::AreEqual(list->at(2), 'b');

			delete list;
		}

		TEST_METHOD(pop_back_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			list->pop_back();
			Assert::AreEqual(list->at(0), 'b');
			Assert::AreEqual(list->at(1), 'c');
			try {
				list->at(2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_back();
			Assert::AreEqual(list->at(0), 'b');
			try {
				list->at(1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_back();
			try {
				list->pop_back();
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "List is empty");
			}

			delete list;
		}

		TEST_METHOD(pop_front_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			list->pop_front();
			Assert::AreEqual(list->at(0), 'c');
			Assert::AreEqual(list->at(1), 'k');
			try {
				list->at(2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_front();
			Assert::AreEqual(list->at(0), 'k');
			try {
				list->at(1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_front();
			try {
				list->at(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			try {
				list->pop_front();
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "List is empty");
			}

			delete list;
		}

		TEST_METHOD(insert_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			list->insert(0, 'l');
			Assert::AreEqual(list->at(0), 'l');
			Assert::AreEqual(list->at(1), 'b');

			list->insert(2, 'z');
			Assert::AreEqual(list->at(2), 'z');
			Assert::AreEqual(list->at(3), 'c');

			try {
				list->insert(-2, 'x');
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			try {
				list->insert(25, 'x');
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			delete list;
		}

		TEST_METHOD(at_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			Assert::AreEqual(list->at(0), 'b');
			Assert::AreEqual(list->at(1), 'c');
			Assert::AreEqual(list->at(2), 'k');

			try {
				list->at(-8);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			try {
				list->at(50);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			MyList<char>* emptylist = new MyList<char>();
			try {
				list->at(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			delete list;
			delete emptylist;
		}

		TEST_METHOD(remove_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('a');
			list->push_back('b');
			list->push_back('c');
			list->push_back('d');
			list->push_back('e');

			list->remove(0);
			Assert::AreEqual(list->at(0), 'b');
			Assert::AreEqual(list->at(1), 'c');

			list->remove(2);
			Assert::AreEqual(list->at(1), 'c');
			Assert::AreEqual(list->at(2), 'e');
			try {
				list->remove(55);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			try {
				list->remove(-7);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			MyList<char>* emptylist = new MyList<char>();
			try {
				emptylist->remove(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			delete list;
			delete emptylist;
		}

		TEST_METHOD(get_size_char)
		{
			MyList<int>* list = new MyList<int>;
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			Assert::AreEqual(list->get_size(), size_t(3));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(2));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(1));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(0));

			delete list;
		}

		TEST_METHOD(clear_char)
		{
			MyList<char>* list = new MyList<char>();
			MyList<char>* emptylist = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');
			list->clear();
			emptylist->clear();
			Assert::IsTrue(list->isEmpty());
			Assert::IsTrue(emptylist->isEmpty());

			delete list;
			delete emptylist;
		}

		TEST_METHOD(set_char)
		{
			MyList<char>* list = new MyList<char>;
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			list->set(0, 'z');
			Assert::AreEqual(list->at(0), 'z');

			list->set(1, 'f');
			Assert::AreEqual(list->at(1), 'f');

			list->set(2, 'y');
			Assert::AreEqual(list->at(2), 'y');

			try {
				list->set(-2, 'o');
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "There's no this index");
			}

			try {
				list->set(47, 'o');
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "There's no this index");
			}

			delete list;
		}

		TEST_METHOD(isEmpty_char)
		{
			MyList<char>* list = new MyList<char>();
			list->push_back('b');
			list->push_back('c');
			list->push_back('k');

			MyList<char> * emptylist = new MyList<char>();

			Assert::IsFalse(list->isEmpty());
			Assert::IsTrue(emptylist->isEmpty());

			delete list;
			delete emptylist;
		}
	};

	TEST_CLASS(string_tests)
	{
	public:

		TEST_METHOD(push_back_string)
		{
			string sample1 = "oof";
			string sample2 = "sup";
			string sample3 = "dam";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			Assert::AreEqual(list->at(0), sample1);
			Assert::AreEqual(list->at(1), sample2);
			Assert::AreEqual(list->at(2), sample3);

			delete list;
		}

		TEST_METHOD(push_front_string)
		{
			string sample1 = "oof";
			string sample2 = "sup";
			string sample3 = "dam";
			MyList<string>* list = new MyList<string>();
			list->push_front("oof");
			list->push_front("sup");
			list->push_front("dam");

			Assert::AreEqual(list->at(0), sample3);
			Assert::AreEqual(list->at(1), sample2);
			Assert::AreEqual(list->at(2), sample1);

			delete list;
		}

		TEST_METHOD(pop_back_string)
		{
			string sample1 = "oof";
			string sample2 = "sup";
			string sample3 = "dam";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			list->pop_back();
			Assert::AreEqual(list->at(0), sample1);
			Assert::AreEqual(list->at(1), sample2);
			try {
				list->at(2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_back();
			Assert::AreEqual(list->at(0), sample1);
			try {
				list->at(1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_back();
			try {
				list->pop_back();
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "List is empty");
			}

			delete list;
		}

		TEST_METHOD(pop_front_string)
		{
			string sample1 = "oof";
			string sample2 = "sup";
			string sample3 = "dam";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			list->pop_front();
			Assert::AreEqual(list->at(0), sample2);
			Assert::AreEqual(list->at(1), sample3);
			try {
				list->at(2);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_front();
			Assert::AreEqual(list->at(0), sample3);
			try {
				list->at(1);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			list->pop_front();
			try {
				list->at(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			try {
				list->pop_front();
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "List is empty");
			}

			delete list;
		}

		TEST_METHOD(insert_string)
		{
			string sample1 = "wow";
			string sample2 = "oof";
			string sample3 = "heh";
			string sample4 = "sup";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			list->insert(0, "wow");
			Assert::AreEqual(list->at(0), sample1);
			Assert::AreEqual(list->at(1), sample2);

			list->insert(2, "heh");
			Assert::AreEqual(list->at(2), sample3);
			Assert::AreEqual(list->at(3), sample4);

			try {
				list->insert(-2, "dog");
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			try {
				list->insert(25, "dog");
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			delete list;
		}

		TEST_METHOD(at_string)
		{
			string sample1 = "oof";
			string sample2 = "sup";
			string sample3 = "dam";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			Assert::AreEqual(list->at(0), sample1);
			Assert::AreEqual(list->at(1), sample2);
			Assert::AreEqual(list->at(2), sample3);

			try {
				list->at(-8);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			try {
				list->at(50);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			MyList<char>* emptylist = new MyList<char>();
			try {
				list->at(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Element doesn't exist");
			}

			delete list;
			delete emptylist;
		}

		TEST_METHOD(remove_string)
		{
			string sample2 = "sup";
			string sample3 = "dam";
			string sample5 = "wow";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");
			list->push_back("heh");
			list->push_back("wow");

			list->remove(0);
			Assert::AreEqual(list->at(0), sample2);
			Assert::AreEqual(list->at(1), sample3);

			list->remove(2);
			Assert::AreEqual(list->at(1), sample3);
			Assert::AreEqual(list->at(2), sample5);
			try {
				list->remove(55);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			try {
				list->remove(-7);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			MyList<char>* emptylist = new MyList<char>();
			try {
				emptylist->remove(0);
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "Invalid Index");
			}

			delete list;
			delete emptylist;
		}

		TEST_METHOD(get_size_string)
		{
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			Assert::AreEqual(list->get_size(), size_t(3));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(2));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(1));

			list->pop_front();
			Assert::AreEqual(list->get_size(), size_t(0));

			delete list;
		}

		TEST_METHOD(clear_string)
		{
			MyList<string>* emptylist = new MyList<string>();
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");
			list->clear();
			emptylist->clear();
			Assert::IsTrue(list->isEmpty());
			Assert::IsTrue(emptylist->isEmpty());

			delete list;
			delete emptylist;
		}

		TEST_METHOD(set_string)
		{
			string sample1 = "heh";
			string sample2 = "wow";
			string sample3 = "dog";
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			list->set(0, "heh");
			Assert::AreEqual(list->at(0), sample1);

			list->set(1, "wow");
			Assert::AreEqual(list->at(1), sample2);

			list->set(2, "dog");
			Assert::AreEqual(list->at(2), sample3);

			try {
				list->set(-2, "lol");
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "There's no this index");
			}

			try {
				list->set(47, "lol");
			}
			catch (const std::out_of_range & error) {
				Assert::AreEqual(error.what(), "There's no this index");
			}

			delete list;
		}

		TEST_METHOD(isEmpty_string)
		{
			MyList<string>* list = new MyList<string>();
			list->push_back("oof");
			list->push_back("sup");
			list->push_back("dam");

			MyList<string>* emptylist = new MyList<string>();

			Assert::IsFalse(list->isEmpty());
			Assert::IsTrue(emptylist->isEmpty());

			delete list;
			delete emptylist;
		}
	};
}
