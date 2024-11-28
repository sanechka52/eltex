#include <stdio.h>
#include <string.h>
char* findSubstring(const char* str, const char* substr) {
    int strLen = strlen(str);
    int substrLen = strlen(substr);
    if (substrLen > strLen) {
        return NULL;
    }
    for (int i = 0; i <= strLen - substrLen; i++) {
        if (strncmp(&str[i], substr, substrLen) == 0) {
            return (char*)&str[i]; 
        }
    }
    return NULL; 
}
int main() {
    char str[100];
    char substr[100];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    printf("Введите подстроку: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; 
    char* result = findSubstring(str, substr);
    if (result != NULL) {
        printf("Подстрока найдена: %s\n", result);
    } else {
        printf("Подстрока не найдена.\n");
    }
    return 0;
}
