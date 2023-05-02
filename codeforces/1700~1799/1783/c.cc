#include <bits/stdc++.h>

using namespace std;

void solve(int n, int m, vector<int>& a) {
  vector<pair<int,int>> p(n);
  for (int i = 0; i < n; ++i) {
    p[i].first = a[i];
    p[i].second = (n-i);
  }
  sort(p.begin(), p.end());

  auto more_win = [&](int place) -> bool {
    int prepare = m;
    int win_count = 0;
    for (int i = 0; i < n; ++i) {
      if (prepare - p[i].first >= 0) {
        prepare -= p[i].first;
        win_count++;
      } else {
        break;
      }
    }
    return win_count > (n-place);
  };

  auto same_win = [&](int place) -> bool {
    int index = 0;
    for (int i = 0; i < n; ++i) {
      if (p[i].second == place) {
        index = i;
        break;
      }
    }

    int prepare = m;

    if (prepare < p[index].first) return false;
    prepare -= p[index].first;
    int win_count = 1;

    for (int i = 0; i < n; ++i) {
      if (i == index) continue;

      if (prepare - p[i].first >= 0) {
        prepare -= p[i].first;
        win_count++;
      } else {
        break;
      }
    }
    return win_count >= (n-place);
  };

  int l = 1, r = n+1;
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (more_win(mid) || same_win(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    solve(n, m, a);
  }
  return 0;
}
