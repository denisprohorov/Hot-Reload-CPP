## Hot reloading in c++

This example shows the loading of a dynamic library using C++.
Changes made to the library are applied during the execution of the main programme.
#### printer.hpp
Contains a class interface and a typedef function to create an object of the class.
#### printer.cpp, printer2.cpp
These are two shared libraries containing the interface implementation and a function to load these libraries.
#### main.cpp
In an infinite loop, provides an option to choose to use the library of your choice. The library is loaded at runtime and,
if changes occur, the library is reloaded.


## Перезагрузка динамической библиотеки во время выполнения в c++
В данном примере показана возможность загрузки динамической библиотеки с использованием языка C++.
Изменения, внесенные в библиотеку, применяются во время выполнения основной программы.
#### printer.hpp
Содержит интерфейс класса и typedef функцию для создания объекта класса.
#### printer.cpp, printer2.cpp
Это две разделяемые библиотеки, содержащие реализацию интерфейса, и функцию для загрузки этих библиотек.
#### main.cpp
В бесконечном цикле предоставляет выбор использования библиотеки на выбор. Библиотека загружается во время выполнения и,
если есть изменения, то библиотека перезагружается.


