# Chuyến Đi Vòng Quanh II

**CSES ID:** 1678  
**Đề bài gốc:** https://cses.fi/problemset/task/1678  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng, tìm một chu trình đơn (đầu cuối trùng nhau, đỉnh trung gian phân biệt) và xuất dãy đỉnh, hoặc thông báo không tồn tại.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$.

## Kết quả
Độ dài chu trình $k$ kèm $k$ đỉnh, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
