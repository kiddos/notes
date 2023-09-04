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
    let p = read_vec::<i32>();

    let mut ans = 0;
    let mut s: Vec<usize> = Vec::new();
    for i in 0..n {
        let mut inv = 0;
        while !s.is_empty() && p[*s.last().unwrap()] > p[i] {
            s.pop();
            inv += 1;
        }
        
        s.push(i);

        if inv >= 1 {
            ans += 1;
            s.clear();
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
