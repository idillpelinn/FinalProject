#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Soru Soru;
typedef struct SkorKaydi SkorKaydi;

struct Soru {
    int soru_ID;
    char *soru_metni;
    char *sik_A;
	char *sik_B;
	char *sik_C;
	char *sik_D;
    char dogru_cevap;
    Soru *sonraki;
};

struct SkorKaydi {
    char *kullanici_adi;
    int skor;
    SkorKaydi *sonraki;
};

int soruID, soru_miktari;
Soru *ilk_soru;
SkorKaydi *ilk_skor;

//MAÝN içinde kullandýðýmýz fonksiyonlar
void soru_ekle();
void soru_sil();
void soru_goster_guncelle();
void oyun_oyna();
void yuksek_skor();
void delay(int number_of_seconds);
void sorulari_dosyadan_oku();
void skorlari_dosyadan_oku();

int main()
{
	soruID = 1;
    soru_miktari = 0;
    srand(time(0));

    sorulari_dosyadan_oku();
    skorlari_dosyadan_oku();
    
int secenek;
 	while(1){
 	system("color F5");
    printf("\n");
    printf("                                        ___________________________________                                               \n");
  	printf("=====================================> |   EN IYI KIM BILIR'E HOSGELDINIZ  | <==========================================\n");
  	printf("                                       |___________________________________|                                              \n");

	printf("                                          Soru eklemek istiyorsan eger --->(1)..........\n");
	printf("                                          Soru  silmek istersen eger --->(2)..........\n");
    printf("                                          Sorulari gostermek ve guncellemek istersen eger --->(3)..........\n");
	printf("                                          Oyun oynamak istersen eger-->(4)..........\n");
	printf("                                          En yuksek skorlari gormek istersen eger--->(5)..........\n");
	printf("                                          Cikmak istersen eger --->(6).......\n\n");
	printf(" ====================================================================================================================== \n");
	printf("                                          Yapmak istediginiz islemi secin lutfen: ");
	scanf("%d",&secenek);
	printf("\n");
system("CLS");
    switch(secenek){
	case 1: //Soru ekle.
	system("color 70");
	    soru_ekle();
	    system("CLS");
    break;
    case 2: //Sorulari goster ve sil.
        system("color F0");
    	soru_sil();
        system("CLS");
	break;
	case 3: //Sorulari goster ve guncelle.
	    system("color 85");
		soru_goster_guncelle();
	    system("CLS");
	break;
    case 4: 
        system("color 0D");
		oyun_oyna();
		system("CLS");
	break;
	case 5: // Skor tablosu gosterilir.
	    system("color 0F");
		yuksek_skor();
		system("CLS");
	break;
	case 6: 
	printf("\n\n\n\tP");
	delay(1);
	printf("R");
	delay(1);
	printf("O");
	delay(1);
	printf("G");
	delay(1);
	printf("R");
	delay(1);
	printf("A");
	delay(1);
	printf("M");
	delay(1);
	printf("D");
	delay(1);		
	printf("A");
	delay(1);
	printf("N");
	delay(1);
	printf(" ");
	delay(1);
	printf("C");
	delay(1);
	printf("I");
	delay(1);
	printf("K");
	delay(1);
	printf("I");
	delay(1);
	printf("L");
	delay(1);
	printf("I");
	delay(1);
	printf("Y");
	delay(1);
	printf("O");
	delay(1);
	printf("R");
	delay(1);
	printf("R");
	delay(1);
	printf("R");
	delay(1);
	system("CLS");
	printf("\n\n\n\n\n\n\t\t3");
	delay(1);
	system("CLS");
	printf("\n\n\n\n\n\n\t\t2");
	delay(1);
	system("CLS");
	printf("\n\n\n\n\n\n\t\t1");
	delay(1);
	system("CLS");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                               Tekrar bekleriz. Saglicakla kalin *_*  \n\n\n\n\n\n\n\n\n\n\n\n");
	delay(2);
	system("CLS");
	//Çýkýþ
	break;
	
 }}
system("CLS");
}

//bekletme fonksiyonu
void delay(int number_of_seconds) {
	int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds) ;
}
//sorularý listeye ekler
void soru_listesine_ekle(Soru *yeni_soru) {
    if (ilk_soru == NULL) {
        ilk_soru = yeni_soru;
    } else {
        Soru *soru;
        for (soru = ilk_soru; soru->sonraki != NULL; soru = soru->sonraki);
        soru->sonraki = yeni_soru;
    }
    soru_miktari++;
}
//dosyadan metin okur 
char *dosyadan_metin_oku(char *str, FILE *file) {
    str = (char *)calloc(100, sizeof(char));
	/*Her birinin boyutu byte olarak ifade edilen ve
	 size parametre deðeri kadar olan bellekten num parametre deðeri kadar
	  sayýda bellek bloðunu tahsis eder ve tahsis edilen belleðin tamamýný sýfýr deðeri ile doldurur.*/
    int i;
    char c;
    for (i = 0; fscanf(file, "%c", &c); i++) {
        if (c == '\n') {
            if (i == 0) {
                i = -1;
                continue;
            }
            str[i] = '\0';
            break;
        } else {
            str[i] = c; }}
			 return str;
}

