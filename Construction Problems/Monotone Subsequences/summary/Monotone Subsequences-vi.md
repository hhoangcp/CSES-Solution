# Monotone Subsequences

**CSES ID:** 2215  
**Đề bài gốc:** https://cses.fi/problemset/task/2215  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Với mỗi test, xây dựng một hoán vị của $1,2,\dots,n$ mà dãy con đơn điệu (tăng hoặc giảm) dài nhất có độ dài đúng bằng $k$. Dãy con đơn điệu là dãy toàn tăng hoặc toàn giảm.

## Đầu vào
Dòng đầu: số nguyên $t$. Sau đó $t$ dòng, mỗi dòng chứa hai số nguyên $n$ và $k$.

## Kết quả
Với mỗi test in một hoán vị hợp lệ, hoặc `IMPOSSIBLE` nếu không tồn tại.

## Ràng buộc
- $1 \le t \le 1000$
- $1 \le k \le n \le 100$
