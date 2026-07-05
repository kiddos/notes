#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  int min_h = *min_element(h.begin(), h.end());
  int max_h = *max_element(h.begin(), h.end());
  vector<i64> line(max_h+1);
  for (int i = 0; i < n; ++i) {
    line[h[i]]--;
  }
  vector<i64> total(max_h+1);
  for (int j = 0, count = n; j <= max_h; ++j) {
    count += line[j];
    total[j] = count;
  }
  vector<i64> prefix = total;
  for (int j = 1; j <= max_h; ++j) {
    prefix[j] += prefix[j-1];
  }

  // for (int i = 0; i <= max_h; ++i) {
  //   cout << total[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i <= max_h; ++i) {
  //   cout << prefix[i] << " ";
  // }
  // cout << endl;

  int ans = 0;
  int current_h = max_h;
  while (current_h > min_h) {
    int l = min_h, r = current_h;
    int next_h = r;
    while (l <= r) {
      int mid = l + (r-l) /2;
      i64 removed = prefix[current_h-1] - prefix[mid-1];
      if (removed <= k) {
        next_h = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    current_h = next_h;
    // cout << "current_h=" << current_h << endl;
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
