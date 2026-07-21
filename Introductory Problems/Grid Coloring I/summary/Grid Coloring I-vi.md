# Grid Coloring I

**CSES ID:** 3311  
**Đề bài gốc:** https://cses.fi/problemset/task/3311  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Lưới $n\times m$ chứa các ký tự `A`, `B`, `C`, hoặc `D`. Hãy thay ký tự mỗi ô bằng một ký tự khác trong cùng bảng chữ cái sao cho không có hai ô kề nhau (theo cạnh) giống ký tự. In ra một cách tô lại hợp lệ bất kỳ, hoặc `IMPOSSIBLE` nếu không có cách.

## Đầu vào
Dòng đầu: hai số nguyên $n$ và $m$. Tiếp theo $n$ dòng mỗi dòng $m$ ký tự mô tả lưới.

## Kết quả
In ra $n$ dòng mỗi dòng $m$ ký tự là lưới đã tô lại, hoặc `IMPOSSIBLE` nếu không có lời giải.

## Ràng buộc
- $1 \le n, m \le 500$
