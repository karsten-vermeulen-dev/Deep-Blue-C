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


