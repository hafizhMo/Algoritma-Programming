#include <stdio.h>
#include <math.h>

int main()
{
    float equationFirst, equationSecond;
    int inputA, inputB, inputC, inputD;

    printf("\t\t\t Kalkulator Emteka\n");
    printf("\t\t   Hafizh Naufal - 2301886310\n");
    printf("\t\t================================\n\n");
    printf("Calculation of First unsorted equation\n");
    printf("######################################\n\n");

    printf("\t\tx = ((sqrt(a) + b^3 – c*b))*sqrt(b)\n\n");
    printf("Where	: a = angka pertama yg dimasukin\n");
    printf("\t  b = angka kedua yg dimasukin\n");
    printf("\t  c = angka ketiga yg dimasukin\n");
    printf("\t  x = first unsorted equation result\n\n");

    printf("Input a : ");
    scanf("%d", &inputA);
    printf("Input b : ");
    scanf("%d", &inputB);
    printf("Input c : ");
    scanf("%d", &inputC);

    equationFirst = (sqrt(inputA) + pow(inputB, 3) - inputC * inputB) * sqrt(inputB);
    printf("\n\n      x : %.2f", equationFirst);

    /*=====================second equation==============================*/
    printf("\n\nCalculation of Second unsorted equation\n");
    printf("######################################\n\n");

    printf("\t\ty = (d/b - x*c + a)^3\n\n");
    printf("Where	: d = angka keempat yg dimasukin\n");
    printf("\t  y = second unsorted equation result\n\n");

    printf("Input d : ");
    scanf("%d", &inputD);

    equationSecond = pow((inputD / inputB - equationFirst * inputC + inputA), 3);
    printf("\n\n      y : %.2f", equationSecond);

    return 0;
}