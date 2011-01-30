#include <iostream>
#include "ArrayList.h"
#include <list>
using namespace std;


void testsize() {
	ArrayList<int>* test = new ArrayList<int>();
	test->add(0, 1);
	if (test->size()!=1){
		cout<<"Length test fails!"<<endl;
		return;
	}
	test->add(0, 2);
	if (test->size()!=2 && test->get(1) == 1){
		cout<<"Length test fails!\n";
		delete test;
		return;
	}
	cout<<"Length test passes!\n";
	delete test;
}

void testcopy() {
	ArrayList<int>* test = new ArrayList<int>();
	test->add(0, 1);
	test->add(0, 2);
	ArrayList<int>* t2 = new ArrayList<int>(*test);
	delete test;
	if (t2->get(0) != 2 || t2->get(1) != 1) {
		cout<<"Copy test fails!\n";
	}
	delete t2;
	
	test = new ArrayList<int>();
	test->add(0, 1);
	test->add(0, 2);
	ArrayList<int> t3 = *test;
	delete test;
	if (t3.get(0) != 2 || t3.get(1) != 1) {
		cout<<"Copy test fails!\n";
		delete test;
		return;
	}
	
	test = new ArrayList<int>();
	test->add(0, 1);
	test->add(0, 2);
	t3 = *test;
	test->add(0, 3);
	if (t3.size() != 2) {
		cout<<"Copy test fails!\n";
		delete test;
		return;
	}
	delete test;
	cout<<"Copy test passes!\n";
}

void testappend() {
	ArrayList<int> * test = new ArrayList<int>();
	test->append(1);
	test->append(2);
	test->append(3);
	if (test->get(0) != 1 || test->get(1) != 2 || test->get(2) != 3) {
		cout<<"Append test fails!\n";
		cout<<test->get(0)<<" "<<test->get(1)<<" "<<test->get(2)<<endl;
		delete test;
		return;
	}
	delete test;
	cout<<"Append test passes!\n";
}

void testremove() {
	ArrayList<int> * test = new ArrayList<int>();
	test->append(1);
	test->append(2);
	test->append(3);
	if (test->get(0) != 1 || test->get(1) != 2 || test->get(2) != 3 || test->size() != 3) {
		cout<<"Remove test fails!\n";
		delete test;
		return;
	}
	test->remove(2);
	test->remove(1);
	
	if (test->get(0) != 1 || test->size() != 1) {
		cout<<"Remove test fails!\n";
		delete test;
		return;
	}
	test->append(2);
	test->append(3);
	test->remove(0);
	if (test->get(0) != 2 || test->get(1) != 3 || test->size() != 2) {
		cout<<"Remove test fails!\n";
		delete test;
		return;
	}
	delete test;
	cout<<"Remove test passes!\n";
}
/*
void testdoublesize() {
	ArrayList<int> * test = new ArrayList<int>(2);
	test->append(0);
	test->append(1);
	test->append(2);
	if (test->size() != 3 || test->getmemsize() != 4) {
		cout<<"Doublesize test fails!\n";
		delete test;
		return;
	}
	delete test;
	cout<<"Doublesize test passes!\n";
}
void testhalfsize() {
	ArrayList<int> * test = new ArrayList<int>(32);
	test->append(0);
	test->append(1);
	test->remove(0);
	if (test->size() != 1 || test->get(0) != 1 || test->getmemsize() != 16) {
		cout<<"Halfsize test fails!\n";
		delete test;
		return;
	}
	test->append(1);
	if (test->size() != 2 || test->getmemsize() != 16) {
		cout<<"Halfsize test fails!\n";
		delete test;
		return;
	}
	delete test;
	cout<<"Halfsize test passes!\n";
}
*/

void testequals() {
	ArrayList<int> * test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	ArrayList<int> * test1 = new ArrayList<int>();
	test1->append(0);
	test1->append(1);
	if (!test->equals(*test1)) {
		cout<<"Equals test fails!\n";
		delete test;
		delete test1;
		return;
	}
	if (*test != *test1) {
		cout<<"Equals test fails!\n";
		delete test;
		delete test1;
		return;
	}
	test->append(1);
	test1->append(0);
	if (test->equals(*test1)) {
		cout<<"Equals test fails!\n";
		delete test;
		delete test1;
		return;
	}
	cout<<"Equals test passes!\n";
	delete test;
	delete test1;
	return;
}

