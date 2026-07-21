# MST Edge Cost

**CSES ID:** 3409  
**Đề bài gốc:** https://cses.fi/problemset/task/3409  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Với mỗi cạnh của một đồ thị vô hướng có trọng số, liên thông và đơn, tính chi phí cây khung nhỏ nhất bắt buộc bao gồm cạnh đó.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng $a, b, w$ mô tả một cạnh vô hướng có trọng số.

## Kết quả
Với mỗi cạnh theo thứ tự đầu vào, in ra chi phí MST nhỏ nhất khi bắt buộc bao gồm cạnh đó.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le w \le 10^9$
