#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#ifdef _cplusplus_
#include <cstdlib>
#else
#include <stdlib.h>
#endif

struct stc_member
{
    char fullname[69];   /*************Created By**************/
    char nickname[69];   /* Hafizh Naufal - 2301886310 		**/
    char team_type[10];  /* Muhammad Faiz Azmi - 2301901173 	**/
    char blood_type[4];  /* Daffa Pratama - 2301948076 		**/
    char birth_date[12]; /* Michael Kwan - 2301877565 		**/
} MEMBRE[6];             /*************************************/

void CLEAR_SCREEN()
{
    if (system("CLS"))
        system("clear");
};

char PRINT_TABLE_HEAD()
{
    printf("=======================================================================================\n");
    printf("| %-2s | %-20s | %-15s | %-5s | %-15s | %-10s |\n", "No", "Nama Lengkap", "Nama Panggilan", "Goldar", "Tanggal Lahir", "Kelas");
    printf("=======================================================================================\n");
}

char PRINT_TABLE_BODY(int number, char *fullname, char *nickname, char *bloodtype, char *birthdate, char *team)
{
    printf("| %-2d | %-20s | %-15s | %-5s  | %-15s | %-10s |\n", number, fullname, nickname, bloodtype, birthdate, team);
}

char PRINT_TABLE_FOOTER()
{
    printf("=======================================================================================\n");
    printf("=======================================================================================\n");
}

void READ_DEFAULT()
{
    int i = 0;
    FILE *f_membre = fopen("member.txt", "r");

    while ((fscanf(f_membre, "%s %s %s %s %s/%s/%s", &MEMBRE[i].fullname, &MEMBRE[i].nickname, &MEMBRE[i].blood_type, &MEMBRE[i].team_type, &MEMBRE[i].birth_date)) != EOF)
    {

        i++;
    }
}

void READ_BY_DEFAULT()
{
    READ_DEFAULT();

    int i = 0;
    int size = sizeof(MEMBRE) / sizeof(MEMBRE[0]);
    PRINT_TABLE_HEAD();

    for (i = 0; i < size; i++)
    {
        PRINT_TABLE_BODY(i + 1, MEMBRE[i].fullname, MEMBRE[i].nickname, MEMBRE[i].blood_type, MEMBRE[i].birth_date, MEMBRE[i].team_type);
    }

    PRINT_TABLE_FOOTER();
}

void READ_BY_NAME()
{
    READ_DEFAULT();

    int j, i;
    char fullname_temp[69], nickname_temp[69], bloodtype_temp[69], birthdate_temp[69], team_temp[69];
    int size = sizeof(MEMBRE) / sizeof(MEMBRE[0]);
    PRINT_TABLE_HEAD();

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j <= size; j++)
        {
            if (strcmp(MEMBRE[i].fullname, MEMBRE[j].fullname) > 0)
            {
                strcpy(fullname_temp, MEMBRE[i].fullname);
                strcpy(MEMBRE[i].fullname, MEMBRE[j].fullname);
                strcpy(MEMBRE[j].fullname, fullname_temp);

                strcpy(nickname_temp, MEMBRE[i].nickname);
                strcpy(MEMBRE[i].nickname, MEMBRE[j].nickname);
                strcpy(MEMBRE[j].nickname, nickname_temp);

                strcpy(bloodtype_temp, MEMBRE[i].blood_type);
                strcpy(MEMBRE[i].blood_type, MEMBRE[j].blood_type);
                strcpy(MEMBRE[j].blood_type, bloodtype_temp);

                strcpy(birthdate_temp, MEMBRE[i].birth_date);
                strcpy(MEMBRE[i].birth_date, MEMBRE[j].birth_date);
                strcpy(MEMBRE[j].birth_date, birthdate_temp);

                strcpy(team_temp, MEMBRE[i].team_type);
                strcpy(MEMBRE[i].team_type, MEMBRE[j].team_type);
                strcpy(MEMBRE[j].team_type, team_temp);
            }
        }
    }

    for (i = 1; i <= size; i++)
    {
        PRINT_TABLE_BODY(i, MEMBRE[i].fullname, MEMBRE[i].nickname, MEMBRE[i].blood_type, MEMBRE[i].birth_date, MEMBRE[i].team_type);
    }

    PRINT_TABLE_FOOTER();
}

