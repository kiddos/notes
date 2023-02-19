#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    int m = n-1;

    vector<vector<int>> permutations;
    for (int i = 0; i < n; ++i) {
      vector<int> p;
      for (int j = 0; j < m; ++j) {
        int value = 0;
        cin >> value;
        p.push_back(value);
      }
      permutations.push_back(p);
    }

    vector<int> most_count(n+1);
    for (vector<int>& p : permutations) {
      most_count[p.back()]++;
    }
    int last_value = max_element(most_count.begin(), most_count.end()) - most_count.begin();
    for (vector<int>& p : permutations) {
      if (p.back() != last_value) {
        for (int val : p) cout << val << " ";
        cout << last_value << endl;
        break;
      }
    }
  }
  return 0;
}
