# Sliding Window Minimum

**CSES ID:** 3221  
**Đề bài gốc:** https://cses.fi/problemset/task/3221  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Vì dữ liệu rất lớn nên mảng được sinh chứ không đọc từng phần tử: từ tham số $x,a,b,c$ với $x_1=x$ và $x_i=(ax_{i-1}+b)\bmod c$. Với mỗi cửa sổ trượt kích thước $k$ cần tìm giá trị nhỏ nhất, nhưng thay vì in tất cả, chỉ in xor của chúng.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: bốn số nguyên $x,a,b,c$ của bộ sinh.

## Kết quả
In ra một số nguyên: xor của tất cả $n-k+1$ giá trị nhỏ nhất mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 10^7$
- $0 \le x, a, b \le 10^9$
- $1 \le c \le 10^9$
