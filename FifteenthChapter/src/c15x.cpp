#include"Random.h"

#include<iostream>
#include<string>
/*
15.x Summary

- *this is const pointer which holds address of current implicit object
- *this returned by reference can enable method chaining
- class definitions should always be put in header files, non trivial member 
  functions should be defined in a source file with the same name as the class
- static member variables are static duration members that arre shared by all 
  objects of the class, they exist even if no objects of the class have been
  instantiated
- static member functions can be called with no object and can not access
  non-static member variables. they have no access to *this pointer
*/
// Question 1



class Monster {
public:
    enum Type {
        dragon,
        goblin,
        ogre,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

private:
    Type m_type {};
    std::string m_name {"???"}; 
    std::string m_roar {"???"};
    int m_hit_points {};
public:
    Monster(Type type, std::string name, std::string roar, int hit_points)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points}
    {}
    std::string getTypeString(Type type) {
        switch (type) {
            case dragon:
                return "dragon";
            case goblin:
                return "dragon";
            case ogre:
                return "ogre";
            case skeleton:
                return "skeleton";
            case troll:
                return "troll";
            case vampire:
                return "vampire";
            case zombie:
                return "zombie";
        }
    }
    void print() {
        std::cout << m_name << " the " << getTypeString(m_type) << " has " 
             << m_hit_points << " hit points " << "and says " << m_roar << '\n'; 
    }
};

namespace MonsterGenerator 
{
     std::string getName(int number) 
    {
        switch (number) 
        {
            case 0: return "Blarg";
            case 1: return "Marc";
            case 2: return "Andre";
            case 3: return "Pierre";
            case 4: return "Timo";
            case 5: return "Lennart";
        }
    }
    std::string getRoar(int number) 
    {
        switch (number) 
        {
            case 0: return "*ROAR*";
            case 1: return "*meow*";
            case 2: return "*boo*";
            case 3: return "*urgh*";
            case 4: return "*ahhh*";
            case 5: return "*hahaha*";
        }

    }
 
    Monster generate() 
    {   
        return Monster
        { 
            Monster::Type(Random::get(0, 6)),
            MonsterGenerator::getName(Random::get(0, 5)),
            MonsterGenerator::getRoar(Random::get(0, 5)),
            Random::get(0, 100) 
        };
    }

}



int main() {
    Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

	Monster m{ MonsterGenerator::generate()};
	
    m.print();

    return 0;
}