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
    let mut t: Vec<String> = Vec::new();
    for _i in 0..(n*2+1) {
        let s = read_str();
        t.push(s);
    }

    for i in b'a'..=b'z' {
        let ch = i as char;
        let mut count = 0;
        for s in &t {
            for c in s.chars() {
                if c == ch {
                    count += 1;
                }
            }
        }

        if count % 2 == 1 {
            println!("{}", ch);
        }
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
