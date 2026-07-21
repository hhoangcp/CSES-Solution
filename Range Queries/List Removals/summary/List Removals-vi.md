# List Removals

**CSES ID:** 1749  
**Đề bài gốc:** https://cses.fi/problemset/task/1749  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn bắt đầu với danh sách $n$ số nguyên và phải xóa từng phần tử, mỗi lần xóa theo vị trí tính trong danh sách hiện tại (đang rút ngắn). In ra các giá trị bị xóa theo thứ tự xóa.

## Đầu vào
Dòng đầu chứa $n$. Dòng hai liệt kê $n$ phần tử danh sách. Dòng ba liệt kê $n$ vị trí xóa $p_1,\dots,p_n$ (vị trí trong danh sách hiện tại).

## Kết quả
In các phần tử bị xóa theo thứ tự xóa.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $1 \le p_i \le n-i+1$
