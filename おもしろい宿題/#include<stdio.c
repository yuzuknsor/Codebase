#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, d, x[5], y[5];
    int i, j;
    char k[5] = {'+', '-', '*', '/'};
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    x[0] = a + c;
    y[0] = b + d;
    x[1] = a - c;
    y[1] = b - d;
    x[2] = a * c - b * d;
    y[2] = b * c + a * d;
    x[3] = (a * c + b * d) / (c * c + d * d);
    y[3] = (b * c - a * d) / (c * c + d * d);

    for (i = 0; i < 4; i++)
    {
        if (fabs(x[i]) < 0.05 && fabs(y[i]) < 0.05)
        {
            printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = 0.0\n", a, b, k[i], c, d);
        }
        else if (fabs(x[i]) < 0.05)
        {
            printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = %.1fi\n", a, b, k[i], c, d, y[i]);
        }
        else if (fabs(y[i]) < 0.05)
        {
            printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = %.1f\n", a, b, k[i], c, d, x[i]);
        }
        else
        {
            printf("(%.1f%+.1fi) %c (%.1f%+.1fi) = %.1f%+.1fi\n", a, b, k[i], c, d, x[i], y[i]);
        }
    }
    return 0;
}
