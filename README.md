## C program -- Convert ASCII strings to hexadecimal numbers

This C application converts an ASCII string to a hexadecimal number to be input into an assembly source code file.

To compile, run `make`.

To use it, run this for a little-endian string:
> env -i ENDIANNESS=LE ./exe helloworld

Run this for a big-endian string:
> env -i ENDIANNESS=BE ./exe helloworld

This also generates a big-endian string:
> env -i ./exe helloworld

I mainly wrote this to practice the use of environment variables and function pointers in C.

