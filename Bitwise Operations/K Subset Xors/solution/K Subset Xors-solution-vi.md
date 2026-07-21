# K Subset Xors - Lời giải

**ID:** 3192 | **URL:** https://cses.fi/problemset/task/3192

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, tìm $k$ giá trị XOR tập con nhỏ nhất (bao gồm tập rỗng với XOR bằng 0), in theo thứ tự không giảm.

### Ý tưởng chính

Xây dựng **cơ sở tuyến tính** từ các phần tử mảng. Cơ sở có hạng $sz$, sinh ra $2^{sz}$ giá trị XOR phân biệt. Vì mỗi giá trị phân biệt xuất hiện $2^{n-sz}$ lần trong tổng $2^n$ tập con, ta ánh xạ giá trị đầu ra thứ $i$ sang giá trị XOR phân biệt nhỏ thứ $\lceil i / 2^{n-sz} \rceil$, truy xuất bằng cách duyệt cơ sở rút gọn kiểu tìm kiếm nhị phân.

### Thuật toán

1. **Xây cơ sở XOR (từ bit cao xuống thấp):** Duy trì `basis[i]` lưu vector cơ sở có bit dẫn đầu $i$. Với mỗi phần tử, khử các bit cao hơn bằng XOR với vector cơ sở hiện có (duyệt bit 29 xuống 0). Nếu phần tử chưa bị triệt, nó trở thành vector cơ sở mới. Thứ tự từ cao xuống thấp đảm bảo `basis[i]` có bit $i$ là bit cao nhất, đủ cho bước truy vấn — khi bật/tắt bit $i$ qua `basis[i]`, các bit thấp hơn bị ảnh hưởng sẽ được sửa ở các bước sau.
2. **Xử lý lặp lại:** Mỗi giá trị XOR phân biệt xuất hiện $len = 2^{n-sz}$ lần. Nếu $n - sz \ge 20$, thì $len > k$ và mọi giá trị đầu ra đều là 0. Ngược lại, giá trị đầu ra thứ $i$ là `query(⌈i/len⌉)`.
3. **Truy vấn XOR phân biệt nhỏ thứ $k$:** Đặt $tot = 2^{sz}$. Duyệt cơ sở từ bit cao xuống thấp. Tại mỗi `basis[i]`:
   - $mid = tot / 2$: nửa dưới có bit $i$ = 0, nửa trên có bit $i$ = 1.
   - Nếu $k > mid$ (nửa trên) và bit $i$ của `mask` bằng 0: XOR `mask` với `basis[i]`.
   - Nếu $k \le mid$ (nửa dưới) và bit $i$ của `mask` bằng 1: XOR `mask` với `basis[i]`.
   - Nếu $k > mid$: $k \mathrel{-}= mid$.
   - $tot \mathrel{>>}= 1$.
   
   Tính đúng đảm bảo vì thuộc tính bit dẫn đầu khiến bit $i$ là yếu tố quyết định tại mỗi mức, chia không gian XOR đã sắp thành hai nửa.

### Ví dụ minh họa

Đầu vào: $n = 4$, mảng $[3, 5, 14, 8]$, $k = 9$.

**Xây cơ sở:**
- Chèn 3: `basis[1] = 3` (011), $sz = 1$.
- Chèn 5: bit 2 chưa có cơ sở → `basis[2] = 5` (101), $sz = 2$.
- Chèn 14: bit 3 chưa có cơ sở → `basis[3] = 14` (1110), $sz = 3$.
- Chèn 8: $8 \oplus 14 = 6$, $6 \oplus 5 = 3$, $3 \oplus 3 = 0$ → phụ thuộc tuyến tính, không chèn.

$sz = 3$, $len = 2^{4-3} = 2$.

**Giá trị XOR phân biệt** (qua `query(1)` đến `query(8)`): 0, 3, 5, 6, 8, 11, 13, 14.

**Kết quả** ($k = 9$, mỗi giá trị lặp 2 lần): `0 0 3 3 5 5 6 6 8`.

## Độ phức tạp

- **Thời gian:** $O(n \cdot 30 + k \cdot 30)$
- **Không gian:** $O(30)$

## Mã nguồn (C++)

[Mã nguồn](../code/K%20Subset%20Xors.cpp)
