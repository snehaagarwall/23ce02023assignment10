#include <stdio.h>

// Define the union named Data
union Data {
    int integer;
    float floating_point;
    char character;
};

int main() {
    // Declare a variable of type Data
    union Data data;

    // Assign values to the members of the union
    data.integer = 10;
    data.floating_point = 3.14;
    data.character = 'A';

    // Access and print the values
    printf("Integer: %d\n", data.integer);
    printf("Float: %.2f\n", data.floating_point);
    printf("Character: %c\n", data.character);

    return 0;
}
