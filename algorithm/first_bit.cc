#include <bits/stdc++.h>

// find the most significant bit set

using namespace std;

int fls(int x) {
  // Note: open Cutter to see this
  // this get translate into bsr instruction
  //
  // or edi, 1
  // bsr eax, edi
  //
  // so edi is x
  // bsr stands for Bit Scan Reverse
  // which finds the first set bit index
  //
  // if there is a Bit Scan Reverse
  // there should also be a Bit Scane Forward
  // which is __builtin_ctz
  return (sizeof(int) << 3) - 1 - __builtin_clz(x);
}

void test(int x) {
  cout << bitset<32>(x) << " -> " << fls(x) << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  test(1302973);
  test(~0);
  test(4);
  test(0);

  return 0;
}
