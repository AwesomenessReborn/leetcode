// C program to illustrate Pointers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1) {
        return strs[0]; 
    }
    char *comm[200];

    int index = 0; 
    bool end = false; 
    while (!end) { 
        char pot = strs[index][0]; 

        for (int i = 1; i < strsSize; i++) {
            if (!pot == strs[index][i]) {
                end = true; 
            }
        }
        if (end == false) {
            comm[index] = pot; 
            index++; 
        }
    }

    return comm; 
}

int main() {
    char *test_a[] = {"flower", "flow", "flight"};
    char *test_b[] = {"dog","racecar","car"}; 

    printf("%s\n", longestCommonPrefix(test_a, 3)); 
    printf("%s\n", longestCommonPrefix(test_b, 3)); 
	
	return EXIT_SUCCESS;
}