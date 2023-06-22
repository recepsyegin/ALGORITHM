#include <iostream>
using namespace std;

const int MAX = 1001;

// Recursive :

int fibo_rec(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	
	return fibo_rec(n-1) + fibo_rec(n-2);
}

// Bottom Up (Iterative Approach)
int fibo_bu(int n) // 0 1 1 2 3 5 8 13 ...
{
	int map[MAX];
	map[0] = 0;
	map[1] = 1;
	
	for(int i = 2;i<=n ; i++)
		map[i] = map[i-1]+map[i-2];
	return map[n];
}
// Top Down (Recursive + Memoization)

int fibo_td(int n)
{
	static int map[MAX];
	if(map[n]>0) return map[n];
	
	if(n==0)
		map[n] = 0; // n=0 olursa map[0] 0 olsun cevap 0
	else if(n==1)	// n=1 olursa map[1] 1 olsun cevap 1
		map[n]=1;
	else			// deðilse rekürsif olarak devam et...
		map[n] = fibo_td(n-1)+fibo_td(n-2);
		
		
	return map[n];
}

//Merdiven tepesine ulaþma 
const int N = 100;
int count(int n) // 1,2 yada 3 adim atabiliriz.
				 // n=4 basamaklý merdivene kac yolla
				 // týrmanabiliriz?
{ 
	if(n<0) return 0;
	if(n==0) return 1;
	
	return count(n-3)+count(n-2)+count(n-1);
}

int count_dp(int n)
{
	static int map[N];
	if(n<0) return 0;
	if(n==0) return 1;
	if(map[n]>0) return map[n];
			// Sýrayla 3 adým atarak cikmak isterse? 2 adim...
			// Hepsini toplar ve sonucu dondurur.
			//Mesela: 4 basamakli merdiven: 1 + 1 + 1 + 1 = 4
			// 2 adim atarsa : 2+2 = 4 (2 tane 2 adim)
			// 3 adim atarsa : 3 + 1 = 1 (1 tane 3 kullandi)
			// toplayalim : 4 + 2 + 1 = 7
	map[n] = count_dp(n-3)+count_dp(n-2)+count_dp(n-1);
	return map[n];
	
	
}



int main()
{
	cout << fibo_rec(5) << endl;	// 5
	cout << fibo_bu(6)  << endl;	// 8
	cout << fibo_td(7)  << endl;   // 13
	//////////////////////////////////////
	cout << count(4) << endl;
	cout << count_dp(4) << endl;
	
	
	
	
	
	return 0;
} 
