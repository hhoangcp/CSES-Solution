# Sliding Window Mex - Lời giải

**ID:** 3219 | **URL:** https://cses.fi/problemset/task/3219

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi cửa sổ trượt gồm $k$ phần tử liên tiếp, tìm mex — số nguyên không âm nhỏ nhất không xuất hiện trong cửa sổ.

### Ý tưởng chính

Cửa sổ có $k$ phần tử thì mex tối đa bằng $k$, nên chỉ cần quan tâm các giá trị trong $[0, k]$. Duy trì tập hợp sắp xếp các giá trị thuộc $[0, k]$ hiện vắng mặt trong cửa sổ; mex luôn là phần tử nhỏ nhất của tập này. Cập nhật tập hợp tịnh tiến khi cửa sổ trượt.

### Thuật toán

**Bước 1: Cận trên của mex.** Tập hợp $k$ phần tử có mex tối đa bằng $k$ (chỉ đạt khi $\{0, 1, \ldots, k-1\}$ đều có mặt). Mọi giá trị $> k$ đều có thể bỏ qua.

**Bước 2: Cấu trúc dữ liệu.** Duy trì:
- `cnt[v]`: số lần xuất hiện của giá trị $v$ trong cửa sổ hiện tại (chỉ với $v \le k$).
- `set<int> S`: tất cả giá trị thuộc $[0, k]$ hiện vắng mặt trong cửa sổ, khởi tạo bằng $\{0, 1, \ldots, k\}$.

**Bước 3: Trượt cửa sổ.** Với mỗi vị trí $i$:
1. Nếu $a[i] \le k$: tăng `cnt[a[i]]`. Nếu đây là lần đầu xuất hiện (tần suất trước đó bằng 0), xóa $a[i]$ khỏi $S$.
2. Nếu $i > k$ và $a[i-k] \le k$: giảm `cnt[a[i-k]]`. Nếu tần suất về 0, chèn lại $a[i-k]$ vào $S$.
3. Khi $i \ge k$: mex là `*S.begin()`.

$S$ luôn bằng $[0, k] \setminus \{v \in [0, k] : \text{cnt}[v] > 0\}$, nên phần tử nhỏ nhất của $S$ chính là mex.

### Ví dụ minh họa

Với $n=8$, $k=3$, mảng $[1, 2, 1, 0, 5, 1, 1, 0]$:

- $i=1$: thêm 1, xóa khỏi $S$. $S = \{0, 2, 3\}$
- $i=2$: thêm 2, xóa khỏi $S$. $S = \{0, 3\}$
- $i=3$: thêm 1 (đã vắng mặt trong $S$). $S = \{0, 3\}$. Mex = **0**
- $i=4$: thêm 0, xóa. Loại $a[1]=1$ (tần suất 2→1). $S = \{3\}$. Mex = **3**
- $i=5$: thêm 5 (>3, bỏ qua). Loại $a[2]=2$ (tần suất 1→0, chèn lại). $S = \{2, 3\}$. Mex = **2**
- $i=6$: thêm 1 (tần suất 1→2). Loại $a[3]=1$ (tần suất 2→1). $S = \{2, 3\}$. Mex = **2**
- $i=7$: thêm 1 (tần suất 2→3). Loại $a[4]=0$ (tần suất 1→0, chèn lại). $S = \{0, 2, 3\}$. Mex = **0**
- $i=8$: thêm 0, xóa. Loại $a[5]=5$ (>3, bỏ qua). $S = \{2, 3\}$. Mex = **2**

Kết quả: `0 3 2 2 0 2`

## Độ phức tạp

- **Thời gian:** $O(n \log k)$
- **Bộ nhớ:** $O(k)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Mex.cpp)
