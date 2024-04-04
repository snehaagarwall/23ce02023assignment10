
#include <stdio.h>

// Define a structure named MyStruct
struct MyStruct {
    int integer1;
    int integer2;
    char character;
};

// Define a union named MyUnion
union MyUnion {
    int integer1;
    int integer2;
    char character;
};

int main() {
    // Declare variables of type MyStruct and MyUnion
    struct MyStruct myStruct;
    union MyUnion myUnion;

    // Display the size of the structure
    printf("Size of MyStruct: %lu bytes\n", sizeof(struct MyStruct));

    // Display the size of the union
    printf("Size of MyUnion: %lu bytes\n", sizeof(union MyUnion));

    return 0;
}
