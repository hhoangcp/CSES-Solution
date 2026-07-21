# Tìm Chu Trình

**CSES ID:** 1197  
**Đề bài gốc:** https://cses.fi/problemset/task/1197  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho đồ thị có hướng có trọng số, kiểm tra xem có chu trình tổng trọng số âm hay không, nếu có thì in ra một chu trình dạng dãy đỉnh.

## Đầu vào
$n$ và $m$, rồi $m$ dòng mỗi dòng ghi cạnh $a \to b$ với trọng số $c$.

## Kết quả
`YES` kèm theo các đỉnh của chu trình theo thứ tự, hoặc `NO` nếu không có chu trình âm.

## Ràng buộc
- $1 \le n \le 2500$
- $1 \le m \le 5000$
- $1 \le a,b \le n$
- $-10^9 \le c \le 10^9$
