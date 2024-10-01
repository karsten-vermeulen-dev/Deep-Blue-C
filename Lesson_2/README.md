# Lesson 2: _Refresh my memory_

Memory is a storage space that holds data for a finite time. It’s used by desktop applications, games, apps, etc., to store specific data. Many devices and hardware peripherals today have some form of memory installed, with storage limited to a particular amount. PCs, laptops, consoles, tablets, smartphones, graphics cards, you name it, hold _Random Access Memory_, or RAM. In C++, memory is allocated and managed by using _variables_.

## "I now declare you to be a variable"

Variables are temporary storage spaces in memory that contain data for the program and are identified by an address. Data is stored as binary bits and bytes and represented differently based on the variable type. 
To create a variable, we must declare it first, which tells the compiler that you wish to use the following named memory block to store your data. The compiler will set some memory aside for you so that you can use that variable to store your data. Each variable has a type, which tells the compiler how much memory to set aside. Therefore, it’s imperative that when declaring variables, we specify their type and a suitable name.

```cpp
char letter;
int number;
float decimal;
```

Variable names in C++ are case-sensitive and should always start with a letter. They may contain numbers and underscores after that. You should always follow a standard when naming your variables. If you have not set your own, follow common _coding standards_ set by either your employer if you're working on a team or your lecturer if you're studying at university. A general standard for naming variables is to use _Camel Casing_, i.e., `thisIsAVariable`.

Declaring multiple variables of the same type can be done in one line, like so:

```cpp
int number1, number2, number3;
```

Variable types come in two forms, namely _fundamental data types_ and _object data types_. Variables can also be classified as _value types_ or _reference types_. Depending on where the variable is declared in the code, it is said to have a particular _scope_. A variable's value can be altered as and when needed during the program unless it is declared as a _constant_. More on all of this a little later on in the show.

## Initializing variables

When declared, variables will initially contain random values or garbage data based on their type. Initializing a variable as soon as it is declared is always good practice.

```cpp
int age = 100;
char letter = 'k';
double velocity = 24.5;
```

You can also declare and initialize variables in one single line, like so:

```cpp
int number1 = 10, number2 = 20, number3 = 30;
```

Furthermore, we can initialize variables using existing variables, like so:

```cpp
int number1 = 1000;
int number2 = number1;
int number3(number2);
```

## Brace wars

While the above method of initializing is not wrong, a more modern approach would be to use _brace initialization_:

```cpp
int age {100};
char letter {'k'};
double velocity {24.5};
int number1{ 10 }, number2{ 20 }, number3{ 30 };
int number1{ 1000 };
int number2{ number1 };
int number3{ number2 };
```

The wonderful thing about brace initialization is that the compiler will scream at you if you accidentally cause a _narrowing conversion_, which might occur if the data types differ. Consider the following:

```cpp
float floatNum = 10.234f;
int intNum = floatNum; 
```

What happens above is that the **.234** portion of the number is lost, assigning the whole number **10** to `intNum`. While this is not serious and will only yield a warning, it might create runtime bugs later down the line that might be hard to track down. Instead, we can use _brace initialization_ that will produce a compiler error and explicitly remind us that we are making a conversion:

```cpp
float floatNum{ 10.234f };
int intNum{ floatNum }; 
```

Brace initialization may also be termed _list_ or _uniform initialization_ and may not always be your desired solution. There are various (sometimes heated) discussions online about when, where, how, and why to use them. If you choose braces, stay consistent in your codebase unless it cannot be used in a particular situation. We will revert to **not** using brace initialization for the remainder of the lesson material.

## Assigning values to variables

Initializing variables only happens when declaring the variable and assigning it a value straight away to avoid garbage data. Variables may also be assigned data throughout their lifetime or scope unless it’s been declared a constant (More on that later). 

```cpp
number1 = -10;
number2 = 2.345f;
name = "Karsten";
```

We can also assign an existing variable to another, like so:

```cpp
firstNumber = anotherNumber;
```

Assignment chaining is also supported and allows us to assign different variables to each other: 

```cpp
number1 = number2 = number3 = number4;
```

