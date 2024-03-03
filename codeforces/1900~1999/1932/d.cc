#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  char trump = '\0';
  cin >> trump;
  unordered_map<char, vector<string>> cards;
  for (int i = 0; i < 2 * n; ++i) {
    string card;
    cin >> card;
    char type = card[1];
    cards[type].push_back(card);
  }

  vector<pair<string, string>> ans;
  vector<string> left_over;
  for (auto& [type, list] : cards) {
    if (type == trump) continue;
    sort(list.begin(), list.end());

    int size = list.size() / 2 * 2;
    for (int i = 0; i < size; i += 2) {
      ans.push_back({list[i], list[i+1]});
    }
    if (list.size() % 2 == 1) {
      left_over.push_back(list.back());
    }
  }

  vector<string>& t = cards[trump];
  sort(t.begin(), t.end());
  int i = 0;
  for (string& card : left_over) {
    if (i < (int)t.size()) {
      ans.push_back({card, t[i++]});
    } else {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  for (; i < (int)t.size(); i += 2) {
    ans.push_back({t[i], t[i+1]});
  }

  for (auto& [c1, c2] : ans) {
    cout << c1 << " " << c2 << endl;
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
