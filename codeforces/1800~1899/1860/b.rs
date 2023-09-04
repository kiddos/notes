use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{min, max};

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn can_fill(m: i64, k: i64, a1: i64, ak: i64) -> bool {
    let k_coin = min(m / k, ak);
    let x = k_coin * k;
    let y = a1;
    return x + y >= m;
}

fn solve() {
    let inputs = read_vec::<i64>();
    let mut m = inputs[0];
    let k = inputs[1];
    let mut a1 = inputs[2];
    let mut ak = inputs[3];

    if can_fill(m, k, a1, ak) {
        println!("0");
        return;
    }

    let mut ans = 0;
    if a1 >= m % k {
        a1 -= m % k;
        ak += a1 / k;
    } else {
        ans += (m % k) - a1;
    }
    m -= m % k;

    let k_coin = m / k;
    ans += max(k_coin - ak, 0);

    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
