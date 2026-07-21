# Grid Puzzle I

**CSES ID:** 2432  
**Đề bài gốc:** https://cses.fi/problemset/task/2432  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong lưới $n \times n$, đánh dấu các ô sao cho hàng $i$ có đúng $a_i$ ô được chọn và cột $j$ có đúng $b_j$ ô được chọn. In ra bất kỳ cách đánh dấu hợp lệ hoặc báo không thể.

## Đầu vào
Dòng đầu: $n$. Dòng tiếp theo: $a_1,\dots,a_n$. Dòng cuối: $b_1,\dots,b_n$.

## Kết quả
$n$ dòng gồm `X` (chọn) và `.` (không chọn), hoặc chỉ in `-1` nếu không thể.

## Ràng buộc
- $1 \le n \le 50$
- $0 \le a_i \le n$
- $0 \le b_j \le n$