void listeyi_temizle(Soru *soru) {
    if (soru == NULL) return;

    listeyi_temizle(soru->sonraki);
    free(soru);
    /*tahsis edilen belleðin baþlangýç adresini geri döndürür. 
	Bellek sorunlarýný engellemek için, gerekli iþlemler yapýldýktan sonra,
	 bu iþaretçi free() veya realloc() fonksiyonu ile boþaltýlmalýdýr.*/
}

void sorulari_dosyadan_oku() {
    listeyi_temizle(ilk_soru);
    soru_miktari = 0;
    ilk_soru = NULL;
    char sorular_txt[] = "Sorular.txt";
    FILE *soru_dosyasi = fopen(sorular_txt, "r");

    if (soru_dosyasi == NULL) {
        return;
    }

    int ID;
    fscanf(soru_dosyasi, "%d-) ", &ID);

    while (!feof(soru_dosyasi)) {
        Soru *soru = (Soru *) malloc(sizeof(Soru));
        /*malloc() fonksiyonunda kullanýlan byte-sayýsý 
		ifadesi tahsis etmek istediðiniz belleðin byte olarak deðerini gösterir.
		 malloc() fonksiyonu tahsis edilmiþ belleðin baþlangýcýný gösteren bir iþaretçi geri verir.*/
        if (ID != 0) {
            soru->soru_ID = ID;
            ID = 0;
        } else {
            fscanf(soru_dosyasi, "%d-) ", &soru->soru_ID);
        }
        soruID = soru->soru_ID + 1;
        soru->soru_metni = dosyadan_metin_oku(soru->soru_metni, soru_dosyasi);
        fscanf(soru_dosyasi, "A) ");
        soru->sik_A = dosyadan_metin_oku(soru->sik_A, soru_dosyasi);
        fscanf(soru_dosyasi, "B) ");
        soru->sik_B = dosyadan_metin_oku(soru->sik_B, soru_dosyasi);
        fscanf(soru_dosyasi, "C) ");
        soru->sik_C = dosyadan_metin_oku(soru->sik_C, soru_dosyasi);
        fscanf(soru_dosyasi, "D) ");
        soru->sik_D = dosyadan_metin_oku(soru->sik_D, soru_dosyasi);
        fscanf(soru_dosyasi, "Cevap: ");
        fscanf(soru_dosyasi, "%c", &soru->dogru_cevap);

        char c;
        fscanf(soru_dosyasi, "%c\n", &c);

        soru->sonraki = NULL;

        soru_listesine_ekle(soru);
    }

    fclose(soru_dosyasi);
}

char *metin_oku(char *str) {
    str =(char*) calloc(100, sizeof(char));

    int i;
    char c;
    for (i = 0; (c = getc(stdin)); i++) {
        if (c == '\n') {
            if (i == 0) {
                i = -1;
                continue;
            }
            str[i] = '\0';
            break;
        } else {
            str[i] = c; }}
 return str;
}

void soru_dosyasini_guncelle() {
    char sorular_txt[] = "Sorular.txt";
    FILE *soru_dosyasi = fopen(sorular_txt, "w");
    Soru *soru;

    for (soru = ilk_soru; soru != NULL; soru = soru->sonraki) {
        fprintf(soru_dosyasi, "%d-) %s\nA) %s\nB) %s\nC) %s\nD) %s\nCevap: %c\n\n",
                soru->soru_ID, soru->soru_metni, soru->sik_A, soru->sik_B, soru->sik_C, soru->sik_D, soru->dogru_cevap);
    }

    fclose(soru_dosyasi);
}
//soru ekleme fonk
void soru_ekle() {
    Soru *yeni_soru = (Soru *) malloc(sizeof(Soru));
    yeni_soru->soru_ID = soruID++;
    yeni_soru->sonraki = NULL;
    printf("\nNOT:eklemek istediginiz sorunun dogru sikkini buyuk harfle giriniz.\n");
    printf("EKLEMEK ISTEDIGINIZ SORU METNINI GIRINIZ:");
    yeni_soru->soru_metni = metin_oku(yeni_soru->soru_metni);
    printf("A:");
    yeni_soru->sik_A = metin_oku(yeni_soru->sik_A);
    printf("B:");
    yeni_soru->sik_B = metin_oku(yeni_soru->sik_B);
    printf("C:");
    yeni_soru->sik_C = metin_oku(yeni_soru->sik_C);
    printf("D:");
    yeni_soru->sik_D = metin_oku(yeni_soru->sik_D);
    printf("DOGRU CEVAP:");
    scanf("%c", &yeni_soru->dogru_cevap);
    soru_listesine_ekle(yeni_soru);
    soru_dosyasini_guncelle();
    
    system("CLS");
    printf("\n\n\tsoru ekleniyor");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    system("CLS");
    printf("\n\n\tSoru basariyla eklendi.\n");
    delay(1);
    system("CLS");
}

