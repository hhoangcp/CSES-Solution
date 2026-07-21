# Grid Completion

**CSES ID:** 2429  
**Đề bài gốc:** https://cses.fi/problemset/task/2429  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Xây lưới $n \times n$ mà mỗi hàng và cột chứa đúng một `A` và một `B`. Một số ô đã được điền sẵn; có thể giả sử chưa hàng/cột nào quá một `A` hoặc một `B`. Hãy đếm số cách điền các ô còn lại, modulo $10^9+7$.

## Đầu vào
Dòng đầu chứa $n$. Tiếp theo là $n$ dòng, mỗi dòng $n$ ký tự (`.` là ô trống, hoặc `A`/`B`).

## Kết quả
In một số nguyên, số cách hoàn thành hợp lệ modulo $10^9+7$.

## Ràng buộc
- $2 \le n \le 500$
