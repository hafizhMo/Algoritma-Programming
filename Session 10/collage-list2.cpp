#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#ifdef _cplusplus_
#include <cstdlib>
#else
#include <stdlib.h>
#endif

struct str_mahasiswa
{
    int mh_nim;
    char mh_name[20];
    char mh_category[20];
    int mh_dd;
    int mh_mm;
    int mh_yyyy;
} MAHASISWA;

struct str_mahasiswa2
{
    int mh_nim;
    char mh_name[20];
    char mh_category[20];
    int mh_dd;
    int mh_mm;
    int mh_yyyy;
} MAHASISWA2[100];

struct str_mahasiswa *mhs;

FILE *f_menu;
int status = 0;

void CLEAR_SCREEN()
{
    if (system("CLS"))
        system("clear");
};

void SORT_DATA()
{
    printf("SISTEM INFORMASI MAHASISWA");
    printf("\n=========================");
    printf("\n1. Sort by NIM");
    printf("\n2. Sort by Birthday");

    char PIL;
    do
    {
        fflush(stdin);
        printf("\n\nInput Your Choice [1-2] : ");
        PIL = getche();

    } while ((PIL != '1') && (PIL != '2'));
    switch (PIL)
    {
    case '1':
        status = 1;
        break;
    case '2':
        status = 2;
        break;
    };
}

void SHOW_DATA_SORTED_BIRTH()
{
    f_menu = fopen("mahasiswa.txt", "r");
    int i = 0;
    int j, temp = 0;
    int angka = 0;
    int ddd, mmm, yyy;
    char name[10][20], category[10][20], namaa[20], categoryy[20];

    int nim[10], nimTemp[10], dd[10], mm[10], yyyy[10];
    printf("=================================================================================\n");
    printf("|%-15s| %-20s| %-20s | %s\t|", "NIM", "JURUSAN", "NAMA MAHASISWA", "TGL LAHIR");
    printf("\n=================================================================================");

    if (f_menu == NULL)
    {
        printf("\n|\t\t\t%-50s|", "data mahasiswa is empty");
    }
    else
    {
        while (fscanf(f_menu, "%d %s %s %d/%d/%d", &nim[i], &category[i], &name[i], &dd[i], &mm[i], &yyyy[i]) != EOF)
        {
            for (j = i; j < sizeof(f_menu); j++)
            {
                if (yyyy[i] > yyyy[j])
                {
                    angka = nim[i];
                    nim[i] = nim[j];
                    nim[j] = angka;
                    ddd = dd[i];
                    dd[i] = dd[j];
                    dd[j] = ddd;
                    mmm = mm[i];
                    mm[i] = mm[j];
                    mm[j] = mmm;
                    yyy = yyyy[i];
                    yyyy[i] = yyyy[j];
                    yyyy[j] = yyy;
                    strcpy(namaa, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], namaa);
                    strcpy(categoryy, category[i]);
                    strcpy(category[i], category[j]);
                    strcpy(category[j], categoryy);
                }
                else if (yyyy[i] == yyyy[j])
                {
                    if (mm[i] > mm[j])
                    {
                        angka = nim[i];
                        nim[i] = nim[j];
                        nim[j] = angka;
                        ddd = dd[i];
                        dd[i] = dd[j];
                        dd[j] = ddd;
                        mmm = mm[i];
                        mm[i] = mm[j];
                        mm[j] = mmm;
                        yyy = yyyy[i];
                        yyyy[i] = yyyy[j];
                        yyyy[j] = yyy;
                        strcpy(namaa, name[i]);
                        strcpy(name[i], name[j]);
                        strcpy(name[j], namaa);
                        strcpy(categoryy, category[i]);
                        strcpy(category[i], category[j]);
                        strcpy(category[j], categoryy);
                    }
                    else if (mm[i] == mm[j])
                    {
                        if (dd[i] > dd[j])
                        {
                            angka = nim[i];
                            nim[i] = nim[j];
                            nim[j] = angka;
                            ddd = dd[i];
                            dd[i] = dd[j];
                            dd[j] = ddd;
                            mmm = mm[i];
                            mm[i] = mm[j];
                            mm[j] = mmm;
                            yyy = yyyy[i];
                            yyyy[i] = yyyy[j];
                            yyyy[j] = yyy;
                            strcpy(namaa, name[i]);
                            strcpy(name[i], name[j]);
                            strcpy(name[j], namaa);
                            strcpy(categoryy, category[i]);
                            strcpy(category[i], category[j]);
                            strcpy(category[j], categoryy);
                        }
                        else if (dd[i] == dd[j])
                        {
                            angka = nim[i];
                            nim[i] = nim[j];
                            nim[j] = angka;
                            ddd = dd[i];
                            dd[i] = dd[j];
                            dd[j] = ddd;
                            mmm = mm[i];
                            mm[i] = mm[j];
                            mm[j] = mmm;
                            yyy = yyyy[i];
                            yyyy[i] = yyyy[j];
                            yyyy[j] = yyy;
                            strcpy(namaa, name[i]);
                            strcpy(name[i], name[j]);
                            strcpy(name[j], namaa);
                            strcpy(categoryy, category[i]);
                            strcpy(category[i], category[j]);
                            strcpy(category[j], categoryy);
                        }
                    }
                }
            }
        }
        for (i = 1; i < sizeof(f_menu); i++)
        {
            printf("\n|%-15d| %-20s| %-20s | %d/%d/%d\t|", nim[i], category[i], name[i], dd[i], mm[i], yyyy[i]);
        }
    }
}

