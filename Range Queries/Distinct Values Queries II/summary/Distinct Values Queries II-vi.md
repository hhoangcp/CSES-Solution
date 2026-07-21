# Distinct Values Queries II

**CSES ID:** 3356  
**Đề bài gốc:** https://cses.fi/problemset/task/3356  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì một mảng với hai thao tác: cập nhật một vị trí và truy vấn đoạn hỏi xem mọi giá trị trong đoạn có phân biệt không. Mỗi truy vấn đoạn trả lời YES/NO.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai chứa $n$ giá trị ban đầu. $q$ dòng tiếp theo có dạng "$1$ $k$ $u$" (gán vị trí $k$ thành $u$) hoặc "$2$ $a$ $b$" (kiểm tra đoạn $[a,b]$).

## Kết quả
Với mỗi truy vấn loại 2 in `YES` nếu mọi giá trị trong đoạn phân biệt, ngược lại in `NO`.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le x_i, u \le 10^9$
- $1 \le k \le n$
- $1 \le a \le b \le n$
