# Line Segments Trace II

**CSES ID:** 3428  
**Đề bài gốc:** https://cses.fi/problemset/task/3428  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ đoạn thẳng có đầu mút nguyên và độ dốc nguyên, mỗi đoạn trải qua một khoảng ngang $[x_1, x_2] \subseteq [0,m]$. Với mỗi số nguyên $x \in [0,m]$ cần tìm giá trị $y$ lớn nhất mà các đoạn phủ cột đó đạt tới, hoặc $-1$ nếu không có đoạn nào phủ.

## Đầu vào
Dòng đầu hai số nguyên $n$ và $m$, sau đó $n$ dòng mỗi dòng bốn số nguyên $x_1, y_1, x_2, y_2$ mô tả hai đầu mút của một đoạn.

## Kết quả
In ra $m+1$ số nguyên: giá trị lớn nhất tương ứng $x=0,1,\dots,m$, dùng $-1$ khi không có đoạn.

## Ràng buộc
- $1 \le n, m \le 10^5$
- $0 \le x_1 < x_2 \le m$
- $0 \le y_1, y_2 \le 10^9$
