#include <stdio.h>
#include<string.h>
int findSubstring(const char *str, const char *substr) {
    int len_str = 0;
    int len_substr = 0;
    
    while (str[len_str] != '\0') {
        len_str++;
    }
    
    while (substr[len_substr] != '\0') {
        len_substr++;
    }
    
    int i, j;
    for (i = 0; i <= len_str - len_substr; i++) {
        for (j = 0; j < len_substr; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == len_substr) {
            return i; // substring found at index i
        }
    }
    
    return -1; // substring not found
}

void replaceSubstring(char *str, const char *substr, const char *replace) {
    int len_str = 0;
    int len_substr = 0;
    int len_replace = 0;
    
    while (str[len_str] != '\0') {
        len_str++;
    }
    
    while (substr[len_substr] != '\0') {
        len_substr++;
    }
    
    while (replace[len_replace] != '\0') {
        len_replace++;
    }
    
    int substr_pos = findSubstring(str, substr);
    
    while (substr_pos != -1) {
        // Shift characters to the right to accommodate longer replace
        for (int i = len_str - 1; i >= substr_pos + len_substr; i--) {
            str[i + len_replace - len_substr] = str[i];
        }
        
        // Copy replace into str at substr_pos
        for (int i = 0; i < len_replace; i++) {
            str[substr_pos + i] = replace[i];
        }
        
        // Update length of str after replacement
        len_str = len_str + len_replace - len_substr;
        
        // Find next occurrence of substr in updated str
        substr_pos = findSubstring(str + substr_pos + len_replace, substr);
    }
    
    printf("String after replacement: %s\n", str);
}

int main() {
    char str[100];
    char substr[100];
    char replace[100];

    printf("Enter str: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character

    printf("Enter substr: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0';  // Remove newline character

    printf("Enter replacement string: ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = '\0';  // Remove newline character

    replaceSubstring(str, substr, replace);

    return 0;
}