void testappendall() {
	ArrayList<int> * test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	ArrayList<int> * test1 = new ArrayList<int>();
	test1->appendAll(*test);
	if(test1->size() != 2 || test1->get(0) != 0 || test1->get(1) != 1) {
		cout<<"AppendAll test fails!\n";
		delete test;
		delete test1;
		return;
	}
	cout<<"AppendAll test passes!\n";
	delete test;
	delete test1;
	return;
}

void testcontains() {
	ArrayList<int> * test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	if (!test->contains(0) || !test->contains(1)) {
		cout<<"Contains test fails!\n";
		delete test;
		return;
	}
	cout<<"Contains test passes!\n";
	delete test;
	return;
}

void testcontainsAll() {
	ArrayList<int> * test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	ArrayList<int> * test1 = new ArrayList<int>();
	test1->append(0);
	test1->append(1);
	test1->append(2);
	if (!test1->containsAll(*test) || test->containsAll(*test1)) {
		cout<<"ContainsAll test fails!\n";
		delete test;
		delete test1;
		return;
	}
	cout<<"ContainsAll test passes!\n";
	delete test;
	delete test1;
	return;
}
/*
void testensurecapacity() {
	ArrayList<int>* test = new ArrayList<int>(1);
	test->ensureCapacity(10);
	if(test->getmemsize() != 10) {
		cout<<"EnsureCapacity test fails!\n";
		delete test;
		return;
	}
	cout<<"EnsureCapacity test passes!\n";
	delete test;
	return;
}*/

void testgetall() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(25);
	test->append(30);
	ArrayList<int>* find = new ArrayList<int>();
	find->append(1);
	find->append(2);
	ArrayList<int>* ret = test->getAll(*find);
	if (ret->size() != 2 || ret->get(0) != 25 || ret->get(1) != 30) {
		cout<<"GetAll test fails!\n";
		delete test;
		delete find;
		delete ret;
		return;
	}
	cout<<"GetAll test passes!\n";
	delete test;
	delete find;
	delete ret;
	return;
}

void testallindicesof() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(25);
	test->append(30);
	test->append(20);
	ArrayList<int>* ret = test->allIndicesOf(20);
	if (ret->get(0) != 0 || ret->get(1) != 3) {
		cout<<"AllIndicesOf test fails!\n";
		delete test;
		delete ret;
		return;
	}
	cout<<"AllIndicesOf test passes!\n";
	delete test;
	delete ret;
	return;
}

void testfirstindexof() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(20);
	if (test->firstIndexOf(20) != 0) {
		cout<<"FirstIndexOf test fails!\n";
		delete test;
		return;
	}
	cout<<"FirstIndexOf test passes!\n";
	delete test;
	return;
}

void testlastindexof() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(20);
	if (test->lastIndexOf(20) != 1) {
		cout<<"LastIndexOf test fails!\n";
		delete test;
		return;
	}
	cout<<"LastIndexOf test passes!\n";
	delete test;
	return;
}

void testisempty() {
	ArrayList<int>* test = new ArrayList<int>();
	if (!test->isEmpty()) {
		cout<<"IsEmpty test fails!\n";
		delete test;
		return;
	}
	test->append(1);
	if (test->isEmpty()) {
		cout<<"IsEmpty test fails!\n";
		delete test;
		return;
	}
	cout<<"IsEmpty test passes!\n";
	delete test;
	return;
}

void testprepend() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(1);
	test->prepend(0);
	if (test->get(0) != 0 || test->get(1) != 1 || test->size() != 2) {
		cout<<"Prepend test fails!\n";
		delete test;
		return;
	}
	cout<<"Prepend test passes!\n";
	delete test;
	return;
}

void testprependall() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(1);
	test->prepend(0);
	ArrayList<int>* test1 = new ArrayList<int>();
	test1->append(10);
	test1->prependAll(*test);
	if (test1->get(0) != 0 || test1->get(1) != 1 || test1->get(2) != 10 || test1->size() != 3) {
		cout<<"PrependAll test fails!\n";
		delete test;
		delete test1;
		return;
	}
	cout<<"PrependAll test passes!\n";
	delete test;
	delete test1;
	return;
}

void testremoveall() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	test->append(0);
	test->removeAll(0);
	if (test->get(0) != 1 || test->size() != 1) {
		cout<<"RemoveAll test fails!\n";
		delete test;
		return;
	}
	cout<<"RemoveAll test passes!\n";
	delete test;
	return;
}

