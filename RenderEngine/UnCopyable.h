#ifndef UnCopyable_H_
#define UnCopyable_H_

namespace Graphics{ namespace BasicUtils{ 

class UnCopyable
{
protected:
    UnCopyable() {}
    ~UnCopyable() {}
private:
	UnCopyable(const UnCopyable &other) {}
	UnCopyable& operator=(const UnCopyable &other) {}
};

}}

#endif // UnCopyable_H_
