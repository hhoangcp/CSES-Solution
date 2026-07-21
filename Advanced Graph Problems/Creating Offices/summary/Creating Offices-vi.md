# Creating Offices

**CSES ID:** 1752  
**Đề bài gốc:** https://cses.fi/problemset/task/1752  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một cây gồm $n$ thành phố (số cạnh $n-1$, có đường đi duy nhất giữa hai thành phố, khoảng cách là số cạnh trên đường đi đó). Một công ty muốn mở văn phòng tại một tập con các thành phố sao cho khoảng cách giữa hai thành phố được chọn ít nhất là $d$. Tìm số văn phòng tối đa và một tập con như vậy.

## Đầu vào
Dòng đầu: $n$ và $d$. Sau đó $n-1$ dòng, mỗi dòng mô tả một cạnh cây với hai đầu mút $a,b$.

## Kết quả
In ra số lượng tối đa $k$ rồi đến các thành phố được chọn (bất kỳ tập tối ưu nào cũng được).

## Ràng buộc
- $1 \le n, d \le 2 \cdot 10^5$
- $1 \le a, b \le n$
