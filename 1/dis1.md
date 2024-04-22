Pointer is an address of another variable. 

Use a pointer to point to the variables, and print the values in that address. We should get the same answer.

```c
#include <stdio.h>
int main() {
    int var = 23;
    int *ptr = &var;

    printf("Address of var: %p\n", (void *)&var);
    printf("Stored in ptr: %p\n", (void *)ptr);
    printf("Value of var using ptr: %d\n", *ptr);
    return 0;
}
```
# Pass by value

```c
void foo(int* val){
	printf("%d", val);
  val=1;
}
int main() {
  int val=10;
  foo(&val);
  printf("%d",val);
  return 0
}
```



```c
#include <stdio.h>
#include <stdlib.h>
void foo(int *val){
    printf("%d\n", *val);
    *val = 1;
}
int main(){
    int val = 10;
    foo(&val);
    printf("%d\n", val);
    return 0;
}


```

# Function pointer

Dynamic dispatch is a method used to invoke functions at runtime based on some condition.

E.g. We want to pass in different function to the same function in  a struct.

```c
#include <stdio.h>
typedef struct Animal
{
    char *name;
    void (*speak)(struct Animal *self);
} Animal;

void dogSpeak(Animal *self){printf("%s says: Woof!\n", self->name);}
void catSpeak(Animal *self){printf("%s says: Meow!\n", self->name);}

int main()
{
    Animal dog = {"Buddy", dogSpeak};
    Animal cat = {"Whiskers", catSpeak};
    dog.speak(&dog);
    cat.speak(&cat);
    return 0;
}

```

Speak is dynamic.

The  `speak` method based on the actual type of the `Animal` (either dog or cat).

### 2. Static Dispatch

Static dispatch is a compile-time method used to invoke functions, So the function to be executed is fixed at compile time.

```c
#include <stdio.h>

void add(int a, int b) {
    printf("Addition is %d\n", a + b);
}

void subtract(int a, int b) {
    printf("Subtraction is %d\n", a - b);
}

int main() {
    void (*op)(int, int) = NULL;

    op = add;
    op(5, 3);

    op = subtract;
    op(5, 3);

    return 0;
}

```

While this is set at runtime, each call is direct and doesn't involve any condition-based logic to determine which function to call during execution.

### 3. Callbacks

A callback function is a function that is passed into another function as an argument.

```c
#include <stdio.h>

void repeatThreeTimes(void (*f)(void)) {
    f();
    f();
    f();
}

void hello() {
    printf("Hello, world!\n");
}

void goodbye() {
    printf("Goodbye, world!\n");
}

int main() {
    repeatThreeTimes(hello);
    repeatThreeTimes(goodbye);
    return 0;
}

```

# void*

**Explanation**: `void *` is a type of pointer in C that is used to point to some data location in storage, which can be cast to any other pointer type.

It's often used for generic data interfaces in functions, especially for memory allocation.

If we don't know the type of value that pointer will point to.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10;
    char str[255];
    void *ptr = &a;
    printf("Integer value of a: %d\n", *((int*)ptr));
    void *ptr = str;
    printf("Integer value of a: %s\n", (char*)ptr);
    return 0;
}

```

# constructor

A **constructor** in C++ is a member function of a class which initializes objects of a class. In C++, Constructor is a special type of member function which is invoked automatically at the time of object creation. It helps in setting initial values for member of the class.

```c++
#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    Rectangle()
    {
        width = 5;
        height = 5;
    }
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
};

int main()
{
    Rectangle rect1;
    printf("Width: %d, Height: %d\n", rect1.width, rect1.height);
    Rectangle rect2(10, 20);
    printf("Width: %d, Height: %d\n", rect2.width, rect2.height);
    return 0;
}
```



# destructor

A **destructor** in C++ is a member function which destructs or deletes an object. It will be executed automatically when the object goes out of scope or is explicitly destroyed by a call to delete.

```c++
#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    char *name;
    Rectangle()
    {
        width = 5;
        height = 5;
        name = new char[10];
        strcpy(name, "My Rectangle");
    }
    Rectangle(int w, int h, char *n)
    {
        width = w;
        height = h;
        name = new char[10];
        strcpy(name, n);
    }
    ~Rectangle()
    {
        delete[] name;
        cout << "Destructor called" << endl;
    }
    void display(){cout << "Width: " << width << ", Height: " << height << name << endl;}
};

int main()
{
    char name[] = "Rectangle 1";
    Rectangle rect(10, 20, name);
    rect.display();
    return 0;
}
```

# AddressSanitizer (ASan) 

is a powerful memory error detector designed to find memory errors in C/C++ programs. It is part of the LLVM and GCC compilers, which makes it widely accessible and effective for detecting various types of memory issues such as buffer overflows, underflows, use-after-free, and memory leaks.