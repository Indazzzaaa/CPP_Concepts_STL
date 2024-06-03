# Topics
    -   Arrays
    -   Pointers
    -   Strings
    -   Structures
    -   Enumerations
    -   Streams


# Arrays
-   Used to design cache friendly systems.
-   In cpp array can  be created at both places on stack and heap.
-   Arrays name is const pointer to first memory address in the chunk.
-   When we pass stack created  array to function it looses it's size information called array decay.
-   1D array values can be accessed as : a[index] / *(a +index);
  - ## Extra
    - Array created on stack has default value of 0 for int.
    - Array created on heap has garbage value. Make sure to de-allocate , delete[] arr;
    - For stack created array we have two-way to know it's size(only in place where array created otherwise in another function we have to pass it's size.)
      1. for integer array = sizeof(arr)/sizeof(int)
      2. using size function = size(arr)
    - Always use `size_t` to store the size of array , it's special data type specifically designed for this purpose.
    - Array Destructing(name in python cpp calls something else)
         auto [x,y,z] = numbers;

# About new and delete
1. They are used to allocate dynamic memory on heap and de-allocate it.
2. When memory is allocated using new eg`int* var new int; then it's delete like ` delete var`;
3. But if memory is allocated using new[] then it's deleted using delete[]
    eg. int* var = new int[10]; delete[] var;


# Pointers
1. Special kind of variables that stores memory address of another variable.
2. It is used in : Efficiently pass large objects , Dynamic memory allocation , Enabling Polymorphism.
3. Operators used : &(address of operator), *(de-ref operator) , ->(in-direction operator)
4. null , nullptr : null means 0 never use it it's not type same , use nullptr (it's type safe way to point to nothing)
5. ptr+1 / ptr++ , ptr--/ptr-1 // called pointer arithmetic which help to go next and previous memory address.
        this is how it works, with the pointer data type it know what's block size and with number we provide it calculate how many jumps it needs to take.
    ## Pointers and constants
        1. Data is constant(poiner can refer to another memory address , but can't change the data stored on them).
                int* const ptr;
        2. Pointer is constant(can't refer to another memory address) 
                const int* ptr;
        3. Bot data and pointer is constant.
                const int* const ptr;

# Smart Pointers  (#include<memory>)
-   The problem we deal with pointer is we have to always delete the memory we allocate .
        and if we don't then it would lead to memory leak. And also using delete ptr twice can lead to our  program/system crash.
- Smart pointer solves the above issues. It takes care of free-up the storage.
  ## Types
        1. Unique Pointer : No two pointer can point to same location. It does not allow pointer arithmetics.
                            Can use to create singleton objects.
                            syntex : unique_ptr<int> x(new int(10)); auto number= make_unique<int>()/make_unique<int[]>(10)//array of size 10;
                            To move ownership :  // Creating another unique pointer and transferring ownership
                            std::unique_ptr<int> ptr2(std::move(ptr1));    // now ptr1 will be nullptr

        2. Shared Pointer : With this we can have multiple pointers pointing to same memory location. 
                            and like unique pointer it takes care of free up the memory.
                            syntex : shared_ptr<int> x = make_shared<int>();
                            To share : shared_ptr<int> ptr2 = x;


# Strings
- One of the main problems with `C-style strings` (character arrays terminated by a null character, '\0') 
        is that they do not carry information about their length. This lack of length information can lead to 
        several issues, such as buffer overflows, memory corruption, and difficulty in handling strings dynamically.
- `CPP String` : solves this issue by encapsulating the dynamic array of characters with its length.
                and it also take care of allocating and de-allocating of memory.
- `CPP string` is not any new type , it works on top of char array and its apis are similar to vector because under the hood it uses same.
[String Features]
  1. assignment operator creates deep copy like vector. eg. string name2 = name1 // creates deep copy.
  2. we can use operator to append string . eg. name2+="Pate";   and name1==name2 to compare strings.
  3. APIs : length(), front(),back() // for use as queue.
  4. Insert : insert,replace, erase,clear.
  5. Search : find, rfind,find_first_of(",.;"),find_las_of(",.;") // find from first or from last occurrences of these characters.
  6. extract substring : name.substr(start,number of chars) => returns deep copy.
  7. There is string view class explore it, it will help us to use same string for its substring.

-  converting string to other type like double or int : stoi(str) ->int, stod(str)->double;
- converting int or double to string : to_string(19),to_string(19.90)
- Escaping chars : eg. "c:\\my_folder" , '\'' for printing ' int char.
- Raw String : R"(c:\my_folder): => after typing first word R , everything inside parenthesis will be treated as raw string.

[String View] (#include<string_view>)
- Every time we try to extract the substring from string we get the new string.To save us from these string_view was created in cpp17.
- String_view : this is wrapper around the string , which does not copy the data our returns the view of it. See the StringTest.h file.
- We can create string_view from : 1. another string 2. String literals 3. Character array.

[Span] (#include<vector> , #include<span>)
- just like string_view , there is span available to work with view of vector(which can hold any data type.)  And do all other operations.
- We can create span from array , vector.  But we have to mindful when dealing with multidimensional array we have to deal with flatten way.


# Structures
- In cpp structures are only there for compatibility reasons with c.
- cpp structure are similar to cpp classes except. 1. all the things in structs are private by default. 
- We can do all things with structs as with classes like : operator overloading,templates,inheritance,Access control,constructor destructors,member functions,member variables.
- Structs are normally used in places where we just have to create complex data type , while we use classes where we have to bind methods with data too.

Q. We can assign the value for int or float or any primitive this way : () , {} , can we do same for struct and classes and what about arrays.
eg.1 Simple struct(string title,int year)
           Movie s{"Terminator",1984};  even we can define the nested struct like below
            Movie s{ "Terminator",1984,{1984,1,1} }; there is another struct date.
eg2. Now array of struct
        Movies movies[] = { {"Terminator: , 1984},{"Star Trek",1997}};

eg3. De-structuring the struct // like array we can destructure the structs too.
        auto [title,release_year] = s;
    
# Enum
- We used the enum to define the constants with name which will not change through out the program.
- Eg. Days of week, Moth of year, Start/Strop/Turn etc.
- Every enum value starts with 0 , until we define other value and subsequent will be +1 last one.
eg. enum Action { LIST, ADD,UPDATE};  // issue with this approach is we can't create another enum with LIST in it.
    solution : create enum with class keyword.
        enum class Operations {LIST=1,ADD,UPDATE};


# Diff between normal enum and class enum
1. Scope:
    Enum: Enumerators declared without the class keyword are placed in the same scope as the enclosing scope. This means that enumerators can potentially cause naming conflicts with other identifiers in the same scope.
    Enum class: Enumerators declared with the class keyword are scoped enumerations, meaning their enumerators are scoped within the enum class. This provides better encapsulation and avoids naming conflicts.
2. Type Safety:
    Enum: Enumerators are implicitly converted to integers, which can lead to unintended behavior, such as comparing enumerators from different enums.
    Enum class: Enumerators are strongly typed. They are not implicitly convertible to integers, and explicit conversion is required to convert between enum class values and integers.
3.  Underlying Representation:
     Enum: By default, enumerators are represented using integral types (usually int), and you can explicitly specify the underlying type.
     Enum class: The underlying type of enumerators is not implicitly defined. You can explicitly specify the underlying type using a colon after the enum class name.
  
# Static and dynamic cast
1. Static Cast : preferred way to do typecasting at compile time. eg. static_cast<int>(var_name);
2. Dynamic cast : Dynamic casting in C++ is used to perform safe down-casting and cross-casting of pointers and references within the class hierarchy. It's primarily used in the context of polymorphism to convert a base class pointer or reference to a derived class pointer or referenceIt's use to downcast from base class to derived class at runtime. Only works if we derived class existed in hierarchy . Eg. if we create object to base class then we try to use that pointer to cast to derived class then it won't work.
    eg. dynamic_cast<Derived*>(basePtr);
3. There is other casting operators too :  const_cast, reinterpret_cast<new_type>(expression);

# Streams  (#include<limits> , #include<iostream>)                                       
- Streams : Sequence of bytes
- Data Sources : Terminal(console : cin, cout), File, Network
- Available Streams : istream, ostream, ifstream, ofstrem, istringstream, ostringstream.
- Buffer : temporary storage where our input from console is stored.
- [10 20] : if we give 10 20 separated by space it will go and stored in buffer.
  So result is , once we read from cin , it will take 10, but next time when we use cin
  it won't ask user , it will directly pick the 20 , because it sees there is 20 already present.
- Solution : after every read we can clear the buffer like this: `cin.ignore(numeric_limits<streamsize>::max(), '\n');` , streamsize is the inbuilt variable which used for storing the size of stream allowed.
    In this first we pass number of char we are ignoring, and then the delimiter after we have to consider.

Q. What if user has entered the wrong value (eg. int val; user giving char or string which are considered wrong value , but float , int , double are considered ok);
- cin.fail() // this function will help to know whether the number entered was wrong type or not.
- cin.clear() // which will help to clear the state of cin , which was fail earlier.
- see eg. StreamTest:get_input

[File Stream]     (#include<fstream>)
- Types of files 
    Text Files : Takes 1 byte for each `asci` character , used for designing files which humans can read.
    Binary File : Not designed for humans , just for machine to interpret. We use `.dat` or `.bin` as extension to represent binary files.
- Types of File Stream
    ifstream: reading data from file.
    ofstream: writing data to file.
    fstream : used for both reading and writing data.
- Few function to now : file.open(),file.is_open() ,file.close(), file.eof() ,reinterpret_cast<char*>(&num)    .
        file.open("file.txt", ios::in | ios::out | ios::app | ios::binary);
- For Examples see : FileStreamTest.h

[String Stream] (#include<sstream>)
- String Streams : used for manipulate the string as they are stream, like we manipulate the input output streams.
    And they work on in-memory and expand if needed more memory.So very efficient.
- String stream classes
    istringstream: reading stream
    ostringstream : writing stream
    stringstream  : both read and write.
- For more examples see StringStream.h file.

