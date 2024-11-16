#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 find_first_size(int percent, i64 size) {
  i64 l = 0, r = size;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 p = mid * 100 / size;
    if (p >= percent) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }
  return ans;
}

i64 find_last_size(int percent, i64 size) {
  i64 l = 0, r = size;
  i64 ans = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 p = mid * 100 / size;
    if (p <= percent) {
      l = mid+1;
      ans = mid;
    } else {
      r = mid-1;
    }
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 total_transfer = accumulate(a.begin(), a.end(), 0LL);
  vector<i64> prefix = {0};
  for (int i = 0; i < n; ++i) {
    prefix.push_back(prefix.back() + a[i]);
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int p = 0; p <= 100; ++p) {
      i64 low = find_first_size(p, a[i]);
      i64 high = find_last_size(p, a[i]);
      if (low > high) continue;

      i64 total_low = (prefix[i] + low) * 100 / total_transfer;
      i64 total_high = (prefix[i] + high) * 100 / total_transfer;
      // cout << "p=" << p << ", low=" << total_low << ", high=" << total_high << endl;
      if (p >= total_low && p <= total_high) {
        // cout << "i=" << i << ", p=" << p << ", totol low=" << total_low << ", high=" << total_high 
        //     << " | low=" << low << ", high=" << high << endl;
        ans.push_back(p);
      }
    }
  }

  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  for (int p : ans) {
    cout << p << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
