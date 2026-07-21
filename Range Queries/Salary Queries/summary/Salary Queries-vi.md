# Salary Queries

**CSES ID:** 1144  
**Đề bài gốc:** https://cses.fi/problemset/task/1144  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một công ty có $n$ nhân viên, mỗi người có mức lương có thể thay đổi theo thời gian. Truy vấn hỏi có bao nhiêu nhân viên hiện có lương trong đoạn $[a,b]$.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê lương ban đầu. $q$ dòng tiếp theo có dạng `!` $k$ $x$ (gán lương nhân viên $k$ thành $x$) hoặc `?` $a$ $b$ (đếm lương trong $[a,b]$).

## Kết quả
In kết quả mỗi truy vấn `?`.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le p_i \le 10^9$
- $1 \le k \le n$
- $1 \le x \le 10^9$
- $1 \le a \le b \le 10^9$
