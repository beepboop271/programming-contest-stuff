#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    int instruction;
    char x, y;
    int n;
    do {
        scanf(" %d", &instruction);
        switch (instruction) {
            case 1:
                scanf(" %c %d", &x, &n);
                if(x == 'A') { a = n; }
                else { b = n; }
                break;
            case 2:
                scanf(" %c", &x);
                if(x == 'A') { printf("%d\n", a); }
                else { printf("%d\n", b); }
                break;
            case 3:
                scanf(" %c %c", &x, &y);
                if(y == 'A') { n = a; }
                else if(y == 'B') { n = b;}
                else { n = atoi(y); }

                if(x == 'A') { a += n; }
                else { b += n; }
                break;
            case 4:
                scanf(" %c %c", &x, &y);
                if(y == 'A') { n = a; }
                else if(y == 'B') { n = b; }
                else { n = atoi(y); }

                if(x == 'A') { a *= n; }
                else { b *= n; }
                break;
            case 5:
                scanf(" %c %c", &x, &y);
                if(y == 'A') { n = a; }
                else if(y == 'B') { n = b; }
                else { n = atoi(y); }

                if(x == 'A') { a -= n; }
                else { b -= n; }
                break;
            case 6:
                scanf(" %c %c", &x, &y);
                if(y == 'A') { n = a; }
                else if(y == 'B') { n = b; }
                else { n = atoi(y); }

                if(x == 'A') { a /= n; }
                else { b /= n; }
                break;
        }
    } while (instruction != 7);
    
    

    return 0;
}
