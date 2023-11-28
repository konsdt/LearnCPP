#include <iostream>
#include <vector>
/*
16.9 std::vector resizing and capacity
What makes std::vector significantly special in comparison to other arrays
is its ability to resize itself after it has been instantiated

std::vector can be resized after instantiation by calling the resize() member
function with the new desired length

When resizing new elements are value initialized, which means default initialization
for class types and zero initialization for all other types

std::vector also has a "capacity", this determines how many elements it
has allocated storage for while its "length" says how many elements are currently
in use.

From the outside it looks like the vector is resized but on the inside its
contents are acutally copied to another memory location!
This requires every element to be copied and therefore is expensive!
One should generally avoid unnecessary reallocations.

Keeping track of its capacity aswell allows a vector to sometimes be a littles
smarter and thus avoid expensive copying.

vector indexing is based on length not capacity!

resizeing to a smaller size does not free memory.
There exists the member function ".shrink_to_fit()" which advises the implementation
to free the unuccupied capacity, but it is non binding. So the implementation
may fullfill the request or only partially or not at all.
*/

void printCapLen(const std::vector<int>& v)
{
    std::cout << "Capacity: " << v.capacity() << " Length: " << v.size() << '\n';
}

int main()
{    
    // create vector with length 5
    std::vector v {0, 1, 2, 3, 4};
    v = {0, 1, 2, 3, 4}; //okay, array length = 5
    printCapLen(v);
 
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    // resize vector to 3 elements
    v.resize(3);
    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    // resize vector back to 5 elements
    v.resize(5);
    printCapLen(v);

    for (auto i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    std::vector<int> v2(1000);
    printCapLen(v2);

    v2.resize(0);
    printCapLen(v2);

    v2.shrink_to_fit();
    printCapLen(v2);


    return 0;
}