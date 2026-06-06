#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[0] << endl;
    return;
  }

  vector<i64> neg, pos;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      neg.push_back(a[i]);
    } else {
      pos.push_back(a[i]);
    }
  }
  i64 ans = 0;
  if (neg.empty()) {
    i64 pos_sum = accumulate(pos.begin(), pos.end(), 0LL);
    i64 min_pos = *min_element(pos.begin(), pos.end());
    ans = pos_sum - min_pos - min_pos;
  } else {
    if (pos.empty()) {
      i64 max_neg = *max_element(neg.begin(), neg.end());
      i64 sum = accumulate(neg.begin(), neg.end(), 0LL);
      ans = -sum + max_neg + max_neg;
    } else {
      i64 neg_sum = accumulate(neg.begin(), neg.end(), 0LL);
      i64 pos_sum = accumulate(pos.begin(), pos.end(), 0LL);
      ans = pos_sum - neg_sum;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
