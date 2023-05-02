#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> pos, neg;
  int zeros = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) pos.push_back(a[i]);
    else if (a[i] < 0) neg.push_back(a[i]);
    else zeros++;
  }
  if (zeros == n) {
    cout << "NO" << endl;
    return;
  }

  sort(pos.begin(), pos.end());
  sort(neg.rbegin(), neg.rend());
  vector<int> ans;
  ll sum = 0;
  while (!pos.empty() || !neg.empty()) {
    if (sum <= 0 && !pos.empty()) {
      sum += pos.back();
      ans.push_back(pos.back());
      pos.pop_back();
    } else if (!neg.empty()) {
      sum += neg.back();
      ans.push_back(neg.back());
      neg.pop_back();
    }
  }
  while (zeros-- > 0) {
    ans.push_back(0);
  }
  cout << "YES" << endl;
  for (int num : ans) cout << num << " ";
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
