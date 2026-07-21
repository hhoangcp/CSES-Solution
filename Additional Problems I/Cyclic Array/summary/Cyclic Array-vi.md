# Cyclic Array

**CSES ID:** 1191  
**Đề bài gốc:** https://cses.fi/problemset/task/1191  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho mảng tròn $n$ giá trị dương. Hãy chia thành ít nhất đoạn liên tiếp (được phép vòng quanh) sao cho tổng mỗi đoạn không vượt $k$. Đảm bảo không có phần tử đơn lẻ nào lớn hơn $k$.

## Đầu vào
Các số nguyên $n$ và $k$, rồi $n$ giá trị mảng.

## Kết quả
In ra số đoạn tối thiểu.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le k \le 10^{18}$
