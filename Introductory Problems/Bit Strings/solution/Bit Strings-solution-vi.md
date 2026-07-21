# Bit Strings - Lời giải

**ID:** 1617 | **URL:** https://cses.fi/problemset/task/1617

## Phương pháp

### Tóm tắt bài toán

Đếm số lượng xâu nhị phân độ dài $n$ ($1 \le n \le 10^6$), kết quả lấy modulo $10^9 + 7$.

### Ý tưởng chính

Mỗi vị trí trong $n$ vị trí độc lập nhận giá trị 0 hoặc 1. Theo nguyên lý nhân, tổng số xâu là $2^n$. Vì mỗi vị trí nhân đôi số xâu có thể, đây là đáp án duy nhất — không xâu nào bị bỏ sót hay đếm trùng.

Để tính $2^n \bmod (10^9+7)$, dùng tính chất $(a \cdot b) \bmod m = ((a \bmod m) \cdot (b \bmod m)) \bmod m$. Lấy modulo ở mỗi bước nhân không làm thay đổi kết quả cuối cùng mà giữ giá trị trung gian nhỏ, ngăn tràn số. Tính đúng đắn được đảm bảo: sau $k$ bước, biến tích lũy giữ giá trị $2^k \bmod m$ (quy nạp — cơ sở $k=0$: giá trị = 1 = $2^0$; bước: $2^k \bmod m \cdot 2 \bmod m = 2^{k+1} \bmod m$).

### Thuật toán

**Nhân lặp (dùng trong code):** Khởi tạo `power = 1`. Lặp $n$ lần: `power = power * 2 % mod`. Thời gian: $O(n)$.

**Lũy thừa nhị phân (cho $n$ lớn hơn):** $2^n = (2^{n/2})^2$ nếu $n$ chẵn, $2 \cdot 2^{n-1}$ nếu $n$ lẻ. Mỗi bước giảm $n$ đi một nửa, thời gian $O(\log n)$. Với $n \le 10^6$, nhân lặp đã đủ nhanh và đơn giản hơn.

### Ví dụ minh họa

$n = 3$: $2^3 = 8$. 8 xâu nhị phân là 000, 001, 010, 011, 100, 101, 110, 111.

## Độ phức tạp

- **Thời gian:** $O(n)$ (nhân lặp) / $O(\log n)$ (lũy thừa nhị phân)
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Bit%20Strings.cpp)
