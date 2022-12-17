#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

void SoruSec(int sayi)
{

    char soruSayisi[12];
    snprintf(soruSayisi, 12, "soru_%d.txt", sayi);

    FILE *dosya = fopen(soruSayisi, "r");

    while (!feof(dosya))
    {
        putchar(fgetc(dosya));
    }

    fclose(dosya);
}

int Rand()
{

    int sayi;

    srand(time(NULL));

    sayi = rand() % 9;

    return sayi;
}

char Cevap(int sayi)
{

    char cevaplar[] = {'C', 'D', 'B', 'D', 'B', 'D', 'D', 'A'};

    return cevaplar[sayi - 1];
}

int kontrolDizi[10];

bool kontrol(int sayi, int cikacakSoru)
{

    for (int i = 0; i < 10; i++)
    {
        if (kontrolDizi[i] == sayi)
        {
            return false;
        }
    }
    kontrolDizi[cikacakSoru] = sayi;

    return true;
}

int main()
{
    int cikacakSoru = 0;
    char cevap;
    char kullaniciCevap;
    int soruSayi;

    printf("*******Kim Milyoner Olmak Ister'e hos geldiniz.*******\n");
    Sleep(0);
    printf("Yarismamiz 8 sorudan olusmaktadir.\n");
    Sleep(0);
    printf("Ilk soru baraj sorusudur daha sonraki sorularda q yazarak ayrilma hakkiniz bulunmaktadir.\n\n");
    Sleep(0);
    printf("*******1. SORU*******\n");
    printf("                                       1.000TL\n\n");
    Sleep(0);

    soruSayi = Rand();
    kontrol(soruSayi, cikacakSoru);
    SoruSec(soruSayi);
    cevap = Cevap(soruSayi);

    do
    {

        printf("\n");
        Sleep(0);
        printf("Cevabiniz: ");
        scanf("%s", &kullaniciCevap);

        cikacakSoru += 1;
        if (cevap == kullaniciCevap)
        {
            Sleep(0);
            printf("Tebrikler ! Dogru Cevap\n");
            Sleep(0);
            if (cikacakSoru != 8)
            {
                system("cls");
            }

            if (cikacakSoru == 7)
            {
                printf("Son soruya ulastiniz\n");
                Sleep(0);
            }
            else if (cikacakSoru == 8)
            {
                printf("Yarismayi kazandiniz. Para odulunuz: 30.000TL");
            }

            soruSayi = Rand();
            if (cikacakSoru != 8)
            {
                printf("*******%d. SORU*******\n", cikacakSoru + 1);
                Sleep(0);
            }
            switch (cikacakSoru + 1)
            {
            case 2:
                printf("                                       2.000TL\n\n");
                break;
            case 3:
                printf("                                       3.000TL\n\n");
                break;
            case 4:
                printf("                                       5.000TL\n\n");
                break;
            case 5:
                printf("                                       3.000TL\n\n");
                break;
            case 6:
                printf("                                       7.500TL\n\n");
                break;
            case 7:
                printf("                                       10.000TL\n\n");
                break;
            case 8:
                printf("                                       30.000TL\n\n");
                break;
            }
            Sleep(1000);
            while (!kontrol(soruSayi, cikacakSoru))
            {
                soruSayi = Rand();
            }
            SoruSec(soruSayi);
            cevap = Cevap(soruSayi);
        }
        else if (kullaniciCevap == 'q' || kullaniciCevap == 'Q')
        {
            Sleep(0);
            printf("Yarismadan cekildiniz.\n");
            switch (cikacakSoru)
            {

            case 1:
                printf("Kazandiginiz para miktari : 0TL\n\n");
                break;
            case 2:
                printf("Kazandiginiz para miktari : 1000TL\n\n");
                break;
            case 3:
                printf("Kazandiginiz para miktari : 2.000TL\n\n");
                break;
            case 4:
                printf("Kazandiginiz para miktari : 3.000TL\n\n");
                break;
            case 5:
                printf("Kazandiginiz para miktari : 4.000TL\n\n");
                break;
            case 6:
                printf("Kazandiginiz para miktari : 5.000TL\n\n");
                break;
            case 7:
                printf("Kazandiginiz para miktari : 7.5000L\n\n");
                break;
            case 8:
                printf("Kazandiginiz para miktari : 10.000TL\n\n");
                break;
            }
            break;
        }

        else
        {
            Sleep(0);
            printf("Yanlis cevap ! Elendiniz.Dogru cevap: %c", cevap);
            break;
        }

    } while (cikacakSoru < 8);

    return 0;
}
