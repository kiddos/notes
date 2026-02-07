#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  map<string,int> count;
  for (int i = 0; i < n; ++i) {
    count[s[i]]++;
  }
  int most_score = 0;
  string ans;
  for (auto [team, score] : count) {
    if (score > most_score) {
      most_score = score;
      ans = team;
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
