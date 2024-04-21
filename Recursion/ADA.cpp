// #include <iostream>
// using namespace std;

// CONSECUTIVE INTEGER CHECKING ALGORITHM

// int gcd(int m, int n)
// {
//     int t = min(m,n);
//     while(t!=0)
//     {
//         if(m%t == 0 && n%t == 0)
//         {
//             return t;
//         }
//         t--;
//     }
//     return -1;
// }

// EUCLID'S ALGORITHM

// int gcd(int m, int n)
// {
//     if(n == 0)
//         return m;
//     return gcd(n,m%n);
// }

//MIDDLE SCHOOL PROCEDURE

// int gcd(int m, int n)
// {
//     while(n!=m)
//     {
//         if(n > m)
//         {
//             n = n - m;
//         }
//         else
//         {
//             m = m - n;
//         }
//     }
//     return n;
// }

// MAIN FUNCTION FOR GCD

// int main()
// {   
//     int m,n;
//     cin >> m >> n;
//     cout << gcd(m,n) << endl;
// }

// SIEVE OF ERASTOTHENES

// void sieve(int n)
// {
//     int p;
//     int a[n+1];
//     for(int i = 0; i < n; i++) a[i] = 1;
//     for(p = 2; p*p <= n; p++)
//         if(a[p] == 1)
//             for(int i = p*p; i <= n; i+=p) a[i] = 0;
//     for(int i = 2; i <= n; i++)
//         if(a[i]) cout << i << " ";
//     cout << endl;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     sieve(n);
//     return 0;
// }