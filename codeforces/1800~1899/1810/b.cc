#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, int> candy;

void solve() {
  ll n = 0;
  cin >> n;

  if (n % 2 == 0) {
    cout << "-1" << endl;
    return;
  }

  vector<int> ans;
  while (n > 1) {
    ll n2 = (n-1) / 2;
    if (n2 % 2 != 0) {
      n = n2;
      ans.push_back(2);
    } else {
      n2 = (n+1) / 2;
      n = n2;
      ans.push_back(1);
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int a : ans) cout << a << " ";
  cout << endl;
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
