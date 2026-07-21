# Array Description

**CSES ID:** 1746  
**Đề bài gốc:** https://cses.fi/problemset/task/1746  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một mảng có thể thiếu thông tin, mỗi phần tử nằm trong $[1,m]$ và hai phần tử liền kề chênh lệch nhiều nhất $1$ (với `0` là ô chưa biết). Hãy đếm số mảng đầy đủ thỏa mãn các ràng buộc.

## Đầu vào
Hai số nguyên $n$ và $m$, tiếp theo là $n$ giá trị $x_1,\dots,x_n$ với `0` là chưa biết.

## Kết quả
Số mảng hợp lệ modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 100$
- $0 \le x_i \le m$
