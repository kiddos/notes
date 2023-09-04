use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

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
    let inputs = read_vec::<i64>();
    let n = inputs[0] as usize;
    let k = inputs[1];
    let a = read_vec::<i64>();

    if k <= n as i64 {
        let mut p: Vec<i64> = vec![0];
        for i in 0..n {
            p.push(p.last().unwrap() + a[i]);
        }
        let mut ans: i64 = 0;
        for i in 0..=n-(k as usize) {
            ans = max(ans, p[i+(k as usize)] - p[i]);
        }
        ans += k * (k-1) / 2;
        println!("{}", ans);
    } else {
        let mut ans: i64 = a.iter().sum();
        ans += (k-1 + k-(n as i64)) * (n as i64) / 2; 
        println!("{}", ans);
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
