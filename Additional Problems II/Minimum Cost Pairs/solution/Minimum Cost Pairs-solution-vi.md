# Minimum Cost Pairs - Lời giải

**ID:** 3402 | **URL:** https://cses.fi/problemset/task/3402

## Đề bài

Cho $n$ số nguyên, với mỗi $k$ từ 1 đến $\lfloor n/2 \rfloor$, tìm tổng chi phí tối thiểu tạo $k$ cặp, chi phí cặp $(a,b)$ là $|a-b|$, mỗi số thuộc tối đa 1 cặp.

## Hướng tiếp cận

### Ghép cặp kề nhau trong mảng đã sắp xếp

Sắp xếp mảng. Trong lời giải tối ưu, mỗi cặp luôn gồm hai phần tử kề nhau: nếu có cặp $(a_i, a_j)$ với $j > i+1$ và $a_m$ ở giữa chưa ghép, đổi sang $(a_i, a_m)$ không tệ hơn (do $|a_i - a_m| \le |a_i - a_j|$); nếu $a_m$ đã ghép với $a_k$, trao đổi thành $(a_i, a_m)$ và $(a_j, a_k)$ cũng không tệ hơn. Lặp lại trao đổi đến khi mọi cặp đều kề.

Bài toán quy về: trên mảng hiệu $D[i] = a[i+1] - a[i]$, chọn $k$ hiệu sao cho không hai hiệu kề nhau cùng được chọn, tối thiểu hóa tổng.

### Kỹ thuật Gộp (Wiers-Johnson): Cho phép "hối hận"

Chọn hiệu nhỏ nhất $D[i]$, nhưng sau này có thể muốn đổi sang chọn $D[i-1]$ và $D[i+1]$ thay vì $D[i]$. Khi đó:

- Chi phí trao đổi = bỏ cặp $i$ (tiết kiệm $D[i]$), thêm cặp $l$ và $r$ (chi phí $D[l] + D[r]$).
- Hiệu dụng = $D[l] + D[r] - D[i]$.

Nút gộp mới mang giá trị này, đại diện cho lựa chọn thay thế. Thuật toán tham lam chọn hiệu nhỏ nhất từ heap ở mỗi bước, gộp nút kề, lặp $k$ lần — đây chính là bài toán khớp tối thiểu trên đường, giải đúng bằng tham lam với gộp.

## Thuật toán

1. Sắp xếp mảng.
2. Tính $D[i] = a[i+1] - a[i]$, xây danh sách liên kết kép (`L[]`, `R[]`) và min-heap.
3. Với $k$ từ 1 đến $\lfloor n/2 \rfloor$:
   - Lấy hiệu nhỏ nhất hợp lệ $(val, i)$ từ heap (bỏ qua nút đã gộp bằng `removed[]`).
   - Cộng `val` vào chi phí tích lũy, lưu kết quả.
   - Gộp: $l = L[i]$, $r = R[i]$. Cập nhật $D[i] = D[l] + D[r] - D[i]$, đẩy vào heap. Đánh dấu `removed[l] = removed[r] = true`, cập nhật liên kết.
4. Xuất dãy chi phí.

## Ví dụ minh họa

Mảng: $[3, 1, 2, 7, 9, 3, 4, 7]$ → sắp xếp: $[1, 2, 3, 3, 4, 7, 7, 9]$.

Hiệu kề: $[1, 1, 0, 1, 3, 0, 2]$.

| $k$ | Chọn | Chi phí tích lũy |
|:---:|:---:|:---:|
| 1 | 0 (cặp 3,3) | 0 |
| 2 | 0 (cặp 7,7) | 0 |
| 3 | 1 (cặp 1,2) | 1 |
| 4 | tiếp tục | 6 |

Kết quả: `0 0 1 6`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp + tối đa $n$ thao tác heap
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Minimum%20Cost%20Pairs.cpp)
