//
//  arrayadt.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayadt.h"


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

int Get(Array *arr, size_t index) {
    
    if (index >= 0 && index < arr->length) {
        return arr->A[index];
    }
    
    return -1;
}

void Set(Array *arr, size_t index, int value) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = value;
    }
}

int Max(Array *arr) {
    if (arr->length > 0) {
        int max = arr->A[0];
        
        for (size_t i = 1; i < arr->length; ++i) {
            if (max < arr->A[i]) {
                max = arr->A[i];
            }
        }
        
        return max;
    }
    
    return -1;
}

int Min(Array *arr) {
    if (arr->length > 0) {
        int min = arr->A[0];
        
        for (size_t i = 1; i < arr->length; ++i) {
            if (min > arr->A[i]) {
                min = arr->A[i];
            }
        }
        
        return min;
    }
    
    return -1;
}

int Sum(Array *arr) {
    int sum = 0;
    
    for (size_t i = 0; i < arr->length; ++i) {
        sum += arr->A[i];
    }
    
    return sum;
}

double Avg(Array *arr) {
    int sum = Sum(arr);
    
    return arr->length == 0 ? 0 : (double)(sum / arr->length);
}

void Reverse(Array *arr) {
    size_t i = 0, j = arr->length - 1;
    int temp = 0;
    
    while (i < j) {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        i++;
        j--;
    }
}

bool IsSorted(Array *arr) {
    for (size_t i = 0; i < arr->length - 1; ++i) {
        if (arr->A[i] > arr->A[i + 1]) {
            return false;
        }
    }
    
    return true;
}

void InsertInSortedArray(Array *arr, int value) {
    if (arr->length == 0) {
        return;
    }
    
    if (IsSorted(arr)) {
        if (value >= arr->A[arr->length - 1]) {
            Append(arr, value);
            return;
        }
        
        size_t i = 0;
        
        for(i = arr->length; i > 0; --i) {
            if (i == arr->length) {
                Append(arr, arr->A[i - 1]);
            } else if (value < arr->A[i - 1]) {
                arr->A[i] = arr->A[i - 1];
            } else {
                break;
            }
        }
        
        arr->A[i] = value;
    }
}

void NegativeOnLeftSide(Array *arr) {
    if (arr->length > 1) {
        size_t i = 0, j = arr->length - 1;
        
        while (i < j) {
            if (arr->A[i] < 0) {
                i++;
            } else if (arr->A[j] > 0) {
                j--;
            } else {
                int temp = arr->A[i];
                arr->A[i] = arr->A[j];
                arr->A[j] = temp;
                i++;
                j--;
            }
        }
    }
}

void LeftShift(Array *arr) {
    if (arr->length > 0) {
        for (size_t i = 0; i < arr->length - 1; ++i) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->A[arr->length - 1] = 0;
    }
}

void RightShift(Array *arr) {
    if (arr->length > 0) {
        for (size_t i = arr->length - 1; i > 0; --i) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[0] = 0;
    }
}

void Rotate(Array *arr) {
    if (arr->length > 1) {
        int temp = arr->A[0];
        
        LeftShift(arr);
        
        arr->A[arr->length - 1] = temp;
    }
}

Array* Merge(Array *arr1, Array *arr2) {
    Array *m = CreateArray(arr1->size + arr2->size);
    
    size_t i = 0;
    size_t j = 0;
    
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] <= arr2->A[j]) {
            Append(m, arr1->A[i]);
            i++;
        } else if (arr1->A[i] > arr2->A[j]) {
            Append(m, arr2->A[j]);
            j++;
        }
    }
    
    while (i < arr1->length) {
        Append(m, arr1->A[i]);
        i++;
    }
    while (j < arr2->length) {
        Append(m, arr2->A[j]);
        j++;
    }
    
    return m;
}

