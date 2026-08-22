#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int N = 0;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  unordered_map<string, int> count;
  for (string& s : S) {
    for (char& ch : s) {
      ch = tolower(ch);
    }
    count[s]++;
  }

  int ans = 0;
  for (auto [s, c] : count) {
    ans = max(ans, c);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
