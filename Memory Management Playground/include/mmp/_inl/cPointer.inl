#ifdef _CPOINTER_H_
#ifndef _CPOINTER_INL_
#define _CPOINTER_INL_

//pass-thru custom placement new/delete
template <typename bufferType>
inline void* operator new (size_t sz, bufferType* buffer)	//take in some managed chunk of memory, which would be buffer type, whenever buffertype is used as placement new op, itll do what you want it to do
{
	//do whatever management buffer does
	//void* p = buffer->alloc(sz);	//obviously we dont have a manager, but if we did we would do this
	//return p;

	void* p = 0;
	return p;
}

template <typename bufferType>
inline void operator delete (void* ptr, bufferType* buffer)	
{
	//buffer->dealloc(ptr);
}


template <typename bufferType>
inline void* operator new[](size_t sz, bufferType* buffer)	
{
	//return operator::new<bufferType>(sz, buffer);
	return 0;
}


template <typename bufferType>
inline void operator delete[](void* ptr, bufferType* buffer)	
{
	//operator::operator delete<bufferType>(ptr, buffer);
}




#endif  // !_CPOINTER_INL_
#endif // _CPOINTER_H_