Assignment chaining works from right to left, meaning the value of the variable on the right is assigned to all other variables. When assigning variables of different types to each other, a narrowing conversion may occur, just like when they are initialized. Again, a warning will appear to inform you of this potential problem, and we should always heed the warning before it becomes a runtime issue. 

```cpp
float floatNum = 10.234f;
int number = floatNum;
```

To do this, we cast the variable into the data type we wish to store it as.

```cpp
number = (int)(floatNum);
```

However, if you can, prefer to use the modern style of typecasting, i.e., `static_cast<>` instead of the older C-style cast.

```cpp
number = static_cast<int>(floatNum);
```

## Fundamental data types

So far, we have been demonstrating straightforward data types, also known as _fundamental data types_, and these are built into the C++ language. Also known as _built-in_ or _intrinsic types_, they include the following:

| Data type   | Description    |
| ----------- | -------------- |
| int         | Stands for integer and is a whole number such as 1, 900 or -23                      |
| float       | This is a floating-point or real number that contains decimal values                |
| double      | This is also a real number with double the precision of a _float_ type              |
| bool        | This holds two types of values, namely true or false                                |
| char        | This contains only a single character or single digit number, such as A, x, 0 or 9  |

The _char_ and _bool_ data types are numeric, meaning they store numeric values. The value stored inside a _char_ is the _ASCII_ code of the stored character. When storing _bool_ data, although we conventionally would store `true` or `false`, you can store any 8-bit number in the variable. Any non-zero number is interpreted as `true`, and storing a 0 would mean `false`.

The above intrinsic data types may also be declared using type modifiers, which further specify how large or small that variable is or if the variable can also store positive and negative numbers. For instance, a `long long int` may use up more storage than a `short int` and thus may be assigned more values. An `unsigned int` cannot hold any negative numbers. See the table below to view them:

| Modifier    | Description    |
| ----------- | -------------- |
| long        | Works only with int, float and double data types to increase the range of values they can store   |
| short       | Works only with int types and decreases the range of values they can store                        |
| signed      | Works only with int and char types and allows them to represent positive and negative numbers     |
| unsigned    | Works only with int and char types and restricts them to only representing positive numbers       |

Because fundamental data types come built into the compiler, different compilers may represent them differently in memory. The type modifier may also be used without the data type to declare a variable. For instance, using `long` would be the same as `long int`. When using signed and unsigned modifiers, beware of integer wrap-around.

For those of you who are curious as to how much storage each of these variables requires, as well as what range of values each variable can store, see the comprehensive table below:

| Data type               | Size      | Range                                                   |
| ----------------------- | --------- | ------------------------------------------------------- |
| bool                    | 1 byte  | true or false                                             |
| char                    | 1 byte  | -128 to 127                                               |
| unsigned char	          | 1 byte  | 0 to 255                                                  |
| float                   | 4 bytes | -3.4e±38 to 3.4e±38 (7-digit accuracy)                    |
| double	          | 8 bytes | -1.7e±308 to 1.7e±308 (15-digit accuracy)                 |
| int                     | 4 bytes | -2,147,483,648 to 2,147,483,647                           |
| unsigned int            | 4 bytes |	0 to 4,294,967,295                                      |
| short int	          | 2 bytes | -32768 to 32767                                           |
| unsigned short int      | 2 bytes | 0 to 65535                                                |
| long int	          | 4 bytes | -2,147,483,648 to 2,147,483,647                           |
| unsigned long int       | 4 bytes | 0 to 4,294,967,295                                        |
| long long int	          | 8 bytes | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807   |
| unsigned long long int  | 8 bytes | 0 to 18,446,744,073,709,551,615                           |

## Wrapping numbers
More info on this topic coming soon...

## Object data types
These data types are external to the built-in C++ types that come with the language. They can also be types you created yourself, such as a _struct_ or a _class_:

```cpp
class ClassType
{
    //definition...
};

struct StructType
{
    //definition...
};

ClassType myOwnClass;
StructType myOwnStruct;
```

