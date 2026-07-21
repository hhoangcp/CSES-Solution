# Xor Pyramid Row

**CSES ID:** 3195  
**Đề bài gốc:** https://cses.fi/problemset/task/3195  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong một kim tự tháp xor, mỗi ô là xor của hai ô ngay bên dưới. Cho hàng đáy có $n$ phần tử và một mức mục tiêu $k$ (đếm từ trên xuống), hãy in ra $k$ giá trị trên mức đó.

## Đầu vào
Dòng đầu: hai số nguyên $n$ và $k$. Dòng sau: $n$ số nguyên $a_1,\dots,a_n$ (hàng đáy).

## Kết quả
In $k$ số nguyên: các ô trên hàng thứ $k$ tính từ trên cùng.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
