#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 min_operation(const string& s, char ch) {
  int n = s.length();
  i64 total = 0;
  i64 index = 0;
  vector<i64> prefix(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == ch) {
      total++;
      index += i;
    }
    i64 upper = i*total - (total - 1) * total / 2;
    prefix[i] = upper - index;
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << prefix[i] << " ";
  // }
  // cout << endl;

  vector<i64> suffix(n+1);
  total = 0;
  index = 0;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == ch) {
      total++;
      index += i;
    }
    i64 lower = i*total + (total-1) * total / 2;
    suffix[i] = index - lower;
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << suffix[i] << " ";
  // }
  // cout << endl;

  i64 ans = numeric_limits<i64>::max();
  for (int i = 0; i < n; ++i) {
    // cout << "i=" << i << " p=" << prefix[i]  << ", s=" << suffix[i+1] << endl;;
    ans = min(ans, prefix[i] + suffix[i+1]);
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  i64 ans = min(min_operation(s, 'a'), min_operation(s, 'b'));
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
