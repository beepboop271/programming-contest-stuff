#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    char *encoding[20];
} huffmanCode;

int main() {
    int numChars;
    scanf("%d", &numChars);

    huffmanCode *codes = malloc(numChars*sizeof(huffmanCode));

    for(int i = 0; i < numChars; i++) {
        scanf(" %c %s", &codes[i].character, codes[i].encoding);
    }
    char *code = malloc(sizeof(char)*300);
    scanf(" %s", code);

    char result[300];
    int charsWritten = 0;
    while(strlen(code) > 0) {
        for(int i = 0; i < numChars; i++) {
            if(strncmp(code, codes[i].encoding, strlen(codes[i].encoding)) == 0) {
                result[charsWritten] = codes[i].character;
                charsWritten += 1;
                code = memmove(code, code+(strlen(codes[i].encoding)), 300);
            }
        }
    }
    result[charsWritten] = '\0';
    printf("%s\n", result);
    free(codes);
    free(code);
    return 0;
}