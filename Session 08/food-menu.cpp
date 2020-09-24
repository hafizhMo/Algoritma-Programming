#include <stdio.h>

int main()
{
    FILE *f = fopen("menu.txt", "r");
    //    FILE* fx = fopen("soal08.txt", "w");
    char name_item[10][20];
    int price_item[10], count_item[10];
    int i = 0;

    printf("===============================================================\n");
    printf("\tSELAMAT DATANG DI RESTO SEDERHANA\n");
    printf("===============================================================\n");
    printf("|%-3s| %-20s| %-10s | %-2s ", "No", "Nama Makanan", "Harga", "Jumlah");
    printf("\n===============================================================");

    while (fscanf(f, "%s %d %d", &name_item[i], &price_item[i], &count_item[i]) != EOF)
    {

        printf("\n|%-3d| %-20s| %-10d | %-2d ", i + 1, name_item[i], price_item[i], count_item[i]);
        i++;
    }

    int anw, anw_count;

    do
    {

        printf("\n\nMasukan kode pesanan anda [1..5]: ");
        scanf(" %d", &anw);
    } while (anw >= 5 && anw < 0);

    printf("Pesanan %s sejumlah: ", name_item[anw - 1]);
    scanf("%d", &anw_count);

    fclose(f);
}
