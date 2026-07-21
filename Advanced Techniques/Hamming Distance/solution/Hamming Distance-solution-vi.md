# Hamming Distance - Lời giải

**ID:** 2136 | **URL:** https://cses.fi/problemset/task/2136

## Phương pháp

### Tóm tắt bài toán

Khoảng cách Hamming giữa hai chuỗi cùng độ dài là số vị trí mà chúng khác nhau. Cho $n$ chuỗi bit độ dài $k$, tìm khoảng cách Hamming nhỏ nhất giữa hai chuỗi bất kỳ.

### Ý tưởng chính

Vì $k \le 30$, mỗi chuỗi bit vừa trong một số nguyên 32-bit. Mã hóa mỗi chuỗi thành số nguyên với bit $j$ đặt 1 nếu vị trí $j$ là '1'. Khi đó khoảng cách Hamming giữa hai chuỗi bằng $\text{popcount}(a_i \oplus a_j)$: XOR cho bit 1 tại đúng các vị trí khác nhau, popcount đếm số vị trí đó.

Với $n \le 2 \times 10^4$, có $\binom{n}{2} \approx 2 \times 10^8$ cặp. Mỗi phép XOR + popcount mất khoảng 1 chu kỳ CPU nhờ hỗ trợ phần cứng, nên duyệt tất cả cặp chạy trong khoảng 0.2 giây — đủ nhanh.

### Thuật toán

1. Mã hóa mỗi chuỗi bit thành số nguyên 32-bit.
2. Với mọi cặp $(i, j)$, $i < j$: tính $\operatorname{popcount}(a[i] \oplus a[j])$ và theo dõi giá trị nhỏ nhất.
3. Xuất kết quả nhỏ nhất.

### Ví dụ minh họa

5 chuỗi độ dài 6: `110111`, `001000`, `100001`, `101000`, `101110`.

- `101000` vs `001000`: chỉ khác tại vị trí 0 → khoảng cách Hamming = 1.
- `110111` vs `001000`: khác tất cả 6 vị trí → khoảng cách = 6.
- `100001` vs `101000`: khác tại vị trí 2 và 5 → khoảng cách = 2.

Tối thiểu = 1.

## Độ phức tạp

- **Thời gian:** $O(n^2)$ — với popcount phần cứng, hằng số rất nhỏ.
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Hamming%20Distance.cpp)
