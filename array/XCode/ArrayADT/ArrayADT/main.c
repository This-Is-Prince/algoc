#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *A;
    size_t size;
    size_t length;
} Array;

Array* CreateArray(size_t);
void FillArray(Array*);
void Display(Array*);
void Append(Array*, int);

Array* CreateArray(size_t size) {
    Array *arr = malloc(sizeof(Array));
    arr->size = size;
    arr->length = 0;
    arr->A = malloc(size * sizeof(*arr->A));
    
    return arr;
}

void FillArray(Array *arr) {
    for (int i = 0; i < 5; ++i) {
        Append(arr, i + 2);
    }
}

void Display(Array *arr) {
    for (size_t i = 0; i < arr->length; ++i) {
        if (i == arr->length - 1) {
            printf("%d\n", arr->A[i]);
        } else {
            printf("%d, ", arr->A[i]);
        }
    }
}

void Append(Array *arr, int value) {
    if (arr->length >= arr->size) {
        arr->size = arr->size == 0 ? 8 : arr->size * 2;
        arr->A = realloc(arr->A, arr->size * sizeof(*arr->A));
    }
    arr->A[arr->length++] = value;
}

void Insert(Array *arr, size_t index, int value) {
    if (arr->length < index || index < 0) {
        return;
    }
    
    if (arr->length >= arr->size) {
        arr->size = arr->size == 0 ? 8 : arr->size * 2;
        arr->A = realloc(arr->A, arr->size * sizeof(*arr->A));
    }
    
    for (size_t i = arr->length; i > index; --i) {
        arr->A[i] = arr->A[i-1];
    }
    
    arr->A[index] = value;
    arr->length++;
}

void Delete(Array *arr, size_t index) {
    if (arr->length <= index) {
        return;
    }
    
    for (size_t i = index; i < arr->length - 1; ++i) {
        arr->A[i] = arr->A[i+1];
    }
    
    arr->length--;
}

size_t LinearSearch(Array *arr, int elm) {
    for (size_t i = 0; i < arr->length; ++i) {
        if (arr->A[i] == elm) {
            return i;
        }
    }
    
    return -1;
}

size_t binarySearch(Array *arr, size_t low, size_t high, int elm) {
    if (high < low || low > arr->length || high > arr->length) {
        return -1;
    }
    
    size_t mid = (low + high) / 2;
    
    if (arr->A[mid] == elm) {
        return mid;
    } else if (arr->A[mid] < elm) {
        return binarySearch(arr, mid + 1, high, elm);
    } else if (arr->A[mid] > elm) {
        return binarySearch(arr, low, mid - 1, elm);
    }
    
    return -1;
}

size_t BinarySearch(Array *arr, int elm) {
    return binarySearch(arr, 0, arr->length - 1, elm);
}


int main(int argc, const char* argv[]) {
    Array *arr = CreateArray(10);
    
    FillArray(arr);
    
    Display(arr);
    
    Append(arr, 7);
    Append(arr, 8);
    Append(arr, 9);
    Append(arr, 10);
    Append(arr, 11);
    Append(arr, 12);
    Append(arr, 13);
    Append(arr, 14);
    Append(arr, 15);
    
    Display(arr);
    
    Insert(arr, -1, 100);
    Insert(arr, 0, 110);
    Insert(arr, 15, 120);
    Insert(arr, 10, 130);
    
    Display(arr);
    
    Delete(arr, -1);
    Delete(arr, 17);
    Delete(arr, 16);
    Delete(arr, 10);
    Delete(arr, 0);
    
    Display(arr);
    
    printf("7 is at index: %d\n", (int)LinearSearch(arr, 7));
    printf("1 is at index: %d\n", (int)LinearSearch(arr, 1));
    printf("100 is at index: %d\n", (int)LinearSearch(arr, 100));
    printf("15 is at index: %d\n", (int)LinearSearch(arr, 15));
    printf("7 is at index: %d\n", (int)BinarySearch(arr, 7));
    printf("1 is at index: %d\n", (int)BinarySearch(arr, 1));
    printf("100 is at index: %d\n", (int)BinarySearch(arr, 100));
    printf("15 is at index: %d\n", (int)BinarySearch(arr, 15));
    
    printf("\n\n");
    
    printf("Length of Array: %zu\n", arr->length);
    printf("Size of Array: %zu\n\n", arr->size);
    
    free(arr->A);
    free(arr);
    
    return 0;
}
