#include <stdio.h>

#define ARRAY_SIZE 5

// Define a union named ArrayUnion
union ArrayUnion {
    int *int_array;
    float *float_array;
    char *char_array;
};

int main() {
    // Declare a variable of type ArrayUnion
    union ArrayUnion arr_union;

    // Assigning values to each array within the union
    int int_data[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    float float_data[ARRAY_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char char_data[ARRAY_SIZE] = {'a', 'b', 'c', 'd', 'e'};

    arr_union.int_array = int_data;
    // OR: arr_union.float_array = float_data;
    // OR: arr_union.char_array = char_data;

    // Accessing and printing values of the integer array
    printf("Integer Array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", arr_union.int_array[i]);
    }
    printf("\n");

    // Accessing and printing values of the float array
    
    printf("Float Array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%.2f ", arr_union.float_array[i]);
    }
    printf("\n");
    

    // Accessing and printing values of the character array
    
    printf("Character Array: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%c ", arr_union.char_array[i]);
    }
    printf("\n");

    return 0;
}
