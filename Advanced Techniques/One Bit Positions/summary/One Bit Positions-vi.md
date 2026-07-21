# One Bit Positions

**CSES ID:** 2112  
**Đề bài gốc:** https://cses.fi/problemset/task/2112  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho chuỗi nhị phân độ dài $n$, với mỗi khoảng cách $k$ từ $1$ đến $n-1$, đếm số cặp vị trí $(i,j)$ thỏa $i-j=k$ và cả hai vị trí đều là bit `1`.

## Đầu vào
Một dòng duy nhất chứa chuỗi nhị phân gồm các ký tự `0` và `1`.

## Kết quả
In $n-1$ số nguyên, số đếm tương ứng với $k=1,\ldots,n-1$.

## Ràng buộc
- $2 \le n \le 2 \cdot 10^5$
