#include "mmp/cPointer.h"


cDummy::cDummy()
{
	data = 0;
	size = 0;
}

//copy ctor
cDummy::cDummy(cDummy const& rhs)
	: cDummy(rhs.size)
{
	//copy data in actual array
	if (data)
	{

	}
}

//move ctor
cDummy::cDummy(cDummy&& rhs)
{
	size = rhs.size;
	data = rhs.data;
	rhs.data = 0;
}

//dtor
cDummy::~cDummy()
{
	//c++ has null check inside of it (so the if(data) is kind of redundant)
	if (data)
	{
		delete[] data;
	}
}


//other ctor
cDummy::cDummy(size_t newSize)
	: cDummy()
{
	//validate new size
	if (newSize > 0)
	{
		size = newSize;
		data = new foo[size];
	}
}


//copy assign
cDummy& cDummy::operator=(cDummy const& rhs)
{
	//this isnt redundant, we are deleting to make new room and need to know if shits in there
	if (data)
	{
		size = 0;
		delete[] data;
	}
	
	if(rhs.data)
	{
		size = rhs.size;
		data = new foo[size];

		//copy data

	}

	return *this;
}

//move assign
cDummy& cDummy::operator=(cDummy&& rhs)
{
	if (data)
	{
		size = 0;
		delete[] data;
	}

	size = rhs.size;
	data = rhs.data;
	rhs.data = 0;

	return *this;
}

//new overload
void* operator new(size_t sz)
{
	return 0;
}

//delete overload
void operator delete(void* ptr)
{
	
}

void* operator new(size_t sz, void* buffer)
{
	return 0;
}

void operator delete(void* buffer, void* ptr)
{
	
}


//new overload
void* operator new[](size_t sz)
{
	return 0;
}

//delete overload
void operator delete[](void* ptr)
{

}

void* operator new[](size_t sz, void* buffer)
{
	return 0;
}

void operator delete[](void* buffer, void* ptr)
{

}