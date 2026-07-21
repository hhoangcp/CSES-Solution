# Sắp xếp theo nghịch thế

**CSES ID:** 3140  
**Đề bài gốc:** https://cses.fi/problemset/task/3140  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bài tương tác. Cần sắp xếp hoán vị ẩn của $1..n$ bằng cách liên tục đảo ngược một mảng con được chọn; sau mỗi phép, trình chấm báo số nghịch thế. Thắng khi số nghịch thế về $0$.

## Đầu vào
Đọc $n$ trước. Mỗi lượt in hai chỉ số $i, j$ để đảo mảng con đó, rồi đọc số nghịch thế mới; bằng $0$ là thành công và kết thúc.

## Kết quả
Mỗi phép toán in cặp chỉ số `i j`, mỗi lượt một phép.

## Ràng buộc
- $1 \le n \le 1000$
- tối đa $4n$ phép đảo
