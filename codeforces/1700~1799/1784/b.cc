#include <bits/stdc++.h>

using namespace std;

struct Swap {
  int i, j;
  char x, y;
};

unordered_map<char,int> c2i = {{'w', 0}, {'i', 1}, {'n', 2}};

string win = "win";

void solve() {
  int n = 0;
  cin >> n;

  vector<int> edges[3][3];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    vector<int> count(3);
    for (char ch : s) {
      count[c2i[ch]]++;
    }

    for (int p = 0; p < 3; ++p) {
      for (int q = 0; q < 3; ++q) if (p != q && count[p] > 1 && !count[q]) {
        // cout << p << " -> " << q << " : " << i << endl;
        edges[p][q].push_back(i);
      }
    }
  }

  vector<Swap> ans;
  for (int p = 0; p < 3; ++p) {
    for (int q = 0; q < 3; ++q) if (p != q) {
      while (!edges[p][q].empty() && !edges[q][p].empty()) {
        int i1 = edges[p][q].back();
        int i2 = edges[q][p].back();
        edges[p][q].pop_back();
        edges[q][p].pop_back();
        ans.push_back(Swap{i1, i2, win[p], win[q]});
        // cout << "found?" << endl;
      }
    }
  }

  while (!edges[0][1].empty() && !edges[1][2].empty() && !edges[2][0].empty()) {
    int i1 = edges[0][1].back();
    int i2 = edges[1][2].back();
    int i3 = edges[2][0].back();
    edges[0][1].pop_back();
    edges[1][2].pop_back();
    edges[2][0].pop_back();

    ans.push_back(Swap{i1, i2, win[0], win[1]});
    ans.push_back(Swap{i2, i3, win[0], win[2]});
  }

  while (!edges[0][2].empty() && !edges[2][1].empty() && !edges[1][0].empty()) {
    int i1 = edges[1][0].back();
    int i2 = edges[2][1].back();
    int i3 = edges[0][2].back();
    edges[1][0].pop_back();
    edges[2][1].pop_back();
    edges[0][2].pop_back();

    ans.push_back(Swap{i1, i3, win[1], win[0]});
    ans.push_back(Swap{i2, i3, win[2], win[1]});
  }

  // for (int i = 0; i < 3; ++i) {
  //   for (int j = 0; j < 3; ++j) {
  //     if (edges[i][j].size() > 0) {
  //       cout << i << " -> " << j << endl;
  //     }
  //   }
  // }

  cout << ans.size() << endl;
  for (auto& [i, j, c1, c2] : ans) {
    cout << (i+1) << " " << c1 << " " << (j+1) << " " << c2 << endl;
  }
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
