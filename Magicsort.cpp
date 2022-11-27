#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long a[100];
    for(int i=0; i<n ; i++) scanf("%d", &a[i]);
    long long tg;
    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(a[i] > a[j]){
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }
    printf("mang duoc sap xep la: ");
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    return 0;
}
