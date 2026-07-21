# Maximum Xor Subset - Lời giải

**ID:** 3191 | **URL:** https://cses.fi/problemset/task/3191

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, tìm tổng XOR lớn nhất của một tập con bất kỳ (không cần liên tiếp).

### Ý tưởng chính

Tập hợp tất cả XOR tập con tạo thành **không gian vector trên GF(2)** (trường nhị phân), trong đó phép cộng là XOR. Ta cần tìm vector có giá trị số lớn nhất trong không gian này. **Phép khử Gaussian trên GF(2)** đưa mảng về cơ sở dạng bậc thang hàng rút gọn (RREF), từ đó đáp án đơn giản là XOR tất cả các phần tử khác 0.

### Thuật toán

**Khử Gaussian đưa về RREF:** Xử lý các bit từ cao nhất (bit 30) xuống thấp nhất (bit 0):

1. **Chọn trục:** Tại vị trí bit $i$, tìm phần tử có bit $i$ bằng 1 (trong số các phần tử chưa dùng làm trục). Nếu không có, bỏ qua. Đổi chỗ phần tử đó vào vị trí ranh giới $l$ và tăng $l$.
2. **Khử:** XOR phần tử trục vào **mọi** phần tử khác (cả trước và sau trục) có bit $i$ bằng 1. Đây là khử RREF — không chỉ khử thuận — đảm bảo bit $i$ chỉ xuất hiện ở đúng một phần tử.
3. **Lặp lại** cho tất cả vị trí bit.

Sau khi khử, mỗi phần tử khác 0 có **bit dẫn đầu duy nhất** (bit 1 cao nhất), và không phần tử nào khác có bit đó.

**Tính đáp án:** XOR tất cả phần tử khác 0 cho kết quả XOR tập con lớn nhất.

### Tại sao XOR toàn bộ cơ sở là tối ưu

Sau RREF, gọi các trục có bit dẫn đầu là $b_1 > b_2 > \cdots > b_m$. Tính chất quan trọng: **bit $b_k$ chỉ xuất hiện ở đúng một trục** (trục thứ $k$). Do đó, với mọi XOR tập con $v = \bigoplus_{k \in S} P_k$, bit $b_k$ của $v$ bằng 1 khi và chỉ khi $k \in S$.

Giả sử chọn tập $S \neq \{1, \ldots, m\}$, tức bỏ qua một trục nào đó. Gọi $k^*$ là chỉ số lớn nhất bị bỏ. Khi đó bit $b_{k^*}$ của kết quả bằng 0. Mọi số nguyên có bit $b_{k^*} = 0$ đều có giá trị tối đa $2^{b_{k^*}} - 1$. Nhưng XOR **tất cả** các trục có bit $b_{k^*} = 1$, nên giá trị ít nhất là $2^{b_{k^*}}$. Vì $2^{b_{k^*}} > 2^{b_{k^*}} - 1$, việc bỏ bất kỳ trục nào đều cho kết quả nhỏ hơn. Vậy XOR toàn bộ cơ sở là tối ưu.

### Ví dụ minh họa

Đầu vào: $n = 4$, mảng $[1, 6, 12, 6]$ (nhị phân: 0001, 0110, 1100, 0110).

**Bit 3:** Trục = 12 (1100). Không phần tử nào khác có bit 3. Mảng: `[12, 6, 1, 6]`, $l=1$.

**Bit 2:** Trục = 6 (0110) tại vị trí 1. Khử bit 2 khỏi mọi phần tử khác:
- $12 \oplus 6 = 10$ (1010): có bit 2 → đã khử.
- Số 6 thứ hai: $6 \oplus 6 = 0$: có bit 2 → đã khử.
- 1 (0001): không có bit 2 → giữ nguyên.

Mảng: `[10, 6, 1, 0]`, $l=2$.

**Bit 1:** Không phần tử nào từ vị trí 2 trở đi có bit 1. Bỏ qua.

**Bit 0:** Trục = 1 (0001) tại vị trí 2. Không phần tử nào khác có bit 0 (10=1010, 6=0110 đều có bit 0 bằng 0). Mảng không đổi: `[10, 6, 1, 0]`.

**Cơ sở:** $\{10, 6, 1\}$ với các bit dẫn đầu duy nhất:
- $10 = \mathbf{1}010_2$ (bit dẫn đầu 3)
- $6 = 0\mathbf{1}10_2$ (bit dẫn đầu 2)
- $1 = 000\mathbf{1}_2$ (bit dẫn đầu 0)

**Đáp án:** $10 \oplus 6 \oplus 1 = 1010 \oplus 0110 \oplus 0001 = 1101_2 = 13$.

Chú ý: bit 1 ($2^1$) không thể xuất hiện trong bất kỳ XOR tập con nào — để bật nó cần một vector có bit dẫn đầu 1, nhưng không có vector nào như vậy trong cơ sở.

## Độ phức tạp

- **Thời gian:** $O(n \cdot 31)$ — 31 vị trí bit, mỗi vị trí quét và khử trên $n$ phần tử
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Xor%20Subset.cpp)
