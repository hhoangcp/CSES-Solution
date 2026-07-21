# Parcel Delivery

**CSES ID:** 2121  
**Đề bài gốc:** https://cses.fi/problemset/task/2121  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mạng có hướng gồm $n$ thành phố và $m$ tuyến, tuyến $a\to b$ có sức chứa $r$ bưu kiện, mỗi kiện giá $c$. Gửi đúng $k$ bưu kiện từ thành phố $1$ (Syrjälä) đến thành phố $n$ (Lehmälä) với tổng chi phí nhỏ nhất, hoặc báo không khả thi bằng $-1$.

## Đầu vào
Dòng đầu: $n,m,k$. Sau đó $m$ dòng, mỗi dòng bốn số nguyên $a,b,r,c$ mô tả một tuyến.

## Kết quả
In tổng chi phí nhỏ nhất, hoặc $-1$ nếu không có lời giải.

## Ràng buộc
- $2 \le n \le 500$
- $1 \le m \le 1000$
- $1 \le k \le 100$
- $1 \le a,b \le n$
- $1 \le r,c \le 1000$
