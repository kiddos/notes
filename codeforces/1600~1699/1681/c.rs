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
    let mut a = read_vec::<i32>();
    let mut b = read_vec::<i32>();

    let mut ans: Vec<(usize,usize)> = Vec::new();

    let mut c = a.clone();
    c.sort();
    for i in 0..n {
        if a[i] != c[i] {
            for j in (i+1)..n {
                if a[j] == c[i] {
                    a.swap(i, j);
                    b.swap(i, j);
                    ans.push((i+1, j+1));
                    break;
                }
            }
        }
    }

    c = b.clone();
    c.sort();
    for i in 0..n {
        if b[i] != c[i] {
            for j in (i+1)..n {
                if b[j] == c[i] {
                    a.swap(i, j);
                    b.swap(i, j);
                    ans.push((i+1, j+1));
                    break;
                }
            }
        }
    }

    for i in 1..n {
        if a[i-1] > a[i] {
            println!("-1");
            return;
        }
    }

    println!("{}", ans.len());
    for i in 0..ans.len() {
        println!("{} {}", ans[i].0, ans[i].1);
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
