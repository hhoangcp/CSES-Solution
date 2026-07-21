# Replace with Difference

**CSES ID:** 3159  
**Đề bài gốc:** https://cses.fi/problemset/task/3159  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Xuất phát từ mảng $n$ số nguyên, thực hiện $n-1$ thao tác: mỗi lần chọn hai số, xóa cả hai và thêm $|a-b|$, đến khi còn một số. Tìm dãy thao tác để số cuối cùng là 0, hoặc báo không thể.

## Đầu vào
Dòng đầu: $n$. Dòng tiếp theo: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
$n-1$ dòng mỗi dòng ghi hai số được chọn, hoặc chỉ in `-1` nếu không thể. Bất kỳ lời giải hợp lệ đều được.

## Ràng buộc
- $2 \le n \le 1000$
- $1 \le x_i \le 1000$
