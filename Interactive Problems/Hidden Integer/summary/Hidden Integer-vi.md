# Số nguyên ẩn

**CSES ID:** 3112  
**Đề bài gốc:** https://cses.fi/problemset/task/3112  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bài tương tác. Có số nguyên bí mật $x$ trong $[1, 10^9]$, cần tìm bằng truy vấn so sánh: bạn đưa $y$ và biết $y < x$ hay không.

## Đầu vào
Giao thức: in `? y` để hỏi $y < x$ (trình chấm trả `YES`/`NO`); in `! x` để báo kết quả rồi kết thúc.

## Kết quả
Các truy vấn so sánh và câu trả lời cuối, flush sau mỗi dòng.

## Ràng buộc
- $1 \le x \le 10^9$
- tối đa $30$ truy vấn `?`
