/*
Memory Management Playground (MMP)
By Daniel S. Buckstein
Copyright 2019-2020
*/
//-----------------------------------------------------------------------------

#ifndef _MMP_TYPES_H_
#define _MMP_TYPES_H_
														//this is all in Hungarian notation

// core signed type abbreviations
typedef				__int8			i8,		byte;
typedef				__int16			i16,	word;
typedef				__int32			i32,	dword;
typedef				__int64			i64,	qword;

// core unsigned type abbreviations
typedef	unsigned	__int8			ui8,	ubyte;
typedef	unsigned	__int16			ui16,	uword;
typedef	unsigned	__int32			ui32,	udword;
typedef	unsigned	__int64			ui64,	uqword;

// core floating point type abbreviations
typedef				float			f32,	flt;
typedef				double			f64,	dbl;

// core pointer type abbreviations
typedef				void			* ptr,	* addr;		//generic pointer, pointer is an address
typedef				void const		* kptr,	* kaddr;	//the diff between ptr and kptr is ptr is pointing at data globally, but kptr is you are pointing at constant data
														//		dont know the type, but you know you cant change it

// architecture, block size and pointer difference type abbreviations
#ifdef _MMP_64BIT_
#define				mmp_arch		64					//size changes based on 32bit v 64bit, switching architectures will toggle this block
typedef				ui64			size;
typedef				i64				ptrdiff;			//pointer a - pointer b
#else	// !_MMP_64BIT_
#ifdef _MMP_32BIT_
#define				mmp_arch		32
typedef				ui32			size;
typedef				i32				ptrdiff;
#else	// !_MMP_32BIT_
#error "MUST DEFINE EITHER _MMP_64BIT_ OR _MMP_32BIT_"
#endif	// _MMP_32BIT_
#endif	// _MMP_64BIT_


// special types
typedef				byte			cstr[mmp_arch];		//standard c string that matches architecture size
typedef				byte const		* cstrp;
typedef				size			uindex;					//size also represents index
typedef				ptrdiff			index, addrdiff, flag;


#define				szbyte			((size)sizeof(byte))
#define				szword			((size)sizeof(word))		// word = "short"
#define				szdword			((size)sizeof(dword))		// dword = "long"
#define				szqword			((size)sizeof(qword))
#define				szflt			((size)sizeof(flt))
#define				szdbl			((size)sizeof(dbl))
#define				szaddr			((size)sizeof(addr))
#define				szcstr			((size)sizeof(cstr))


#endif	// !_MMP_TYPES_H_