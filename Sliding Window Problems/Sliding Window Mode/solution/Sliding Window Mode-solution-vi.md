# Sliding Window Mode - Lời giải

**ID:** 3224 | **URL:** https://cses.fi/problemset/task/3224

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi cửa sổ trượt gồm $k$ phần tử liên tiếp, tìm mode — phần tử xuất hiện nhiều nhất. Nếu nhiều phần tử có cùng tần suất lớn nhất, chọn giá trị nhỏ nhất.

### Ý tưởng chính

Duy trì bảng tần số và tập hợp sắp xếp các cặp (tần suất, $-$giá trị). Phần tử cuối tập hợp cho tần suất lớn nhất với giá trị nhỏ nhất, do sắp xếp theo (tần suất tăng, $-$giá trị tăng) đẩy tần suất cực đại và $-$giá trị cực đại (tức giá trị cực tiểu) về cuối.

### Thuật toán

**Bước 1: Cấu trúc dữ liệu.** Duy trì:
- `map<int,int> cnt`: tần suất mỗi giá trị trong cửa sổ hiện tại.
- `set<pair<int,int>> S`: các cặp (tần suất, $-$giá trị) cho mọi giá trị trong cửa sổ.

**Bước 2: Trượt cửa sổ.** Với mỗi vị trí $i$:
1. **Thêm** $a[i]$: xóa cặp cũ $(\text{cnt}[a[i]], -a[i])$ khỏi $S$ (nếu có), tăng `cnt[a[i]]`, chèn cặp mới.
2. **Xóa** $a[i-k]$ (khi $i > k$): xóa cặp cũ khỏi $S$, giảm `cnt[a[i-k]]`. Nếu tần suất về 0, xóa khỏi `cnt`; ngược lại, chèn cặp đã cập nhật vào $S$.
3. **Mode** là $-S.\text{rbegin()} \to \text{second}$.

Tập hợp sắp xếp theo từ điển (tần suất, $-$giá trị). Phần tử cuối có tần suất lớn nhất; trong số các phần tử có tần suất đó, $-$giá trị lớn nhất tương ứng với giá trị gốc nhỏ nhất. Do đó `*S.rbegin()` cho đúng mode theo quy ước đề bài.

### Ví dụ minh họa

Với $n=8$, $k=3$, mảng $[1, 2, 3, 2, 5, 2, 4, 4]$:

- $i=3$: $S = \{(1,-3), (1,-2), (1,-1)\}$. mode $= -(-1) = \mathbf{1}$
- $i=4$: thêm 2 (tần suất 1→2), xóa 1. $S = \{(1,-3), (2,-2)\}$. mode $= \mathbf{2}$
- $i=5$: thêm 5, xóa 2 (tần suất 2→1). $S = \{(1,-5), (1,-3), (1,-2)\}$. mode $= \mathbf{2}$
- $i=6$: thêm 2 (tần suất 1→2), xóa 3. $S = \{(1,-5), (2,-2)\}$. mode $= \mathbf{2}$
- $i=7$: thêm 4, xóa 2 (tần suất 2→1). $S = \{(1,-5), (1,-4), (1,-2)\}$. mode $= \mathbf{2}$
- $i=8$: thêm 4 (tần suất 1→2), xóa 5. $S = \{(1,-2), (2,-4)\}$. mode $= \mathbf{4}$

Kết quả: `1 2 2 2 2 4`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Mode.cpp)
