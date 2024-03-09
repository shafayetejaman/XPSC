// 

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef pair<long long, long long> pll;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
#define loop(n) for(auto j = 0; j < (n); j++)
#define even(n) ((n) % 2 == 0)
#define odd(n) ((n) % 2 != 0)
#define LL (long long)
#define LD (long double)
#define ll long long
#define ln '\n'
#define all(x) (x).begin(), (x).end()

// const int N = 1e5 + 1;
// const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    map<int, int> m;
    vll a;

    for (auto& i : v)
    {
        if (i >= 1 and i <= n)
        {
            m[i]++;

            if (m[i] > 1) a.push_back(i);
        }
        else a.push_back(i);
    }

    vb b(n + 1, true);

    for (auto& [f, s] : m)
    {
        b[f] = false;
    }

    sort(all(a));
    int count = 0;

    for (auto i = 1, j = 0; i <= n; i++)
    {
        if (b[i])
        {
            if ((a[j++] + 1) / 2 <= i)
            {
                cout << -1 << ln;
                return;
            }
            else count++;
        }
    }

    cout << count << ln;

    // cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}