#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> tags(n);
  for (int i = 0; i < n; ++i) {
    cin >> tags[i];
  }

  vector<string> fruits(m);
  for (int i = 0; i < m; ++i) {
    cin >> fruits[i];
  }

  unordered_map<string, int> count;
  for (int i = 0; i < m; ++i) {
    count[fruits[i]]++;
  }
  vector<int> total_count;
  for (auto [f, c] : count) {
    total_count.push_back(c);
  }

  sort(tags.begin(), tags.end());
  sort(total_count.rbegin(), total_count.rend());
  int ans1 = 0;
  int size = total_count.size();
  for (int i = 0; i < size; ++i) {
    ans1 += tags[i] * total_count[i];
  }

  reverse(tags.begin(), tags.end());
  int ans2 = 0;
  for (int i = 0; i < size; ++i) {
    ans2 += tags[i] * total_count[i];
  }

  cout << ans1 << " " << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
