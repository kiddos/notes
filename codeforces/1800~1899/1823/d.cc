#include <bits/stdc++.h>

using namespace std;

bool check(int x, int c) {
  if (x == 1 && c != 1) {
    return false;
  }
  if (x == 2 && c != 2) {
    return false;
  }
  if (x >= 3 && (c < 3 || c > x)) {
    return false;
  }
  return true;
}

string generate(int x, int c, int& ch, char ch2) {
  string ans;
  for (int i = 0; i < c; ++i) {
    ans.push_back(ch2);
  }
  while (ans.length() < x) {
    ans.push_back(ch + 'a');
    ch = (ch+1) % 3;
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(k);
  for (int i = 0; i < k; ++i) cin >> x[i];
  vector<int> c(k);
  for (int i = 0; i < k; ++i) cin >> c[i];

  vector<pair<int,int>> conditions;
  for (int i = 0; i < k; ++i) {
    if (!check(x[i], c[i])) {
      cout << "NO" << endl;
      return;
    }
    if (x[i] >= 3) {
      conditions.push_back({x[i], c[i]});
    }
  }

  sort(conditions.begin(), conditions.end());

  int ch = 0;
  char ch2 = 'd';
  string ans = generate(conditions[0].first, conditions[0].second-3, ch, 'a');
  for (int i = 1; i < k; ++i) {
    int len = conditions[i].first - conditions[i-1].first;
    int p = conditions[i].second - conditions[i-1].second;
    if (p > len) {
      cout << "NO" << endl;
      return;
    }
    ans += generate(len, p, ch, ch2++);
  }

  ans += generate(n-conditions.back().first, 0, ch, ch2);

  cout << "YES" << endl;
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
