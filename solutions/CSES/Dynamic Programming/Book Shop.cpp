#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n, x;
    cin >> n >> x;

    vector<int> h(n);
    for(int& hi : h) cin >> hi;

    vector<int> s(n);
    for(int& si : s) cin >> si;

    vector<int> dp(x+1, 0);

    for(int i = 0; i < n; i++) {
        for(int p = x; p >= 0; p--) {
            if(p - h[i] >= 0) dp[p] = max(dp[p], dp[p-h[i]] + s[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}