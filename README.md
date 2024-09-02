# chk_common

Stuff that every C project should have

## Description

Common types, some logging functions...
Sometimes all you need is to chk_file_read.
(TODO) Other times, you REALLY want to know the size in advance... 

Usage:

```c
    #include <chk_io.h>

    int main() {
        chk_file f = {0};
        chk_file_read(&f, "foo.txt");

        printf("File size: %zu.\nFile contents: %s\n", 
            f.size, f.data);

        chk_file_destroy(&f);
        return 0;
    }
```

## Getting Started

### Dependencies

None.

### Building

- As any CMake project.

If using visual studio code, you can install the cmake extension, and press Build in the status bar.
Everything should just work.

## Authors

Jorge Botarro. [@chikinrasshu](https://x.com/chikinrasshu)

## License

This project is licensed under the MIT License - see the LICENSE.md file for details

## Acknowledgments

- [cwalk](https://github.com/likle/cwalk)