void soru_silinme_kontrol(int basarili) {
    if (basarili) {
        soru_dosyasini_guncelle();
        soru_miktari--;
        system("CLS");
        printf("\n\n\tsoru siliniyor");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        system("CLS");
        printf("Soru basariyla silindi.");
        delay(1);
        system("CLS");
        
    } else {
    	system("CLS");
        printf("Soru bulunamadi.\n");
        delay(1);
        system("CLS");
    }
}

void soru_sil() {
    int silinecekID;
    Soru *soru, *temp;
    for (soru = ilk_soru; soru != NULL; soru = soru->sonraki) {
        printf("%d-) %s\n", soru->soru_ID, soru->soru_metni);
    }

    if (ilk_soru == NULL) {
    	system("CLS");
       printf("\n\n\tDosyada kayitli soru yok\n");
        delay(1);
        system("CLS");
        return;
    }

    printf("Silmek istediginiz sorunun numarasini girin:");
    scanf("%d", &silinecekID);

    if (ilk_soru->soru_ID == silinecekID) {
        temp = ilk_soru;
        ilk_soru = ilk_soru->sonraki;
        free(temp);
        soru_silinme_kontrol(1);
        return;
    }

    for (soru = ilk_soru; soru->sonraki != NULL; soru = soru->sonraki) {
        if (soru->sonraki->soru_ID == silinecekID) {
            temp = soru->sonraki;
            soru->sonraki = soru->sonraki->sonraki;
            free(temp);
            soru_silinme_kontrol(1);
            return;
        }
    }
    soru_silinme_kontrol(0);
}

void soru_goster_guncelle() {
    if (ilk_soru == NULL) {
        printf("\n\n\tDosyada kayitli soru bulunamadi\n");
        return;
    }

    char sorular_txt[] = "Sorular.txt";
    FILE *soru_dosyasi = fopen(sorular_txt, "r");
    while (!feof(soru_dosyasi)) {
        char c;
        fscanf(soru_dosyasi, "%c", &c);
        putchar(c);
    }

    fclose(soru_dosyasi);

    printf("Guncellemek istediginiz soru ID'sini girin:");
    int ID;
    scanf("%d", &ID);

    Soru *soru;
    for (soru = ilk_soru; soru != NULL; soru = soru->sonraki) {
        if (soru->soru_ID == ID) {
        	system("CLS");
            printf("\n\n\tYeni soru metnini girin:");
            soru->soru_metni = metin_oku(soru->soru_metni);
            printf("A:");
            soru->sik_A = metin_oku(soru->sik_A);
            printf("B:");
            soru->sik_B = metin_oku(soru->sik_B);
            printf("C:");
            soru->sik_C = metin_oku(soru->sik_C);
            printf("D:");
            soru->sik_D = metin_oku(soru->sik_D);
            printf("Dogru cevap:");
            scanf("%c", &soru->dogru_cevap);

            soru_dosyasini_guncelle();
            system("CLS");
            printf("\n\n\tsoru guncelleniyor");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            system("CLS");
            printf("\n\n\n\tSoru basariyla guncellendi.\n");
            delay(1);
            system("CLS");
            return;
        }
    }
   
    printf("\n\n\tSoru bulunamadi.\n");
    delay(1);
    system("CLS");
}

void skor_dosyasini_guncelle() {
    char skorlar_txt[] = "Skorlar.txt";
    FILE *skor_dosyasi = fopen(skorlar_txt, "w");
    SkorKaydi *kayit;

    for (kayit = ilk_skor; kayit != NULL; kayit = kayit->sonraki) {
        fprintf(skor_dosyasi, "\n\n\tKullanici adi: %s\nSkor: %d\n\n", kayit->kullanici_adi, kayit->skor);
    }

    fclose(skor_dosyasi);
}

void skor_listesine_ekle(SkorKaydi *kayit) {
    SkorKaydi *temp, *kontrol;
    if (ilk_skor == NULL) ilk_skor = kayit;
    else if (kayit->skor > ilk_skor->skor) {
        temp = ilk_skor;
        ilk_skor = kayit;
        kayit->sonraki = temp;
    } else {
        for (kontrol = ilk_skor; ; kontrol = kontrol->sonraki) {
            if (kontrol->sonraki == NULL) {
                kontrol->sonraki = kayit;
                break;
            } else if (kayit->skor > kontrol->sonraki->skor) {
                temp = kontrol->sonraki;
                kontrol->sonraki = kayit;
                kayit->sonraki = temp;
                break;
            }
        }
    }

    skor_dosyasini_guncelle();
}