void testremovefirst() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	test->append(0);
	test->removeFirst(0);
	if (test->get(0) != 1 || test->get(1) != 0 || test->size() != 2) {
		cout<<"RemoveFirst test fails!\n";
		delete test;
		return;
	}
	cout<<"RemoveFirst test passes!\n";
	delete test;
	return;
}

void testremovelast() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	test->append(0);
	test->removeLast(0);
	if (test->get(0) != 0 || test->get(1) != 1 || test->size() != 2) {
		cout<<"RemoveLast test fails!\n";
		delete test;
		return;
	}
	cout<<"RemoveLast test passes!\n";
	delete test;
	return;
}

void testset() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	test->set(1, 10);
	if (test->get(0) != 0 || test->get(1) != 10 || test->size() != 2) {
		cout<<"Set test fails!\n";
		delete test;
		return;
	}
	cout<<"Set test passes!\n";
	delete test;
	return;
}

void testsublist() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	test->append(23);
	test->append(45);
	ArrayList<int>* ret = test->subList(1, 3);
	if (ret->get(0) != 1 || ret->get(1) != 23 || ret->size() != 2) {
		cout<<"SubList test fails!\n";
		delete test;
		delete ret;
		return;
	}
	cout<<"SubList test passes!\n";
	delete test;
	delete ret;
	return;
}
/*
void testtrimtosize() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(0);
	test->append(1);
	test->append(23);
	test->append(45);
	test->trimToSize();

	if (test->getmemsize() != 4) {
		cout<<"TrimToSize test fails!\n";
		delete test;
		return;
	}
	cout<<"TrimToSize test passes!\n";
	delete test;
	return;
}*/

void testplus() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(25);
	ArrayList<int>* test1 = new ArrayList<int>();
	test1->append(1);
	test1->append(2);
	ArrayList<int>* t = *test + *test1;
	if (t->get(0) != 20 || t->size() != 4) {
		cout<<"Plus test fails!\n";
		delete test;
		delete test1;
		delete t;
		return;
	}
	cout<<"Plus test passes!\n";
	delete test;
	delete test1;
	delete t;
	return;
}

void testplusequals() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(25);
	ArrayList<int>* test1 = new ArrayList<int>();
	test1->append(1);
	test1->append(2);
	(*test) += *test1;
	if (test->get(2) != 1 || test->size() != 4) {
		cout<<"PlusEquals test fails!\n";
		delete test;
		delete test1;
		return;
	}
	cout<<"PlusEquals test passes!\n";
	delete test;
	delete test1;
	return;
}

void testminus() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(25);
	ArrayList<int>* test1 = new ArrayList<int>();
	test1->append(20);
	test1->append(2);
	ArrayList<int>* t = *test - *test1;
	if (t->get(0) != 25 || t->size() != 1) {
		cout<<"Minus test fails!\n";
		delete test;
		delete test1;
		delete t;
		return;
	}
	cout<<"Minus test passes!\n";
	delete test;
	delete test1;
	delete t;
	return;
}

void testminusequals() {
	ArrayList<int>* test = new ArrayList<int>();
	test->append(20);
	test->append(25);
	ArrayList<int>* test1 = new ArrayList<int>();
	test1->append(20);
	test1->append(2);
	(*test) -= *test1;
	if (test->get(0) != 25 || test->size() != 1) {
		cout<<"MinusEquals test fails!\n";
		delete test;
		delete test1;
		return;
	}
	cout<<"MinusEquals test passes!\n";
	delete test;
	delete test1;
	return;
}

void testlist() {
	ArrayList<list<int> >* test = new ArrayList<list<int> >();
	delete test;
}

int main(int argc, char ** argv) {
	testsize();
	testcopy();
	testappend();
	testremove();
	//testdoublesize();
	//testhalfsize();
	testequals();
	testappendall();
	testcontains();
	testcontainsAll();
	//testensurecapacity();
	testgetall();
	testallindicesof();
	testfirstindexof();
	testlastindexof();
	testisempty();
	testprepend();
	testprependall();
	testremoveall();
	testremovefirst();
	testset();
	testsublist();
	//testtrimtosize();
	testplus();
	testplusequals();
	testminus();
	testminusequals();
	testlist();
}