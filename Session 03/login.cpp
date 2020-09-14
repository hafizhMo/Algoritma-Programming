#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int menu_remaining_balance()
{
    printf("Remaining Balance\n");
    printf("#################\n\n");

    printf("Your Remaining Balance\t\t = Rp. 250000\n");
    printf("Your phone number valid until\t = 31 December 2019");

    printf("\n\nThankyou for using this application.");

    return 0;
}

int menu_reload()
{
    int int_choice2;
    int int_total2;

    printf("Your Remaining Balance = Rp. 250000\n\n");

    printf("Reload\n");
    printf("######\n\nChoose a product to reload\n");

    printf("1. Rp. 50.000\n");
    printf("2. Rp. 100.000\n");
    printf("3. Rp. 150.000\n");
    printf("4. Rp. 200.000\n\n");

    printf("Enter your choice : ");
    scanf("%d", &int_choice2);

    switch (int_choice2)
    {
    case 1:
    {
        int_total2 = 250000 + 50000;
        break;
    }
    case 2:
    {
        int_total2 = 250000 + 100000;
        break;
    }
    case 3:
    {
        int_total2 = 250000 + 150000;
        break;
    }
    case 4:
    {
        int_total2 = 250000 + 200000;
        break;
    }
    default:
    {
        int_total2 = 0;
        break;
    }
    }

    if (int_total2 > 0)
        printf("\n\nCongrats!\nYour balance now = Rp. %d", int_total2);
    else
        printf("\n\nIt is out of our choice.");

    printf("\n\nThankyou for using this application.");

    return 0;
}

int menu_transfer_balance()
{
    int int_transfer;
    int int_total;

    printf("Your Remaining Balance\t\t = Rp. 250000\n\n");

    printf("Transfer Balance\n");
    printf("#################\n\n");

    printf("Phone number to be transferred [10..14]\t = 082121392929\n");
    printf("Balance to be transferred\t\t = ");
    scanf("%d", &int_transfer);

    int_total = 250000 - int_transfer;

    if (int_total < 0)
        printf("\nYour balance is not enough.\n\nThankyou for using this application.");
    else
        printf("\nCongrats!\nYou successfully transferred Rp. %d\nYour balance now = Rp. %d\n\nThankyou for using this application.", int_transfer, int_total);

    return 0;
}

int menu_phone_services()
{
    int int_choice;

    printf("\t\t# Simple Phone Services #\n");
    printf("\t\t#########################\n\n");

    printf("1. Remaining Balance\n");
    printf("2. Reload\n");
    printf("3. Transfer Balance\n");
    printf("4. Exit\n\n");

    printf("Enter your choice : ");
    scanf("%d", &int_choice);

    switch (int_choice)
    {
    case 1:
    {
        system("cls");
        menu_remaining_balance();
        break;
    }
    case 2:
    {
        system("cls");
        menu_reload();
        break;
    }
    case 3:
    {
        system("cls");
        menu_transfer_balance();
        break;
    }
    case 4:
    {
        system("cls");
        break;
    }
    default:
    {
        printf("\n\nIt is out of our choice");
        break;
    }
    }
    return 0;
}

int main()
{
    char str_user[8], str_pass[8];

    printf("\t\t  Login First\n\n");

    printf("Username : ");
    scanf("%s", str_user);

    printf("Password : ");
    scanf("%s", str_pass);

    if (strcmp(str_user, "phone") == 0 && strcmp(str_pass, "phone") == 0)
    {
        system("cls");
        menu_phone_services();
    }
    else
    {
        printf("\n\nYour username and password is incorrect.\nPress enter for continue...\n\nThankyou for using this application.");
    }

    return 0;
}
