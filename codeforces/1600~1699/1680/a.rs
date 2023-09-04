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
    let l1 = inputs[0];
    let r1 = inputs[1];
    let l2 = inputs[2];
    let r2 = inputs[3]; 

    let ans;
    if l1 == r1 && l2 == r2 {
        if l1 == l2 {
            ans = l1;
        } else {
            ans = l1 + l2;
        }
    } else if l1 == r1 {
        if l1 >= l2 && l1 <= r2 {
            ans = l1;
        } else {
            ans = l1+l2;
        }
    } else if l2 == r2 {
        if l2 >= l1 && l2 <= r1 {
            ans = l2;
        } else {
            ans = l1+l2;
        }
    } else {
        if l1 >= l2 {
            if l1 <= r2 {
                ans = l1;
            } else {
                ans = l1 + l2;
            }
        } else {
            if l2 <= r1 {
                ans = l2;
            } else {
                ans = l1 + l2;
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
