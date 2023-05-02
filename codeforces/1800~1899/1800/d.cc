#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve() {
  const ll MOD = 100000000000000007;
 
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
 
  vector<ll> p(n);
  ll h = 1;
  for (int i = 0; i < n; ++i) {
    p[i] = h;
    h = (h * 26) % MOD;
  }
 
  ll hash = 0;
  for (int i = 2; i < n; ++i) {
    int c = s[i] - 'a';
    hash += p[i-2] * c;
    hash %= MOD;
  }
  unordered_set<ll> hashes = {hash};
  // cout << "hash: " << hash << endl;
  for (int i = 0; i < n-2; ++i) {
    int c1 = s[i] - 'a';
    int c2 = s[i+2] - 'a';
    hash = hash + p[i] * c1;
    hash %= MOD;
    hash -= p[i] * c2;
    hash %= MOD;
    hash = (hash + MOD) % MOD;
    // cout << "hash: " << hash << endl;
    hashes.insert(hash);
  }
  cout << hashes.size() << endl;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
