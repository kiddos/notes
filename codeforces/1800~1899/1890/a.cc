#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  map<int,int> freq;
  for (int i = 0; i < n; ++i) freq[a[i]]++;

  if (freq.size() == 1) {
    cout << "YES" << endl;
  } else if (freq.size() == 2) {
    int c1 = freq.begin()->second;
    int c2 = freq.rbegin()->second;
    if (abs(c1 - c2) <= 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
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
