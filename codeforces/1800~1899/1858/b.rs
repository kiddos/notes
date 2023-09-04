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
    let line = read_vec::<i32>();
    let n = line[0];
    let d = line[2];

    let mut s = read_vec::<i32>();
    s.insert(0, 1);

    let mut p: Vec<i32> = vec![1];
    for i in 1..s.len() {
        let diff = s[i] - s[i-1];
        let eat = (diff + d - 1) / d;
        p.push(*p.last().unwrap() + eat);
    }

    if s[s.len()-1] != n {
        p.push(*p.last().unwrap() + (n - *s.last().unwrap()) / d);
    } else {
        p.push(*p.last().unwrap());
    }

    let mut min_val: i32 = std::i32::MAX;
    let mut amount: i32 = 0;

    for i in 1..s.len() {
        let result: i32;
        if i == s.len()-1 {
            let diff = n - s[i-1];
            let eat = diff / d;
            result = p[i-1] + eat;
        } else {
            let diff = s[i+1] - s[i-1];
            let eat = (diff + d - 1) / d;
            result = p[i-1] + *p.last().unwrap() - p[i+1] + eat;
        }

        if result < min_val {
            min_val = result;
            amount = 1;
        } else if result == min_val {
            amount += 1;
        }
    }

    println!("{} {}", min_val, amount);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
