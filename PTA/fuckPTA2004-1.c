#include <stdio.h>

int main()
{
    char ch;
    int num = 0;
    int flag = 0;
    int started = 0;
    int last_num = 0;
    int Fuck_you_PTA_and_This_is_my_last_fucking_change_What_mf_a_bullshit_fuching_bloody_hell_stupid_question = 0;
    while ((ch = getchar()) != '.')
    {
        if (ch == ' ')
        {
            if (!flag && started)
            {
                if (Fuck_you_PTA_and_This_is_my_last_fucking_change_What_mf_a_bullshit_fuching_bloody_hell_stupid_question)
                {
                    printf("%d ", last_num);
                }
                last_num = num;
                Fuck_you_PTA_and_This_is_my_last_fucking_change_What_mf_a_bullshit_fuching_bloody_hell_stupid_question = 1;
                num = 0;
            }
            flag = 1;
        }
        else
        {
            ++num;
            flag = 0;
            started = 1;
        }
    }
    if (started)
    {
        if (Fuck_you_PTA_and_This_is_my_last_fucking_change_What_mf_a_bullshit_fuching_bloody_hell_stupid_question)
        {
            printf("%d", last_num);
        }
        if (num > 0)
        {
            if (Fuck_you_PTA_and_This_is_my_last_fucking_change_What_mf_a_bullshit_fuching_bloody_hell_stupid_question)
            {
                printf(" ");
            }
            printf("%d", num);
        }
    }
    return 0;
}
