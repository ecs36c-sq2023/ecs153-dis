# Homework

https://github.com/ecs36c-sq2023/ecs153-sq-hw0

Final presentation

https://docs.google.com/spreadsheets/d/1LgZPTI1F4Ni7a97XK6vV6UsJKKgO7O1ZErkyqms_P9M/edit?usp=sharing

# Develop environment

### Environment Isolation

**Why**

- Different projects require different setups
- Do experiments without messing up your host env
- Security for production workloads

**How**

- Separate Physical Machines
- Virtual Machines (VMs)
- Docker Containers

**Docker Containers**

- Widely adopted and loved
- Can be used in every stage of the DevOps cycle
- Lightweight compared to Virtual Machines (VMs)
- Easy to setup across different host environments
- Code Editor support (such as VS Code and NeoVim)

# Pointers and arrays
## Pass by value vs Pass by pointer

# Function pointers

What can function pointers do?

- Dynamic dispatch and static dispatch
- Callbacks

# `void *`

`void *` can be anything. 
You are free to cast it to anything at your own risk.

# Struct memory layout

```c
struct ST {
   char ch1;     // 0
   char ch2;
   long long ll;
   int i;
};
```
```c
struct ST {
   BinOp op1;
   BinOp op2;
} ST;
```

## Constructors and destructors

# static and global

```c
char* foo;     // In Program
char foo[255];    // In Program
static char* foo; // Local to file
static char foo[255];   // Local to file

int main() { ... }
```

# Sanitizers

**AddressSanitizer (ASan)**