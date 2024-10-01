#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0, k = 0;
  cin >> n >> d >> k;
  vector<pair<int,int>> events;
  for (int i = 0; i < k; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    events.emplace_back(l, r);
  }
  sort(events.begin(), events.end());

  vector<int> overlap(n+2);
  multiset<int> ends;
  for (int i = 1, j = 0; i <= n+1; ++i) {
    while (j < (int)events.size() && events[j].first <= i+d-1) {
      ends.insert(events[j].second);
      j++;
    }
    while (!ends.empty() && *ends.begin() < i) {
      ends.erase(ends.begin());
    }
    int event_count = ends.size();
    overlap[i] = event_count;
  }

  // for (int i = 1; i <= n+1; ++i) {
  //   cout << overlap[i] << " ";
  // }
  // cout << endl;

  int ans1 = max_element(overlap.begin()+1, overlap.begin() + n-d+2) - overlap.begin();
  int ans2 = min_element(overlap.begin()+1, overlap.begin() + n-d+2) - overlap.begin();
  cout << ans1 << " " << ans2 << endl;
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
