#include <bits/stdc++.h>

using namespace std;

void solve(vector<pair<int, int>>& segments, int k) {
  vector<int> line(52);
  for (auto& [l, r] : segments) {
    if (k >= l && k <= r) {
      line[l]++;
      line[r+1]--;
    }
  }

  for (int i = 1; i < line.size(); ++i) {
    line[i] += line[i-1];
  }

  for (int i = 0; i < line.size(); ++i) if (i != k) {
    if (line[i] >= line[k]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;

    vector<pair<int,int>> segments;
    for (int i = 0; i < n; ++i) {
      pair<int,int> seg;
      cin >> seg.first >> seg.second;
      segments.push_back(seg);
    }

    solve(segments, k);
  }
  return 0;
}
