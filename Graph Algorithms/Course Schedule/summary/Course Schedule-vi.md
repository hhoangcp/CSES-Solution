# Lịch Trình Khóa Học

**CSES ID:** 1679  
**Đề bài gốc:** https://cses.fi/problemset/task/1679  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ khóa học với $m$ điều kiện tiên quyết: khóa $a$ phải làm trước khóa $b$. Tìm một thứ tự hoàn thành hợp lệ bao gồm mọi khóa.

## Đầu vào
Hai số $n, m$, rồi $m$ dòng mỗi dòng ghi cặp tiên quyết $a$ trước $b$.

## Kết quả
Một dòng liệt kê $n$ khóa theo thứ tự hợp lệ, hoặc `IMPOSSIBLE` nếu không tồn tại.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
