#include <iostream>
#include <string_view>

enum  MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};



struct Monster
{
    MonsterType monsterType { orc };
    std::string_view name { "Peter" };
    int health { 100 };
};


constexpr std::string_view getMonsterName(Monster m)
{
    switch (m.monsterType)
    {
        case ogre:
              return "Ogre";
        case dragon:
              return "Dragon";
        case orc:
              return "Orc";
        case giant_spider:
              return "Giant spider";
        case slime:
              return "Slime";
        default: 
              return "Error: Monster has no name\n";
    }
}

void printMonster(const Monster& m)
{
    std::cout << "This " << getMonsterName(m) << " is named " << m.name << " and has " << m.health << " health.\n";
}


template <typename T>
struct Triad
{
    T first {};
    T second {};
    T third {};
};

template <typename T>
void print(const Triad<T>& t)
{
    std::cout << "[" << t.first << ", " << t.second << ", " << t.third << "]";
}

int main()
{
    Monster m1 { ogre, "Torg", 145 };
    Monster m2 { slime, "Blurp", 23 };
    
    printMonster(m1);
    printMonster(m2);

    Triad t1 {1, 2, 3};
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 };
    print(t2);

    return 0;
}
