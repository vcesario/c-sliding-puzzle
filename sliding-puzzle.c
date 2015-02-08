#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tabelaChars();
void randomizar();
void printar();
int controlar();
int achaChar(char *arr,int n,char c);
char teclaPress();
void mover(char *arr, int n, char dir, int pos);

int main(){
    int i;
    //char elements[9] = {'A','B','C','D','E','F','G','H',' '};
    char elements[/*9*/] = "ABCDEFGH ";

    randomizar(elements,9);

    do{
        system("cls");
        printar(elements,9);
    }while(controlar(elements,9));


    return 0;
}
void tabelaChars(){
    int i;
    printf("COD\tCHAR");
    for (i = 255; i>32; i--){
        printf("\n%d\t%c",i,i);
    }
}
void randomizar(char *arr, int n){
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
void printar(char *arr, int n){
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
int achaChar(char *arr,int n,char c){
    int i;
    for (i = n-1;i>=0;i--){
        if (arr[i] == c){
            return i;
        }
    }
    return -1;
}
int controlar(char *arr, int n){
    char tecla;
    int pos;

    pos = achaChar(arr,n,' ');

    switch(pos){
    case 0:
        tecla = teclaPress();
        if (tecla == 'U' || tecla == 'L'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 1:
        tecla = teclaPress();
        if (tecla == 'U' || tecla == 'L' || tecla == 'R'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 2:
        tecla = teclaPress();
        if (tecla == 'U' || tecla == 'R'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 3:
        tecla = teclaPress();
        if (tecla == 'U' || tecla == 'D' || tecla == 'L'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 4:
        tecla = teclaPress();
        if (tecla == 'U' || tecla == 'L' || tecla == 'D' || tecla == 'R'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 5:
        tecla = teclaPress();
        if (tecla == 'U' || tecla == 'D' || tecla == 'R'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 6:
        tecla = teclaPress();
        if (tecla == 'D' || tecla == 'L'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 7:
        tecla = teclaPress();
        if (tecla == 'D' || tecla == 'L' || tecla == 'R'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    case 8:
        tecla = teclaPress();
        if (tecla == 'D' || tecla == 'R'){
            mover(arr,n,tecla,pos);
        }
        else if (tecla == 'E'){
            //SAIR
            return 0;
        }
        break;
    }
    return 1;
}

char teclaPress(){
    int point;
    char input;

    input = getch();

    switch(input){
    // DIRECIONAIS
    case -32:
        input = getch();
        switch (input){
        //CIMA
        case 72:
            return 'U';
            //break;
        //BAIXO
        case 80:
            return 'D';
            //break;
        //ESQUERDA
        case 75:
            return 'L';
            //break;
        //DIREITA
        case 77:
            return 'R';
            //break;
        default:
            return teclaPress();
            //break;
        }
        break;
    //ESC
    case 27:
        return 'E';
        //break;
    }
}

void mover(char *arr, int n, char tecla, int pos){
    char aux;
    if (tecla == 'U'){
        aux = arr[pos+3];
        arr[pos+3] = arr[pos];
        arr[pos] = aux;
    }
    else if (tecla == 'D'){
        aux = arr[pos-3];
        arr[pos-3] = arr[pos];
        arr[pos] = aux;
    }
    else if (tecla == 'L'){
        aux = arr[pos+1];
        arr[pos+1] = arr[pos];
        arr[pos] = aux;
    }
    else if (tecla == 'R'){
        aux = arr[pos-1];
        arr[pos-1] = arr[pos];
        arr[pos] = aux;
    }
}
