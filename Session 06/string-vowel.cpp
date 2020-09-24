#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printValue(int total_consonant, int total_vowel)
{

    printf("\nDISPLAY ELEMENT");
    printf("\nTotal of Consonant : %d", total_consonant);
    printf("\nTotal of Vowel : %d", total_vowel);
}

int countConsonant(char inp_value[144])
{
    int cont, i;
    for (i = 0; inp_value[i] != '\0'; ++i)
    {

        if (inp_value[i] == 'a' || inp_value[i] == 'e' || inp_value[i] == 'i' ||
            inp_value[i] == 'o' || inp_value[i] == 'u' || inp_value[i] == 'A' ||
            inp_value[i] == 'E' || inp_value[i] == 'I' || inp_value[i] == 'O' ||
            inp_value[i] == 'U')
        {
            //do nothing
        }
        else if ((inp_value[i] >= 'a' && inp_value[i] <= 'z') || (inp_value[i] >= 'A' && inp_value[i] <= 'Z'))
        {
            cont = cont + 1;
        }
    }

    return cont;
}

int countVowel(char inp_value[144])
{
    int vowl, space, i;
    for (i = 0; inp_value[i] != '\0'; ++i)
    {

        if (inp_value[i] == ' ')
        {
            space = space + 1;
        }
    }

    return i - space;
}

void procesValue(char inp_value[144])
{
    int t_cont, t_vowl;

    t_cont = countConsonant(inp_value);
    t_vowl = t_cont - countVowel(inp_value);

    printValue(t_cont, t_vowl);
}

void getValue()
{
    char inp_value[114];

    printf("\nINPUT");
    printf("\nInput String : ");
    scanf("%[^\n]", inp_value);

    procesValue(inp_value);
}

int main()
{
    char ch_repeat;

    do
    {

        getValue();

        printf("\nRepeat [Y/N] ?");
        scanf("%s", &ch_repeat);

        fflush(stdin);

    } while ((ch_repeat == 'y') || (ch_repeat == 'Y'));

    return 0;
}