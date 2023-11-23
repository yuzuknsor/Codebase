#include <stdio.h>

int isPerfectNumber(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++) if (num % i == 0) sum += i;
    return sum == num;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int Perfect = 0;

    for (int i = m; i <= n; i++)
    {
        if (isPerfectNumber(i))
        {
            Perfect = 1;
            printf("%d = 1", i);
            for (int j = 2; j < i; j++) if (i % j == 0) printf(" + %d", j);
            printf("\n");
        }
    }

    if (!Perfect) printf("None");

    return 0;
}
