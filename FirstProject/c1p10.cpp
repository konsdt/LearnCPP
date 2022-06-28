// five() is a function that retrunds the value 5
//

int five() {
    return 5;
}

int main() {
    int a{ 2 };          // initialize variable a with literal value 2
    int b{ 2 + 3 };      // initialize variable b with computed value 5
    int c{ (2 * 3) + 4}; // initialize variable c with computed value 10
    int d{ b };          // initialize variable d with variable value 5
    int e{ five() };     // initialize variable e with function return value 5

    // All of these initialization make use of an "expression":
    // Combination of literals, variables, operators and functions calls that
    // can be combined to produce a single value
    // Execution an expression is called "Evaluation" and the single value is
    // called "result"
    // Expressions do not end with a semicolon and can not be evaluated by
    // themselves "x = 5", rather they are evaluated in a statement:
    int x{ 5 };
    // this broken down into its syntax would be:
    // type identifier{expression};
    // -> Wherever a single value is used an expression can be used instead, 
    // which will be evaluated into a single number
    // any expression can be converted into an expression statement like:
    x = 4;
    // when this statement is executed the expression is evalueated and the 
    // result of the expression will be discarded
    //
    return 0;
}
