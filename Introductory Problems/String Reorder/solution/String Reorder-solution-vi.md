# String Reorder - Lời giải

**ID:** 1743 | **URL:** https://cses.fi/problemset/task/1743

## Hướng tiếp cận

### Tóm tắt bài toán

Sắp xếp lại xâu chữ cái hoa A–Z sao cho không có hai ký tự kề nhau giống nhau, và kết quả là **nhỏ nhất theo thứ tự từ điển** trong tất cả các cách sắp xếp hợp lệ. Nếu không thể, xuất $-1$.

### Ý tưởng chính

Kết hợp **kiểm tra khả thi** với **tham lam phát hiện ký tự bắt buộc**.

**Khả thi.** Sắp xếp hợp lệ tồn tại khi và chỉ khi không có ký tự nào xuất hiện quá $\lceil n/2 \rceil$ lần, tương đương $\text{cnt}[c] \times 2 \le n + 1$ với mọi $c$. *Tính cần:* ký tự $c$ tối đa chiếm tất cả vị trí xen kẽ ($\lceil n/2 \rceil$ ô); vượt quá buộc hai bản sao kề nhau theo nguyên lý Dirichlet. *Tính đủ:* nếu $\text{cnt}[c] \le \lceil n/2 \rceil$ với mọi $c$, luôn chọn ký tự có tần suất lớn nhất khác ký tự trước đó cho kết quả hợp lệ — không ký tự nào vượt quá nửa số vị trí còn lại ở bất kỳ bước nào.

**Ký tự bắt buộc.** Tham lam đơn giản (luôn chọn ký tự nhỏ nhất khác ký tự trước) có thể thất bại: bỏ sót ký tự tần suất cao đến khi không còn đủ ô, tạo ngõ cụt. Thay vào đó, tại mỗi bước với `remaining` vị trí còn lại, ký tự $c$ bị **bắt buộc** khi $\text{cnt}[c] > \text{remaining}/2$ (tương đương $\text{cnt}[c] \times 2 - \text{remaining} > 0$). Nếu $c$ bị bắt buộc mà ta đặt ký tự khác, số vị trí còn lại giảm xuống $\text{remaining}-1$ còn $\text{cnt}[c]$ không đổi, khiến bài toán con không khả thi — do đó $c$ phải được đặt ngay. Vì xuất phát từ trạng thái khả thi và mỗi bước duy trì khả thi, $\text{cnt}[c] \times 2 - \text{remaining}$ luôn đúng bằng $1$ khi ký tự bị bắt buộc, nên điều kiện đơn giản thành $\text{cnt}[c] \times 2 - \text{remaining} = 1$.

**Lựa chọn tham lam.** Khi không có ký tự bắt buộc, duyệt từ A đến Z và chọn ký tự đầu tiên $c$ thỏa: (1) $c \neq \text{last}$, (2) $\text{cnt}[c] > 0$, và (3) $\text{cnt}[c] \times 2 - \text{remaining} < 1$ (đặt $c$ vẫn giữ bài toán con khả thi — đối với ký tự được đặt, số lần còn lại sau khi đặt vẫn không vượt quá nửa số ô; đối với ký tự khác, quét bắt buộc đã đảm bảo khả thi). Vì duyệt theo thứ tự bảng chữ cái, ký tự $c$ đầu tiên thỏa mãn là ký tự nhỏ nhất vẫn giữ được khả thi, đảm bảo tối ưu theo từ điển.

### Thuật toán

1. **Đếm** tần suất mỗi ký tự.
2. **Kiểm tra khả thi:** nếu $\text{cnt}[c] \times 2 > n + 1$ với bất kỳ $c$, xuất $-1$.
3. **Xây dựng kết quả** từng ký tự, với `remaining = n` và `last = -`:
   - **Quét bắt buộc:** tìm ký tự $c \neq \text{last}$ với $\text{cnt}[c] \times 2 - \text{remaining} = 1$. Nếu tìm thấy, đặt $c$.
   - **Quét tham lam:** ngược lại, tìm ký tự đầu tiên $c$ từ A đến Z sao cho $c \neq \text{last}$, $\text{cnt}[c] > 0$, và $\text{cnt}[c] \times 2 - \text{remaining} < 1$. Đặt $c$.
   - Giảm $\text{cnt}[c]$, đặt $\text{last} = c$, giảm `remaining`.

### Ví dụ minh họa

**Đầu vào:** `HATTIVATTI` ($n = 10$, tần suất: A=2, H=1, I=2, T=4, V=1)

| remaining | last | Bắt buộc? | Chọn | cnt còn lại |
|---|---|---|---|---|
| 10 | - | T: 8−10 < 0 → không | A (nhỏ nhất, thỏa) | A=1, H=1, I=2, T=4, V=1 |
| 9 | A | T: 8−9 < 0 → không | H (nhỏ nhất ≠ A, thỏa) | A=1, H=0, I=2, T=4, V=1 |
| 8 | H | T: 8−8 = 0 → không | A (nhỏ nhất ≠ H, thỏa) | A=0, H=0, I=2, T=4, V=1 |
| 7 | A | **T: 8−7 = 1** → bắt buộc | T | A=0, H=0, I=2, T=3, V=1 |
| 6 | T | không | I (nhỏ nhất ≠ T, thỏa) | A=0, H=0, I=1, T=3, V=1 |
| 5 | I | **T: 6−5 = 1** → bắt buộc | T | A=0, H=0, I=1, T=2, V=1 |
| 4 | T | không | I (nhỏ nhất ≠ T, thỏa) | A=0, H=0, I=0, T=2, V=1 |
| 3 | I | **T: 4−3 = 1** → bắt buộc | T | A=0, H=0, I=0, T=1, V=1 |
| 2 | T | không | V (nhỏ nhất ≠ T, thỏa) | A=0, H=0, I=0, T=1, V=0 |
| 1 | V | **T: 2−1 = 1** → bắt buộc | T | A=0, H=0, I=0, T=0, V=0 |

**Kết quả:** `AHATITITVT` ✓

## Độ phức tạp

- **Thời gian:** $O(n \times |\Sigma|) = O(n)$, với $|\Sigma| = 26$ — mỗi trong $n$ vị trí, quét nhiều nhất 26 ký tự hai lần (bắt buộc + tham lam).
- **Không gian:** $O(|\Sigma|) = O(1)$ — mảng tần suất cố định 26 phần tử.

## Mã nguồn (C++)

[Mã nguồn](../code/String%20Reorder.cpp)
