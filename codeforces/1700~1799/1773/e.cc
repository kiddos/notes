#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> stacks;
  for (int i = 0; i < n; ++i) {
    int k = 0;
    cin >> k;
    vector<int> s(k);
    for (int j = 0; j < k; ++j) {
      cin >> s[j];
    }
    stacks.push_back(s);
  }

  vector<int> final;
  for (vector<int>& s : stacks) {
    for (int x : s) {
      final.push_back(x);
    }
  }
  sort(final.begin(), final.end());
  int size = final.size();
  map<pair<int,int>, int> pairs;
  for (int i = 1; i < size; ++i) {
    pair<int,int> p = {final[i-1], final[i]};
    pairs[p]++;
  }

  int split = 0;
  for (vector<int>& s : stacks) {
    int s_size = s.size();
    for (int j = 1; j < s_size; ++j) {
      pair<int,int> p = {s[j-1], s[j]};
      if (pairs.count(p)) {
        if (--pairs[p] == 0) pairs.erase(p);
      } else {
        // final answer does not have this 2 numbers together,
        // so must split
        split++;
      }
    }
  }
  int combine = 0;
  for (auto& [p, count] : pairs) {
    combine += count;
  }
  cout << split << " " << combine << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
