#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

char str_user[24], str_pass[24];
char str_valid[24] = "phone";
int int_choice;
int int_balance = 0;

int menu_login()
{

    printf("\t\t  Login First\n\n");

    printf("Username : ");
    scanf("%s", &str_user);

    printf("Password : ");
    scanf("%s", &str_pass);
}

int menu_remaining_balance()
{
    system("cls");

    printf("Remaining Balance\n");
    printf("#################\n\n");

    printf("Your Remaining Balance\t\t = Rp. %d\n", int_balance);
    printf("Your phone number valid until\t = 31 December 2019");

    printf("\n\nThankyou for using this application.\n");
}

int menu_reload()
{
    system("cls");

    int int_choice2;

    printf("Your Remaining Balance = Rp. %d\n\n", int_balance);

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
        int_balance = int_balance + 50000;
        break;
    }
    case 2:
    {
        int_balance = int_balance + 100000;
        break;
    }
    case 3:
    {
        int_balance = int_balance + 150000;
        break;
    }
    case 4:
    {
        int_balance = int_balance + 200000;
        break;
    }
    default:
    {
        break;
    }
    }

    if (int_balance > 0)
        printf("\n\nCongrats!\nYour balance now = Rp. %d", int_balance);
    else
        printf("\n\nIt is out of our choice.");

    printf("\n\nThankyou for using this application.");
}

int menu_transfer_balance()
{
    system("cls");

    int int_transfer;

    printf("Your Remaining Balance\t\t = Rp. %d\n\n", int_balance);

    printf("Transfer Balance\n");
    printf("#################\n\n");

    printf("Phone number to be transferred [10..14]\t = 082121392929\n");
    printf("Balance to be transferred\t\t = ");
    scanf("%d", &int_transfer);

    if (int_balance < int_transfer)
        printf("\nYour balance is not enough.\n\nThankyou for using this application.");
    else
    {
        int_balance = int_balance - int_transfer;
        printf("\nCongrats!\nYou successfully transferred Rp. %d\nYour balance now = Rp. %d\n\nThankyou for using this application.", int_transfer, int_balance);
    }
}

int menu_phone_services()
{
    system("cls");

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
        menu_remaining_balance();
        getch();
        break;
    }
    case 2:
    {
        menu_reload();
        getch();
        break;
    }
    case 3:
    {
        menu_transfer_balance();
        getch();
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
}

int main()
{
    printf("Nama: Hafizh Naufal Hizbullah\n");
    printf("NIM : 2301886310 - 4\n\n");

    do
    {
        menu_login();
    } while (strcmp(str_user, str_valid) != 0 || strcmp(str_pass, str_valid) != 0);

    do
    {
        system("cls");
        menu_phone_services();
    } while (int_choice < 4);

    return 0;
}
