# Prüfer Code

**CSES ID:** 1134  
**Đề bài gốc:** https://cses.fi/problemset/task/1134  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Mã Prüfer của một cây $n$ đỉnh là dãy dài $n-2$ xây bằng cách liên tục loại bỏ lá có nhãn nhỏ nhất và ghép nhãn của đỉnh kề duy nhất của nó. Cho mã đó, dựng lại cây có nhãn ban đầu.

## Đầu vào
Dòng đầu: $n$. Dòng hai: $n-2$ số nguyên của mã Prüfer.

## Kết quả
In ra $n-1$ dòng, mỗi dòng hai đầu mút của một cạnh $a,b$; bất kỳ thứ tự cạnh nào cũng được.

## Ràng buộc
- $3 \le n \le 2 \cdot 10^5$
- $1 \le a, b \le n$
