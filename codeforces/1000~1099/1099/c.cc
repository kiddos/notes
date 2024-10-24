#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int k = 0;
  cin >> k;

  vector<int> one, zero_or_one, zero_or_more;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (i+1 < n && s[i+1] == '*') {
      zero_or_more.push_back(i);
      i++;
    } else if (i+1 < n && s[i+1] == '?') {
      zero_or_one.push_back(i);
      i++;
    } else {
      one.push_back(i);
    }
  }

  if ((int) one.size() > k) {
    cout << "Impossible" << endl;
    return;
  }

  vector<int> include = one;
  for (int i = 0; i < (int)zero_or_one.size() && (int) include.size() < k; ++i) {
    include.push_back(zero_or_one[i]);
  }

  while (!zero_or_more.empty() && (int)include.size() < k) {
    include.push_back(zero_or_more[0]);
  }

  if ((int)include.size() < k) {
    cout << "Impossible" << endl;
    return;
  }

  sort(include.begin(), include.end());
  string ans;
  for (int idx : include) {
    ans.push_back(s[idx]);
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
