/*
Memory Management Playground (MMP)
By Daniel S. Buckstein
Copyright 2019-2020
*/
//-----------------------------------------------------------------------------

#include "mmp/mmp_memory.h"

#pragma comment(lib, "MemoryManagementPlayground.lib")


//-----------------------------------------------------------------------------

typedef		byte				chunk_kb[1024];


//-----------------------------------------------------------------------------

#define		decl_argc			ui32 const argc
#define		decl_argv			cstrp const argv[]
typedef		i32(*entry_func)(decl_argc, decl_argv);


//-----------------------------------------------------------------------------

int testMMP(decl_argc, decl_argv);
int testMalloc(decl_argc, decl_argv);


//-----------------------------------------------------------------------------

int main(decl_argc, decl_argv)
{
	//return testMMP(argc, argv);
	return testMalloc(argc, argv);
}


//-----------------------------------------------------------------------------

int testMMP(decl_argc, decl_argv)
{
	// stack-allocate a bunch of data
	chunk_kb chunk[12];
	size count = sizeof(chunk);
	ptr chunk_base = mmp_set_zero(chunk, count);	//set that chunk of 12 kilobytes to 0, this is the pool, call pool init on this chunk, 
													//		when done release it



	// done, stack-allocated data popped
	return 0;
}


//-----------------------------------------------------------------------------

#include <stdlib.h>


int testMalloc(decl_argc, decl_argv)
{
	//all heap allocation

	//read the variable names letter for letter right to left to get the description
	//------------------------------------------------------------------------------
	//void* p								points to mem address we dont know type of data
	//int* p								points to mem address but knows how long it is
	//int const* kpi						points to mem address, we know how long it is, but we cant change the value of where its pointing (what we are pointing at)
	//												pointer to a const integer (no modding allowing of value)
	//int* const pki						points to mem address, we know how long it is, but we cant change what it points to
	//												constant pointer to integer (you cant change address, but you can change value)
	//int const* const kpki					constant pointer to a constant integer
	//int const* const* const* const kpkpkpki		constant pointer, to a constant pointer, to a constant pointer, to a constant integer
	//int**** ppppi							pointer to pointer to pointer to pointer to integer

	//use const as much as possible, and if you need to, you cant type_cast from a const pointer to a non const pointer

	union malloctest
	{
		i32 data[32];		//fuckton of data

		struct 
		{
			i32 dummy;		
		};

	};
	typedef union malloctest malloctest;

	malloctest* test1024 = malloc(1024);
	malloctest* test2048 = malloc(2048);
	malloctest* test4096 = malloc(4096);



			//start of our block is 1024, but the start of our header is some amount of bytes before it

	//every malloc must have a free
	free(test1024);


	test1024 = malloc(8192);

	free(test4096);
	free(test1024);
	free(test2048);

	
	return 0;
}
