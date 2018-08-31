#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Helper Functions
int numDigits(int num) { // Counts the number of digits in an integer
	int n = 1;
	while (num > 9) {
		num /= 10;
		n++;
	}
	return n;
}
 
int splitFirst(int num, int numDig) { // Splits the 'numDig' digit integer into the first half ('a' or 'c')
	int m = (numDig / 2) + (numDig % 2);
    int base = pow(10, m);
	int first = num / base;
	return first;
}

int splitSecond(int num, int numDig) { // Splits the 'numDig' digit integer into the second half ('b' or 'd')
	int m = (numDig / 2) + (numDig % 2);
	int base = pow(10, m);
	int second = num % base;
	return second;
}

// Karatsuba Function
int karatsuba(int x, int y) {
	int ac, bd, adbc; // declaring variables for algorithm
	int min = 1;
	int xDig = numDigits(x);
	int yDig = numDigits(y);

	// Compares which integer has the least amount of digits to use for the splitting function(s)
	if (xDig < yDig) {
		min = xDig;
	}
	else {
		min = yDig;
	}

	// Base case for the recursion
	if (xDig == 1 && yDig == 1) {
		return x * y;
	}
	else {
		int a = splitFirst(x, min);
		int b = splitSecond(x, min);
		int c = splitFirst(y, min);
		int d = splitSecond(y, min);
		ac = karatsuba(a, c);
		bd = karatsuba(b, d);
		adbc = karatsuba( (a + b), (c + d)) - ac - bd;
	}
	min = (min / 2) + (min % 2); // Ceil's the rounding of the integer (adds 1)

	int result = (pow(10, 2*min)*ac + pow(10, min)*adbc + bd); // The karatsuba algorithm
	return result;
}

int main() {
	
	cout << "15*15 = " << karatsuba(15, 15) << endl; // 225
	cout << "6*13 = " << karatsuba(6, 13) << endl; // 78
	cout << "51*49 = " << karatsuba(51, 49) << endl; // 2499
	cout << "111*111 = " << karatsuba(111, 111) << endl; // 12321
	cout << "5678*1234 = " << karatsuba(5678, 1234) << endl; // 7006652
	cout << "12345678*1 = " << karatsuba(12345678, 1) << endl; // 12345678
	cout << "12345678*0 = " << karatsuba(12345678, 0) << endl; // 0

	system("PAUSE");
	return 0;
}