#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 9

void randomize();
void printGame();
int moveTiles();
int charPosition(char *arr,int n,char c);
char getKey();
void tileChange(char *arr, int n, char dir, int pos);
int completed(char *arr, int n);

int main(){
    int i;
    char elements[] = "ABCDEFGH ";

    randomize(elements,size);

    do{
        system("cls");
        printf("\n\n\n");
        printGame(elements,size);
    }while(moveTiles(elements,size) && !completed(elements,size));

    system("cls");
    printf("\n\n\n");
    printf(" Wow, you did it! I never solved this game, so I'm not really sure if\n you'll read this message at all. Well, congratulations anyway.\n Thank you for playing!");


    return 0;
}

void randomize(char *arr, int n){
    int i, pos;
    char aux;

    srand(time(NULL));

    for (i = 0;i<n;i++){
        pos = rand()%n;

        aux = arr[i];
        arr[i] = arr[pos];
        arr[pos] = aux;
    }

    return;
}

void printGame(char *arr, int n){
    int i;
    printf("\t\t\t\t%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,187);
    for (i = 0; i<n;i=i+3){
        printf("\t\t\t\t%c\t%c\n",186,186);
        printf("\t\t\t\t%c %c %c %c %c\n",186,arr[i],arr[i+1],arr[i+2],186);
    }
    printf("\t\t\t\t%c\t%c\n",186,186);
    printf("\t\t\t\t%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,188);
    printf("\n\n Welcome to Cesario's Sliding Puzzle! Use the arrow keys to move the letters\n towards the empty space and try to rearrange them into");
    printf(" ascending order.\n Press [ESC] to leave. Good luck!");

    return;
}

int charPosition(char *arr,int n,char c){
    int i;
    for (i = n-1;i>=0;i--)
        if (arr[i] == c)
            return i;

    return -1;
}
int completed(char *arr, int n){
    if (charPosition(arr,n,'A') == 0)
        if (charPosition(arr,n,'B') == 1)
            if (charPosition(arr,n,'C') == 2)
                if (charPosition(arr,n,'D') == 3)
                    if (charPosition(arr,n,'E') == 4)
                        if (charPosition(arr,n,'F') == 5)
                            if (charPosition(arr,n,'G') == 6)
                                if (charPosition(arr,n,'H') == 7) return 1;
                                else return 0;
                            else return 0;
                        else return 0;
                    else return 0;
                else return 0;
            else return 0;
        else return 0;
    else return 0;
}
int moveTiles(char *arr, int n){
    char keyPressed;
    int pos;

    pos = charPosition(arr,n,' ');

    switch(pos){
    case 0:
        keyPressed = getKey();
        if (keyPressed == 'U' || keyPressed == 'L'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 1:
        keyPressed = getKey();
        if (keyPressed == 'U' || keyPressed == 'L' || keyPressed == 'R'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 2:
        keyPressed = getKey();
        if (keyPressed == 'U' || keyPressed == 'R'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 3:
        keyPressed = getKey();
        if (keyPressed == 'U' || keyPressed == 'D' || keyPressed == 'L'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 4:
        keyPressed = getKey();
        if (keyPressed == 'U' || keyPressed == 'L' || keyPressed == 'D' || keyPressed == 'R'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 5:
        keyPressed = getKey();
        if (keyPressed == 'U' || keyPressed == 'D' || keyPressed == 'R'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 6:
        keyPressed = getKey();
        if (keyPressed == 'D' || keyPressed == 'L'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 7:
        keyPressed = getKey();
        if (keyPressed == 'D' || keyPressed == 'L' || keyPressed == 'R'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    case 8:
        keyPressed = getKey();
        if (keyPressed == 'D' || keyPressed == 'R'){
            tileChange(arr,n,keyPressed,pos);
        }
        else if (keyPressed == 'E'){
            return 0;
        }
        break;
    }
    return 1;
}

char getKey(){
    int point;
    char input;

    input = getch();

    switch(input){
    // ARROW KEYS
    case -32:
        input = getch();
        switch (input){
        //UP
        case 72:
            return 'U';
        //DOWN
        case 80:
            return 'D';
        //LEFT
        case 75:
            return 'L';
        //RIGHT
        case 77:
            return 'R';
        default:
            return getKey();
        }
        break;
    //ESC
    case 27:
        return 'E';
    }
}

void tileChange(char *arr, int n, char arrowKey, int pos){
    char aux;
    if (arrowKey == 'U'){
        aux = arr[pos+3];
        arr[pos+3] = arr[pos];
        arr[pos] = aux;
    }
    else if (arrowKey == 'D'){
        aux = arr[pos-3];
        arr[pos-3] = arr[pos];
        arr[pos] = aux;
    }
    else if (arrowKey == 'L'){
        aux = arr[pos+1];
        arr[pos+1] = arr[pos];
        arr[pos] = aux;
    }
    else if (arrowKey == 'R'){
        aux = arr[pos-1];
        arr[pos-1] = arr[pos];
        arr[pos] = aux;
    }
}
