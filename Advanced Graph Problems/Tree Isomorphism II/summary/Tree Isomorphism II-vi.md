# Tree Isomorphism II

**CSES ID:** 1701  
**Đề bài gốc:** https://cses.fi/problemset/task/1701  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho hai cây không gốc trên cùng $n$ đỉnh có nhãn, với mỗi test quyết định xem chúng có đồng cấu (giống nhau đến mức đổi nhãn, không cố định gốc) hay không.

## Đầu vào
Dòng đầu: $t$ test. Với mỗi test: một số nguyên $n$, rồi $n-1$ cạnh của cây 1, rồi $n-1$ cạnh của cây 2.

## Kết quả
Với mỗi test, in ra `YES` nếu hai cây đồng cấu, ngược lại `NO`.

## Ràng buộc
- $1 \le t \le 1000$
- $2 \le n \le 10^5$
- tổng tất cả $n$ không vượt quá $10^5$
