#ifndef _CPOINTER_H_
#define _CPOINTER_H_



template <bool, typename T = void>
struct TYPEDEF {};
template <typename T>
struct TYPEDEF<true, T> { typedef T TYPE; };	//this struct is a version of the one above that HAS to be true
												//	the one member it has is a generic type called TYPE, and TYPE is based on T, TYPE and T can be the same they might not
											
#define  TYPE(T)		TYPEDEF<T != void>::TYPE	//anytime we see TYPE of T, we get the type of one of those TYPEDEF structures
													//	you are going to get a bool telling you whether or not youre equal to void
													//	if T does not equal void, then we get TYPE (bool arg true)
													//	if T is void, then bool arg is false, and we do not have a type defined

#define NONVOID(T)		template<typename t = TYPE(T)>	//NONVOID is a template declaration replacement, that ensures type used for the template is never void


template<typename T>
class cNonVoidTest
{
public:
	NONVOID(T) t someFunc(t value) {};
};




struct foo
{
	int bar;
};

class cDummy
{
	foo* data;
	int size;

public:
	cDummy();
	cDummy(cDummy const& rhs);
	cDummy(cDummy&& rhs);	//move constructor (redundancy removal technique): tells the destructor to forget about the data by setting the pointer to zero, to not
							//						allow for deletion.

	~cDummy();

	//"param" ctor
	cDummy(size_t newSize);

	cDummy& operator =(cDummy const& rhs);
	//cDummy& operator =(cDummy const& rhs) = default;		//sets to default values, same as not declaring this at all 
	//cDummy& operator =(cDummy const& rhs) = delete;		//any members given by compiler will get deleted

	
	cDummy& operator =(cDummy&& rhs);	//move operator: (&&) means R-value, its just some temporary data

	//acessspr operator
	foo* operator->() const
	{
		return data;
	}

	
	void* operator new(size_t sz);	//new overload
	void operator delete(void* ptr); //delete overload
	void* operator new(size_t sz, void* buffer);
	void operator delete(void* buffer, void* ptr);

	void* operator new[](size_t sz);	//new overload
	void operator delete[](void* ptr); //delete overload
	void* operator new[](size_t sz, void* buffer);
	void operator delete[](void* buffer, void* ptr);
};

class cPointer
{

};

#include "_inl/cPointer.inl"

#endif	// !_CPOINTER_H_

