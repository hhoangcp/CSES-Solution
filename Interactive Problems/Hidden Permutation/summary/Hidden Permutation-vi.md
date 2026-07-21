# Hoán vị ẩn

**CSES ID:** 3139  
**Đề bài gốc:** https://cses.fi/problemset/task/3139  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bài tương tác. Cần khôi phục hoán vị ẩn của $1..n$ bằng truy vấn so sánh cặp: chọn hai chỉ số $i, j$ và biết $a_i < a_j$ hay không.

## Đầu vào
Đọc $n$ trước. Giao thức: in `? i j` để hỏi $a_i < a_j$ (`YES`/`NO`); in `! a_1 ... a_n` để báo hoán vị rồi kết thúc.

## Kết quả
Các truy vấn so sánh và dòng hoán vị cuối, flush sau mỗi dòng.

## Ràng buộc
- $1 \le n \le 1000$
- tối đa $10^4$ truy vấn `?`
