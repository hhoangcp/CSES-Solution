# Điểm cao thứ K

**CSES ID:** 3305  
**Đề bài gốc:** https://cses.fi/problemset/task/3305  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bài tương tác. Hai đội $n$ lập trình viên (Phần Lan, Thụy Điển) có $2n$ điểm khác nhau; cần tìm điểm cao thứ $k$ tổng thể. Mỗi truy vấn chọn quốc gia và thứ hạng $i$ để nhận điểm cao thứ $i$ của quốc gia đó.

## Đầu vào
Đọc $n$ và $k$ trước. Giao thức: in `F i` để lấy điểm cao thứ $i$ của Phần Lan, `S i` của Thụy Điển, và `! s` để báo điểm cao thứ $k$ tổng thể rồi kết thúc.

## Kết quả
Các truy vấn quốc gia-thứ hạng và câu trả lời cuối, flush sau mỗi dòng.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le k \le 2n$
- điểm trong $[1, 10^9]$, đôi một khác nhau
- tối đa $100$ truy vấn `F`/`S` tổng cộng
