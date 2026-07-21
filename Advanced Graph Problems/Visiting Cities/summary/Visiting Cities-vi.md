# Visiting Cities

**CSES ID:** 1203  
**Đề bài gốc:** https://cses.fi/problemset/task/1203  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong một đồ thị có hướng có trọng số với các chuyến bay một chiều, tìm các thành phố nằm trên mọi tuyến đường giá rẻ nhất từ Syrjälä (thành phố 1) đến Lehmälä (thành phố $n$).

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng một chuyến bay một chiều $a \to b$ với giá $c$. Đảm bảo có đường đi từ 1 đến $n$.

## Kết quả
In ra số lượng $k$ thành phố bắt buộc, rồi $k$ chỉ số thành phố theo thứ tự tăng dần.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le c \le 10^9$
