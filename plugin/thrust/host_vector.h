#ifndef CLANG_COMPLETE_THRUST_HOST_VECTOR_H
#define CLANG_COMPLETE_THRUST_HOST_VECTOR_H
namespace thrust
{
class DefaultAllocator;

template<typename T, class ALLOCATOR>
class device_vector;

template<typename T, class ALLOCATOR = DefaultAllocator>
class host_vector
{
    public:
    host_vector<T, ALLOCATOR> & operator = (const device_vector<T, ALLOCATOR> &);
    T * date();
    const T * date()const;
    size_t size()const;
};
};

#endif