Object types can also be data types that belong to an external library, such as the _Standard Library_, a popular example being the _std::string_ data type. Other types include _vectors_, _fstream_, _maps_, etc, which we will delve into later. With object types, we can usually perform operations on them, such as finding the length of a _std::string_ by using its `size()` member function. 

## Structs

In ye olde days of C, a collection of variables was grouped using something called a _struct_. This allowed related data to be self-contained within a particular entity. They are still in use today in C++ and behave almost the same as _classes_, with minor differences. One slight difference is that the members of a struct are `public` by default. Structs are great for grouping data without any other complexities. However, it’s always best to stick to classes as much as possible.

A struct can be defined using variables such as built-in types, arrays or other object types:

```cpp
struct MyStruct
{
    int number;
    float anotherNumber;
    std::string name;
};
```

Structs can be instantiated on stack space or heap space, just as previously demonstrated with regular variables:

```cpp
//create object on the stack
MyStruct aStruct;
//create object on the heap
MyStruct* anotherStruct = new MyStruct;
```

Objects of a struct may also be instantiated right after defining the struct, like so:

```cpp
struct MyStruct
{
    int number;
    float anotherNumber;
    std::string name;
} aStruct;
```

Alternatively, objects can be initialized straight away:

```cpp
MyStruct aStruct = { 100, 1.23f, "Frank" };
```

To access any member of a statically created struct, we can use the direct member operator (.) like so:

```cpp
aStruct.name = "John";
aStruct.number = 100;
aStruct.anotherNumber = 1.234f;
```

If the object lies on the heap, we would need to use the indirect member operator (->):

```cpp
anotherStruct->name = "Jack";
anotherStruct->number = -200;
anotherStruct->anotherNumber = -2.34f;
```

We will return to structs later in the course, leading us to discuss classes, so stay tuned or flip ahead to the OOP lessons. 

## A very brief look at _std::string_

Let's now look at the `std::string` data type and see how we can declare, initialize and store data in a variable of this type.

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "John Smith";
    std::cout << "My name is " << name;
}
```

Outputting the string data to the console is as simple as any other data type, but inputting is tricky. If we use `std::cin`, all whitespace is ignored if multiple words have spaces in between because only the first word is captured. To alleviate this problem, we could use multiple string variables and capture all words, like so:

```cpp
std::string firstName, lastName;
std::cin >> firstName >> lastName;
std::cout << "My full name is " << firstName << ' ' << lastName << std::endl;
```

The problem with the above method is that we need to know the number of strings we require and add manual spaces between them when displaying the name. This is very laborious. A much more preferred method is to use the `getline()` function, which works as follows:

```cpp
std::string fullName;
std::getline(std::cin, fullName);
std::cout << "My full name is " << fullName << std::endl;
```

The `getline()` function uses the `std::cin` stream object and the variable to store the string in, which in this case is `fullName`.
	
## Value types

Value types are variables that store the actual value in their memory location. These types of variables are created on the _stack_, and this is known as _static memory allocation_:

```cpp
int number;
float anotherNumber;
ClassType myOwnClass;
```

## Reference types

Reference types are variables, also known as _pointers_, that store the _address of other variables_, thereby referencing these variables and the data they store. These variables usually point to data created on the _heap_, and this is known as _dynamic memory allocation_:

```cpp
int* number = new int;
ClassType* myOwnClass = &otherClass;
std::unique_ptr<SomeType> smartPtr(new SomeType);
```

## The scope of a variable

Variables have a particular scope within which they are valid and can be used, and they can be classified as having _global_ or _local scope_. The scope of a variable is determined based on what block of code it is declared in, and when used outside of this block, the compiler will not recognise the variable, and errors will arise. Global variables have the broadest scope in a program and are accessible anywhere and everywhere. They are usually declared within header files or outside the `main()` function in _main.cpp_.

```cpp
int globalNumber = 999;
char globalLetter = 'G';

