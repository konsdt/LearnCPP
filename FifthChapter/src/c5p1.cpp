#include <iostream>

#define PROJECT_NAME "Operators"

// 5.1 Operator precedence and associativity
// "Precedence" defines order in which operators are evaluated(e.g. math)
// "associativity" tells the compiler in which order to evaluate adjacent 
// operators if their precedence has the same level
// "parenthesization" change order of execution () have one of the highest 
// precedence level
// /Best Practice/ Use parantheses to make it clear how a non-trivial expression
// should evaluate. (Even if they are technically unnecessary.)
// /Best Practice/
// Outside of operator precendence and associativity rules, assuem that the parts
// of an expression could evaluate in any order. Ensure that the expressions you
// write are not dependent on the order of evaluation ot those parts.
// 5.2 Arithmetic operators
// "int and float division": if both operands are ints any fraction that results
// from division is simply dropped! Use static cast to double to avoid it
// Assignment operations work: x = x + 4 <=> x += 4.

int main(int argc, char **argv) {
    if(argc != 1) {
        std::cout << argv[0] <<  "takes no arguments.\n";
        return 1;
    }
    std::cout << "This is project " << PROJECT_NAME << ".\n";
    return 0;
}
