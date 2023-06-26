#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;

  vector<ll> values = {1, 10, 100, 1000, 10000};
  int n = s.length();
  ll value = 0;
  vector<int> sign(n);
  vector<int> max_cs(n+1);
  int max_c = 0;
  for (int i = n-1; i >= 0; --i) {
    int c = s[i] - 'A';
    max_c = max(max_c, c);
    if (max_c > c) {
      value -= values[c];
      sign[i] = -1;
    } else {
      value += values[c];
      sign[i] = 1;
    }
    max_cs[i] = max_c;
  }

  // cout << "value= " << value << endl;

  ll ans = value;
  vector<int> add(5), sub(5);
  max_c = 0;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'A';
    for (int c2 = 0; c2 < 5; ++c2) {
      // cout << i << ": " << c+'A' << " -> " << c2 + 'A' << endl;
      ll gain = values[c2] - sign[i] * values[c];
      ll lose = 0;
      int cc = max({c2, max_cs[i+1]});
      for (int c3 = 0; c3 < cc; ++c3) {
        lose += values[c3] * add[c3];
      }
      for (int c3 = cc; c3 < 5; ++c3) {
        gain -= values[c3] * sub[c3];
      }
      ll new_value = value + gain - lose;
      ans = max(ans, new_value);
      // cout << "new value: " << new_value << " gain: " << gain << ", lose: " << lose << endl;
    }

    max_c = max(max_c, c);
    for (int c2 = 0; c2 < c; ++c2) {
      add[c2] = 0;
      sub[c2] = 0;
    }
    add[c] += max(sign[i] * 2, 0);
    sub[c] += min(sign[i] * 2, 0);
  }

  cout << ans << endl;
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
