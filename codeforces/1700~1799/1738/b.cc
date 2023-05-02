#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<ll> s(k);
  for (int i = 0; i < k; ++i) cin >> s[i];
  vector<ll> a;
  for (int i = k-1; i >= 1; --i) {
    ll ai = s[i] - s[i-1];
    a.push_back(ai);
  }

  int left = n - k + 1;
  ll ave = s[0] / left;
  ll extra = s[0] - ave * left;
  vector<ll> temp;
  for (int i = 0; i < left; ++i) {
    ll current = ave;
    if (extra != 0) {
      if (extra < 0) {
        extra++;
        current--;
      } else {
        extra--;
        current++;
      }
    }
    temp.push_back(current);
  }
  sort(temp.begin(), temp.end());

  // cout <<" left " << left <<  ", ave: " << ave << endl;
  while (!temp.empty()) {
    a.push_back(temp.back());
    temp.pop_back();
  }

  reverse(a.begin(), a.end());
  // for (int val : a) cout << val << " ";
  // cout << endl;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
