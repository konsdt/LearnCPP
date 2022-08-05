#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    constexpr double pi { 3.1415926 };
    constexpr double avogadro { 6.0221413e23 };
    //this is the prefered way with c++ => 17, because it saves lots of memory
    inline constexpr double myGravity { 9.18 };
    // ..etc.
    inline constexpr int max_class_size { 35 };
}
#endif
