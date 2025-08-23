#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool possible(int x, map<int,int>& count, vector<pair<int,int>>& ans) {
  if (count.size() == 0) {
    return true;
  }

  int largest = count.rbegin()->first;
  int looking_for = x - largest;
  if (!count.count(looking_for)) {
    return false;
  }
  if (looking_for == largest && count[largest] < 2) {
    return false;
  }

  if (--count[largest] == 0) {
    count.erase(largest);
  }
  if (--count[looking_for] == 0) {
    count.erase(looking_for);
  }

  ans.emplace_back(largest, looking_for);
  bool result = possible(largest, count, ans);

  count[largest]++;
  count[looking_for]++;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;
  int m = n * 2;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int largest = a.back();

  map<int,int> count;
  for (int i = 0; i < m; ++i) {
    count[a[i]]++;
  }
  vector<pair<int,int>> ans;

  for (int i = 0; i < m-1; ++i) {
    int x = largest + a[i];

    ans.clear();
    if (possible(x, count, ans)) {
      cout << "YES" << endl;
      cout << x << endl;
      for (auto [val1, val2] : ans) {
        cout << val1 << " " << val2 << endl;
      }
      return;
    }
  }

  cout << "NO" << endl;
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
