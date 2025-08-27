#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DynamicArray DynamicArray;

typedef enum {
    TYPE_INT,
    TYPE_ARRAY,
} ElementType;

typedef struct {
    ElementType type;
    union {
        int value;
        DynamicArray *array;
    } data;
} Element;

struct DynamicArray {
    Element *items;
    size_t count;
    size_t capacity;
};

DynamicArray* create_array(void) {
    DynamicArray* arr = malloc(sizeof(DynamicArray));
    
    arr->items = NULL;
    arr->count = 0;
    arr->capacity = 0;
    
    return arr;
}

void append_int(DynamicArray *arr, int value) {
    if (arr->count >= arr->capacity) {
        arr->capacity = (arr->capacity == 0 ? 8 : 2 * arr->capacity);
        arr->items = realloc(arr->items, arr->capacity * sizeof(Element));
    }
    
    arr->items[arr->count].type = TYPE_INT;
    arr->items[arr->count].data.value = value;
    arr->count++;
}

void append_array(DynamicArray *arr, DynamicArray *subarray) {
    if (arr->count >= arr->capacity) {
        arr->capacity = (arr->capacity == 0 ? 8 : 2 * arr->capacity);
        arr->items = realloc(arr->items, arr->capacity * sizeof(Element));
    }
    
    arr->items[arr->count].type = TYPE_ARRAY;
    arr->items[arr->count].data.array = subarray;
    arr->count++;
}

void print_array(const DynamicArray *arr) {
    printf("[");
    for (size_t i = 0; i < arr->count; ++i) {
        if (arr->items[i].type == TYPE_INT) {
            printf("%d", arr->items[i].data.value);
        } else if (arr->items[i].type == TYPE_ARRAY) {
            print_array(arr->items[i].data.array);
        }
        if (i < arr->count - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void free_array(DynamicArray *arr) {
    if (arr == NULL) return;
    for (size_t i = 0; i < arr->count; i++) {
        if (arr->items[i].type == TYPE_ARRAY) {
            free_array(arr->items[i].data.array);
        }
    }
    free(arr->items);
    free(arr);
}

typedef struct {
    int *items;
    size_t count;
    size_t capacity;
} IntArray;

IntArray* createIntArray(void) {
    IntArray *arr = malloc(sizeof(IntArray));
    
    arr->count = 0;
    arr->capacity = 0;
    arr->items = NULL;
    
    return arr;
}

void append(IntArray *arr, int value) {
    if (arr->count >= arr->capacity) {
        arr->capacity = (arr->capacity == 0? 8 : arr->capacity * 2);
        arr->items = realloc(arr->items, arr->capacity * sizeof(int));
    }
    
    arr->items[arr->count++] = value;
}

IntArray* flatten(DynamicArray *arr) {
    IntArray *result = createIntArray();
    
    for (size_t i = 0; i < arr->count; ++i) {
        if (arr->items[i].type == TYPE_INT) {
            append(result, arr->items[i].data.value);
        } else if (arr->items[i].type == TYPE_ARRAY) {
            IntArray *r = flatten(arr->items[i].data.array);
            for (size_t j = 0; j < r->count; ++j) {
                append(result, r->items[j]);
            }
        }
    }
    
    return result;
}

void print_flattened_array(IntArray *arr) {
    for (size_t i = 0; i < arr->count; ++i) {
        printf("%d", arr->items[i]);
        if (i < arr->count - 1) {
            printf(", ");
        }
    }
}

int main(int argc, const char* argv[]) {
    // Let's build [[1, 2, 3], 4, [5, [6, 7, 8]]]
    
    DynamicArray *main_array = create_array();
    
    DynamicArray *sub_array1 = create_array();
    append_int(sub_array1, 1);
    append_int(sub_array1, 2);
    append_int(sub_array1, 3);
    
    DynamicArray *sub_array2 = create_array();
    append_int(sub_array2, 5);
    
    DynamicArray *nested_array = create_array();
    append_int(nested_array, 6);
    append_int(nested_array, 7);
    append_int(nested_array, 8);
    
    append_array(main_array, sub_array1);
    append_int(main_array, 4);
    append_array(sub_array2, nested_array);
    append_array(main_array, sub_array2);
    
    print_array(main_array);
    printf("\n");
    IntArray *flattened_array = flatten(main_array);
    print_flattened_array(flattened_array);
    printf("\n");
    free(flattened_array->items);
    free(flattened_array);
    
    free_array(main_array);

    return 0;
}
