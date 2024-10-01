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
	
 
	
	
	

