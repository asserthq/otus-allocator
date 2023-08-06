#include "allocator.h"
#include <vector>

struct hard 
{
    int fa;
    int fi;
    hard(int fa, int fi) : fa(fa), fi(fi) {};
};


int main()
{
    std::vector<int, my::allocator<int>> v = { 1, 2, 3, 4 };
    v.push_back(777);

    return 0;
}