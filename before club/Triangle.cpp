#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && a == c && a != 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}