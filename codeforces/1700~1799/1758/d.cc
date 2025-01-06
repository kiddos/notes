#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  vector<i64> ans;
  if (n % 2 == 0) {
    i64 l = n / 2, r = n * 3 / 2;
    for (int k = 0; k < n /2; ++k) {
      ans.push_back(l++);
      ans.push_back(r--);
    }
    sort(ans.begin(), ans.end());
  } else {
    ans.push_back(n);
    int l = n-1, r = n+1;
    for (int k = 0; k < n / 2; ++k) {
      ans.push_back(l--);
      ans.push_back(r++);
    }
    for (int i = 0; i < n; ++i) {
      ans[i] += 2;
    }
    sort(ans.begin(), ans.end());
    ans[0]--;
    ans.back()++;
    ans[n-2]++;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

  i64 sum = accumulate(ans.begin(), ans.end(), 0LL);
  assert(sqrt(sum) == *max_element(ans.begin(), ans.end()) - *min_element(ans.begin(), ans.end()));
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