void READ_BY_BIRTH()
{
    READ_DEFAULT();

    int j, i, birth, birth2;
    char fullname_temp[69], nickname_temp[69], bloodtype_temp[69], birthdate_temp[69], team_temp[69];
    int size = sizeof(MEMBRE) / sizeof(MEMBRE[0]);
    PRINT_TABLE_HEAD();

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j <= size; j++)
        {
            if (strcmp(MEMBRE[i].birth_date, MEMBRE[j].birth_date) > 0)
            {
                strcpy(fullname_temp, MEMBRE[i].fullname);
                strcpy(MEMBRE[i].fullname, MEMBRE[j].fullname);
                strcpy(MEMBRE[j].fullname, fullname_temp);

                strcpy(nickname_temp, MEMBRE[i].nickname);
                strcpy(MEMBRE[i].nickname, MEMBRE[j].nickname);
                strcpy(MEMBRE[j].nickname, nickname_temp);

                strcpy(bloodtype_temp, MEMBRE[i].blood_type);
                strcpy(MEMBRE[i].blood_type, MEMBRE[j].blood_type);
                strcpy(MEMBRE[j].blood_type, bloodtype_temp);

                strcpy(birthdate_temp, MEMBRE[i].birth_date);
                strcpy(MEMBRE[i].birth_date, MEMBRE[j].birth_date);
                strcpy(MEMBRE[j].birth_date, birthdate_temp);

                strcpy(team_temp, MEMBRE[i].team_type);
                strcpy(MEMBRE[i].team_type, MEMBRE[j].team_type);
                strcpy(MEMBRE[j].team_type, team_temp);
            }
        }
    }

    for (i = 1; i <= size; i++)
    {
        PRINT_TABLE_BODY(i, MEMBRE[i].fullname, MEMBRE[i].nickname, MEMBRE[i].blood_type, MEMBRE[i].birth_date, MEMBRE[i].team_type);
    }

    PRINT_TABLE_FOOTER();
}

void SEARCH_MEMBRE()
{
    READ_DEFAULT();

    char keyword[69];
    int size = sizeof(MEMBRE) / sizeof(MEMBRE[0]);
    int i, status;

    printf("masukan nama panggilan member: ");
    scanf("%s", &keyword);

    status = 0;
    for (i = 0; i < size; i++)
    {
        if (strcasecmp(keyword, MEMBRE[i].nickname) == 0)
        {
            printf("\nNama Lengkap: %s", MEMBRE[i].fullname);
            printf("\nNama Panggilan: %s", MEMBRE[i].nickname);
            printf("\nGolongan Darah: %s", MEMBRE[i].blood_type);
            printf("\nTanggal Lahir: %s", MEMBRE[i].birth_date);
            printf("\nKelas: %s", MEMBRE[i].team_type);
            status = 1;
            break;
        }
    }

    if (status == 0)
    {
        printf("\nnotfound");
    }
}

void MAIN_MENU()
{
    printf("1. lihat list member\n");
    printf("2. cari member\n");
    printf("3. urutkan member\n");
    printf("4. keluar\n");
}

void SORT_MENU()
{
    char anw_user;
    do
    {
        CLEAR_SCREEN();
        printf("1. urut berdasarkan nama lengkap\n");
        printf("2. urut berdasarkan tanggal lahir\n");
        printf("3. kembali\n");

        do
        {
            printf("\nMasukan pilihan mu [1..3]");
            anw_user = getche();

        } while ((anw_user != '1') && (anw_user != '2') && (anw_user != '3'));
        switch (anw_user)
        {
        case '1':
            CLEAR_SCREEN();
            READ_BY_NAME();
            break;
        case '2':
            CLEAR_SCREEN();
            READ_BY_BIRTH();
            break;
        };
        if (anw_user != '3')
            getche();
    } while (anw_user != '3');
}

int main()
{
    char anw_user;
    do
    {
        CLEAR_SCREEN();
        printf("|%-10s/%-10s/%-10s/%-10s|\n\n", "HafizhNaufal[2301886310]", "MuhammadFaiz[2301901173]", "DaffaPratama[2301948076]", "MichaelKwan[2301877565]");
        MAIN_MENU();

        do
        {
            fflush(stdin);
            printf("\nMasukan pilihan mu [1..4]");
            anw_user = getche();

        } while ((anw_user != '1') && (anw_user != '2') && (anw_user != '3') && (anw_user != '4'));
        switch (anw_user)
        {
        case '1':
            CLEAR_SCREEN();
            READ_BY_DEFAULT();
            break;
        case '2':
            CLEAR_SCREEN();
            SEARCH_MEMBRE();
            break;
        case '3':
            CLEAR_SCREEN();
            SORT_MENU();
            break;
        };
        if (anw_user != '4')
            getche();
    } while (anw_user != '4');
}