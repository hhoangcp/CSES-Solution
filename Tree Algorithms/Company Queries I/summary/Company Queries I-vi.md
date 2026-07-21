# Company Queries I

**CSES ID:** 1687  
**Đề bài gốc:** https://cses.fi/problemset/task/1687  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Nhân viên của một công ty tạo thành một cây có gốc, mỗi người (trừ tổng giám đốc) có đúng một sếp trực tiếp. Mỗi truy vấn yêu cầu đi lên cây phân cấp một số bậc cho trước từ một nhân viên và cho biết tổ tiên tương ứng.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng tiếp theo cho sếp của mỗi nhân viên $2 \dots n$ (chỉ số sếp nhỏ hơn nhân viên). Sau đó là $q$ dòng, mỗi dòng gồm nhân viên $x$ và số bậc $k$.

## Kết quả
Với mỗi truy vấn in ra tổ tiên cao hơn $k$ bậc của $x$, hoặc $-1$ nếu không có.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le e_i \le i-1$
- $1 \le x \le n$
- $1 \le k \le n$
