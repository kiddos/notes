#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, A = 0, B = 0;
  cin >> n >> A >> B;
  vector<i64> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  i64 S = accumulate(s.begin(), s.end(), 0LL);
  i64 current = s[0] * A;
  vector<i64> can_block;
  for (int i = 1; i < n; ++i) {
    can_block.push_back(s[i]);
  }
  sort(can_block.begin(), can_block.end());
  int ans = 0;
  while (!can_block.empty() && current < B * S) {
    S -= can_block.back();
    can_block.pop_back();
    ans++;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
