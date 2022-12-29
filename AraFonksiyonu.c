#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ara(int dizi[0][0], int satir, int sutun, int deger)
{
    for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j < sutun; j++)
        {
            if (dizi[i][j] == deger)
            {
                printf("girdiginiz deger %d. satirda, %d. sutunda bulunuyor.", i + 1, j + 1);
                return;
            }
        }
    }
    printf("girdiginiz deger dizide bulunmuyor.");
    return;
}

int main()
{
    srand(time(NULL));
    int sayi, dizi[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dizi[i][j] = (rand() % 10);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", dizi[i][j]);
        }
        printf("\n");
    }
    printf("bir sayi giriniz: ");
    scanf("%d", &sayi);
    ara(&dizi[0][0], 3, 3, sayi);

    return 0;
}
