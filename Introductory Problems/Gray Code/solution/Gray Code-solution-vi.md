# Gray Code - Lời giải

**ID:** 2205 | **URL:** https://cses.fi/problemset/task/2205

## Phương pháp

### Tóm tắt bài toán

Tạo ra tất cả $2^n$ xâu bit độ dài $n$ ($1 \le n \le 16$) sao cho hai xâu liên tiếp khác nhau đúng một bit (dãy mã Gray).

### Ý tưởng chính

Hai phương pháp xây dựng dãy mã Gray:

**Phương pháp 1: Phản xạ (dùng trong code).** Xây dựng $G(n)$ từ $G(n-1)$: thêm "0" vào đầu mỗi xâu trong $G(n-1)$ tạo nửa đầu, thêm "1" vào đầu mỗi xâu trong $G(n-1)$ đảo ngược tạo nửa sau. Công thức: $G(n) = 0 \cdot G(n-1) + 1 \cdot \overline{G(n-1)}$.

*Tính đúng đắn:* Trong mỗi nửa, hai xâu liên tiếp khác nhau đúng 1 bit vì hậu tố của chúng đến từ các phần tử liên tiếp trong $G(n-1)$ (hoặc đảo của nó), khác nhau đúng 1 bit theo giả thiết quy nạp. Tại ranh giới, xâu cuối nửa đầu ($0 \cdot a_{cuối}$) và xâu đầu nửa sau ($1 \cdot a_{cuối}$) có cùng hậu tố, chỉ khác bit đầu.

**Phương pháp 2: Công thức trực tiếp.** Xâu mã Gray thứ $i$ (đánh số từ 0) là $g(i) = i \oplus (i \gg 1)$. Khi $i \to i+1$, bit duy nhất thay đổi trong mã Gray tương ứng với bit 1 thấp nhất của $i+1$ — tất cả thay đổi khác trong $i$ và $i \gg 1$ triệt tiêu nhau dưới XOR. Do đó hai mã liên tiếp khác nhau đúng 1 bit.

### Thuật toán

1. Khởi tạo $G = \{"0", "1"\}$.
2. Với mỗi bước từ 2 đến $n$: nhân đôi $G$ theo thứ tự ngược với tiền tố "1" rồi thêm vào; thêm tiền tố "0" vào mỗi phần tử nửa gốc.
3. Xuất tất cả xâu trong $G$.

### Ví dụ minh họa

$n = 2$: $G(1) = \{"0", "1"\}$. Nửa đầu: $\{"00", "01"\}$. Nửa sau: $\{"11", "10"\}$. Kết quả: 00, 01, 11, 10.

## Độ phức tạp

- **Thời gian:** $O(2^n \cdot n)$
- **Không gian:** $O(2^n \cdot n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Gray%20Code.cpp)
