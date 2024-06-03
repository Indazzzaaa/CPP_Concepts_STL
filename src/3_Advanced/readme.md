# Topics
    -   Classes
    -   Exceptions
    -   Templates
    -   Containers

[Concepts]
1.classes
2.Operator Overloading ( Static Binding ,aka (Compile time Binding)=> Happens with the ormal (non-virtual) member functions and with function overloading.)
3.Friends of classes : We have seen that when overloaded stream operator.
4. inline functions : compiler replace the function calls with function definition, not recommended for function with more then 1 line. and it's upto compiler to decide what to do with them.
5. Access Modifier : public , private, protected
6. Inheritance
   ->> Constructors : are called from base to derived order(top-down)
   ->> Destructors  : are called in reverse order.
7. Overriding : used for cases where we want to give flexibility to derived class to define there own way how that method to be implemented.(Dynamic binding(aka runtime time binding) this happen only when we declare methods in base class as virtual , if not then Static binding will as explained above.

8. Polymorphism : We achieve this using the pointers,and overriding method		with virtual keyword.
9. Abstract Class : classes with pure virtual method.
   ->> Syntax: virtual void draw() const =0;
10. Final classes : to prevent classes and methods from extended and		 override . We can protect our methods and classes by using final keyword.
    ->> Syntax : void draw() const  final override;
    ->> For class: class ClassName Final : public BaseClass {};
    Exceptions
    Templates
    */

`Advice from MOSH` : don't go for deep inheritance hierarchies , limit them to maximum 3 levels.Even we have to duplicate something then also , too much of good thing is also a bad thing.

[Note]
You'll notice each file has .hpp and .cpp file reason , is to reduce the compile time.
So if we make changes to .hpp then only this file and other file depends on that will be compiled.
And if we make changes to .cpp then only cpp will have to compile and since all files depends on .hpp and we assume signature will be same so nothing will be compiled except the cpp file.

# Classes
- Classes in any language is just blueprint. It does not allocate memory itself.
- Encapsulation : Combining the data and functions that operate on the data into one unit.
- Cpp compilers creates : constructor , destructor , copy constructor, assignment operator for every class by default until we tell it by using delete keyword.
[Access Modifiers]
- public : (Visible everywhere)default for struct.
- private : (visible only in class)default for classes.
- protected : visible in only derived classes.

[Parts of classes]
Keywords : default(to specify in code we are using default compiler one), explicit(stop compiler from implicit conversion), delete(to tell compiler not create this)
            mutable (To mark variables with this name so it can be modified in the const functions.)
            creating object with const keyword : only the methods marked const can be called.And any member variables can't be modified.
1. Constructor:
        Assign values(efficiently ) or run some important functions. Or call parent constructor.
        Use explicit keyword to stop compiler from implicit conversion.
2. Destructor:
        Useful for de-allocating the data , by calling delete for class pointer or implicit by compiler for variable created on stack and when it goes out of scope.
        We can create virtual destructor to delete the child class memory using  parent class pointer.

        

        
   

