#include<iostream>
#include<cstdarg> // needed to use ellipsis

/*
12.6 Ellipsis (and why to avoid them)
ellipsis (aka "...") allows to pass a variable number of arguments to a function

We should not use ellipsis at all if possible to avoid!
it omits type checking which is generally never a good idea
There are different options for a flexible amount of paramaters that need to be
passed to a function (e.g. dynamically sized array)

if you have to use it, make sure, that all parameters passed via the ellipsis have
the same type. Mixing them might cause the caller to mix up themselves, count 
parameters or decoder string are generally safer than using a sentinel value

*/


double findAverage(int count, ...) {
    int sum{ 0 };

    //We access the ellipsis through a va_list, so lets declare one
    std::va_list list;

    //We intialize the va_list using va_start. The first argument is
    //the list to initialize. The second argument is the last non-ellipsis
    //parameter.

    va_start(list, count);

    //Loop through all the ellipsis values

    for (int arg{ 0 }; arg < count; ++arg) {
        //We use va_arg to get values out of our ellipsis
        //The first argument is the va_list we're using
        //The second argument ios the type of the value
        sum += va_arg(list, int);
    }

    //Cleanup the va_list when we are done
    va_end(list);

    return static_cast<double>(sum) / count;
}



int main() {

    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';

    return 0;
}