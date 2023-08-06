#include <limits>
#include <iostream>

namespace my {

    template<class T>
    class allocator
    {
    public:
        using value_type = T;

    public:
        allocator() = default;
 
        template<class U>
        constexpr allocator(const allocator<U>&) noexcept {}

        T* allocate(std::size_t n)
        {
            if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
                throw std::bad_array_new_length();
 
            if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
            {
                report(p, n);
                return p;
            }
    
            throw std::bad_alloc();
        }

        void deallocate(T* p, std::size_t n) noexcept
        {
            report(p, n, false);
            std::free(p);
        }

        template<class U>
        bool operator==(const allocator<U>&) { return true; }
        
        template<class U>
        bool operator!=(const allocator<U>&) { return false; }

    private:
        void report(T* p, std::size_t n, bool alloc = true) const
        {
            std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
                    << " bytes at " << std::hex << std::showbase
                    << reinterpret_cast<void*>(p) << std::dec << '\n';
        }

    };

}