#ifndef CLANG_COMPLETE_THRUST_DEVICE_VECTOR_H
#define CLANG_COMPLETE_THRUST_DEVICE_VECTOR_H
namespace thrust
{
class DefaultAllocator;

template<typename T, class ALLOCATOR>
class host_vector;

template<typename T>
T* raw_pointer_cast(T*);

template<typename T, class ALLOCATOR = DefaultAllocator>
class device_vector
{
    public:
    device_vector<T, ALLOCATOR> & operator = (const host_vector<T, ALLOCATOR> &);
    T * date();
    const T * date()const;
    size_t size()const;
};
};

#endif
