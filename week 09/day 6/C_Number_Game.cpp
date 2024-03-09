// https://codeforces.com/problemset/problem/1749/C

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#ifdef LOCAL
#include "DEBUG_TEMPLATE.h"
#else
#define line
#define print(args...)
#endif

using namespace std;
using namespace __gnu_pbds;

typedef vector<long long> vll;
typedef vector<int> vi;
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

bool valid(vll& v, int k)
{
    multiset s(all(v));

    for (auto i = 1; i <= k; i++)
    {
        int l = k - i + 1;

        auto p = s.upper_bound(l);

        if (s.empty() or p == s.begin()) return false;
        p--;

        s.erase(p);

        if (!s.empty())
        {
            int b = *s.begin();

            s.erase(s.begin());
            s.insert(b + l);
        }
    }

    return true;
}

void solve()
{
    int n;
    cin >> n;

    vll v(n);

    for (auto& i : v)
    {
        cin >> i;
    }

    int l = 0;
    int r = n;
    int ans;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (valid(v, mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }

    cout << ans << ln;
    // cout << ln;
}

int main()
{

#ifndef LOCAL
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}