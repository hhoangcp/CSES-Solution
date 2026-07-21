# Line Segments Trace I

**CSES ID:** 3427  
**Đề bài gốc:** https://cses.fi/problemset/task/3427  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ đoạn thẳng đều trải từ $x=0$ đến $x=m$ với độ dốc nguyên, mỗi đoạn nối $(0,y_1)$ và $(m,y_2)$. Với mỗi số nguyên $x \in [0,m]$ cần tìm giá trị $y$ lớn nhất mà bất kỳ đoạn nào đạt tới tại cột đó.

## Đầu vào
Dòng đầu hai số nguyên $n$ và $m$, sau đó $n$ dòng mỗi dòng hai số nguyên $y_1, y_2$ mô tả hai đầu mút của một đoạn.

## Kết quả
In ra $m+1$ số nguyên: giá trị lớn nhất tương ứng với $x=0,1,\dots,m$.

## Ràng buộc
- $1 \le n, m \le 10^5$
- $0 \le y_1, y_2 \le 10^9$
