#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using i64 = long long;

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  ordered_set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }

  int idx = k;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    idx %= s.size();

    auto it = s.find_by_order(idx);
    ans.push_back(*it);
    s.erase(it);
    idx += k;
  }
  for (int i = 0; i < n; ++i) {
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
