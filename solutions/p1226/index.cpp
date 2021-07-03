#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long num, index, to_mod;
    cin >> num >> index >> to_mod;

    long long result;
    if (index)
    {
        long long to_power = index, to_multiply = num;
        result = 1;
        while (to_power != 0)
        {
            if (to_power & 1) // 二进制最后一位为1
            {
                // a * b mod c = ((a mod c) * (b mod c)) mod c
                result *= to_multiply;
                result %= to_mod;
            }
            to_multiply *= to_multiply;
            to_multiply %= to_mod;
            to_power >>= 1;
        }
    }
    else
        result = 1 % to_mod;

    cout << num << "^" << index << " mod " << to_mod << "=" << result << endl;

    return 0;
}
