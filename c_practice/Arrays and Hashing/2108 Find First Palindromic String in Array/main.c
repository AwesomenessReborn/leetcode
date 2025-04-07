
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i < wordsSize; i++) {
        if (isPalindrome(words[i])) return words[i];  
    }
    return ""; 
}

int main(int argc, char const *argv[])
{
    char* words1[] = {"abc", "car", "ada", "racecar", "cool"};
    int wordsSize1 = sizeof(words1) / sizeof(words1[0]);
    printf("Output: %s\n", firstPalindrome(words1, wordsSize1)); // Expected: "ada"
    printf("expceted: ada \n\n"); 

    char* words2[] = {"notapalindrome", "racecar"};
    int wordsSize2 = sizeof(words2) / sizeof(words2[0]);
    printf("Output: %s\n", firstPalindrome(words2, wordsSize2)); // Expected: "racecar"
    printf("expceted: racecar \n\n"); 

    char* words3[] = {"def", "ghi"};
    int wordsSize3 = sizeof(words3) / sizeof(words3[0]);
    printf("Output: %s\n", firstPalindrome(words3, wordsSize3)); // Expected: ""
    printf("expceted: \"\" \n\n"); 

    return 0;
}
