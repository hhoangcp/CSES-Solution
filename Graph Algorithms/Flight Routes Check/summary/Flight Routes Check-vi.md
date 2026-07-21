# Kiểm Tra Tuyến Bay

**CSES ID:** 1682  
**Đề bài gốc:** https://cses.fi/problemset/task/1682  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho đồ thị có hướng, kiểm tra xem mọi thành phố có đến được từ mọi thành phố khác hay không. Nếu không, đưa ra một cặp $a, b$ mà $b$ không đến được từ $a$.

## Đầu vào
$n$ và $m$, rồi $m$ cạnh có hướng $a \to b$.

## Kết quả
`YES` nếu đồ thị liên thông mạnh, ngược lại `NO` kèm theo một cặp $a, b$.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
