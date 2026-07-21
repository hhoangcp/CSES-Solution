# Movie Festival Queries

**CSES ID:** 1664  
**Đề bài gốc:** https://cses.fi/problemset/task/1664  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn biết thời gian bắt đầu và kết thúc của $n$ phim. Mỗi truy vấn cho thời điểm đến và rời, hỏi số phim tối đa có thể xem trọn trong khoảng đó (chọn được phim nếu nó bắt đầu không sớm hơn lúc phim trước kết thúc, cho phép đến/rời đúng ở đầu mút khoảng).

## Đầu vào
Dòng đầu chứa $n$ và $q$. Tiếp theo $n$ dòng mỗi dòng cho bắt đầu $a$ và kết thúc $b$ của một phim. Cuối cùng $q$ dòng mỗi dòng cho thời gian đến $a$ và rời $b$.

## Kết quả
In số phim tối đa có thể xem cho mỗi truy vấn.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le a < b \le 10^6$
