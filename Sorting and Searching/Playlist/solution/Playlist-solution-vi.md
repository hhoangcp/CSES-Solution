# Playlist - Lời giải

**ID:** 1141 | **URL:** https://cses.fi/problemset/task/1141

## Hướng tiếp cận

Duy trì cửa sổ trượt $[l, i]$ mà mọi bài hát trong đó đều có ID phân biệt. Duyệt từng vị trí $i$ (con trỏ phải) và điều chỉnh $l$ (con trỏ trái) để đảm bảo tính phân biệt. Dùng bảng tần suất (`std::map` vì ID lên tới $10^9$) đếm số lần xuất hiện của mỗi ID trong cửa sổ hiện tại.

Với mỗi vị trí $i$ từ $1$ đến $n$:

1. Tăng $\text{cnt}[a[i]]$ lên 1.
2. Nếu $\text{cnt}[a[i]] > 1$, thu hẹp từ trái: giảm $\text{cnt}[a[l]]$ và tăng $l$ cho đến khi $\text{cnt}[a[i]] = 1$.
3. Cập nhật $\text{res} = \max(\text{res}, i - l + 1)$.

**Tính đúng:** Sau khi thu hẹp, $\text{cnt}[a[i]] = 1$ và không có bài nào khác bị trùng (chỉ $a[i]$ bị trùng khi thêm, thu hẹp chỉ giảm số đếm). Cửa sổ $[l, i]$ là cửa sổ phân biệt dài nhất kết thúc tại $i$: mọi cửa sổ $[l', i]$ với $l' < l$ đều chứa hai bản sao của $a[i]$, mâu thuẫn với tính phân biệt. Vì mọi đoạn con phân biệt $[a, b]$ đều thỏa $a \geq l_b$, độ dài của nó không vượt quá $b - l_b + 1$. Lấy max trên tất cả $i$ được đáp án toàn cục.

### Ví dụ minh họa

Xét $n = 8$, dãy $a = [1, 2, 1, 3, 2, 7, 4, 2]$ (chỉ số từ 1).

| $i$ | $a[i]$ | Cửa sổ $[l, i]$ | $l$ | Độ dài | $\text{res}$ |
|-----|--------|-----------------|-----|--------|---------------|
| 1 | $1$ | $[1,1]$ | 1 | 1 | 1 |
| 2 | $2$ | $[1,2]$ | 1 | 2 | 2 |
| 3 | $1$ | $[2,3]$ (trùng 1, thu qua $a[1]$) | 2 | 2 | 2 |
| 4 | $3$ | $[2,4]$ | 2 | 3 | 3 |
| 5 | $2$ | $[3,5]$ (trùng 2, thu qua $a[2]$) | 3 | 3 | 3 |
| 6 | $7$ | $[3,6]$ | 3 | 4 | 4 |
| 7 | $4$ | $[3,7]$ | 3 | 5 | 5 |
| 8 | $2$ | $[6,8]$ (trùng 2, thu qua $a[5]$) | 6 | 3 | 5 |

Đáp án: $5$ (đoạn con $[1, 3, 2, 7, 4]$ từ vị trí 3 đến 7).

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ với `map` (mỗi thao tác $O(\log n)$). Cả hai con trỏ chỉ tiến, tổng bước thu hẹp $\leq n$. Có thể đạt $O(n)$ nếu nén tọa độ + mảng.
- **Bộ nhớ:** $O(n)$ — bảng tần suất lưu nhiều nhất $n$ phần tử.

## Mã nguồn (C++)

[Mã nguồn](../code/Playlist.cpp)
