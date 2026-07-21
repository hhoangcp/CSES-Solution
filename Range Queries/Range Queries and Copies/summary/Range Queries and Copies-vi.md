# Range Queries and Copies

**CSES ID:** 1737  
**Đề bài gốc:** https://cses.fi/problemset/task/1737  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì danh sách mảng (ban đầu có một) và xử lý ba thao tác: gán giá trị tại một vị trí của mảng đã chọn, truy vấn tổng đoạn của mảng đã chọn, và thêm bản sao của một mảng có sẵn vào cuối danh sách.

## Đầu vào
Dòng đầu chứa kích thước mảng $n$ và số truy vấn $q$. Dòng hai liệt kê mảng ban đầu. $q$ dòng truy vấn có dạng "1 $k$ $a$ $x$" (gán), "2 $k$ $a$ $b$" (tổng), hoặc "3 $k$" (sao chép).

## Kết quả
In kết quả mỗi truy vấn tính tổng.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i, x \le 10^9$
- $1 \le a \le b \le n$
