#include <stdio.h>

// Função que retorna 1 se o ponto (x, y) está dentro do retângulo definido pelos pontos (x0, y0) e (x1, y1)

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y){

    if( x > x0 && x < x1 && y > y0 && y < y1 ){
        return 1;
    }else{
        return 0;
    }

}


int main(){

    int x0, y0, x1, y1, x, y;

    scanf("%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x, &y);

    printf("%d", dentro_ret(x0, y0, x1, y1, x, y));

}