Array* Union(Array *s1, Array *s2) {
    Array *u = CreateArray(s1->size + s2->size);
    
    if (s1->length == 0) {
        for (size_t i = 0; i < s2->length; ++i) {
            Append(u, s2->A[i]);
        }
    } else if (s2->length == 0) {
        for (size_t i = 0; i < s1->length; ++i) {
            Append(u, s1->A[i]);
        }
    } else if (IsSorted(s1) && IsSorted(s2)) {
        size_t i = 0, j = 0;
        
        while (i < s1->length && j < s2->length) {
            if (u->length == 0) {
                if (s1->A[i] <= s2->A[j]) {
                    Append(u, s1->A[i++]);
                } else {
                    Append(u, s2->A[j++]);
                }
            } else if (s1->A[i] <= s2->A[j]) {
                if (u->A[u->length - 1] != s1->A[i]) {
                    Append(u, s1->A[i++]);
                } else {
                    i++;
                }
            } else if (s1->A[i] > s2->A[j]) {
                if (u->A[u->length - 1] != s2->A[j]) {
                    Append(u, s2->A[j++]);
                } else {
                    j++;
                }
            }
        }
        
        while (i < s1->length) {
            if (u->A[u->length - 1] != s1->A[i]) {
                Append(u, s1->A[i]);
            }
            i++;
        }
        while (j < s2->length) {
            if (u->A[u->length - 1] != s2->A[j]) {
                Append(u, s2->A[j]);
            }
            j++;
        }
    } else {
        for (size_t i = 0; i < s1->length; ++i) {
            Append(u, s1->A[i]);
        }
        
        for (size_t i = 0; i < s2->length; ++i) {
            bool isPresent = false;
            for (size_t j = 0; j < u->length; ++j) {
                if (s2->A[i] == u->A[j]) {
                    isPresent = true;
                    break;
                }
            }
            
            if (!isPresent) {
                Append(u, s2->A[i]);
            }
        }
    }
    
    return u;
}

Array* Intersection(Array *s1, Array *s2) {
    Array *u = CreateArray(s1->size + s2->size);
 
    if (s1->length == 0) {
        for (size_t i = 0; i < s2->length; ++i) {
            Append(u, s2->A[i]);
        }
    } else if (s2->length == 0) {
        for (size_t i = 0; i < s1->length; ++i) {
            Append(u, s1->A[i]);
        }
    } else if (IsSorted(s1) && IsSorted(s2)) {
        size_t i = 0, j = 0;
        
        while (i < s1->length && j < s2->length) {
            if (s1->A[i] == s2->A[j]) {
                if (u->length == 0 || s1->A[i] != u->A[u->length - 1]) {
                    Append(u, s1->A[i]);
                }
                i++;
                j++;
            } else if (s1->A[i] < s2->A[j]) {
                i++;
            } else {
                j++;
            }
        }
    } else {
        for (size_t i = 0; i < s1->length; ++i) {
            for (size_t j = 0; j < s2->length; ++j) {
                if (s1->A[i] == s2->A[j]) {
                    if (u->length == 0 || s1->A[i] != u->A[u->length - 1]) {
                        Append(u, s1->A[i]);
                    }
                }
            }
        }
    }
    
    return u;
}

Array* Difference(Array *s1, Array *s2) {
    Array *d = CreateArray(s1->size + s2->size);
    
//    d = s1 - s2
    
    if (s1->length == 0) {
        for (size_t i = 0; i < s2->length; ++i) {
            Append(d, s2->A[i]);
        }
    } else if (s2->length == 0) {
        for (size_t i = 0; i < s1->length; ++i) {
            Append(d, s1->A[i]);
        }
    } else if (IsSorted(s1) && IsSorted(s2)) {
        size_t i = 0, j = 0;
        
        while (i < s1->length && j < s2->length) {
            if (s1->A[i] == s2->A[j]) {
                i++;
                j++;
            } else if (s1->A[i] < s2->A[j]) {
                if (d->length == 0 || d->A[d->length - 1] != s1->A[i]) {
                    Append(d, s1->A[i]);
                }
                i++;
            } else {
                j++;
            }
        }
    } else {
        for (size_t i = 0; i < s1->length; ++i) {
            bool isPresent = false;
            for (size_t j = 0; j < s2->length; ++j) {
                if (s1->A[i] == s2->A[j]) {
                    isPresent = true;
                    break;
                }
            }
            
            if (!isPresent) {
                Append(d, s1->A[i]);
            }
        }
    }
    
    return d;
}

