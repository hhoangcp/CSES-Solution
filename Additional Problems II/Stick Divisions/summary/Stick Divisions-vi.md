# Stick Divisions

**CSES ID:** 1161  
**Đề bài gốc:** https://cses.fi/problemset/task/1161  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có thanh gỗ độ dài $x$ cần chia thành $n$ thanh có độ dài cho trước $d_i$, tổng bằng $x$. Mỗi lần chia một thanh thành hai với chi phí bằng độ dài thanh bị chia. Tìm tổng chi phí nhỏ nhất.

## Đầu vào
Dòng đầu: $x$ và $n$. Dòng thứ hai: $n$ số nguyên $d_1,\dots,d_n$.

## Kết quả
Một số nguyên: chi phí nhỏ nhất của phép chia.

## Ràng buộc
- $1 \le x \le 10^9$
- $1 \le n \le 2 \cdot 10^5$
- $\sum d_i = x$
