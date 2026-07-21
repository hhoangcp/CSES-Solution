# Stick Difference

**CSES ID:** 3401  
**Đề bài gốc:** https://cses.fi/problemset/task/3401  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ thanh gỗ có độ dài nguyên. Thực hiện đúng $k$ lần cắt (mỗi lần chia một thanh thành hai phần nguyên dương), thu được $n+k$ thanh, với $k=1,\dots,m$. Với mỗi $k$ cực tiểu hiệu giữa thanh dài nhất và ngắn nhất.

## Đầu vào
Dòng đầu: $n$ và $m$. Dòng thứ hai: $n$ số nguyên $a_1,\dots,a_n$.

## Kết quả
Một dòng $m$ số nguyên: hiệu nhỏ nhất ứng với $k=1,\dots,m$ lần cắt.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a_i \le 10^9$
