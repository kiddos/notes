use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeSet;

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
    let n = read_int::<i32>();
    let p = read_vec::<i32>();
    let mut lose: BTreeSet<i32> = BTreeSet::new();
    let mut win: BTreeSet<i32> = BTreeSet::new();

    let mut ans = 0;
    for i in 0..n {
        let x = p[i as usize];
        if !win.is_empty() && *win.first().unwrap() < x {
            lose.insert(x.clone());
        } else {
            if !lose.is_empty() && *lose.first().unwrap() < x {
                win.insert(x.clone());
                ans += 1;
            } else {
                lose.insert(x.clone());
            }
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
