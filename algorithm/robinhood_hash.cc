#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Entry {
  bool contains_value;
  int value;
  int psl;

  Entry() : contains_value(false), value(0), psl(0) {}
};

constexpr int DATA_SIZE = 100;
Entry values[DATA_SIZE];

void insert(int value) {
  int p = hash<int>{}(value) % DATA_SIZE;
  int vpsl = 0;
  while (values[p].contains_value && values[p].value != value) {
    p = (p + 1) % DATA_SIZE;
    vpsl++;
  }
  
  values[p].value = value;
  values[p].psl = vpsl;
  values[p].contains_value = true;
}

void solve() {
  mt19937 gen;
  for (int i = 0; i < 100; ++i) {
    int value = gen();
    insert(value);
  }
  for (int i = 0; i < DATA_SIZE; ++i) {
    cout << values[i].contains_value << ", value=" << values[i].value << ", psl=" << values[i].psl << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
