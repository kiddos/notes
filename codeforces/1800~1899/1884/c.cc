#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> segments;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    segments.emplace_back(l, r);
  }

  set<int> s = {1, m, m+1};
  for (int i = 0; i < n; ++i) {
    s.insert(segments[i].first);
    s.insert(segments[i].second);
    s.insert(segments[i].second+1);
  }

  vector<int> points(s.begin(), s.end());
  int p = points.size();
  map<int,int> index;
  for (int i = 0; i < p; ++i) {
    index[points[i]] = i;
  }

  vector<int> line(p);
  for (int i = 0; i < n; ++i) {
    line[index[segments[i].first]]++;
    line[index[segments[i].second+1]]--;
  }
  for (int i = 1; i < p; ++i) {
    line[i] += line[i-1];
  }

  vector<int> line1(p);
  vector<int> line2(p);
  for (int i = 0; i < n; ++i) {
    int i1 = index[segments[i].first];
    int i2 = index[segments[i].second];
    int i3 = index[segments[i].second+1];
    if (i1 > 0) {
      line1[i1]++;
      line1[i3]--;
    }
    if (i2 < index[m]) {
      line2[i1]++;
      line2[i3]--;
    }
  }
  for (int i = 1; i < p; ++i) {
    line1[i] += line1[i-1];
    line2[i] += line2[i-1];
  }

  int ans = max(*max_element(line1.begin(), line1.end()) - line1[0],
                *max_element(line2.begin(), line2.end()) - line2[index[m]]);

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
