#include <iostream>

unsigned int fib(unsigned int);
unsigned int fac(unsigned int);
void printDownTo1(unsigned int);
int power(int, int);
void hanoi(int, int, int, int);

int numberOfMoves = 0;

int main()
{
	std::cout << "all the following test cases are tested with the number 5" << std::endl;
	//test of fac function
	std::cout << "factorial of 5 is: " << fac(5) << std::endl;
	//test of printDownTo1 function
	std::cout << "printing all numbers from 5 and down to 1: ";
	printDownTo1(5);
	std::cout << std::endl;
	//test of fib function
	std::cout << "fibonaccis fifth element is: " << fib(5) << std::endl;
	//test power
	std::cout << "5 to the power of 5 is: " << power(5, 5) << std::endl;
	//test hanoi
	int disks = 2;
	std::cout << "The tower of Hanoi with "<< disks << " disks: " << std::endl;
	hanoi(disks, 1, 3, 2);
	std::cout << "it took " << numberOfMoves << " moves to finish the tower ";
	std::cout << "the optimal amount is " << (power(2, disks) - 1) << std::endl;

}
unsigned int fac(unsigned int n) //complexity is O(n!)
{
	if(n == 0) //base case
	{
		return 0;
	}
	else if(n == 1)
	{
		return n;
	}
	else //recursive case
	{
		return n * fac(n - 1); //wil always reach base case since n is unsigned and decremented towards 0
	}
}
void printDownTo1(unsigned int n)
{
	if (n == 0)
	{
		return;
	}
	else 
	{
		std::cout << n << " ";
		printDownTo1(n - 1);
	}
}
int power(int x, int exp)
{
	if (exp < -1)
	{
		exp = abs(exp);
	}
	else if (exp == -1)
	{
		return 1 / x;
	}
	else if (exp == 1)
	{
		return x;
	}
	else if(x > 1)
	{
		return x * power(x, exp - 1);
	}
	else //return 1 if exp = 0;
	{
		return 1;
	}
}
unsigned int fib(unsigned int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
	//1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 
}
int sum(int* ptr, int n) //sums up from first to n'th element in array
{
	if(n == 0)//base case or exit condition
	{
		return 0;
	}
	else
	{
		return ptr[0] + sum(ptr + 1, n - 1);
	}
}
void hanoi(int nDisk, int ns, int ne, int nv)
{
	if (nDisk >= 1)
	{
		// put (n-1) disk to z by using y
		hanoi((nDisk - 1), ns, nv, ne);
		// move larger disk to right place
		std::cout << "Move disk " << nDisk << " from pin " << ns <<" to " << ne << std::endl;
		numberOfMoves++;
		// put (n-1) disk to right place 
		hanoi((nDisk - 1), nv, ne, ns);
	}
}
