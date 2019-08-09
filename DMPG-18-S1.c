#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int operations[110000];
    int currentOp = 0;

    char input;
    int inputInt = 0;

    scanf("%c", &input);
    inputInt = atoi(&input);
    operations[currentOp] = inputInt;
    scanf("%c", &input);

    while(input != '\n') {
        inputInt = atoi(&input);
        if(inputInt == 0) {
            operations[currentOp]--;
            while(operations[currentOp] == 0 && currentOp > 0) {
                //printf("%d\n", operations[currentOp]);
                currentOp--;
                operations[currentOp]--;
            }
        } else {
            currentOp++;
            operations[currentOp] = inputInt;
        }

        //printf("%d %d %d\n", inputInt, currentOp, operations[currentOp]);
        scanf("%c", &input);
    }
    if(currentOp == 0 && operations[currentOp] == 0) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    
    return 0;
}
