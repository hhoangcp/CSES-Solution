# Tuyến Bay Dài Nhất

**CSES ID:** 1680  
**Đề bài gốc:** https://cses.fi/problemset/task/1680  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong đồ thị có hướng không chu trình, tìm đường đi dài nhất từ thành phố $1$ đến thành phố $n$ theo số thành phố ghé qua, và xuất đường đó.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$ (đồ thị không chu trình).

## Kết quả
Số thành phố tối đa trên tuyến kèm danh sách đỉnh, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
