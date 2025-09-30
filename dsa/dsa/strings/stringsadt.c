//
//  strings.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stringsadt.h"

struct String {
    char *s;
    int len;
    int cap;
};

typedef struct String String;

String* CreateString(int size) {
    if (size < 0) {
        perror("Size can't be negative");
        exit(EXIT_FAILURE);
        return NULL;
    }
    
    String *str = malloc(sizeof(String));
    
    str->s = calloc(size, sizeof(char));
    str->len = 0;
    str->cap = size;
    
    return str;
}

void Free(String *str) {
    if (str == NULL) {
        return;
    }
    
    if (str->s != NULL) {
        free(str->s);
    }
    
    free(str);
}

static void Display(String *str) {
    if (str == NULL || str->s == NULL) {
        return;
    }

    printf("Len: %d\n", str->len);
    printf("Cap: %d\n", str->cap);
    printf("%s\n", str->s);
}

static void Append(String *str, const char *s) {
    if (str == NULL) {
        return;
    }
    
    if (str->s == NULL) {
        return;
    }
    
    for (int i = 0; s[i] != '\0'; ++i) {
        if (str->len >= str->cap) {
            str->cap = str->cap == 0? 8: str->cap * 2;
            str->s = realloc(str->s, str->cap * sizeof(char));
        }
        
        str->s[str->len++] = s[i];
    }
}

void LowerCase(String *str) {
    if (str == NULL || str->s == NULL) {
        return;
    }

    for (int i = 0; i < str->len; ++i) {
        if (str->s[i] >= 65 && str->s[i] <= 90) {
            str->s[i] = 97 + str->s[i] - 65;
        }
    }
}

void UpperCase(String *str) {
    if (str == NULL || str->s == NULL) {
        return;
    }
    
    for (int i = 0; i < str->len; ++i) {
        if (str->s[i] >= 97 && str->s[i] <= 122) {
            str->s[i] = 65 + str->s[i] - 97;
        }
    }
}

bool IsVowel(char c) {
    char vowels[] = "aeiouAEIOU";
    
    for (int i = 0; vowels[i] != '\0'; ++i) {
        if (vowels[i] == c) {
            return true;
        }
    }
    
    return false;
}

int VowelCount(String *str) {
    if (str == NULL || str->s == NULL) {
        return -1;
    }
    
    int count = 0;
    for (int i = 0; i < str->s[i]; ++i) {
        if (IsVowel(str->s[i])) {
            count++;
        }
    }
    
    return count;
}

int WordCount(String *str) {
    if (str == NULL || str->s == NULL) {
        return -1;
    }
    
    int count = 0;
    int i;
    
    for (i = 0; i < str->s[i]; ++i) {
        if (str->s[i] == ' ' && i > 0 && str->s[i - 1] != ' ') {
            count++;
        }
    }
    
    if (i != 0 && str->s[i - 1] != ' ') {
        count++;
    }
    
    return count;
}

bool IsValidString(String *str) {
    if (str == NULL || str->s == NULL) {
        return false;
    }
    
    for (int i = 0; i < str->s[i]; ++i) {
        if (!((str->s[i] >= 48 && str->s[i] <= 57) || (str->s[i] >= 65 && str->s[i] <= 90) || (str->s[i] >= 97 && str->s[i] <= 122))) {
            return false;
        }
    }
    
    return true;
}

static void Reverse(String *str) {
    if (str == NULL || str->s == NULL) {
        return;
    }
    
    int first = 0, last = str->len - 1;
    
    while (first < last) {
        char tmp = str->s[first];
        str->s[first] = str->s[last];
        str->s[last] = tmp;
        first++;
        last--;
    }
}

bool IsEqual(String *str1, String *str2) {
    if (str1 == NULL || str1->s == NULL) {
        return false;
    }
    
    if (str2 == NULL || str2->s == NULL) {
        return false;
    }
    
    int i = 0, j = 0;
    
    while (i < str1->len && j < str2->len) {
        if (str1->s[i] != str2->s[j]) {
            return false;
        }
        i++;
        j++;
    }
    
    if (!(i == str1->len && j == str2->len)) {
        return false;
    }
    
    return true;
}

bool IsPalindrome(String *str) {
    if (str == NULL || str->s == NULL) {
        return false;
    }
    
    int i = 0, j = str->len - 1;
    
    while (i < j) {
        if (str->s[i] != str->s[j]) {
            return false;
        }
    }
    
    return true;
}

String* Duplicates(String *str) {
    if (str == NULL || str->s == NULL) {
        return NULL;
    }
    
    String *r = CreateString(str->len);
    
    long int H = 0, x = 0;
    
    for (int i = 0; i < str->len; ++i) {
        x = 1;
        x = x << (str->s[i] - 97);
        
        if ((H & x) > 0) {
            const char s[1] = {str->s[i]};
            Append(r, s);
        } else {
            H = H | x;
        }
    }
    
    return r;
}

bool IsAnagram(String *s1, String* s2) {
    int H[26] = {0};
    
    for (int i = 0; i < s1->len; ++i) {
        H[s1->s[i] - 97]++;
    }
    
    for (int i = 0; i < s2->len; ++i) {
        H[s2->s[i] - 97]--;
    }
    
    for (int i = 0; i < 26; ++i) {
        if (H[i] < 0 || H[i] > 0) {
            return false;
        }
    }
    
    return true;
}

void RunStringADT(bool run) {
    if (!run) {
        return;
    }
    
    String *str = CreateString(10);
    Append(str, "   I     Love     Golang");
    Display(str);
    
    LowerCase(str);
    Display(str);
    UpperCase(str);
    Display(str);
    printf("Vowel count is: %d\n", VowelCount(str));
    printf("Word Count is: %d\n", WordCount(str));
    Reverse(str);
    Display(str);
//    s = "321342adsgasdg4543";
    
    String *temp = CreateString(8);
    Append(temp, "32145342#534dsagsgas");
    Display(temp);
    printf("Is string Valid: %d\n", IsValidString(temp));
    
    String *str1 = CreateString(10);
    Append(str1, "Painter");
    Display(str1);
    String *str2 = CreateString(0);
    Append(str2, "Painter");
    Display(str2);
    printf("Is string equal: %d\n", IsEqual(str1, str2));
    
    String *ds = CreateString(10);
    Append(ds, "findinnggg");
    Display(ds);
    String *r = Duplicates(ds);
    Display(r);
    
    String *s1 = CreateString(10);
    Append(s1, "decimal");
    String *s2 = CreateString(10);
    Append(s2, "medical");
    
    printf("Is anagram: %d\n", IsAnagram(s1, s2));
    
    Free(str);
    Free(temp);
    Free(str1);
    Free(str2);
    Free(ds);
    Free(r);
}
