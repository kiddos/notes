use std::io;
use std::io::Write;

fn read_int() -> i32 {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    return s.trim().parse().expect("invalid input");
}

fn query(l: i32, r: i32) -> i32 {
    if l == r {
        return 0;
    }

    println!("? {} {}\n", l, r);
    io::stdout().flush().unwrap();
    return read_int();
}

fn divide(l: i32, r : i32) -> i32 {
    if l == r {
        return l;
    }

    let mid = (l + r) / 2;
    let i = divide(l, mid);
    let j = divide(mid+1, r);
    let q1 = query(l, j-1);
    let q2 = query(l, j);
    if q1 == q2 {
        return j;
    }

    i
}

fn solve() {
    let n = read_int();
    let ans = divide(1, n);
    println!("! {}\n", ans);
    io::stdout().flush().unwrap();
}

fn main() {
    let n = read_int();
    for _t in 0..n {
        solve();
    }
}
