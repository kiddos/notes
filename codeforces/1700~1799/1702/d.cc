#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  string s;
  cin >> s;
  ll p = 0;
  cin >> p;

  using Pair = pair<int,int>;
  priority_queue<Pair, vector<Pair>, less<>> pq;
  int n = s.length();
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    int score = s[i] - 'a' + 1;
    total += score;
    pq.push({score, i});
  }

  vector<bool> ignore(n);
  while (!pq.empty() && total > p) {
    auto [score, index] = pq.top();
    pq.pop();
    total -= score;
    ignore[index] = true;
  }

  string ans;
  for (int i = 0; i < n; ++i) if (!ignore[i]) {
    ans.push_back(s[i]);
  }
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
