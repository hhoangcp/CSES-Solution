# Xor Pyramid Diagonal

**CSES ID:** 3194  
**Đề bài gốc:** https://cses.fi/problemset/task/3194  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một kim tự tháp xor có hàng đáy là các số, mỗi ô ở trên là xor của hai ô ngay bên dưới. Cho hàng đáy, hãy in giá trị trái nhất của mỗi hàng từ dưới lên trên.

## Đầu vào
Dòng đầu: số nguyên $n$. Dòng sau: $n$ số nguyên $a_1,\dots,a_n$ (hàng đáy).

## Kết quả
In $n$ số nguyên: các giá trị trái nhất của các hàng từ dưới lên trên.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