int FindingSingleMissingElement(Array *arr) {
    if (arr->length > 0) {
        if (IsSorted(arr)) {
            size_t i = 0;
            int curr = 0, next = 0;
            
            while (i < arr->length - 1) {
                curr = arr->A[i];
                next = arr->A[i + 1];
                
                if (curr != next && curr + 1 != next) {
                    return curr + 1;
                }
                
                i++;
            }
        }
    }
    
    return -1;
}

Array* FindingMultipleMissingElement(Array *arr) {
    Array *r = CreateArray(arr->length);
    
    if (arr->length > 0 && IsSorted(arr)) {
        size_t i = 0;
        int curr = 0, next = 0;
        
        while (i < arr->length - 1) {
            curr = arr->A[i];
            next = arr->A[i + 1];
            
            if (curr == next) {
                i++;
            } else if (curr + 1 != next) {
                curr++;
                while (curr < next) {
                    Append(r, curr);
                    curr++;
                }
                i++;
            }
        }
    }
    
    return r;
}

void rec(int n) {
    if (n > 5) {
        return;
    }
    
    printf("%d, ", n);
    
    rec(n + 1);
}


void RunArrayADT(bool run) {
    if (!run) {
        return;
    }
    
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
    
//    printf("%d\n", Get(arr, 9));
//    Set(arr, 0, 15);
//    Display(arr);
//    Reverse(arr);
//    Display(arr);
//    Rotate(arr);
//    Display(arr);
//    Rotate(arr);
//    Display(arr);
//    RightShift(arr);
//    Display(arr);
//    RightShift(arr);
//    Display(arr);
//    LeftShift(arr);
//    Display(arr);
//    LeftShift(arr);
//    Display(arr);
    
    Display(arr);
    InsertInSortedArray(arr, 8);
    Display(arr);
    InsertInSortedArray(arr, 1);
    Display(arr);
    InsertInSortedArray(arr, 16);
    Display(arr);
    
    Array *arr1 = CreateArray(10);
    Append(arr1, 2);
    Append(arr1, -424);
    Append(arr1, 1);
    Append(arr1, -2223);
    Append(arr1, 2);
    Append(arr1, 98);
    Append(arr1, 100);
    Append(arr1, 235);
    Append(arr1, 6345);
    
    NegativeOnLeftSide(arr1);
    Display(arr1);
    Array *m = Merge(arr, arr1);
    Display(m);
    
    Array *s1 = CreateArray(10);
    Array *s2 = CreateArray(10);
    
    Append(s1, 3);
    Append(s1, 5);
    Append(s1, 10);
    Append(s1, 4);
    Append(s1, 6);
    
    Display(s1);
    
    Append(s2, 12);
    Append(s2, 4);
    Append(s2, 7);
    Append(s2, 2);
    Append(s2, 5);
    
    Display(s2);
    
    Array *u = Union(s1, s2);
    Display(u);
    
    Array *i = Intersection(s1, s2);
    Display(i);
    
    Array *d = Difference(s1, s2);
    Display(d);
    
    free(s1->A);
    free(s1);
    free(s2->A);
    free(s2);
    free(u->A);
    free(u);
    free(i->A);
    free(i);
    free(d->A);
    free(d);
    
    printf("\n\n");
    
    s1 = CreateArray(10);
    s2 = CreateArray(10);
    
    Append(s1, 3);
    Append(s1, 4);
    Append(s1, 5);
    Append(s1, 6);
    Append(s1, 10);
    
    Display(s1);
    
    Append(s2, 2);
    Append(s2, 4);
    Append(s2, 5);
    Append(s2, 7);
    Append(s2, 12);
    
    Display(s2);
    
    u = Union(s1, s2);
    Display(u);
    i = Intersection(s1, s2);
    Display(i);
    d = Difference(s1, s2);
    Display(d);
    
    printf("\n\n");
    
    printf("Length of Array: %zu\n", arr->length);
    printf("Size of Array: %zu\n\n", arr->size);
    
    printf("\n\n");
    rec(0);
    
    free(arr->A);
    free(arr);
    free(arr1->A);
    free(arr1);
    free(m->A);
    free(m);
    free(s1->A);
    free(s1);
    free(s2->A);
    free(s2);
    free(u->A);
    free(u);
    free(i->A);
    free(i);
    free(d->A);
    free(d);
}
