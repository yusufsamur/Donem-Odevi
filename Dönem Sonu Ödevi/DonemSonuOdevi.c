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
    Sleep(2000);
    printf("Yarismamiz 8 sorudan olusmaktadir.\n");
    Sleep(2000);
    printf("Ilk soru baraj sorusudur daha sonraki sorularda q yazarak ayrilma hakkiniz bulunmaktadir.\n\n");
    Sleep(2000);
    printf("*******1. SORU*******\n");
    Sleep(2000);

    soruSayi = Rand();
    kontrol(soruSayi, cikacakSoru);
    SoruSec(soruSayi);
    cevap = Cevap(soruSayi);

    do
    {
        printf("\n");
        Sleep(2000);
        printf("Cevabiniz: ");
        scanf("%s", &kullaniciCevap);

        cikacakSoru += 1;
        if (cevap == kullaniciCevap)
        {
            Sleep(2000);
            printf("Tebrikler ! Dogru Cevap\n");
            Sleep(2000);
            system("clear");

            if (cikacakSoru == 7)
            {
                printf("Son soruya ulastiniz\n");
                Sleep(2000);
            }

            soruSayi = Rand();
            if (cikacakSoru != 8)
            {
                printf("*******%d. SORU*******\n", cikacakSoru + 1);
                Sleep(2000);
            }
            while (!kontrol(soruSayi, cikacakSoru))
            {
                soruSayi = Rand();
            }
            SoruSec(soruSayi);
            cevap = Cevap(soruSayi);
        }
        else if (kullaniciCevap == 'q')
        {
            Sleep(2000);
            printf("Yarismadan cekildiniz.");
            break;
        }

        else
        {
            Sleep(2000);
            printf("Yanlis cevap ! Elendiniz.Dogru cevap: %c", cevap);
            break;
        }

    } while (cikacakSoru < 8);

    return 0;
}
