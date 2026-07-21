# Network Renovation

**CSES ID:** 1704  
**Đề bài gốc:** https://cses.fi/problemset/task/1704  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một cây gồm $n$ máy tính là liên thông, nhưng bỏ bất kỳ cạnh nào cũng làm đứt đoạn. Hãy thêm số cạnh mới ít nhất sao cho mạng vẫn liên thông sau khi bất kỳ cạnh nào bị hỏng (trở thành 2-liên thông cạnh).

## Đầu vào
Dòng đầu: $n$. Sau đó $n-1$ dòng, mỗi dòng mô tả một cạnh cây với hai đầu mút $a,b$.

## Kết quả
In ra số liên kết mới ít nhất $k$, rồi $k$ dòng mỗi dòng mô tả một liên kết mới; bất kỳ lời giải hợp lệ nào cũng được.

## Ràng buộc
- $3 \le n \le 10^5$
- $1 \le a, b \le n$
