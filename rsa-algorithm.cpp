#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//author Raden Saleh

int angka[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
char huruf[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
string kata;

int prime(int bil)
{
    int j = sqrt(bil);
    for (int i = 2; i <= j; i++)
    {
        if (bil % i == 0)
            return 0;
    }
    return 1;
}

void cekBilPrime(int bil)
{
    if (prime(bil) == 0 || bil == 1)
    {
        cout << "Inputan harus bilangan prima!" << endl;
        exit(1);
    }
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int encryption(char p, int e, int n)
{
    int cijfers;
    for (int i = 0; i < 26; i++)
    {
        if (huruf[i] == p)
        {
            cijfers = angka[i];
        }
    }
    int pe = pow(cijfers, e);
    return pe % n;
}

char decryption(int c, int d, int n)
{
    long int cd = pow(c, d);
    int chiper = cd % n;

    for (int i = 0; i < 26; i++)
    {
        if (angka[i] == chiper)
        {
            return huruf[i];
        }
    }
}

int main()
{
    int p, q, n, k;

    cout << "Masukan bilangan prima p : ";
    cin >> p;

    cekBilPrime(p);

    cout << "Masukan bilangan prima q : ";
    cin >> q;

    cekBilPrime(q);

    n = p * q;
    cout << "Nilai n diperoleh : " << n << endl;

    k = (p - 1) * (q - 1);
    cout << "Nilai k diperoleh : " << k << endl;

    int e = 2;
    while (e < k)
    {
        if (gcd(e, k) == 1)
        {
            break;
        }
        else
        {
            e++;
        }
    }
    cout << "Nilai e diperoleh : " << e << endl;

    int x, d;
    for (int i = 1; i <= 10; i++)
    {
        x = 1 + i * k;
        if (x % e == 0)
        {
            d = x / e;
            break;
        }
    }
    cout << "Nilai d diperoleh : " << d << endl;

    cout << endl
         << "Kamu mau pilih yang mana : " << endl
         << "[1] Encryption " << endl
         << "[2] Decryption" << endl
         << "Pilih : ";

    int i;
    cin >> i;

    int chiper;
    char plantext;

    if (i == 1)
    {
        cout << "Masukan kata(kapital) yang akan kamu encryption : ";
        cin >> kata;

        int j = kata.length();
        char arrKata[j + 1];

        strcpy(arrKata, kata.c_str());

        cout << "Yeayy chiper kamu adalah : ";
        for (int i = 0; i < j; i++)
        {
            cout << encryption(arrKata[i], e, n) << " ";
        }
    }
    else if (i == 2)
    {
        cout << "Masukan angka/chiper yang akan kamu encryption : ";
        cin >> chiper;
        cout << "Yeayy plantext kamu adalah : " << decryption(chiper, d, n) << endl;
    }
    else
    {
        cout << "Inputan anda tidak ada!" << endl;
        exit(1);
    }

    return 0;
}
