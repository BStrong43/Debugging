#include "mmp/cPointer.h"

int main()
{
	//default ctor
	cDummy obj;

	//copy ctor
	cDummy obj2 = obj;

	//assign op
	obj = obj2;

	//pointer op
	int val = obj->bar;

	char* buffer = new char[1024];
	cDummy* obj3 = new(buffer) cDummy(3);	//pass in the object, then choose your constructor, address of obj3 will be buffer by default (pooling would make this different)
	
	//do something with the obj3
	
	obj3->~cDummy();	//you need to do this one, never delete a placement_new object, call its destructor
	obj3 = 0;	//no longer in use
	delete[] buffer;
	//in c++, new just calls malloc, and delete just calls free



	cNonVoidTest<int> testNonVoid;
	testNonVoid.someFunc(3);

	cNonVoidTest<void> testVoid;
	testVoid.someFunc(3);
}