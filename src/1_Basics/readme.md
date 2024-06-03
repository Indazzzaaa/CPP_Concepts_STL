# Topics Covered
    -   Data Types
    -   Decision Making Statements
    -   Loops
    -   Functions


# Info
-   Always use {} to initialize variables , it throws error if wrong type is assigned.
-   With float numbers always use 'F\f' in the end.
        otherwise compiler will first create double and then convert to float which leads into loss in precision.
-   In end of long  suffix them with 'L\l', other-wise compiler will first create int then cast to long.


# Format of data types
        -  int n1 = 10; // decimal
        -  int n2 = 0111; // octal
        -  int n3 = 0xff ;// hexadecimal
        -  int n4 =  0b11; // binary
        -  int n11 = 1'000'000 ; // formatting big number


# Formatting streams
        Use below keywords for formatting the streams  (#include<iomanip>)
        -       left, right, setw(10)
        -       fixed , setprecision(2) // to work with precision of floating numbers
        -       boolalpha // it used to show true or false instead for 0/1 for boolean values.
        -       noboolalpha // to turn the above manipulator off.

# Data Types
- char, short, int ,long  // can use modifiers signed and unsigned.
- float , double
- bool  // internally false=0 & true : all number which is not 0;

# Data types info (#include<limits>)
- sizeof(int)/sizeof(var) : gives info about how many bytes this data type occupies.
- numeric_limits<int>::max()/min()  // we can get the max and min value a data type can have.

                
# Tick with char
-    char ch = 'a' // if we print normally it will show `a` in console.
     cout << +ch // this will show the numeric value of its.

# Reading input from stream
-  First stream select its value on the basis of space between values or 
        newline character encountered which is inserted when we press enter.
-  getline(cin,name) // this is right way to read the big string.or we can provide the delimiter also.
                        it is found in using namespace std;


#  Intro to Array
- Array Name is address of first memory block.
- Array Stored
  - Stack : default value is  0
  - Heap  : default value is  garbage.
- we can use size(arr) function to get size of array stored on stack.
- Caution: in cpp we can access the element beyond the size of array and that's place we have to more cautious about.
    
# Type Conversion(Casting)
-  How expression are evaluated in cpp ?
        In cpp first compiler see's which is bigger data type,
        and then convert all data type to that one and then do the its defined operations.
- If the evaluation result we are storing in variable and if that variable is smaller size one then operations bigger one in that case we have to cast.
- C-style casting : (int)dVar; // if dVar can't be casted to int we would know only at runtime.
- Cpp-casting (preferred) : static_cast<int>(dVar) // it will tell at compile time if cast can't be happen.
   eg. int x=1; double y=2.0; int z = x + static_cast<int>(y); cout<<z;


# We can see the operators and Precedence and Associativity in cpp

# Decision-Making
- if(condition),elseif(another condition),else {//all fallbacks}
- Conditional operator : var=condition ? 1 : 2;
   Trick : conditional : (var1=1) : (var2=10);
- Switch Statement : normally used to avoid many if else-if. And with switch we can only have the equality comparisons.
        we can't compare in switch statements if value is greater or smaller.
        always insert break after each case and 'default' is like else for all other fallbacks.

# loops 
- Entry Control loops : for(initialize;condition;progress) , while(condition) {}
- Exit Control loops : do{} while(condition);
- For each loop : for(int num:number) // only works if iterators implemented on the type
        and numbers can also be `array` here , but that array must be created on stack.
- Note : We use `continue` and `break` to skip steps , or break out of loops.
          
# Functions
-  Function have `declaraion(function prototype)` , `definition` ,`calling function`.
-  In cpp function can have default values, but it should be from right and all parameters right to it must have default values.
-  And if we create function with same name but it take different parameter now it's called function overloaded.
-  Passing argument by value and reference
        value : void fun (int a,int b) {} // int this value will be copied on new memory a and b.
        Reference : void fun(int& a, int& b) {} // no new memory created.Saves time from creating new memory.
        Reference from Pointer : void fun(int* a, int* b) {} // we pass the address of variables in a and b.
         
# Local and Global
- Variables are visible to the scope they are declared.(called Local Variables)
- But global variables are visible everywhere and lifetime is entire program.

# Organizing files
- We create .hpp/.h file to put all our class and function declaration.
- And we provide there definition in .cpp file that not just improves manageability , but also saves compilation time.
        since .hpp will only have declaration , so until we change the declaration there won't be need to all files depends on those .hpp files.
# Using Namespace to organize 
eg. namespace messaging { void greet(std::string name);} // and greet definition will be in cpp file
   to use it ; add using namespace messaging , or messaging::greet.
- there is also way to bring only specific function from namespace
   eg. using messaging::greet;   using std::cout,std::cin;   // this way helps to avoid name conflicts , member in multiple namespace with same signature.