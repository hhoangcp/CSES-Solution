# School Excursion

**CSES ID:** 1706  
**Đề bài gốc:** https://cses.fi/problemset/task/1706  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

$n$ đứa trẻ chọn một trong hai điểm tham quan, $m$ cặp cho trước phải chọn cùng nhau. Xác định mọi tổng số có thể chọn một điểm cố định.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng mỗi dòng hai chỉ số trẻ $a$ và $b$.

## Kết quả
Chuỗi bit độ dài $n$ với bit thứ $i$ bằng 1 nếu có thể có đúng $i$ trẻ chọn điểm cố định (đánh số từ 1).

## Ràng buộc
- $1 \le n \le 10^5$
- $0 \le m \le 10^5$
- $1 \le a, b \le n$
