#include <stdio.h>
#include <windows.h>
#include<locale.h>  
struct Telefon{//telefon struct yap�s� tan�mlan�yor
char isim[15];//struct yap�s� de�i�kenleri
int kod;//struct yap�s� de�i�kenleri
int numara;//struct yap�s� de�i�kenleri

}kisi[10],yedek[10],silinecek[10];//struct yap�s�na ki�i ve yedek isimleri veriliyor
void kayit_ekle();//fonksiyonlar tan�mlan�yor
void ara_bul();//fonksiyonlar tan�mlan�yor
void listele();//fonksiyonlar tan�mlan�yor
void bul_degistir();//fonksiyonlar tan�mlan�yor
void kayit_sil();//fonksiyonlar tan�mlan�yor
char menu();//fonksiyonlar tan�mlan�yor

int sayac;//global bir sayac eklendi ki�i sy�s�n� bulmak i�in
main()
{
	
	setlocale(LC_ALL,"Turkish");
    char secim;//secim ad�nda bir de�i�en tan�mlan�yor
    do{
        secim=menu();//menuden gelen tu� alg�lan�yor
        switch(secim)//menuden gelen veriyi kar��la�t�rmaya sokuyor
        {
           case '1': kayit_ekle();break;
           case '2': listele();break;
           case '4':ara_bul();break;
           case '3':bul_degistir();break;
           case '6':kayit_sil();break;
           case '5':ara_bul();break;
           case'7':exit;break;
        }
    }while(secim<='7' && secim>='1');//kar��la�t�rma menuden gelen verilerin 1 ile 7 aras�nda ise
 
    }//ana fonksiyon sonu
