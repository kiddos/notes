use std::io;
use std::str::FromStr;
use std::fmt::Debug;

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
    let n = read_int::<i32>();
    let s = read_str();

    let mut l: i32;
    let mut r: i32;
    if n % 2 == 1 {
        r = n / 2;
        l = r;
    } else {
        r = n/ 2;
        l = r-1;
    }

    let b = s.as_bytes();
    while r + 1 < n && b[(r as usize)+1] == b[r as usize] {
        r += 1
    }
    while l - 1 >= 0 && b[(l as usize)-1] == b[l as usize] {
        l -= 1;
    }
    let ans = r - l + 1;
    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
