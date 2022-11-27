#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int c=n-1;
    for (int i = 1; i <= c; i++){
        for(int j=1;j<=c;j++) printf("%d ", c);
        printf("\n");
    }
}