char menu(){//menu fonksiyonu
    char tus;//tus ad�nda char tipinde de�i�ken tan�mlan�yor
    printf("1-Kayit Ekle\n2- Telefonlar� Listele\n3-Kayd� D�zenle\n4-�sim �le Kay�t Bul\n5-Numara  ile Kay�t Bul\n6-Kay�t Sil\n7-��k��\nSe�im:\n");//manu se�enekleri ekrana yazd�r�l�yor
    tus=getch();//kullan�c�n�n girdi�i tu� alg�lan�yor
    return tus;//menu fonksiyonunun �a��r�ld��� yere kullan�c�n�n girdi�i tu� d�nd�r�l�yor
}//menu fonksiyonu sonu
    void kayit_ekle(){//kay�t ekleme fonksiyonu
        char tus2;//tus2 ad�nda char tipinde de�i�ken tan�mlan�yor
        FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor
        dosya=fopen("Rehber.txt","w");//dosya �nceki verilerin �st�ne yazmak i�in a��l�yor
 
    do{
	printf("%d.Ki�inin Ad�n� Giriniz:\n",sayac+1);//kullan�c�dan isim isteniyor
    scanf("%s",kisi[sayac].isim);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
   
    printf("%d.Ki�inin Kodunu Giriniz:\n",sayac+1);//kullan�c�dan vize isteniyor
    scanf("%d",&kisi[sayac].kod);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
    printf("%d.Ki�inin Numaras�n� Giriniz:\n",sayac+1);
    scanf("%d",&kisi[sayac].numara);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
    printf("yeni kayit i�in e basin ve men�ye d�nmek i�in herhangi bir tusa basin\n\n");//veriler girildikten sonra kullan�c�dan yeni veri girmek istermisiniz diye soruluyor
    tus2=getch();//kullan�c�n�n girdi�i karakter tus2 de�i�kenine aktar�l�yor
 
fprintf(dosya,"%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].kod,kisi[sayac].numara);//veriler dosyaya yaz�l�yor
sayac++;//whilei�in sayac 1 artt�r�l�yor
    }while(tus2=='e' || tus2=='E');//e�er kullan�c� devam etmek isterse tekrar d�n
fclose(dosya);//dosya kapat�l�yor
}//kay�t ekleme fonksiyonusonu
void listele(){//listele fonksiyonu
FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor
dosya=fopen("Rehber.txt","r");//dosya �nceki verileri okumak i�in a��l�yor
int a=0,i;//de�i�kenler tan�mlan�yor
while(!feof(dosya)){//dosya sonuna kadar d�n
    fscanf(dosya,"%s%d%d",yedek[a].isim,&yedek[a].kod,&yedek[a].numara);//veriler dosyadan okunuyor
a++;      //while i�in a artt�r�l�yor
}//dosya sonuna kadar d�n sonu
for(i=0;i<(a-1);i++)//yedek yap�s�n�n sonuna kadar d�n�l�yor
printf("%d\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].kod,yedek[i].numara);//okunan veriler ekrana yaz�l�yor
fclose(dosya);//dosya kapat�l�yor
}//listele fonksiyonu sonu
void ara_bul(){//arabul fonksiyonu
    char kelime[150];//kelima ad�nda char tipinde bir de�i�ken tan�mlan�yor
printf("Aranacak Ki�iyi girin");//kullan�c�dan aranacak veri isteniyor
scanf("%s",&kelime);//girilen veri kelime de�i�kenine aktar�l�yor
FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor
dosya=fopen("Rehber.txt","r");//dosya �nceki verileri okumak i�in a��l�yor
int a=0,i;//de�i�kenler tan�mlan�yor d�ng�ler i�in
while(!feof(dosya)){//dosya sonuna kadar d�n
    fscanf(dosya,"%s%d%d",yedek[a].isim,&yedek[a].kod,&yedek[a].numara);//dosyadan veriler okunup yedek yap�s�na aktar�l�yor
a++;     //while i�in a 1 artt�r�l�yor
 }//dosya sonuna kadar d�n sonu
for(i=0;i<(a-1);i++){//yedek yap�s�n�n sonuna kadar d�n�l�yor
 if(strcmp(kelime,yedek[i].isim)==0)
        {//e�er aranan kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
printf("%d\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].kod,yedek[i].numara);//veriler ekrana yad�r�l�yor
}//e�er aranan kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap sonu
}//yedek yap�s�n�n sonuna kadar d�n�l�yorsonu
fclose(dosya);//dosya kapat�l�yor
}//arabul fonksiyonu sonu
void bul_degistir(){//bul de�i�rtir fonksiyonu
    char kelime[150];
printf("Degisecek Kisiyi girin");//degisecek kisi kulan�c�dan al�n�yor
scanf("%s",&kelime);//kullan�c�n�n girdi�i veri kelime de�i�kenine atan�yor
FILE *dosya;//file tipinde bir dosya pointer� tan�mlan�yor
dosya=fopen("Rehber.txt","r");//a.txt dosyas� sadece okunmak i�in yaz�l�yor
int a=0,i;//kullan�lacak de�i�kenler tan�mlan�yor
while(!feof(dosya)){//dosya sonuna kadar d�n�l�yor ba�lang��
    fscanf(dosya,"%s%d%d",yedek[a].isim,&yedek[a].kod,&yedek[a].numara);//dosyadan al�nan veriler yedek yap�s�na aktar�l�yor
a++;     //yedek de�i�kenini her seferinde farkl� gelmesi i�in a her seferinde artt�r�l�yor
}//dosya sonuna kadar d�n�l�yor sonu
for(i=0;i<(a-1);i++){//yedek yap�s�na al�nan verilerin i�leme sokulmas�
 if(strcmp(kelime,yedek[i].isim)==0)//e�er de�i�ecek kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
        {
            printf("%d.Ki�inin Ad�n� Giriniz\n",i+1);//kullan�c�dan yeni isim isteniyor
            scanf("%s",yedek[i].isim);//isim yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            printf("%d. Ki�inin Kodunu:\n",i+1);//kullan�c�dan yeni b�l�m isteniyor
            scanf("%s",yedek[i].kod);//b�l�m yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            printf("%d.Ki�inin NUmaras�n� G�riniz:\n",i+1);//kullan�c�dan yeni vize isteniyor
            scanf("%d",&yedek[i].numara); //vize yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
           
}
}//yedek yap�s�na al�nan verilerin i�leme sokulmas� sonu
fclose(dosya);//dosya sadece okunmak i�in a��lan dosya kapat�l�yor
 
//�imdi bu k�s�mda de�i�tirilen yedek yap�s�n� a.txtnin �zerine yazarak bul de�i�tir �rne�imizi bitirece�iz
FILE *dosya2;//file tipinde bir dosya2 pointer� tan�mlan�yor
dosya2=fopen("Rehber.txt","w");//a.txt dosyas� �nceki veriler silinecek �ekilde a��l�yor
int i2;//integer tipinde for d�ng�s� i�in i2 de�i�keni olu�turuluyor
for(i2=0;i2<(a-1);i2++){//yine yedek de�i�keninin sonuna kadar d�n�l�yor
fprintf(dosya2,"%s\t%d\t%d\n",yedek[i2].isim,yedek[i2].kod,yedek[i2].numara);
}//yedek de�i�keninin sonuna kadar d�nme sonu
fclose(dosya2);//a��lan dosya kapat�l�yor
}//bul de�i�tir fonksiyonu sonu
 
 
void kayit_sil(){//kayit sil fonksiyonu
char kelime[150];
printf("Silinecek Ki�iyi girin:\n");//silinecek ki�i kulan�c�dan al�n�yor
scanf("%s",&kelime);//kullan�c�n�n girdi�i veri kelime de�i�kenine atan�yor
FILE *dosya;//file tipinde bir dosya pointer� tan�mlan�yor
dosya=fopen("Rehber.txt","r");//a.txt dosyas� sadece okunmak i�in yaz�l�yor
int a=0,i=0,kacinci;//kullan�lacak de�i�kenler tan�mlan�yor
while(!feof(dosya)){//dosya sonuna kadar d�n�l�yor ba�lang��
    fscanf(dosya,"%s%d%d",yedek[a].isim,&yedek[a].kod,&yedek[a].numara);//dosyadan al�nan veriler yedek yap�s�na aktar�l�yor
a++;     //yedek de�i�kenini her seferinde farkl� gelmesi i�in a her seferinde artt�r�l�yor
}//dosya sonuna kadar d�n�l�yor sonu
 
for(i=0;i<(a-1);i++){//yedek yap�s�na al�nan verilerin i�leme sokulmas�
 if(strcmp(kelime,yedek[i].isim)==0)//e�er silinmesi gereken ki�i ad� yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
        {            kacinci=i;//aranan verinin ka��nc� oldu�u bulunuyor
                   }//e�er silinmesi gereken ki�i ad� yedek yap�s�n�n ismine e�it ise a�a��dakileri yapsonu
 
}//yedek yap�s�na al�nan verilerin i�leme sokulmas� sonu
for(i=0;i<(kacinci);i++){//verinin bulundu�u yere kadar d�n
    strcpy(silinecek[i].isim,yedek[i].isim);
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
   
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i].kod=yedek[i].kod;
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i].numara=yedek[i].numara;
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
}
//verinin bulundu�u yere kadar d�n sonu
for(i=(kacinci+1);i<=(a-1);i++){//silinen veriden sonrakini silinecek k�sm�na ata
    strcpy(silinecek[i-1].isim,yedek[i].isim);//kac�nc�dan sonra olan k�s�mlar silinen yap�s�na aktar�l�yor
    
    silinecek[i-1].kod=yedek[i].kod;//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i-1].numara=yedek[i].numara;//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
}//silinen veriden sonrakini silinecek k�sm�na ata sonu
 
 
fclose(dosya);//dosya sadece okunmak i�in a��lan dosya kapat�l�yor
 
//�imdi bu k�s�mda de�i�tirilen yedek yap�s�n� a.txtnin �zerine yazarak bul de�i�tir �rne�imizi bitirece�iz
FILE *dosya2;//file tipinde bir dosya2 pointer� tan�mlan�yor
dosya2=fopen("Rehber.txt","w");//a.txt dosyas� �nceki veriler silinecek �ekilde a��l�yor
int i2;//integer tipinde for d�ng�s� i�in i2 de�i�keni olu�turuluyor
for(i2=0;i2<(a-1);i2++){//yine silinecek de�i�keninin sonuna kadar d�n�l�yor
fprintf(dosya2,"%s\t%d\t%d\n",silinecek[i2].isim,silinecek[i2].kod,silinecek[i2].numara);
}
printf("............Ki�i Silindi......");//silinecek de�i�keninin sonuna kadar d�nme sonu
fclose(dosya2);//a��lan dosya kapat�l�yor
 
}//kayitsil fonksiyonu sonu
