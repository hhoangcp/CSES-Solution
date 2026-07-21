# Dynamic Connectivity

**CSES ID:** 2133  
**Đề bài gốc:** https://cses.fi/problemset/task/2133  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị vô hướng ban đầu có $n$ đỉnh và $m$ cạnh, theo sau là $k$ sự kiện, mỗi sự kiện thêm một cạnh mới hoặc xóa một cạnh hiện có. Sau mỗi sự kiện, báo số thành phần liên thông hiện tại (và cả số trước sự kiện đầu tiên).

## Đầu vào
Dòng đầu: $n,m,k$. Sau đó $m$ dòng mô tả cạnh ban đầu (cặp $a,b$). Sau đó $k$ dòng dạng `$t$ $a$ $b$`, $t=1$ thêm cạnh, $t=2$ xóa cạnh. Cạnh thêm không trùng, xóa chỉ áp dụng cho cạnh đang tồn tại.

## Kết quả
In $k+1$ số nguyên: số thành phần trước sự kiện đầu và sau mỗi sự kiện.

## Ràng buộc
- $2 \le n \le 10^5$
- $1 \le m,k \le 10^5$
- $1 \le a,b \le n$
