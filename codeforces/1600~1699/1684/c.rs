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
    let inputs = read_vec::<i32>();
    let n = inputs[0] as usize;
    let m = inputs[1] as usize;

    let mut a: Vec<Vec<i32>> = Vec::new();
    for _i in 0..n {
        let row = read_vec::<i32>();
        a.push(row);
    }


    let mut s: BTreeSet<(usize,usize)> = BTreeSet::new();
    for i in 0..n {
        let mut row = a[i].clone();
        let mut index: Vec<usize> = Vec::new();
        row.sort();

        let mut diff = 0;
        for j in 0..m {
            if row[j] != a[i][j] {
                diff += 1;
                index.push(j);
            }
        }

        if diff != 2 && diff != 0 {
            println!("-1");
            return;
        }

        if diff == 2 {
            s.insert((index[0]+1, index[1]+1));
        }
    }

    if s.is_empty() {
        println!("1 1");
    } else if s.len() > 1 {
        println!("-1");
    } else {
        let index = s.pop_first().unwrap();
        let i1 = index.0 - 1;
        let i2 = index.1 - 1;
        for i in 0..n {
            a[i].swap(i1, i2);
            for j in 1..m {
                if a[i][j-1] > a[i][j] {
                    println!("-1");
                    return;
                }
            }
        }

        println!("{} {}", index.0, index.1);
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
