#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int durum0()
{
	char kr;
	puts("BASLANGIC DURUMUNDAYIM");
	kr = getch();
	if(kr=='A' || kr=='a')
		return 1; // CASE 1'e git
	else return 0;// CASE 0'a git
}

int durum1()
{
	char kr;
	puts("A harfindeyim\n");
	kr = getch();
	if(kr=='s' || kr=='S')
		return 2;
	else if(kr == 'a' || kr == 'A')
		return 1;
	else 
		return 0;
}

int durum2()
{
	char kr;
	puts("S harfindeyim, AS gelmis oldu, bir harf eksik :)\n");
	kr = getch();
	if(kr=='k' || kr == 'K')
		return 3;
	else if(kr=='a'|| kr=='A')
		return 1;
	else
		return 0;
	
}

int durum3()
{
	
	puts("K Harfi ve son");
	puts("Ideallerimizin pesinden gidebildigimiz guzel bir dunya olmasi dilegiyle");
	return -1;
}


int main()
{
	int drm = 0;
	while(1)
	{
		switch(drm)
		{
			case 0: drm = durum0(); break;
			
			case 1: drm = durum1(); break;
			
			case 2: drm = durum2(); break;
			
			case 3: drm = durum3(); break;
			
			case -1: puts("...IYI CALISMALAR..."); exit(0);
			
		}
	}	
	return 0;
}


