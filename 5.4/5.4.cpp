#include <iostream>
#include <cmath>

using namespace std;

double S0(const int k, const int N)
{
    double P = 0;
    for (int k = N; k <= 19; k++)
        P *= ((k - N) / (k + N)) + 1;
    return P;
}

double S1(const int k, const int N, double t)
{
    if (k > 19)
        return 0;
    else
        return ((k - N) / (k + N)) + 1 + S1(k + 1, N, t);
}

double S2(const int k, const int N, double t)
{
    if (k < 19)
        return 0;
    else
        return ((k - N) / (k + N)) + 1 + S2(k - 1, N, t);
}

double S3(const int k, const int N, double t)
{
    t = t + ((k - N) / (k + N)) + 1;
    if (k >= 19)
        return t;
    else
        return S3(k + 1, N, t);
}

double S4(const int k, const int N, double t)
{
    t = t + ((k - N) / (k + N)) + 1;
    if (k <= 19)
        return t;
    else
        return S4(k - 1, N, t);
}

int main()
{
    int k, N;
    cout << "k = "; cin >> k;
    cout << "N = "; cin >> N;

    cout << "(iter) S0 = " << S0(k, N) << endl;

    cout << "(rec up ++) S1 = " << S1(k, N, k) << endl;

    cout << "(rec up --) S2 = " << S2(k, N, k) << endl;

    cout << "(rec down ++) S3 = " << S3(k, N, k) << endl;

    cout << "(rec down --) S4 = " << S4(k, N, k) << endl;

    return 0;
}
