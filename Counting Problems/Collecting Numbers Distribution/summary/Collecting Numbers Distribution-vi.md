# Collecting Numbers Distribution

**CSES ID:** 3157  
**Đề bài gốc:** https://cses.fi/problemset/task/3157  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mỗi vòng quét hoán vị của $1 \dots n$ từ trái qua phải, thu nhặt dãy tăng dài nhất có thể bắt đầu từ giá trị nhỏ nhất chưa được nhặt, lặp lại cho đến khi thu đủ tất cả. Với mỗi $k=1,\dots,n$, hãy đếm trong $n!$ hoán vị có bao nhiêu hoán vị cần đúng $k$ vòng. Đáp án lấy modulo $10^9+7$.

## Đầu vào
Một dòng duy nhất chứa số nguyên $n$.

## Kết quả
In $n$ giá trị, số hoán vị cần đúng $k$ vòng, theo modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 5000$
