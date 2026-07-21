# Letter Pair Move Game

**CSES ID:** 2427  
**Đề bài gốc:** https://cses.fi/problemset/task/2427  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một hàng $2n$ hộp có hai hộp trống kề nhau; các hộp còn lại chứa chữ "A" và "B" (mỗi loại $n-1$). Một nước đi trượt cặp chữ cái liền kề vào hai ô trống kề nhau, giữ nguyên thứ tự. Cần đưa về cấu hình mọi "A" đứng trước mọi "B" trong tối đa $1000$ nước, hoặc thông báo vô nghiệm.

## Đầu vào
Số nguyên $n$, rồi chuỗi $2n$ ký tự gồm `A`, `B`, và `.`.

## Kết quả
In ra số nước đi, theo sau là cấu hình sau mỗi nước, hoặc `-1` nếu không giải được.

## Ràng buộc
- $1 \le n \le 100$
