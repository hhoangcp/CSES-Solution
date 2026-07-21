# Sửa Chữa Đường

**CSES ID:** 1675  
**Đề bài gốc:** https://cses.fi/problemset/task/1675  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 128MB

> Tóm tắt đề bài.

Đồ thị vô hướng có trọng số gồm $n$ thành phố và $m$ đường ứng viên, mỗi đường có chi phí sửa. Chọn đường để sửa sao cho các thành phố liên thông với tổng chi phí nhỏ nhất.

## Đầu vào
$n$ và $m$, rồi $m$ dòng mỗi dòng cho cạnh $a, b$ với chi phí $c$.

## Kết quả
Tổng chi phí sửa tối thiểu, hoặc `IMPOSSIBLE` nếu không thể liên thông.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
