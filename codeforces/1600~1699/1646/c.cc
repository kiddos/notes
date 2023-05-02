#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<ll> f, ll n) {
  int m = f.size();
  function<int(int,ll)> backtrack = [&](int index, ll val) {
    int ans = bitset<64>(val).count();
    if (index < 2) return ans;
    ans = min(ans, backtrack(index-1, val));
    if (val >= f[index]) {
      ans = min(ans, backtrack(index-1, val - f[index]) + 1);
    }
    return ans;
  };
  return backtrack(m-1, n);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<ll> factorial = {1};
  while (factorial.back() <= 1e13) {
    factorial.push_back(factorial.back() * (factorial.size()+1));
  }

  int t = 0;
  cin >> t;
  while (t--) {
    ll n = 0;
    cin >> n;
    int ans = solve(factorial, n);
    cout << ans << '\n';
  }
  cout << flush;

  return 0;
}
