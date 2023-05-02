#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<int>& a) {
  int n = a.size();
  bool pos = true, neg = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) pos = false;
    if (a[i] > 0) neg = false;
  }
  ll total = accumulate(a.begin(), a.end(), 0LL);
  if (!neg && pos) {
    cout << total << endl;
  } else if (!pos && neg) {
    cout << -total << endl;
  } else {
    cout << abs(total) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    solve(a);
  }
  return 0;
}
