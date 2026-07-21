# Course Schedule II

**CSES ID:** 1757  
**Đề bài gốc:** https://cses.fi/problemset/task/1757  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cần hoàn thành $n$ khóa học với ràng buộc trước sau dạng "khóa $a$ trước khóa $b$". Trong mọi lịch trình hợp lệ, chọn lịch hoàn thành khóa 1 sớm nhất, nếu hòa thì khóa 2, rồi khóa 3, v.v.

## Đầu vào
Dòng đầu: $n$ và $m$ (số khóa học, số ràng buộc). Sau đó $m$ dòng, mỗi dòng $a,b$ nghĩa là khóa $a$ phải trước khóa $b$. Có ít nhất một lịch trình hợp lệ.

## Kết quả
In ra một dòng gồm $n$ số nguyên: thứ tự hoàn thành các khóa học.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
