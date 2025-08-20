JSCPP (JavaScript C++)

**JSCPP** stands for **JavaScript C++**, a low-level, easy-to-use, OOP programming language with a syntax similar to C++ and the flexibility of JavaScript.  

JSCPP is designed for developers who want **low-level control with simple syntax**, perfect for educational projects, prototyping, or creating small interpreters and games.  

The language is interpreted by **UJSCC (Uoc JavaScript C Compiler)**, a compiler/interpreter written in C++.

## Features
- Print()
- var and const

### installation / requirement
- GCC / G++
- Cmake (new version)

clone this repository
j

```bash
mkdir build && cd build
```

init the compiler
```bash
cmake ..
```

build compiler
```bash
make
```

run file
```bash
./ujsc main.jscpp
```

## example
1. Print
```bash
#include<psl>

example main() {
    print("Hello world");
}
```
2. Variable
```bash
#include<psl>
#include<vsl>

v variable() {
 var j: 10;
 const hi: "Hallo";

example main() {
    print("v variabel.var");
}
```

## Library
PSL (Print Syntax Library)
add ability to print something in JSCPP.

VSL (Variabel Syntax Library)
add ability to make variabel in JSCPP.

that's all for now, this still beta, so some features still under development.
