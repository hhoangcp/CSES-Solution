# System of Linear Equations

**CSES ID:** 3154  
**Đề bài gốc:** https://cses.fi/problemset/task/3154  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Giải hệ $n$ phương trình tuyến tính $m$ ẩn trên trường $\mathbb{Z}/(10^9+7)\mathbb{Z}$. Tìm nghiệm bất kỳ $x_1, \dots, x_m$ (với $0 \le x_i < 10^9+7$), hoặc báo không có nghiệm.

## Đầu vào
Dòng đầu chứa $n$ và $m$. $n$ dòng tiếp theo mỗi dòng có $m+1$ số $a_{i,1}, \dots, a_{i,m}, b_i$ (hệ số và vế phải).

## Kết quả
In $m$ giá trị nghiệm, hoặc chỉ in $-1$ nếu không có nghiệm.

## Ràng buộc
- $1 \le n, m \le 500$
- $0 \le a_{i,j}, b_i < 10^9+7$
