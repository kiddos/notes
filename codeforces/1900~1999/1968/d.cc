#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, pb = 0, ps = 0;
  cin >> n >> k >> pb >> ps;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) cin >> p[i];
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<bool> visited(n+1);
  function<void(int,vector<int>&)> dfs = [&](int x, vector<int>& scores) {
    if (visited[x]) {
      return;
    }
    visited[x] = true;
    scores.push_back(a[x]);
    dfs(p[x], scores);
  };
  vector<int> bodya;
  dfs(pb, bodya);

  fill(visited.begin(), visited.end(), false);
  vector<int> sasha;
  dfs(ps, sasha);

  // cout << "bodya:";
  // for (int s : bodya) cout << s << " ";
  // cout << endl;
  // cout << "sasha:";;
  // for (int s : sasha) cout << s << " ";
  // cout << endl;

  auto find_score = [&](vector<int>& scores) -> i64 {
    int size = scores.size();
    i64 prefix = 0;
    i64 ans = 0;
    for (int i = 0; i < min(k, size); ++i) {
      i64 left = k - i - 1;
      prefix += scores[i];
      i64 sum = prefix + left * scores[i];
      ans = max(ans, sum);
    }
    return ans;
  };

  i64 bodya_score = find_score(bodya);
  i64 sasha_score = find_score(sasha);
  // cout << bodya_score << " - " << sasha_score << endl;
  if (bodya_score > sasha_score) {
    cout << "Bodya" << endl;
  } else if (bodya_score < sasha_score) {
    cout << "Sasha" << endl;
  } else {
    cout << "Draw" << endl;
  }
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
