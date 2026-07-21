# Chuyến Đi Vòng Quanh

**CSES ID:** 1669  
**Đề bài gốc:** https://cses.fi/problemset/task/1669  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị vô hướng, tìm chu trình đơn độ dài ít nhất 3 (đầu cuối trùng nhau, đỉnh trung gian phân biệt) và xuất dãy đỉnh, hoặc thông báo không tồn tại.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh vô hướng $a, b$.

## Kết quả
Độ dài chu trình $k$ kèm $k$ đỉnh, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
