# Tuyến Tin Nhắn

**CSES ID:** 1667  
**Đề bài gốc:** https://cses.fi/problemset/task/1667  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị vô hướng gồm $n$ máy tính và $m$ kết nối. Tìm đường đi ngắn nhất (ít máy nhất) từ máy $1$ đến máy $n$ và báo cáo độ dài cùng dãy đỉnh.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh vô hướng $a, b$.

## Kết quả
Số máy tối thiểu trên tuyến kèm dãy đỉnh, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
