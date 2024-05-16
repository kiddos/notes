use std::io::{stdin, stdout, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn query(l: i64, r: i64) -> i64 {
    println!("? {} {}", l, r);
    stdout().flush().unwrap();
    read_int()
}

fn find_i(l: i64, r: i64) -> i64 {
    let mut l = l;
    let mut r = r;
    let mut ans = l;
    while l <= r{
        let mid = l + (r-l) / 2;
        let result = query(1, mid);
        if result <= 0 {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    ans
}

fn solve() {
    let n = read_int::<i64>();
    let i = find_i(1, n);
    let total_inversion = query(1, n);
    let len1 = total_inversion - query(i+1, n);
    let j = i + len1 + 1;
    let p1 = len1 * (len1 + 1) / 2;
    let p2 = total_inversion - p1;
    let len2 = (((8 * p2 + 1) as f64).sqrt() as i64 - 1) / 2;
    let k = j + len2;
    println!("! {} {} {}", i, j, k);
    stdout().flush().unwrap();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
