#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// First Implementation
int compress1(char* chars, int charsSize) {
    if (charsSize == 1) return 1;
    int t = 1;
    int w_idx = 0;
    int curr = 1;
    char cc = chars[0];

    while (t < charsSize) {
        if (chars[t] != cc) {
            if (curr == 1) {
                chars[w_idx++] = cc;
            } else {
                chars[w_idx++] = cc;
                char temp[12];
                int length = snprintf(temp, sizeof(temp), "%d", curr);
                for (int i = 0; i < length; i++) {
                    chars[w_idx++] = temp[i];
                }
            }
            cc = chars[t];
            curr = 1;
        } else {
            curr++;
        }
        if (t == charsSize - 1) {
            if (curr == 1) {
                chars[w_idx++] = cc;
            } else {
                chars[w_idx++] = cc;
                char temp[12];
                int length = snprintf(temp, sizeof(temp), "%d", curr);
                for (int i = 0; i < length; i++) {
                    chars[w_idx++] = temp[i];
                }
            }
        }
        t++;
    }
    return w_idx;
}

// Improved Implementation
int compress2(char* chars, int charsSize) {
    if (charsSize == 1) return 1;
    int writeIndex = 0;
    int readIndex = 0;

    while (readIndex < charsSize) {
        char currentChar = chars[readIndex];
        int count = 0;
        while (readIndex < charsSize && chars[readIndex] == currentChar) {
            readIndex++;
            count++;
        }
        chars[writeIndex++] = currentChar;
        if (count > 1) {
            int start = writeIndex;
            while (count > 0) {
                chars[writeIndex++] = (count % 10) + '0';
                count /= 10;
            }
            for (int left = start, right = writeIndex - 1; left < right; left++, right--) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
            }
        }
    }
    return writeIndex;
}

void benchmark(void (*compress)(char*, int), char* input, int inputSize) {
    clock_t start = clock();
    for (int i = 0; i < 100000; i++) {
        char* copy = strdup(input);
        compress(copy, inputSize);
        free(copy);
    }
    clock_t end = clock();
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    char input[] = "aabbbcccc";
    int inputSize = strlen(input);
    printf("Benchmarking first implementation:\n");
    benchmark(compress1, input, inputSize);
    printf("Benchmarking improved implementation:\n");
    benchmark(compress2, input, inputSize);
    return 0;
}
