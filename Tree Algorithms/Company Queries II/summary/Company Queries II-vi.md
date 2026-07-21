# Company Queries II

**CSES ID:** 1688  
**Đề bài gốc:** https://cses.fi/problemset/task/1688  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Nhân viên tạo thành hệ thống phân cấp dạng cây có gốc với tổng giám đốc ở gốc. Mỗi truy vấn cho hai nhân viên và hỏi tổ tiên chung thấp nhất — sếp sâu nhất là tổ tiên của cả hai.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng tiếp theo cho sếp của mỗi nhân viên $2 \dots n$. Sau đó $q$ dòng, mỗi dòng gồm hai nhân viên $a$ và $b$.

## Kết quả
Với mỗi truy vấn in ra sếp chung thấp nhất của $a$ và $b$.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le e_i \le i-1$
- $1 \le a,b \le n$
