# Increasing Array Queries

**CSES ID:** 2416  
**Đề bài gốc:** https://cses.fi/problemset/task/2416  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn có thể tăng một phần tử mảng lên 1 (mỗi lần tăng là một thao tác). Với mỗi truy vấn trên mảng con $[a,b]$, hãy báo cáo số thao tác tăng tối thiểu để mảng con đó không giảm (mỗi phần tử $\ge$ phần tử trước).

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai chứa các giá trị mảng. $q$ dòng tiếp theo mỗi dòng cho hai đầu mút $a$ và $b$ của một mảng con.

## Kết quả
Với mỗi truy vấn in số thao tác tăng tối thiểu cần thiết.

## Ràng buộc
- $1 \le n,q \le 2\cdot10^5$
- $1 \le x_i \le 10^9$
- $1 \le a \le b \le n$
