use std::io;
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn solve() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s = s.trim().to_string();

    if s == "()" {
        println!("NO");
        return;
    }

    let n = s.len();
    let mut found = false;
    for i in 1..n {
        if s.chars().nth(i) == s.chars().nth(i-1) {
            found = true;
            break;
        }
    }

    let mut ans = String::new();
    if found {
        for _i in 0..n {
            ans += "()";
        }
    } else {
        ans = "(".repeat(n) + &")".repeat(n);
    }

    println!("YES");
    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
