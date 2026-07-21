# Visible Buildings Queries

**CSES ID:** 3304  
**Đề bài gốc:** https://cses.fi/problemset/task/3304  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ tòa nhà xếp hàng, bạn đứng bên trái tòa đầu; một tòa nhìn được nếu cao hơn mọi tòa trước nó. Với mỗi truy vấn trên đoạn $[a,b]$, hãy báo số tòa nhìn được nếu chỉ đoạn đó tồn tại.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê chiều cao các tòa. $q$ dòng tiếp theo mỗi dòng cho hai đầu mút $a$ và $b$.

## Kết quả
Với mỗi truy vấn in số tòa nhìn được.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le q \le 2 \cdot 10^5$
- $1 \le h_i \le 10^9$
- $1 \le a \le b \le n$
