

// 2.9 naming collisions and intro to namespaces:
// most naming collisions occur in two cases
// 1. Two or more definitions are introduced in seperate files, therefore it will
// compile fine, but the linker will throw an error
// 2. Two or more definitions are introduced in the same file, the compiler will
// throw an error.
//
// A namespace will allow you to declare names inside it for the purpose of 
// disambiguation. The namespace is a scope region and names declared inside it
// can not be mistaken for identical names in other scopes.
//
// Any name that is not defined inside a class, function or namespace is auto-
// matically part of the global namespace(global scope) 
// Declaration and Definition statements can appear in the global namespace
// expression statements can not be in the global namespace e.g.
// x = 5; can not appear in the global namespace
//
// All functionality of the standard library lives in the standard namespace 
// calles "std"
// Therefore when looking for an identifier that is defined inside a certain 
// namespace, one needs to tell the compiler the namespace e.g. std::cout
// This is the best practice!

int main()
{

    return 0;
}
