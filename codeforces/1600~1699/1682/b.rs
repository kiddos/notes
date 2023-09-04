use std::io;
use std::str::FromStr;
use std::fmt::Debug;

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

fn solve() {
    let n = read_int::<usize>();
    let a = read_vec::<i32>();

    let mut ans = !0;
    for i in 0..n {
        if i as i32 != a[i] {
            ans &= a[i];
        }
    }
    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
