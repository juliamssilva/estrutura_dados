#include <stdio.h>

int primo(int n ){

    if (n <= 2){
        return 1;
    }

    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;   
}

int main(){

    int num;

    scanf("%d", &num);

    printf("%d", primo(num));

    return 0;
}