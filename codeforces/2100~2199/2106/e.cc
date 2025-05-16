#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> index(n+1);
  for (int i = 1; i <= n; ++i) {
    index[p[i]] = i;
  }
  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0, k = 0;
    cin >> l >> r >> k;

    int idx = index[k];
    if (idx < l || idx > r) {
      ans.push_back(-1);
      continue;
    }

    int need_smaller = 0, need_larger = 0;
    int used_smaller = 0, used_larger = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      // cout << "p[mid]=" << p[mid] << endl;
      if (p[mid] == k) {
        break;
      }
      if (mid < idx) {
        l = mid+1;
        if (p[mid] > k) {
          need_smaller++;
          used_larger++;
        } else {
          used_smaller++;
        }
      } else {
        r = mid-1;
        if (p[mid] < k) {
          need_larger++;
          used_smaller++;
        } else {
          used_larger++;
        }
      }
    }

    int has_smaller = k-1-used_smaller;
    int has_larger = n-k-used_larger;

    int cancel_out = min(need_smaller, need_larger);
    need_smaller -= cancel_out;
    need_larger -= cancel_out;

    // cout << "need=" << need_smaller << "," << need_larger
    //   << ", has=" << has_smaller << ", " << has_larger << endl;
    if (has_smaller < need_smaller || has_larger < need_larger) {
      ans.push_back(-1);
    } else {
      int extra = max(need_smaller, need_larger);
      ans.push_back(cancel_out * 2 + extra * 2);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << " ";
  }
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
