#include <stdio.h>

typedef struct
{
    int book_id;
    int start_time;
    int end_time;
} Record;

int Integize(int a, int b)
{
    double c = (double)a / b;
    return (int)(c + 0.5);
}

    int
    main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        Record records[1001] = {0};
        int book_id, hour, minute;
        char operation;
        int borrow_count = 0, total_time = 0;

        while (scanf("%d %c %d:%d", &book_id, &operation, &hour, &minute) != EOF && book_id != 0)
        {
            if (operation == 'S')
            {
                records[book_id].book_id = book_id;
                records[book_id].start_time = hour * 60 + minute;
            }
            else if (operation == 'E' && records[book_id].book_id != 0)
            {
                records[book_id].end_time = hour * 60 + minute;
                borrow_count++;
                total_time += records[book_id].end_time - records[book_id].start_time;
                records[book_id].book_id = 0;
            }
        }

        printf("%d %d\n", borrow_count, borrow_count == 0 ? 0 : Integize(total_time, borrow_count));
    }

    return 0;
}