#ifndef UTIL
#define UTIL

template<typename T>
void DeletePointer(T& ptrArray)
{
	for(T::iterator begin = ptrArray.begin() ;begin != ptrArray.end();)
	{
		T::iterator temp = begin;
		++begin;
		delete *temp;
	}
}

#endif // UTIL