int main()
{
    //main stuff
    //use global variables here
}
```

Alternatively, variables with a local scope are local to a particular block of code and are only accessible within the units they were created within. They usually exist in functions or any other blocks of code surrounded by curly braces ({}), such as `if-else` statements or loops:

```cpp
for (int i = 0; i < 100; i++)
{
    //Do something with the local variable i
}
```

Variables in different scopes are independent of each other and are allowed to share the same name. The variable in the inner-most scope takes precedence over the outer one. The code snippet below shows that the first declared `number` variable is local to the function and will cease to exist when the function ends. It has a different scope to the `number` variable declared within the `while` loop:

```cpp
void DoSomething()
{
    int number = -1234;

    while (true)
    {
        int number = 1234;
    }
}
```

Remember to use global variables wisely and sparingly. It is best practise to keep variable declarations as local as possible because too many global variables will decrease the maintainability of an application and increase what is known as _coupling_. 

## Constants

Sometimes, you may want values to remain unchanged throughout the program. For this, we use _constants_. These special creatures are declared just like their friendly variable counterparts, except they use the keyword `const`, like so:

```cpp
const float gravity = 9.87f;
const double Pi = 3.14159265359;
```

Using uppercase letters when naming constants (`GRAVITY`) has always been a standard convention. However, in modern times, this is starting to become debatable. You will find a plethora of code out there written in this manner, and there is nothing wrong with this. It depends on the coding standard, of course, but it’s generally not preferable. For starters, it's tedious to hold down the _Shift_ key when spelling constants, and for names with two or more words in them, such as `maximumBlastForce`, there is the dreaded underscore character you would need to insert to make it more readable, i.e., `MAXIMUM_BLAST_FORCE`. <br>
Besides creating and using constants to prevent changes to a variable, they also provide other benefits, such as improving the code readability by removing the use of literal values, also known as _magic numbers_. Constants make the code easier to debug, meaning only one change is needed instead of many. We can also use a set of constants as an _enumeration_. <br>
Constants need to be initialized, and from that point onward, their values cannot be altered, else the compiler will generate an error. Alternatively, another common method to ensure unchangeable values is using the preprocessor macro `#define`, which should be avoided in a modern C++ world if possible.
 
## Enumerations

This is a range of constant integer values, also known as _enumerators_, which allow us to create our own range of values by giving each enumerator a specific name. To create an enumeration, we do so using the enum keyword, like so:

```cpp
enum Directions
{
    North,
    South,
    East,
    West
};
```

Now, we can go ahead and create a variable of the type `Directions` and use it like any other:

```cpp
Directions myDirection = East;
```

The first enumerator will be 0 by default when we create enumerations. All subsequent values will be 1, 2, 3, etc. We can also explicitly set a value for the enumerators. 

```cpp
enum Directions
{
    North = 1,
    South = 2,
    East = 4,
    West = 8
};
```

Alternatively, only the first enumerator can be set, and the others will follow suit with incrementations of 1. 

```cpp
enum Directions
{
    North = 1,
    South,
    East,
    West
};
```

While the above enum definitions work fine, a more modern approach would be using an `enum class`. Consider the following enum definitions:

```cpp
enum Days
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum Directions
{
    North,
    South,
    East,
    West
};
```

Without an enum class in place, the enumerators can be used interchangeably, which leads to confusing logic in the code:

```cpp
Directions myDirection = North;

if (myDirection == Monday)
{
    //This will run because North and Monday are 0
}
```

To define an `enum class`, add the **class** keyword in the definition.

```cpp
enum class Directions
{
    North = 1,
    South = 2,
    East = 4,
    West = 8
};
```

Remember to ensure that the exact enum type is specified when assigning values.

```cpp
Days myDay = Days::Monday;
Directions myDirection = Directions::North;
```

## Some very special keywords

Before moving on to the next section of this lesson, we will end with some special C++ keywords that can be used with variables and their data types. 

### `sizeof`
This determines the size, in bytes, of the variable or data type used: 

```cpp
int number;

//Determine size of variable
sizeof(number);

//Determine size of data type
sizeof(int);
```

### `auto` 
This keyword will allow the compiler to determine what data type best suits the variable. (More on this later).

```cpp
auto variable = "Jack"; //variable is a const char*
auto variable = -2;     //variable is an int
auto variable = 2.45;   //variable is a double
```

### `typedef`
This allows you to substitute your own name in place of the data type’s name: 

