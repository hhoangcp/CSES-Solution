# Filling Trominos

**CSES ID:** 2423  
**Đề bài gốc:** https://cses.fi/problemset/task/2423  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Xác định xem một lưới $n \times m$ có thể được lấp đầy bằng các tromino hình chữ L (mỗi mảnh phủ ba ô vuông). Khi có cách lấp, bạn cần đưa ra một cách và đánh dấu các ô bằng chữ cái sao cho hai ô kề nhau cùng chữ cái khi và chỉ khi chúng thuộc cùng một tromino.

## Đầu vào
Dòng đầu: số nguyên $t$ (số test). Sau đó $t$ dòng, mỗi dòng chứa hai số nguyên $n$ và $m$.

## Kết quả
Với mỗi test, in `YES` kèm theo lưới chữ cái $n \times m$ nếu có thể, ngược lại in `NO`.

## Ràng buộc
- $1 \le t \le 100$
- $1 \le n,m \le 100$