void SHOW_DATA_SORTED_NIM()
{
    f_menu = fopen("mahasiswa.txt", "r");
    int i = 0;
    int j, temp = 0;
    int angka = 0;
    int ddd, mmm, yyy;
    char name[10][20], category[10][20], namaa[20], categoryy[20];

    int nim[10], nimTemp[10], dd[10], mm[10], yyyy[10];
    printf("=================================================================================\n");
    printf("|%-15s| %-20s| %-20s | %s\t|", "NIM", "JURUSAN", "NAMA MAHASISWA", "TGL LAHIR");
    printf("\n=================================================================================");

    while (fscanf(f_menu, "%d %s %s %d/%d/%d", &nim[i], &category[i], &name[i], &dd[i], &mm[i], &yyyy[i]) != EOF)
    {
        for (j = i + 1; j < sizeof(f_menu); j++)
        {
            if (nim[i] > nim[j])
            {
                angka = nim[i];
                nim[i] = nim[j];
                nim[j] = angka;
                ddd = dd[i];
                dd[i] = dd[j];
                dd[j] = ddd;
                mmm = mm[i];
                mm[i] = mm[j];
                mm[j] = mmm;
                yyy = yyyy[i];
                yyyy[i] = yyyy[j];
                yyyy[j] = yyy;
                strcpy(namaa, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], namaa);
                strcpy(categoryy, category[i]);
                strcpy(category[i], category[j]);
                strcpy(category[j], categoryy);
            }
        }
    }
    for (i = 1; i < sizeof(f_menu); i++)
    {
        printf("\n|%-15d| %-20s| %-20s | %d/%d/%d\t|", nim[i], category[i], name[i], dd[i], mm[i], yyyy[i]);
    }
}

void SHOW_DATA_DEFAULT()
{
    f_menu = fopen("mahasiswa.txt", "r");
    char name[10][20], category[10][20];

    int nim[10], dd[10], mm[10], yyyy[10];
    int i = 0;

    printf("=================================================================================\n");
    printf("|%-15s| %-20s| %-20s | %s\t|", "NIM", "JURUSAN", "NAMA MAHASISWA", "TGL LAHIR");
    printf("\n=================================================================================");
    while (fscanf(f_menu, "%d %s %s %d/%d/%d", &nim[i], &category[i], &name[i], &dd[i], &mm[i], &yyyy[i]) != EOF)
    {
        printf("\n|%-15d| %-20s| %-20s | %d/%d/%d\t|", nim[i], category[i], name[i], dd[i], mm[i], yyyy[i]);
        i++;
    }
}

void SHOW_DATA_EMPTY()
{
    printf("=================================================================================\n");
    printf("|%-15s| %-20s| %-20s | %s\t|", "NIM", "JURUSAN", "NAMA MAHASISWA", "TGL LAHIR");
    printf("\n=================================================================================");
    printf("\n|\t\t\t%-60s|", "data mahasiswa is empty");
}

void SHOW_DATA()
{
    f_menu = fopen("mahasiswa.txt", "r");

    if (f_menu == NULL)
    {
        SHOW_DATA_EMPTY();
    }
    else
    {
        switch (status)
        {
        case 0:
            SHOW_DATA_DEFAULT();
            break;
        case 1:
            SHOW_DATA_SORTED_NIM();
            break;
        case 2:
            SHOW_DATA_SORTED_BIRTH();
            break;
        }
    }

    printf("\n=================================================================================");

    printf("\nTekan ENTER untuk melanjutkan...");
}

