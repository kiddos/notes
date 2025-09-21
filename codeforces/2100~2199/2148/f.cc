#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    cin >> k;
    vector<int> ai(k);
    for (int j = 0; j < k; ++j) {
      cin >> ai[j];
    }
    a.push_back(ai);
    m = max(m, k);
  }


  vector<int> ans;
  while (!a.empty()) {
    sort(a.begin(), a.end());
    for (int x : a[0]) {
      ans.push_back(x);
    }

    int size = a[0].size();
    vector<vector<int>> a2;
    for (vector<int>& ai : a) {
      if ((int)ai.size() > size) {
        a2.push_back(vector<int>(ai.begin()+size, ai.end()));
      }
    }

    a = std::move(a2);
  }

  for (int x : ans) {
    cout << x << " ";
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
