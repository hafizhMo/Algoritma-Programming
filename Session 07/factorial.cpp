#include <stdio.h>
#include <stdlib.h>

int n, i, min, hasil;
int factorial;
char ch_repeat;

int factorials(int factorial, int min)
{
    return factorial * min;
    ;
}

void print_process()
{
    for (i = n; i >= 1; i--)
    {
        min = i - 1;
        factorial = i * factorial;
        hasil = factorials(factorial, min);
        printf("%d ", factorial);

        if (min != 0)
            printf("* %d = %d\n", min, hasil);
    }
}

int main()
{

    do
    {
        printf("++++++++Hafizh+Naufal+++++++++\n");
        printf("Welcome to Factorial Program\n");
        printf("++++++++++++++++++++++++++++++\n");
        printf("Enter an integer: ");
        scanf("%d", &n);
        printf("\n");
        hasil = n;
        factorial = 1;

        print_process();

        printf("Factorial of %d = %d", n, factorial);
        printf("\n\nPress Y to Repeat...");
        scanf("%s", &ch_repeat);
        system("cls");

    } while (ch_repeat == 'y' || ch_repeat == 'Y');

    return 0;
}