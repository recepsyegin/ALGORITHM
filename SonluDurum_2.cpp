#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
/*Metin icerisinde "papatya" kelimesini aramak*/


typedef int (*Fadres)();
FILE *di;

/*Dosyadan karakter okuma*/

char karakterAl()
{
	char karakter;
	karakter = getc(di);
	if(karakter!=EOF)
		return karakter;
	else
	{
		puts("Dosya sonu");
		fclose(di);
		exit(0);
	}
}

/*Baslangic durum kodu,durum0...sirayla*/
int durum0()
{
	char kr;
	kr = karakterAl();
	if(kr=='p')
		return 1;
	else
		return 0;
}

int durum1()
{
	char kr;
	kr = karakterAl();
	if(kr=='a' || kr == 'A')
		return 2;
	else if(kr=='p' || kr == 'P')
		return 1;
	else
		return 0;
}

int durum2()
{
	char kr;
	kr = karakterAl();
	if(kr=='p' || kr == 'P')
		return 3;
	else
		return 0;
}

int durum3()
{
	char kr;
	kr = karakterAl();
	if(kr=='a' || kr == 'A')
		return 4;
	else if(kr=='p')
		return 1;
	else
		return 0;
}

int durum4()
{
	char kr;
	kr = karakterAl();
	if(kr=='t' || kr == 'T')
		return 5;
	else if(kr == 'p' || kr == 'P')
		return 3;
	else
		return 0;
}

int durum5()
{
	char kr;
	kr = karakterAl();
	if(kr=='y' || kr == 'Y')
		return 6;
	else if(kr=='p' || kr == 'P')
		return 1;
	else
		return 0;
}

int durum6()
{
	char kr;
	kr = karakterAl();
	if(kr=='a' || kr == 'A')
		return 7;
	else if(kr=='p' || kr == 'P')
		return 1;
	else
		return 0;
}

int durum7()
{
	char kr;
	static int say = 0 ;
	say ++ ;
	printf("Papatya %d. kez bulundu\n",say);
	return 0;
}
int main()
{
	int birSonraki;
	Fadres durum[8] = {durum0, durum1, durum2, durum3,
					   durum4, durum5, durum6, durum7};
					   
	/*Karakterlerin okunacagi dosyayi okuma modunda aciyoruz*/
	
	di = fopen("metin.txt","r");
	if(di==NULL)
	{
		puts("Dosya hata\n");
		exit(1);
	}
	
	birSonraki = 0;
	
	while(1)
		birSonraki = durum[birSonraki]();
}





















