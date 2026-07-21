# Mountain Range

**CSES ID:** 3314  
**Đề bài gốc:** https://cses.fi/problemset/task/3314  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ ngọn núi xếp hàng với chiều cao cho trước. Bắt đầu từ một ngọn, bạn có thể bay lượn từ $a$ sang $b$ nếu $a$ cao hơn $b$ và cao hơn mọi ngọn ở giữa. Hãy tìm số ngọn tối đa đi được trên một hành trình.

## Đầu vào
Một số nguyên $n$, rồi $n$ chiều cao $h_1,\dots,h_n$.

## Kết quả
Số ngọn núi tối đa trên hành trình.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le h_i \le 10^9$
