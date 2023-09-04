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
    let inputs = read_vec::<i32>();
    let n = inputs[0];
    let k = inputs[1];
    let a = read_vec::<i64>();
    let mut b: Vec<i64> = a.iter().enumerate().map(|(i, x)| x + (i as i64) + 1).collect();
    let mut ans: i64 = a.iter().sum();

    b.sort();
    b.reverse();

    for i in 0..(k as i64) {
        ans -= b[i as usize];
        ans += n as i64;
        ans -= i;
    }

    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
