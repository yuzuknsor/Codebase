#include <stdio.h>
#define MAXN 10
void find(int a[], int n, int *pmax, int *pmin);

int main()
{
    int i, n, min, max;
    int a[MAXN];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    find(a, n, &max, &min);
    
    printf("%d %d\n", max, min);
    return 0;
}

void find(int a[],int n,int *pmax,int *pmin)
{
    int i,max,min;
    max = min = a[0];
    for (i = 1; i < n; i++) {
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    
    *pmax = max;
    *pmin = min;
}
