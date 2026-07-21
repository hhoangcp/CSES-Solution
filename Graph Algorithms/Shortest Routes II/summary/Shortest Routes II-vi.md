# Tuyến Đường Ngắn Nhất II

**CSES ID:** 1672  
**Đề bài gốc:** https://cses.fi/problemset/task/1672  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị vô hướng có trọng số gồm $n$ thành phố và $m$ con đường. Trả lời $q$ truy vấn hỏi độ dài đường đi ngắn nhất giữa hai thành phố, hoặc $-1$ nếu không đến được.

## Đầu vào
$n$, $m$, $q$, rồi $m$ cạnh vô hướng $a, b$ độ dài $c$, rồi $q$ dòng mỗi dòng cho một cặp truy vấn $a, b$.

## Kết quả
Khoảng cách ngắn nhất cho mỗi truy vấn, hoặc $-1$.

## Ràng buộc
- $1 \le n \le 500$
- $1 \le m \le n^2$
- $1 \le q \le 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
