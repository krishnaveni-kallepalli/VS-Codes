#include <stdio.h>
#include <string.h>

void findSubstrAndReplace(char *str, char *substr, char *replace) {
    int len_str = strlen(str);
    int len_substr = strlen(substr);
    int len_replace = strlen(replace);

    if (len_substr == 0) {
        printf("Error: Substring cannot be empty.\n");
        return;
    }

    int max_size = len_str + (len_replace - len_substr);

    char temp[max_size + 1];
    temp[0] = '\0'; 

    int i = 0;
    while (i <= len_str - len_substr) {
        int j;

        for (j = 0; j < len_substr; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }

        if (j == len_substr) {
            strcat(temp, replace);  
            i += len_substr; 
        } else {
            strncat(temp, &str[i], 1);
            i++;
        }
    }
    strcat(temp, &str[i]);
    strcpy(str, temp);

    printf("String after replacement: %s\n", str);
}

int main() {
    char str[100];
    char substr[100];
    char replace[100];

    printf("Enter str: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter substr: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0';

    printf("Enter replacement string: ");
    fgets(replace, sizeof(replace), stdin);
    replace[strcspn(replace, "\n")] = '\0';

    findSubstrAndReplace(str, substr, replace);

    return 0;
}
