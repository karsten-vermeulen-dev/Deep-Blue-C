# Lesson 1: Getting to know your environment

You are probably eager to start coding, but let's spend some time learning about C++. We will begin by looking at what C++ is, why we should care about it, and who on earth uses it. 

## What exactly is C++?
C++ is the universal language in game programming and is widely used for general application development. It was created by Danish computer scientist Bjarne Stroustrup in 1979 and released in 1983. The International Organization for Standardization, or ISO, has since standardised it, with the current standard being C++23 and C++26 on the way. Created as a successor to C, C++ is still one of the most widely used programming languages ever. It is an object-oriented programming language, sometimes called C with classes that is largely backwards compatible with C.

## Why are we using it?
Well, for one thing, it is superfast, allowing developers to squeeze out the best performance in a game or application. It is also extremely well supported, with many different third-party libraries and code assets available. C++ is a multi-paradigm, intermediate-level programming language that offers extreme flexibility when developing applications. Finally, it allows more control over peripherals, giving programmers direct access to hardware and memory.

## Who else uses C++?
Many game engines are either written in C++ or have some form of C++ under the hood. If you are not into developing games, you might want to use this powerful programming language to create regular desktop or mobile applications or audio plugins. Many third-party graphics, audio, and physics libraries and APIs have been written in C or C++, allowing developers to seamlessly link their code and build their applications. C++ is one of the main programming languages used to create AAA game titles and has helped develop languages such as Java and C#. It is a very complex language that has evolved over the last few decades and seen many additions to its extensive library.

## Some popular game engines worth mentioning 

| Engine          | Description    |
| --------------- | -------------- |
| Unity           | A popular game engine built using C++ yet offering only C# scripting to the developer           |
| Unreal Engine   | Epic's grand master of engines, written in C++ with the option to code in C++ as an alternative to using _Blueprints_     |
| CryEngine       | German studio Crytek's famous engine, popular for the game _Far Cry_, is also written in C++     |
| Open 3D Engine  | Based on Amazon's _Lumberyard_ engine, which in turn is based on _CryEngine_, this new kid on the block also uses C++ alongside Lua and Python     |
| Source 2        | Developed by Valve, this C++ engine can be credited for creating _Dota 2_ and _Half-Life: Alyx_    |
| Frostbite       | Known for producing the Battlefield series of games, Electronic Arts' baby is written in both C++ and C#                                               |
| Godot           | Initially created by two Argentine developers, it was released to the public in 2014. The popular adventure game _Deponia_ was made using this engine  | 
  	
## Tell me about this so-called games industry
The gaming market is massive, globally worth over $100bn annually, with the UK games industry worth about £5bn. The UK has the 6th largest market in the world, following Germany, South Korea, Japan, USA, and China. You can choose to work for any studio, be that AAA, mid-level or indie, and within that realm, you can choose to develop many different kinds of games, namely desktop, console, mobile, online, AR, and VR. And within that, career paths are abundant, namely tools, physics, graphics, gameplay, audio, and AI.

## Want to develop software instead?
Why not? It is a lucrative career and makes good money, too. But that shouldn’t be your ultimate reason for entering the industry. Your passion for creating new cutting-edge software should drive you to pursue this career. In this field, you get the chance to develop applications rather than games, and as such, the software you create might not appear as exciting or dynamic as a game. You could develop applications such as audio plugins, database managers, banking apps, and medical and audio visualisers, to name a few. Much of the middleware that you use in the industry will most likely be written in C++.
	
## Some popular software APIs worth mentioning

| API           | Description    |
| ------------- | -------------- |
| JUCE          | Short for _Jules' Utility Class Extensions_, this cross-platform C++ application framework allows developers to use C++ to create audio apps and plugins with a rich UI   |
| OpenGL        | An ancient yet popular graphics API written in C that allows developers to harness the raw power of the GPU to create visual applications   |
| wxWidgests    | Another C++ library that offers developers a widget toolkit to create GUI applications   |
| wWise         | Another excellent tool for creating audio applications or to integrate audio into your existing application (or game)   |
| OpenVR        | Developed by Valve and created using C, C++, and C#, this API allows developers to manipulate virtual reality devices in their applications   |
| Qt            | Pronounced que tee or simply cute, this software development behemoth gives developers the power to create just about any (GUI) application that can run on just about any device   |

## An introduction to Visual Studio
Let us now take a look at one of the most popular IDEs.

## What is this Visual Studio exactly?
This is an integrated development environment, or IDE, developed by Microsoft. It is used for writing, compiling, and linking your C++ code. Of course, you can use it to code in other languages, and the IDE comes packed with many tools to make software development much more straightforward. The built-in IntelliSense will assist developers with syntax highlighting, code prediction and many different debugging tools to help find and fix issues in the code. We will only be using a small portion of Visual Studio's capabilities, which is why the Community 2022 edition is more than enough for our purposes.
	
## Where can I find Visual Studio? 
Visual Studio comes in three flavours: Professional, Enterprise, and Community. The latter is free and can be downloaded here: https://www.visualstudio.com. Click on **Download Visual Studio** and select the **Community 2022 edition**. This will download a setup EXE file to run and install the IDE.

## Managing the installation
After installing Visual Studio, you can use the Visual Studio Installer to modify or update your installation. Search for this on your machine and run it. You can have multiple versions of Visual Studio installed side-by-side, which can be managed separately. Inside the _Visual Studio Installer_, click **Modify** in the Community 2022 box to make changes to your installation. Under the **Workloads** tab, select the **Desktop development with C++** box, which should provide you with all the bog-standard C++ tools you need. Click **Modify** in the screen's bottom right corner to apply these changes. If you wish to install specific components, click on the **Individual components** tab at the top of the installer. Here, you can install particular compilers, language extras, debugging tools, and plugins. Windows developers can also install specific Windows Software Development Kits (SDKs). You should have default SDKs selected for installation, but if you are after something specific, select it and any other components and click on Modify to install them. At the very least, you will require the C++ core features installed.
	
## Starting a new project
Let us begin by doing the following:
1. Start up Visual Studio and create a **New Project** 
2. Select the **Empty Project** template and click **Next** 
3. Give your project a name, choose the desired location for your solution folder and click **Create**

You are now inside Visual Studio’s famous IDE. Take a good look around and admire the view. This will be your new home away from home. Once you are done viewing, add a source file to the project, which will be your main starting point for the application. To achieve this, right-click on the **Source Files** tab, select **Add** and then **New Item**. Now select the C++ File option and give the file a name, something as dull as _Main.cpp_.
You can now add some start-up code to the Main.cpp file, however, do not worry too much about what it does just yet:
	
```cpp
#include <iostream>

int main()
{
    system("pause");
    return 0;
}
```	
	
	
	
	



