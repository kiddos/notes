#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0, s = 0;
  cin >> n >> k >> s;

  i64 max_dist = (n-1) * k;
  i64 min_dist = k;
  if (s < min_dist || s > max_dist) {
    cout << "NO" << endl;
    return;
  }

  vector<i64> next_house;
  i64 current = 1;
  for (int i = 0; i < k && s > 0; ++i) {
    i64 go_left = current - 1;
    i64 go_right = n - current;
    if (go_right >= go_left) {
      i64 move = min(go_right, s);
      current += move;
      next_house.push_back(current);
      s -= move;
    } else {
      i64 move = min(go_left, s);
      current -= move;
      next_house.push_back(current);
      s -= move;
    }
  }

  // for (i64 h : next_house) {
  //   cout << h << " ";
  // }
  // cout << endl;

  vector<i64> ans;
  int size = next_house.size();
  i64 need_extra = k - size;
  current = 1;
  for (int i = 0; i < size; ++i) {
    if (next_house[i] > current) {
      for (i64 h = current + 1; h < next_house[i] && need_extra > 0; ++h) {
        ans.push_back(h);
        need_extra--;
      }
    } else {
      for (i64 h = current - 1; h > next_house[i] && need_extra > 0; --h) {
        ans.push_back(h);
        need_extra--;
      }
    }
    current = next_house[i];
    ans.push_back(next_house[i]);
  }

  cout << "YES" << endl;
  for (int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
