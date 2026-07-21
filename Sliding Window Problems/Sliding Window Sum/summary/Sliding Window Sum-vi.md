# Sliding Window Sum

**CSES ID:** 3220  
**Đề bài gốc:** https://cses.fi/problemset/task/3220  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mảng được sinh chứ không đọc, với $x_1=x$ và $x_i=(ax_{i-1}+b)\bmod c$ từ tham số $x,a,b,c$. Với mỗi cửa sổ trượt kích thước $k$ tính tổng phần tử, rồi in ra xor của tất cả các tổng đó.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: bốn số nguyên $x,a,b,c$ của bộ sinh.

## Kết quả
In ra một số nguyên: xor của tất cả $n-k+1$ tổng mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
