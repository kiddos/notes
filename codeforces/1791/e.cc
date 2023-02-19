#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(vector<int>& a) {
  bool has_zero = false;
  int n = a.size();
  int negs = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      has_zero = true;
    } else if (a[i] < 0) {
      negs++;
    }
  }

  ll ans = 0;
  for (int aa : a) {
    ans += abs(aa);
  }
  if (has_zero || negs % 2 == 0) {
    cout << ans << endl;
  } else {
    vector<int> vals;
    for (int aa : a) {
      vals.push_back(abs(aa));
    }
    sort(vals.begin(), vals.end());
    ans -= vals[0] * 2;
    cout << ans << endl;
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
