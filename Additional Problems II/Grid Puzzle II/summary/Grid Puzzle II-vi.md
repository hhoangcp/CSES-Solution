# Grid Puzzle II

**CSES ID:** 2131  
**Đề bài gốc:** https://cses.fi/problemset/task/2131  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Lưới $n \times n$ có $c_{ij}$ đồng xu mỗi ô. Chọn các ô sao cho hàng $i$ có đúng $a_i$ ô chọn và cột $j$ có đúng $b_j$ ô chọn, sao cho tổng đồng xu thu được lớn nhất.

## Đầu vào
Dòng đầu: $n$. Dòng tiếp theo: $a_1,\dots,a_n$. Dòng tiếp theo: $b_1,\dots,b_n$. Sau đó $n$ dòng mỗi dòng $n$ số nguyên $c_{ij}$.

## Kết quả
Đầu tiên in tổng đồng xu lớn nhất, sau đó $n$ dòng `X`/`.` mô tả ô được chọn, hoặc chỉ in `-1` nếu không khả thi.

## Ràng buộc
- $1 \le n \le 50$
- $0 \le a_i \le n$
- $0 \le b_j \le n$
- $0 \le c_{ij} \le 1000$
