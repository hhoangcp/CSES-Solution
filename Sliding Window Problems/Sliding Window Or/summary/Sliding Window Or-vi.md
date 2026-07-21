# Sliding Window Or

**CSES ID:** 3405  
**Đề bài gốc:** https://cses.fi/problemset/task/3405  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mảng quá lớn không đọc trực tiếp mà được sinh từ $x,a,b,c$ với $x_1=x$ và $x_i=(ax_{i-1}+b)\bmod c$. Với mỗi cửa sổ trượt kích thước $k$ tính OR bitwise của các phần tử, rồi in ra xor của tất cả các OR đó.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: bốn số nguyên $x,a,b,c$ của bộ sinh.

## Kết quả
In ra một số nguyên: xor của tất cả $n-k+1$ OR mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
