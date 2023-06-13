#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  vector<pair<char, int>> index;
  for (int i = 0; i < n; ++i) {
    index.push_back({s[i], i});
  }

  int sum = 0;
  vector<int> jumps;
  if (s[0] <= s.back()) {
    sort(index.begin(), index.end());
    int start = find(index.begin(), index.end(), pair<char, int>{s[0], 0}) - index.begin();
    int end = find(index.begin(), index.end(), pair<char, int>{s.back(), n-1}) - index.begin();

    jumps.push_back(index[start].second+1);
    for (int i = start+1; i <= end; ++i) {
      sum += index[i].first - index[i-1].first;
      jumps.push_back(index[i].second+1);
    }
  } else {
    sort(index.begin(), index.end(), [&](auto& p1, auto& p2) {
      if (p1.first == p2.first) {
        return p1.second < p2.second;
      }
      return p1.first > p2.first;
    });

    int start = find(index.begin(), index.end(), pair<char, int>{s[0], 0}) - index.begin();
    int end = find(index.begin(), index.end(), pair<char, int>{s.back(), n-1}) - index.begin();

    jumps.push_back(index[start].second+1);
    for (int i = start+1; i <= end; ++i) {
      sum += index[i-1].first - index[i].first;
      jumps.push_back(index[i].second+1);
    }
  }

  cout << sum << " " << jumps.size() << endl;
  for (int i = 0; i < jumps.size(); ++i) cout << jumps[i] << " ";
  cout << endl;
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