```cpp
typedef unsigned long long VeryLong;
VeryLong number = 100'000'000;
```

## Arrays

These are a collection of variables of the same data type that form a single unit and are stored in contiguous areas of memory sequentially and ordered. In terms of dimension, arrays can be _one-dimensional_ or _multidimensional_ and come in two primary flavours, namely:

### Static arrays
These are fixed, and their sizes are determined at compile time and cannot be changed for the entirety of the running program.

### Dynamic arrays
More flexible than their static counterparts, the sizes of dynamic arrays can be altered during runtime.

## One-dimensional arrays

To declare an array of a particular type, we do this:

```cpp
int intNumbers[4];     //an array of 4 integers 
char letters[500];     //an array of 500 characters
float realNumbers[6];  //an array of 6 floats
```

Declaring an array works with constants and not with standard variables. The default values the compiler assigns to the array elements will be garbage values. Therefore, it is best to initialize the array.

```cpp
//initialize all elements to 0
int intNumbers[4] = {};

//initialize all elements to specific values
float realNumbers[6] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f };

//initialize only some of the elements
char letters[500] = { 'a', 'b', 'c', 'd' };
```

We could also leave out the array length between the square brackets and let the compiler determine the size based on the initializer list:

```cpp
//an array of 3 elements
int intNumbers[] = { 100, 200, 300 };
```

We could also make use of a constant to determine the size of the array, like so:

```cpp
const int arrayLength = 10;
int myNumbers[arrayLength];
```

Arrays are zero-based, which means their indexes begin at element 0. To access an element of an array, use the index value between square brackets:

```cpp
float myNumber = realNumbers[4];
```

To assign a value to an array element, we do the same thing we did when we assigned a regular variable:

```cpp
realNumbers[0] = 0.1f;
```

Beware not to overstep the bounds of an array. Accessing an element that is out of bounds is known as a _buffer overflow_ or _fence-post error_ and will generate a runtime error.
 
## Multidimensional arrays

Arrays are not restricted to only one dimension. They can also be multidimensional, also known as an _array of arrays_. For instance, to create a 3x3 array, we do the following:

```cpp
int myArray[3][3];
```

The above declaration will create an array of three rows by three columns. Therefore, when initializing the array, we could do this:

```cpp
int myArray[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
```

However, aesthetically, it might be better to use as many parentheses as possible to make the code more readable:

```cpp
int myArray[3][3] = { { 1, 2, 3}, { 4, 5, 6}, { 7, 8, 9} };
```

We can take our readability one step further and do this:

```cpp
int myArray[3][3] = { { 1, 2, 3},
                      { 4, 5, 6},
                      { 7, 8, 9} };
```

During declaration, you can leave out the size of one dimension if the leftmost one has been left out:

```cpp
int myArray[][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
int a3DArray[][2][2] = { 1, 2, 3, 4, 1, 2, 3, 4 };
```

Looking at the first example, the compiler will know there are two rows because it can determine that after every three elements, a new row begins. Similarly, looking at the second example, a new dimension begins after two blocks of two components. To access a multidimensional array element, use the index values just as you would with one-dimensional arrays:

```cpp
//Assigning a value to an array element
myArray[2][2] = 1000;

//Accessing a value from an array
int number = myArray[0][1];
```

Even though we find it easier to visualize multidimensional arrays as a kind of matrix or seating arrangement, in memory, it is all stored as one single array in one contiguous block. 
You can create as many dimensions as you desire for an array. However, going beyond two dimensions will become more challenging to control and visualize.
 
## Character arrays

This array of _char_ values stores characters to make up a string, also known as a _C-style string_. They require a _terminating null character_ (\0) to be inserted at the end of the array.

```cpp
char sayHello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
```

Many C-style functions exist that perform operations on C-style strings. They hail from the days of C and are cumbersome, causing errors if not used properly. As such, and if at all possible, they are best avoided within a C++ environment unless you are working with a low-level library.

## The new Array
There is also an `std::array` object belonging to the _Standard Library_ that you should probably use often. There is nothing wrong with old C-style arrays, but this newer array has more features and is safer. More info on this is coming soon.
