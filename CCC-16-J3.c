#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *word) {
    int maxLetter = strlen(word);
    for(int i = 0; i < strlen(word)/2; i++) {
        if(word[i] != word[maxLetter-1-i]) {
            return 0;
        }
    }
    return 1;
}

int findPalindrome(char *word, int size) {
    for(int i = 0; i <= strlen(word)-size; i++) {
        char nextWord[41];
        strncpy(nextWord, word+i, size);
        nextWord[size] = '\0';
        if(isPalindrome(nextWord) == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *word = calloc(41, sizeof(char));
    scanf("%s", word);
    for(int i = 40; i > -1; i--) {
        if(i <= strlen(word)) {
            if(findPalindrome(word, i) == 1) {
                printf("%i\n", i);
                return 0;
            }
        }
    }
    free(word);
    return 0;
}