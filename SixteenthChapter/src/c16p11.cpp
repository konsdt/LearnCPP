#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

/*
16.11 std::vector<bool>
the template class vector has a different implementation for the template
type <bool>: it compats 8 boolean values into one byte.
does not have bit manipulation options like "std::bitset"
Tradeoffs:
    - large overhead (uses up quite a lot of bytes even when storing only 5 bools)
    - performance highly dependent on implementation (not optimized)
    - not a vector (not contiguous) nor does it hold bool values, nor does it meet
      C++'s definition of a container
"Best Practice": Favor "constexpr std::bitset", "std::vector<char>" or 3rd party
dynamic bitsets over std::vector<bool>

16.x Summary and Quiz

*/
namespace PlayerItem
{
    enum Type {
        health_potions,
        torches,
        arrows,
        max_items
    };
    std::vector count { 1, 5, 10 };
    
}

std::string_view getItemNamePlural(PlayerItem::Type type)
{
    switch(type)
    {
        case PlayerItem::health_potions: return "health potions";
        case PlayerItem::torches:        return "torches";
        case PlayerItem::arrows:         return "arrows";

        default:                         return "???";
    }
}

std::string_view getItemNameSingular(PlayerItem::Type type)
{
    switch(type)
    {
        case PlayerItem::health_potions: return "health potion";
        case PlayerItem::torches:        return "torche";
        case PlayerItem::arrows:         return "arrow";

        default:                         return "???";
    }
}

void printInventoryItem(const std::vector<int>& inventory, PlayerItem::Type type)
{
    bool plural { inventory[type] != 1 };
    std::cout << "You have " << inventory[type] << ' ';
    std::cout << (plural ? getItemNamePlural(type) : getItemNameSingular(type)) << '\n';
}

int countTotalItems(const std::vector<int>& inventory)
{
    int sum {0};
    for (auto e : inventory)
        sum += e;
    return sum;
}

template <typename T>
std::pair<T,T> minMax(std::vector<T>& v)
{
    std::pair<T,T> min_max {v[0], v[0]};
    for (T value : v)
    {
        if (value < min_max.first)
            min_max.first = value;
        if (value > min_max.second)
            min_max.second = value;
    }
    return min_max;
}

template <typename T>
void printMinMax(std::pair<T,T>& pair)
{
    std::cout << T
}
int main()
{
    /*
    using namespace std::literals::string_view_literals;
    std::vector even_numbers { 2, 4, 6, 8, 10, 12 };
    const std::vector doubles { 1.2, 3.4, 5.6, 7.8 };
    const std::vector names { "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv };
    std::vector single { 12 };
    std::vector<int> integers(12);
    */
    assert(std::size(PlayerItem::count) == PlayerItem::Type::max_items);
    for (int i=0; i < PlayerItem::Type::max_items; ++i)
    {
        auto item { static_cast<PlayerItem::Type>(i) };
        printInventoryItem(PlayerItem::count, item);
    }
   
    std::cout << "You have " << countTotalItems(PlayerItem::count) << " total items.\n";


    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    minMax(v1);


    std::vector<bool> v { true, false, false, true, true };

    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    // Change the Boolean value with index 4 to false
    v[4] = false;

    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    // We store 5 bools but the vector needs 24 bytes
    std::cout << sizeof(v) << '\n';

    return 0;
}