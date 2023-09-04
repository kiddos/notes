use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{min, max};

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_str() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let s = read_str();
    let raw = s.as_bytes();

    let ones = s.matches("1").count();
    let n = s.len();
    let mut right = ones;
    let mut left = 0;
    let mut middle = 0;
    let mut ans = ones;
    let mut j = 0;
    for i in 0.. n {
        if raw[i] == b'1' {
            right -= 1;
        } else if raw[i] == b'0' {
            middle += 1;
        }

        while j < i && left + right < middle {
            if raw[j] == b'1' {
                left += 1;
            } else if raw[j] == b'0' {
                middle -= 1;
            }
            j += 1;
        }

        let cost = max(left + right, middle);
        ans = min(ans, cost);
    }

    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
