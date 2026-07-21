# Filling Trominos - Lời giải

**ID:** 2423 | **URL:** https://cses.fi/problemset/task/2423

## Hướng tiếp cận

### Phát biểu lại bài toán

Lấp đầy lưới $n \times m$ bằng các L-tromino (ba ô hình chữ L) sao cho các ô kề nhau có cùng ký tự khi và chỉ khi chúng thuộc cùng một tromino. Xuất kết quả lát hoặc kết luận không thể.

### Trường hợp không khả thi

Một L-tromino phủ đúng 3 ô, nên $nm$ phải chia hết cho 3. Tuy nhiên, điều kiện này chưa đủ:

- **Cả hai chiều đều không chia hết cho 3:** Nếu $n \bmod 3 \ne 0$ và $m \bmod 3 \ne 0$, thì $nm \bmod 3 \ne 0$, không thể lát.
- **$n = 1$ hoặc $m = 1$:** L-tromino cần ít nhất 2 hàng và 2 cột.
- **Lưới $3 \times m$ với $m$ lẻ:** Khi tô màu lưới theo mẫu 3-màu lặp lại, số ô mỗi màu chênh lệch khi $m$ lẻ, khiến việc lát không thể.

Để đơn giản hóa, ta luôn đảm bảo $m$ chia hết cho 3 bằng cách **xoay lưới** (đổi $n$ và $m$) nếu cần. Sau khi xoay, nếu $m$ vẫn không chia hết cho 3, xuất `NO`.

### Các khối xây dựng

Cấu trúc dựa trên hai khối cơ bản, mỗi khối được phủ bởi đúng 2 L-tromino:

- **Khối $2 \times 3$:** Hai tromino lát theo chiều ngang.
- **Khối $3 \times 2$:** Hai tromino lát theo chiều dọc.

Cho trường hợp khó nhất (cả hai chiều lẻ), ta dùng thêm một mẫu **$5 \times 9$** được tính trước, gồm các khối nhỏ hơn và các tromino được đặt thủ công.

### Cấu trúc lát

Sau khi đảm bảo $m \bmod 3 = 0$ bằng cách xoay:

- **$n$ chẵn, $m$ chẵn:** Lấp toàn bộ lưới bằng khối $2 \times 3$ (bước nhảy 2 hàng, 3 cột).
- **$n$ lẻ, $m$ chẵn:** Lấp 3 hàng đầu bằng khối $3 \times 2$, sau đó lấp các hàng còn lại (số hàng chẵn) bằng khối $2 \times 3$.
- **$n$ lẻ, $m$ lẻ:** Đặt mẫu $5 \times 9$ tại góc trên trái. Lấp hàng từ 6 trở đi bằng khối $2 \times 3$, cột từ 10 trở đi bằng khối $3 \times 2$, và vùng giữa (hàng 4+, cột 10+) bằng khối $2 \times 3$.

Mỗi khối xây dựng phủ diện tích chia hết cho 3, và các vùng không chồng lấn chia hết lưới, nên tổng diện tích luôn đúng.

### Gắn nhãn

Mỗi tromino được gán ký tự theo mẫu lặp $5 \times 5$: `Get_char(x, y) = 'A' + ((x-1) mod 5) · 5 + (y-1) mod 5`. Vì mọi khối xây dựng ($2 \times 3$, $3 \times 2$, $5 \times 9$) đều nằm trong biên $5 \times 5$, các tromino kề nhau luôn nhận nhãn khác nhau.

### Ví dụ minh họa

$n = 4, m = 6$ (cả hai chẵn): lát bằng khối $2 \times 3$.

```
AAHDDF
AHHDFF
KKRNNP
KRRNPP
```

8 L-tromino, mỗi tromino gồm 3 ô kề nhau có cùng ký tự.

$n = 4, m = 7$: sau khi xoay, $m \bmod 3 \ne 0$ → `NO`.

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$ mỗi test case
- **Bộ nhớ:** $O(n \cdot m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Filling%20Trominos.cpp)
