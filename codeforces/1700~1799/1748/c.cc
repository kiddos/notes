#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int i = 0;
  ll p = 0;
  int ans = 0;
  while (i < n && a[i] != 0) {
    p += a[i];
    i++;
    ans += p == 0;
  }

  while (i < n) {
    int j = i+1;
    map<ll, int> freq;
    freq[p]++;
    while (j < n && a[j] != 0) {
      p += a[j];
      freq[p]++;
      j++;
    }

    int max_score = 0;
    for (auto& [prefix, count] : freq) {
      max_score = max(max_score, count);
    }
    ans += max_score;
    i = j;
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
