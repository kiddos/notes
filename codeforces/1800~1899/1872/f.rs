use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::LinkedList;
use std::cmp::min;

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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let mut a = read_vec::<usize>();
    let mut c = read_vec::<i32>();

    a.insert(0, 0);
    c.insert(0, 0);

    let mut fears: Vec<i32> = vec![0; n+1];
    for i in 1..=n {
        fears[a[i]] += 1;
    }

    let mut q = LinkedList::new();
    let mut visited = vec![false; n+1];
    for i in 1..=n {
        if fears[i] == 0 {
            q.push_back(i);
            visited[i] = true;
        }
    }

    let mut ans = Vec::new();
    while !q.is_empty() {
        let mut size = q.len() as i32;
        while size > 0 {
            let node = q.pop_front().unwrap();
            ans.push(node);

            let parent = a[node];
            fears[parent] -= 1;
            if fears[parent] == 0 {
                q.push_back(parent);
                visited[parent] = true;
            }

            size -= 1;
        }
    }

    for i in 1..=n {
        if !visited[i] {
            let mut x = i;
            let mut cycle = Vec::new();
            let mut min_cost: i32 = i32::MAX;
            while !visited[x] {
                visited[x] = true;
                min_cost = min(min_cost, c[x]);
                cycle.push(x);

                x = a[x];
            }

            for j in 0..cycle.len() {
                let node = cycle[j];
                if c[node] == min_cost {
                    for k in j+1..cycle.len() {
                        ans.push(cycle[k]);
                    }
                    for k in 0..=j {
                        ans.push(cycle[k]);
                    }

                    break;
                }
            }
        }
    }

    for i in 0..ans.len() {
        write!(writer, "{} ", ans[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
