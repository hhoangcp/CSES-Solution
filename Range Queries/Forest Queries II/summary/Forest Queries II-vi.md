# Forest Queries II

**CSES ID:** 1739  
**Đề bài gốc:** https://cses.fi/problemset/task/1739  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Giống bản tĩnh nhưng nay có thể chuyển trạng thái từng ô giữa trống/cây, và vẫn cần trả lời truy vấn đếm cây trong hình chữ nhật.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Tiếp theo $n$ dòng mỗi dòng $n$ ký tự (`.`/`*`) mô tả lưới. $q$ dòng truy vấn có dạng "$1$ $y$ $x$" (đảo trạng thái ô) hoặc "2 $y_1$ $x_1$ $y_2$ $x_2$" (đếm cây trong hình chữ nhật).

## Kết quả
In kết quả mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n \le 1000$
- $1 \le q \le 2 \cdot 10^5$
- $1 \le y,x \le n$
- $1 \le y_1 \le y_2 \le n$
- $1 \le x_1 \le x_2 \le n$
