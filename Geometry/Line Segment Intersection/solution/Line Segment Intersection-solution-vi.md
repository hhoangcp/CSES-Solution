# Line Segment Intersection - Lời giải

**ID:** 2190 | **URL:** https://cses.fi/problemset/task/2190

## Phương pháp

### Tóm tắt bài toán

Cho hai đoạn thẳng, xác định xem chúng có cắt nhau (có ít nhất một điểm chung) hay không.

### Ý tưởng chính

Dùng tích có hướng để xác định hướng. Với ba điểm $A, B, C$:

$$\text{cross}(A, B, C) = (B_x - A_x)(C_y - A_y) - (B_y - A_y)(C_x - A_x)$$

Dương nghĩa là $C$ nằm bên trái $\overrightarrow{AB}$, âm nghĩa là bên phải, không nghĩa là thẳng hàng.

Hai đoạn $P_1P_2$ và $P_3P_4$ cắt nhau khi và chỉ khi thỏa một trong hai điều kiện:

**Điều kiện 1 — Nằm hai bên:** Các đầu mút của mỗi đoạn nằm về hai phía đường thẳng chứa đoạn kia, tức $\text{sign}(\text{cross}(P_1, P_2, P_3)) \ne \text{sign}(\text{cross}(P_1, P_2, P_4))$ và $\text{sign}(\text{cross}(P_3, P_4, P_1)) \ne \text{sign}(\text{cross}(P_3, P_4, P_2))$. Điều này đúng vì nếu mỗi đoạn có đầu mút nằm hai bên đường kia, hai đường cắt tại điểm duy nhất nằm trên cả hai đoạn. Khi một tích có hướng bằng 0 và tích kia khác 0, vẫn tính là khác dấu (một đầu mút nằm trên đường).

**Điều kiện 2 — Thẳng hàng và chồng lấp:** Khi một số tích có hướng bằng 0, các điểm có thể thẳng hàng. Khi đó hai đoạn cắt nhau nếu một đầu mút của đoạn này nằm trên đoạn kia. Điểm $C$ nằm trên đoạn $AB$ khi $\text{cross}(A, C, B) = 0$ và tọa độ $C$ nằm trong bao giới hạn bởi $A$ và $B$. Mọi trường hợp giao nhau đều thuộc một trong hai điều kiện: cắt tại điểm trong thỏa điều kiện 1, cắt tại đầu mút hoặc chồng lấp thỏa điều kiện 2.

### Thuật toán

1. Tính $d_1 = \text{cross}(P_1, P_3, P_2)$, $d_2 = \text{cross}(P_1, P_4, P_2)$, $d_3 = \text{cross}(P_3, P_1, P_4)$, $d_4 = \text{cross}(P_3, P_2, P_4)$.
2. Nếu $d_1$ và $d_2$ khác dấu VÀ $d_3$ và $d_4$ khác dấu (0 được coi là khớp cả hai dấu), xuất YES.
3. Ngược lại, nếu có đầu mút nào nằm trên đoạn kia (kiểm tra bằng `On_Segment`), xuất YES.
4. Ngược lại, xuất NO.

### Ví dụ minh họa

Từ 5 test của đề bài, đều dùng $P_1=(1,1), P_2=(5,3)$:

| Test | $P_3$ | $P_4$ | $d_1$ | $d_2$ | $d_3$ | $d_4$ | Kết quả |
|------|-------|-------|-------|-------|-------|-------|---------|
| 1 | $(1,2)$ | $(4,3)$ | $-4$ | $-2$ | $3$ | $1$ | NO (cùng dấu) |
| 2 | $(1,1)$ | $(4,3)$ | $0$ | $-2$ | $0$ | $2$ | YES ($P_1$ trên $P_3P_4$) |
| 3 | $(2,3)$ | $(4,1)$ | $-6$ | $6$ | $6$ | $-6$ | YES (khác dấu) |
| 4 | $(2,4)$ | $(4,1)$ | $-10$ | $6$ | $9$ | $-7$ | YES (khác dấu) |
| 5 | $(3,2)$ | $(7,4)$ | $0$ | $0$ | — | — | YES ($P_2$ trên $P_3P_4$) |

Test 1: $d_1, d_2$ cùng dấu → không nằm hai bên; không có đầu mút trên đoạn kia → NO.
Test 2: $d_1 = 0$ → cặp nằm hai bên thỏa; $P_1$ trùng $P_3$ (nằm trên $P_3P_4$) → YES.
Test 3: Cả hai cặp đều khác dấu → YES.
Test 5: $d_1 = d_2 = 0$ → không nằm hai bên; $P_2=(5,3)$ nằm trên $P_3P_4$ (thẳng hàng, trong bao) → YES.

## Độ phức tạp

- **Thời gian:** $O(1)$ mỗi test
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Line%20Segment%20Intersection.cpp)