void skorlari_dosyadan_oku() {
    ilk_skor = NULL;

    char skorlar_txt[] = "Skorlar.txt";
    FILE *skor_dosyasi = fopen(skorlar_txt, "r");

    if (skor_dosyasi == NULL) {
        return;
    }

    fscanf(skor_dosyasi, "");

    while (!feof(skor_dosyasi)) {
        SkorKaydi *kayit = (SkorKaydi *) malloc(sizeof(SkorKaydi));
        fscanf(skor_dosyasi, "\n\n\tKullanici adiniz: ");
        kayit->kullanici_adi = dosyadan_metin_oku(kayit->kullanici_adi, skor_dosyasi);
        fscanf(skor_dosyasi, "\n\t\tSkor: ");
        fscanf(skor_dosyasi, "%d", &kayit->skor);

        char c;
        fscanf(skor_dosyasi, "%c\n", &c);
        kayit->sonraki = NULL;

        skor_listesine_ekle(kayit);
    }

    fclose(skor_dosyasi);
}

void oyun_oyna() {
    if (soru_miktari < 5) {
        printf("\n\n\tOyun icin en az 5 soru gerekli.\n");
        delay(1);
        printf("\n\tBu yuzden soru ekle secenegine gidiniz.");
        delay(1);
        system("CLS");
        return;
    }

    char dogru_cevap_anahtari[5];
    char kullanici_cevaplari[5];

    SkorKaydi *yeni_kayit = (SkorKaydi *) malloc(sizeof(SkorKaydi));
    yeni_kayit->sonraki = NULL;
    yeni_kayit->skor = 0;
    printf("\n\n\n\t======================OYUN BASLIYOR======================");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\t\t3");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\t\t2");
    delay(2);
    system("CLS");
    printf("\n\n\n\n\t\t1");
    delay(1);
    system("CLS");
    printf("\n\n\n\n\t\t0");
    delay(1);
    system("CLS");
    int i, j;
    for (i = 0; i < 5; i++) {
        fflush(stdin);

        Soru *soru, *temp;
        int index = rand() % (soru_miktari - i);

        if (index == 0) {
            temp = ilk_soru;
            ilk_soru = ilk_soru->sonraki;
        } else {
            for (j = 0, soru = ilk_soru; j < index - 1; j++, soru = soru->sonraki);
            temp = soru->sonraki;
            soru->sonraki = soru->sonraki->sonraki;
        }

        dogru_cevap_anahtari[i] = temp->dogru_cevap;
        printf("\n\n\n\n\tSoru %d-) %s?\nA) %s\nB) %s\nC) %s\nD) %s\nCevabiniz:", i + 1, temp->soru_metni, temp->sik_A, temp->sik_B, temp->sik_C, temp->sik_D);
        free(temp);

        scanf("%c", &kullanici_cevaplari[i]);

        if (dogru_cevap_anahtari[i] == kullanici_cevaplari[i]) yeni_kayit->skor++;
        system("CLS");
    }

    sorulari_dosyadan_oku();

    fflush(stdin);
    delay(1);
    system("CLS");
    printf("\n\n\tOyun bitti\n SKORUNUZ--->: %d\nKullanici adinizi girin:", yeni_kayit->skor);
    yeni_kayit->kullanici_adi = metin_oku(yeni_kayit->kullanici_adi);

    skor_listesine_ekle(yeni_kayit);
    system("CLS");
    printf("\n\n\tskorunuz kaydediiliyor");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    system("CLS");
    printf("\n\n\n\tSkor listesine basariyla eklendi.\n");
    delay(1);
    system("CLS");
}

void yuksek_skor() {
    printf("\n\n\n\tEn yuksek  3 skor goruntuleniyor:");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    system("CLS");
    printf("========================================================================================================================");
    delay(1);
    printf("\n========================================== EN YUKSEK 3 SKOR ==========================================================");
    delay(1);
    printf("\n======================================================================================================================");
    delay(1);
    SkorKaydi *kayit;
    int i;
    for (i = 0, kayit = ilk_skor; i < 3; i++, kayit = kayit->sonraki) {
        printf("\n\tKullanici adi: %s\n\tSkor: %d\n\n", kayit->kullanici_adi, kayit->skor);
        delay(1);
    }
    delay(2);
    system("CLS");
    printf("\n\n\n\tEn yuksek 3 skor gosterildi");
    delay(1);
    system("CLS");
}



