use std::io;
use std::cmp::max;

fn read_int() -> i32 {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    return s.trim().parse::<i32>().expect("invalid input");
}

fn read_vec() -> Vec<i64> {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|s| s.trim().parse::<i64>().expect("invalid input")).collect()
}

fn solve() {
    let n = read_int();
    let mut a: Vec<Vec<i64>> = Vec::new();
    for _i in 0..n {
        let _m = read_int();
        let mut row = read_vec();
        row.sort();
        a.push(row);
    }

    a.sort_by_key(|row| row[0]);

    let mut first: i64 = 0;
    for i in 0..n {
        if i == 0 {
            first += a[i as usize][0];
        } else {
            first += a[i as usize][1];
        }
    }

    let mut ans: i64 = first;

    let mut second: i64 = 0;
    for i in 0..n {
        second += a[i as usize][1];
    }
    for i in 1..n {
        let new_ans: i64 = second - a[i as usize][1] + a[0][0];
        ans = max(ans, new_ans);
    }

    println!("{}", ans);
}

fn main() {
    let t = read_int();
    for _t in 0..t {
        solve();
    }
}
