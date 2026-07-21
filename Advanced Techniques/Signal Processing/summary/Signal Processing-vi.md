# Signal Processing

**CSES ID:** 2113  
**Đề bài gốc:** https://cses.fi/problemset/task/2113  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho dãy tín hiệu độ dài $n$ và mặt nạ độ dài $m$. Trượt mặt nạ qua tín hiệu từ trái sang phải; tại mỗi vị trí, tính tổng các tích của các phần tử tín hiệu và mặt nạ chồng nhau.

## Đầu vào
Dòng đầu: $n,m$. Dòng hai: $n$ số nguyên $a_1,\ldots,a_n$ (tín hiệu). Dòng ba: $m$ số nguyên $b_1,\ldots,b_m$ (mặt nạ).

## Kết quả
In $n+m-1$ số nguyên, tổng căn chỉnh từ vị trí trái nhất đến phải nhất.

## Ràng buộc
- $1 \le n,m \le 2 \cdot 10^5$
- $1 \le a_i,b_i \le 100$
