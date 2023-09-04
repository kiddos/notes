use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];
    let mut carpet: Vec<String> = Vec::new();
    for _i in 0..n {
        carpet.push(read_str());
    }
    let v = "vika";
    let mut k: usize = 0;
    for j in 0..m {
        for i in 0..n {
            if carpet[i].as_bytes()[j] == v.as_bytes()[k] {
                k += 1;
                break;
            }
        }

        if k == v.len() {
            writeln!(writer, "YES").ok();
            return;
        }
    }

    writeln!(writer, "NO").ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
