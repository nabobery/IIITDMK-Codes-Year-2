#include <iostream>
#include <cmath>
using namespace std;

int GCD(int, int);
int LCM(int m, int n, int gcd);
int GCD2(int a, int b, int *x, int *y);
int prime_factors(int n);

int main(){
    int m,n,gcd, lcm, number;
    int x,y;
    cout << "This program is used for calculating GCD and LCM of two numbers.\n";
    cout << "Please enter the two numbers \n";
    cin >> m >> n;
    gcd = GCD(m,n);
    lcm = LCM(m,n,gcd);
    cout << "The GCD and LCM of two numbers "<< m << " and "<< n << " is " << gcd << " and "<< lcm <<" respectively \n";
    int gcd2 = GCD2(m,n, &x, &y);
    cout <<"GCD of two numbers "<< m << " and "<< n << " using Algo2 is " << gcd2 << endl;
    cout<<"Please enter a number who prime factors you want to calculate \n";
    cin >> number;
    cout<<"Therefore the prime factors of the " << number << " are ";
    prime_factors(number);
    return 0;
}

int GCD(int m, int n){
    // Base case 
    if (n == 0) 
        return m;
    else 
        return GCD(n, m % n);     
}

int LCM(int m, int n, int gcd){
    return ((m*n)/gcd); // Euclid's Division Lemma => LCM(m,n) = product of m and n / GCD(m,n)
}

// ax + by = GCD(a,b)
int GCD2(int a, int b, int *x, int *y){ 
    // Base Case
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    int x1,y1; // To store results of recursive calls 
    int gcd = GCD2(b%a, a, &x1, &y1);
    // Uodate x and y at recursion call
    *x = y1 + (b/a) * x1; 
    *y = x1;
    return gcd;
}

int prime_factors(int n){
    // If 2 is a factor of n 
    while(n % 2 == 0){
        cout << "2 ";
        n = n/2;
    }
    // n must be odd as all of it's even factors are taken(all 2's are taken)
    //As n is not even now, we need to check with odd numbers so i = i + 2
    for(int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            cout << i << " ";
            n = n/i;
        }
    }

    // For prime numbers greter than 2 (example; 3,5,7 etc...)
    if (n > 2){
         cout << n << " ";
    }
}