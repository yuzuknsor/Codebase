#include <stdio.h>
#include <string.h>

#define fl(a, b, i) for (int i = a; i <= b; i++)

char numMap[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
int temp;

void print(int t)
{
    int a = t / 1000, b = (t % 1000) / 100, c = (t % 100) / 10, d = t % 10;
    if (a) printf("%cQ", numMap[a]);
    else if (temp) printf("a");
    if (b) printf("%cB", numMap[b]);
    else if (a && !b && (c || d)) printf("%c", numMap[b]);
    if (c) printf("%cS", numMap[c]);
    else if (b && !c && d) printf("%c", numMap[c]);
    if (d) printf("%c", numMap[d]);
    
    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 0) printf("a");

    if (n >= 100000000)
    {
        int temp = n / 100000000;
        printf("%cY", numMap[temp]);
    }
    n %= 100000000;

    if (n >= 10000)
    {
        print(n / 10000);
        temp = n / 10000;
        printf("W");
    }
    n %= 10000;

    if (n) print(n);

    return 0;
}