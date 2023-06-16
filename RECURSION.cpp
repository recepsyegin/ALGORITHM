#include <iostream>
using namespace std;

class Recursion{
	public:
		
		void dec(int n)
		{	//BaseCase
	
			if(n==0) return;
						
			cout << n << ", ";
			dec(n-1);
	 	}

		/******************************************/
		void inc(int n)
		{
			if(n==0) return;
			inc(n-1);
			cout << n << ", ";
		}

		
		/******************************************/
		int fact(int n)
		{
			if(n<0) return 0;
			// Base Case
			if(n==0) return 1;
			//RECURSION
			int cevap = n*fact(n-1);
			return cevap;	
		}
		/******************************************/
		int fibonacci(int n)
		{	// 0 1 1 2 3 5 8 13 ...
			// Base Case
			if(n==0 or n==1)
				return n;
				
			return fibonacci(n-1)+fibonacci(n-2);
		}
		/******************************************/
		bool isSorted(int arr[],int n)
		{	// Base Case
			if(n==1 or n==0) return true;
			//Rec. Case
			if(arr[0]<arr[1] && isSorted(arr+1,n-1))	
				return true;
			return false;
		}
		/******************************************/
		void reverseString(char *s)
		{
			if(*s)
			{
				reverseString(s+1);
				cout << *s;
			}
			
		}
		/******************************************/
		int sum (int num)
		{
			if(num!=0)
			{
				return num + sum(num-1);
			}
			return 0;
		}
		/******************************************/
		int power(int a,int n) // a*a*a*...*a (a^^n)
		{
			if(n == 0) return 1; // Base Case
			
			return a * power(a,n-1);
		}
		/******************************************/
		int fastPower(int a,int n)
		{
			if(n==0) return 1;
			
			int subProb = fastPower(a,n/2);
			int subProbSq = subProb*subProb;
			if(n&1) // N tek sayi ise
			{
				return a * subProbSq;
			}
			return subProbSq;
		}
		/******************************************/
		
		
		
		
};
int main()
{
	Recursion r1;
	cout << r1.fact(5) << endl;
	cout << r1.fibonacci(8) << endl;
	/******************************************/
	int arr[] = {1,2,3,5,4}; int n=sizeof(arr)/sizeof(int);
	cout << r1.isSorted(arr,n) << endl;
	/******************************************/
	r1.reverseString("Recep Sadullah YEGIN"); cout << endl;
	/******************************************/
	char *saa = "Sadullah pointer deneme"; cout << endl;
	cout << *(saa+2) << endl << saa << endl <<*saa << endl;
	/******************************************/
	cout << r1.sum(5) << endl;
	/******************************************/
	cout << r1.power(2,5) << endl;
	cout << r1.fastPower(2,6) << endl;
	/******************************************/
	r1.inc(6); cout << endl; r1.dec(6); cout << endl;
	
	
	
	
	
	return 0;
}