void EDIT_DATA()
{
    f_menu = fopen("mahasiswa.txt", "r");
    char name[10][20], category[10][20];

    int i = 0;
    int nim[10], dd[10], mm[10], yyyy[10];
    int cari, a;
    printf("\n\nSilahkan masukkan NIM [9 angka] : ");
    scanf("%d", &cari);
    fflush(stdin);
    while (fscanf(f_menu, "%d %s %s %d/%d/%d", &MAHASISWA2[i].mh_nim, &MAHASISWA2[i].mh_category, &MAHASISWA2[i].mh_name, &MAHASISWA2[i].mh_dd, &MAHASISWA2[i].mh_mm, &MAHASISWA2[i].mh_yyyy) != EOF)
    {
        if (cari == MAHASISWA2[i].mh_nim)
        {
            printf("\nNIM ditemukan!!");
            printf("\nMasukkan nama[maks 20 karakter]: ");
            scanf("%s", &MAHASISWA2[i].mh_name);
            fflush(stdin);

            do
            {
                printf("\nMasukkan tahun lahir[1990-2000]:  ");
                scanf("%d", &MAHASISWA2[i].mh_yyyy);
                fflush(stdin);
            } while (MAHASISWA2[i].mh_yyyy > 2000 || MAHASISWA2[i].mh_yyyy < 1990);

            do
            {
                printf("\nMasukkan bulan lahir[1-12]:  ");
                scanf("%d", &MAHASISWA2[i].mh_mm);
                fflush(stdin);
            } while (MAHASISWA2[i].mh_mm > 12);

            do
            {
                printf("\nMasukkan tanggal lahir[1-30]:  ");
                scanf("%d", &MAHASISWA2[i].mh_dd);
                fflush(stdin);
            } while (MAHASISWA2[i].mh_dd > 30);
            printf("\n\nData telah diedit!!");
        }
        else if (cari != MAHASISWA2[i].mh_nim)
            printf("\nNIM tidak ditemukan!");
    }
    getch();
}

void INPUT_DATA()
{
    char ch_repeat;
    int inputNim = 0, inputJurusan;
    char inputJur[20];
    srand(time(NULL));
    do
    {
        CLEAR_SCREEN();

        f_menu = fopen("mahasiswa.txt", "a");
        printf("Pengisian Data Mahasiswa");
        printf("\nInput Mahasiswa Name [Max 20 characters]:");
        fflush(stdin);
        gets(MAHASISWA.mh_name);
        printf("\nInput Birth Year [yyyy]:");
        fflush(stdin);
        scanf("%d", &MAHASISWA.mh_yyyy);
        printf("\nInput Birth Month [mm]:");
        fflush(stdin);
        scanf("%d", &MAHASISWA.mh_mm);
        printf("\nInput Birth Day [dd]:");
        fflush(stdin);
        scanf("%d", &MAHASISWA.mh_dd);
        inputNim = rand() % (2022999999 - 2022000000 + 1) + 2022000000;
        inputJurusan = rand() % 5;
        switch (inputJurusan)
        {
        case 1:
            strcpy(inputJur, "Informatics");
            break;
        case 2:
            strcpy(inputJur, "BusinessCreation");
            break;
        case 3:
            strcpy(inputJur, "DesignVisual");
            break;
        case 4:
            strcpy(inputJur, "DesignInterior");
            break;
        case 5:
            strcpy(inputJur, "PublicRelation");
            break;
        }

        fprintf(f_menu, "%d %s %s %d/%d/%d\n", inputNim, inputJur, MAHASISWA.mh_name, MAHASISWA.mh_dd, MAHASISWA.mh_mm, MAHASISWA.mh_yyyy);

        do
        {
            fflush(stdin);
            printf("Apakah anda ingin menambah data item lagi ? [Y/N] : ");
            ch_repeat = getche();
        } while ((ch_repeat != 'y') && (ch_repeat != 'Y') && (ch_repeat != 'n') && (ch_repeat != 'N'));
        fclose(f_menu);
    } while ((ch_repeat == 'y') || (ch_repeat == 'Y'));
}

void MAHASISWA_MENU()
{
    printf("SISTEM INFORMASI MAHASISWA");
    printf("\n=========================");
    printf("\n1. Show Data Mahasiswa");
    printf("\n2. Input Data Mahasiswa");
    printf("\n3. Edit Data Mahasiswa");
    printf("\n4. Sort Data Mahasiswa");
    printf("\n5. Exit");
};

int main()
{
    char PIL;
    do
    {
        CLEAR_SCREEN();
        MAHASISWA_MENU();

        do
        {
            fflush(stdin);
            printf("\n\nInput Your Choice [1-4] : ");
            PIL = getche();

        } while ((PIL != '1') && (PIL != '2') && (PIL != '3') && (PIL != '4') && (PIL != '5'));
        switch (PIL)
        {
        case '1':
            CLEAR_SCREEN();
            SHOW_DATA();
            break;
        case '2':
            CLEAR_SCREEN();
            INPUT_DATA();
            break;
        case '3':
            CLEAR_SCREEN();
            EDIT_DATA();
            break;
        case '4':
            CLEAR_SCREEN();
            SORT_DATA();
            break;
        };
        if (PIL != '5')
            getche();
    } while (PIL != '5');
};