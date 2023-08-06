#include <memory>

namespace my {

    template<class T, class Alloc = std::allocator<T>>
    class list
    {
    public:
        struct node
        {
            T val;
            node<T>* next;
        };

    public:
        

    private:
        node<T>* m_head

    };

    
}
