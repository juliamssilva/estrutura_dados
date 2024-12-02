#include <stdio.h>

int fibo(int n){

    int primeiro = 0, segundo = 1, prox;

    for(int i =0;i<=n;i++){
        if(i<= 1){
            prox = i;
        }else{
            prox = primeiro + segundo;
            primeiro = segundo;
            segundo = prox;
        }
        printf("%d\n", prox);
    } 


}

int main(){

    int n; 

    scanf("%d", &n);

    printf("%d", fibo(n));

    return 0;
    }