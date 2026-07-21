# Truy vấn chuỗi đối xứng

**CSES ID:** 2420  
**Đề bài gốc:** https://cses.fi/problemset/task/2420  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn được cho chuỗi độ dài $n$ (đánh số từ 1) và phải xử lý một dãy thao tác. Thao tác cập nhật thay đổi ký tự tại một vị trí đã chọn, thao tác truy vấn hỏi một khoảng cho trước có phải là chuỗi đối xứng hay không.

## Đầu vào
Dòng đầu chứa hai số nguyên $n$ và $m$. Dòng tiếp theo là chuỗi $n$ ký tự. Sau đó là $m$ dòng thao tác dạng "1 $k$ $x$" (cập nhật vị trí $k$ thành ký tự $x$) hoặc "2 $a$ $b$" (truy vấn đoạn $[a,b]$).

## Kết quả
Với mỗi thao tác loại 2, in "YES" nếu đoạn truy vấn là chuỗi đối xứng, ngược lại in "NO".

## Ràng buộc
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le k \le n$
- $1 \le a \le b \le n$
