# Sliding Window Median

**CSES ID:** 1076  
**Đề bài gốc:** https://cses.fi/problemset/task/1076  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho mảng, in ra trung vị của mỗi cửa sổ trượt kích thước $k$ khi dịch trái sang phải. Trung vị là phần tử giữa của cửa sổ đã sắp; nếu $k$ chẵn thì lấy phần tử nhỏ hơn trong hai phần tử giữa.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ phần tử $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ giá trị, trung vị mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
