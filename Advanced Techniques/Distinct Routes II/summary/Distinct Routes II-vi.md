# Distinct Routes II

**CSES ID:** 2130  
**Đề bài gốc:** https://cses.fi/problemset/task/2130  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị có hướng có $n$ phòng và $m$ máy dịch chuyển. Mỗi ngày phải đi từ phòng $1$ đến phòng $n$, mỗi máy dịch chuyển chỉ dùng nhiều nhất một lần trong cả trò chơi. Chơi đúng $k$ ngày, mỗi lần dùng máy dịch chuyển tốn một đồng xu, tìm tổng số xu ít nhất và in $k$ tuyến đường. Nếu không khả thi, in $-1$.

## Đầu vào
Dòng đầu: $n,m,k$. Sau đó $m$ dòng, mỗi dòng hai số nguyên $a,b$ (máy dịch chuyển $a \to b$). Không có hai máy có cùng cặp điểm đầu-cuối.

## Kết quả
In tổng số xu ít nhất, rồi in mô tả $k$ tuyến đường. Nếu không khả thi, in $-1$.

## Ràng buộc
- $2 \le n \le 500$
- $1 \le m \le 1000$
- $1 \le k \le n-1$
- $1 \le a,b \le n$
