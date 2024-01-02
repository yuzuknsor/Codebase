#include <stdio.h>
// 复数结构体
struct complex
{
    double real;
    double imag;
};
// 复数加法
struct complex add(struct complex *a, struct complex *b)
{
    struct complex c;
    c.real = a->real + b->real;
    c.imag = a->imag + b->imag;
    return c;
}
// 复数减法
struct complex sub(struct complex *a, struct complex *b)
{
    struct complex c;
    c.real = a->real - b->real;
    c.imag = a->imag - b->imag;
    return c;
}
// 复数乘法
struct complex mul(struct complex *a, struct complex *b)
{
    struct complex c;
    c.real = a->real * b->real - a->imag * b->imag;
    c.imag = a->real * b->imag + a->imag * b->real;
    return c;
}
// 复数除法
struct complex div(struct complex *a, struct complex *b)
{
    struct complex c;
    c.real = b->real;
    c.imag = -b->imag;
    struct complex d = mul(a, &c);
    struct complex e = mul(b, &c);
    struct complex f;
    f.real = d.real / e.real;
    f.imag = d.imag / e.real;
    return f;
}

int main()
{
    struct complex a, b;
    scanf("%lf%lf%lf%lf", &a.real, &a.imag, &b.real, &b.imag);
    struct complex c = add(&a, &b);
    c.real *= 10;
    c.real = (int)(c.real);
    c.real /= 10;
    c.imag *= 10;
    c.imag = (int)(c.imag);
    c.imag /= 10;
    struct complex d = sub(&a, &b);
    d.real *= 10;
    d.real = (int)(d.real);
    d.real /= 10;
    d.imag *= 10;
    d.imag = (int)(d.imag);
    d.imag /= 10;
    struct complex e = mul(&a, &b);
    e.real *= 10;
    e.real = (int)(e.real);
    e.real /= 10;
    e.imag *= 10;
    e.imag = (int)(e.imag);
    e.imag /= 10;
    struct complex f = div(&a, &b);
    f.real *= 10;
    f.real = (int)(f.real);
    f.real /= 10;
    f.imag *= 10;
    f.imag = (int)(f.imag);
    f.imag /= 10;
    printf("(%.1f%+.1fi) + (%.1f%+.1fi) = ", a.real, a.imag, b.real, b.imag);
    if (c.real != 0)
    {
        printf("%.1f", c.real);
        if (c.imag != 0)
            printf("%+.1fi", c.imag);
    }
    else if(c.imag != 0)
        printf("%.1fi", c.imag);
    else if (c.real == 0 && c.imag == 0)
        printf("0.0");
    printf("\n");

    printf("(%.1f%+.1fi) - (%.1f%+.1fi) = ", a.real, a.imag, b.real, b.imag);
    if (d.real != 0)
    {
        printf("%.1f", d.real);
        if (d.imag != 0)
            printf("%+.1fi", d.imag);
    }
    else if (d.imag != 0)
        printf("%.1fi", d.imag);
    else if (d.real == 0 && d.imag == 0)
        printf("0.0");
    printf("\n");

    printf("(%.1f%+.1fi) * (%.1f%+.1fi) = ", a.real, a.imag, b.real, b.imag);
    if (e.real != 0)
    {
        printf("%.1f", e.real);
        if (e.imag != 0)
            printf("%+.1fi", e.imag);
    }
    else if (e.imag != 0)
        printf("%.1fi", e.imag);
    else if (e.real == 0 && e.imag == 0)
        printf("0.0");
    printf("\n");

    printf("(%.1f%+.1fi) / (%.1f%+.1fi) = ", a.real, a.imag, b.real, b.imag);
    if (f.real != 0)
    {
        printf("%.1f", f.real);
        if (f.imag != 0)
            printf("%+.1fi", f.imag);
    }
    else if (f.imag != 0)
        printf("%.1fi", f.imag);
    else if (f.real == 0 && f.imag == 0)
        printf("0.0");
    printf("\n");
    return 0;
}