# Two Stacks Sorting

**CSES ID:** 2402  
**Đề bài gốc:** https://cses.fi/problemset/task/2402  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho hoán vị của $1,\dots,n$ dưới dạng luồng đầu vào. Dùng hai ngăn xếp để tạo dãy đã sắp $1,2,\dots,n$: mỗi bước hoặc đẩy giá trị đầu vào tiếp theo vào một ngăn xếp, hoặc lấy đỉnh ngăn xếp ra kết quả. Với mỗi giá trị in ra ngăn xếp (1 hoặc 2) nhận nó, hoặc báo không thể.

## Đầu vào
Dòng đầu: $n$. Dòng thứ hai: $n$ số nguyên, danh sách đầu vào.

## Kết quả
In $n$ số nguyên (1 hoặc 2) chỉ ngăn xếp nhận mỗi giá trị đầu vào, hoặc `IMPOSSIBLE` nếu không có lời giải.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
