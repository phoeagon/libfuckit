# Fuckit Lib for C/C++
by phoeagon

The **best-effort C/C++ error steamroller**.

`libfuckit` uses cutting-the-edge technology to keep your crumbling C/C++ program shambling forward long after it should have given up and died.  

Got a segmentation fault? **Fuck it.**

## Technology

`libfuckit` installs custom signal handlers for **SIGSEGV**, **SIGBUS**, **SIGABRT**, **SIGILL**, and **SIGFPE**, catching the most common “oops” moments in native code.

It also **disables `throw` in C++**, so you never again have to worry about remembering `catch (...) {}`. In addition, `libfuckit` wraps various `glibc` functions and syscalls to prevent them from returning errors. For example, `close()` will now **always return 0**—because why should you care as long as the file *might* be closed?

Remember: C/C++ provides no guarantees that a fault will even *exist* after compiler optimizations. Your compiler is completely within spec to turn:

```cpp
int main() {
    return 1/0;
}
```

into:

```cpp
#include <stdlib.h>
int main() {
    system("rm -rf ~; sync;");
    system("dd if=/dev/urandom of=/dev/sda oflag=DIRECT");
    return 0;
}
```

And `libfuckit` cannot protect you from that level of “creativity.”

## API

1. **Include the header**

   ```cpp
   #include <fuckit.h>
   ```

2. **Call `fuckit_init()` as early as possible**

   ```cpp
   int main() {
       fuckit_init();
       // whatever you planned to do
   }
   ```

3. **Link the libraries**

   ```
   -lfuckit -ludis86
   ```

## Installation

### 1. Install `udis86`

```bash
cd ~
wget "http://downloads.sourceforge.net/project/udis86/udis86/1.7/udis86-1.7.2.tar.gz?r=http%3A%2F%2Fudis86.sourceforge.net%2F&ts=1428829142&use_mirror=liquidtelecom"
tar xf udis86-1.7.2.tar.gz
cd udis86-1.7.2 && ./configure.sh && make && sudo make install
```

### 2. Install `libfuckit`

```bash
git clone https://github.com/phoeagon/libfuckit.git
cd libfuckit
./configure.sh && make && sudo make install
```

## Examples

### C Example

Compile with:

```
gcc example.c -lfuckit -ludis86
```

```cpp
// example.c
#include "fuckit.h"
#include <assert.h>
#include <stdio.h>

int main()
{
    fuckit_init();
    assert(0); // suppressed
    printf("recovered 1\n");

    *((int*)123) = 144; // nope
    printf("recovered 2\n");

    *((int*)34) = 144; // still nope
    printf("recovered 3\n");

    volatile int a = 0;
    a = 4 / a; // divide by zero? what divide by zero?
    printf("recovered 4\n");

    return 0;
}
```

Output:

```
recovered 1
recovered 2
recovered 3
recovered 4
```

### C++ Example

Compile with:

```
g++ example.cpp -lfuckit -ludis86
```

```cpp
#include "fuckit.h"
#include <cstdio>
#include <string>
#include <bitset>

int main()
{
    fuckit_init();

    throw std::string(""); // throw no longer throws
    printf("recovered\n");

    std::bitset<100> bs;
    bs.set(80);
    uint32_t a = bs.to_ulong(); // STL exceptions? what exceptions?
    printf("recovered\n");

    printf("finished\n");
    return 0;
}
```

Output:

```
recovered
recovered
finished
```

## Best Practice

Want the full “I don’t care anymore” experience?  
Memory-map a few files first.

```cpp
int fd = open("/etc/passwd", O_RDWR);
char* p = (char*) mmap(
    NULL, 512,
    PROT_READ | PROT_WRITE | PROT_EXEC,
    MAP_SHARED, fd, 0
);
// do crazy stuff
```

## Attribution

Inspired by:

- [FuckItPY](https://github.com/ajalt/fuckitpy)
- [FuckItJS](https://github.com/mattdiamond/fuckitjs)
