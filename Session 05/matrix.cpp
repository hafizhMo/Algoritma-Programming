#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, int_lines, int_column, answer, *intMatriks;
int odd_count = 0;

int askOddNumber()
{
//    printf("\nodd Number = %d", odd_count);
    printf("\nHow many odd Number? ");
    scanf("%d", &answer);

    if (answer == odd_count)
    {
        printf("Your Are Brilliant");
    }
    else
    {
        printf("Your Are Wrong");
    }
}

int askRowColumn()
{
    printf("Hafizhnaufal-2301886310\n\nSpeed Guess?\nMatrix Row Size [Max 20] = ");
    scanf("%d", &int_lines);
    printf("Matrix Column Size [Max 20] = ");
    scanf("%d", &int_column);
}

int main()
{
    srand(time(0));

    askRowColumn();

    printf("\nSpeed Guess Random Matrix\n\n");
    intMatriks = (int *)malloc(int_lines * int_column * sizeof(int));

    for (i = 0; i < int_lines; ++i)
    {

        for (j = 0; j < int_column; ++j)
        {

            intMatriks[i] = rand() % 99 + 1;

            if (intMatriks[i] % 2 == 1)
            {
                odd_count++;
            }

            printf("[%d][%d] %d\t", i, j, intMatriks[i]);
        }

        printf("\n");
    }

    askOddNumber();
}
