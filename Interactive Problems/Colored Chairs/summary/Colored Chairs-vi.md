# Ghế nhiều màu

**CSES ID:** 3273  
**Đề bài gốc:** https://cses.fi/problemset/task/3273  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bài tương tác. Có $n$ ghế xếp vòng, mỗi ghế màu đỏ hoặc xanh, cần tìm hai ghế kề nhau cùng màu. Vì $n$ lẻ nên chắc chắn tồn tại cặp như vậy. Bạn hỏi màu từng ghế một.

## Đầu vào
Đọc $n$ trước. Giao thức: in `? i` để biết màu ghế $i$ (`R`/`B`); in `! i` để trả lời ghế $i$ và $i+1$ cùng màu (quay vòng).

## Kết quả
Các truy vấn màu và dòng trả lời cuối, flush sau mỗi dòng.

## Ràng buộc
- $3 \le n \le 2 \cdot 10^5$, $n$ lẻ
- tối đa $20$ truy vấn `?`
