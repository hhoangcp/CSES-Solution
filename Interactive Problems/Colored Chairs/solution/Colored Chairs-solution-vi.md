# Colored Chairs - Lời giải

**ID:** 3273 | **URL:** https://cses.fi/problemset/task/3273

## Phương pháp

### Tóm tắt bài toán

Có $n$ chiếc ghế ($n$ lẻ) xếp thành vòng tròn, mỗi ghế màu đỏ (R) hoặc xanh (B). Tìm hai ghế kề nhau cùng màu, bằng cách hỏi màu từng ghế, tối đa 20 truy vấn.

### Ý tưởng chính

Vì $n$ là số lẻ, các màu không thể xen kẽ hoàn toàn trên vòng tròn — sự xen kẽ đòi hỏi số ghế chẵn. Do đó luôn tồn tại ít nhất một cặp ghế kề nhau cùng màu.

Để tìm cặp đó, hỏi ghế 1 và ghế $n$. Nếu cùng màu, chúng kề nhau trên vòng tròn và ta có kết quả ngay. Nếu khác màu, ranh giới cùng màu phải nằm ở đâu đó trên đoạn $1, 2, \ldots, n$.

**Chặt nhị phân trên ranh giới:** Trước ranh giới, các ghế xen kẽ hoàn hảo bắt đầu từ ghế 1. Vậy "màu kỳ vọng" tại vị trí $i$ là:
- Trùng ghế 1 nếu $(i-1)$ chẵn.
- Khác ghế 1 nếu $(i-1)$ lẻ.

Sau khi qua ranh giới cùng màu, tính chẵn lẻ bị đảo. Nếu màu tại vị trí $mid$ không khớp kỳ vọng, ta đã qua ranh giới; ngược lại thì chưa. Điều này cho điều kiện đơn điệu để chặt nhị phân.

### Thuật toán

1. Hỏi ghế 1 và ghế $n$. Nếu cùng màu, xuất $n$ và kết thúc.
2. Ngược lại, chặt nhị phân trên $[l, r] = [2, n]$:
   - Gọi $mid = \lfloor(l + r) / 2\rfloor$. Hỏi ghế $mid$.
   - Nếu màu tại $mid$ khớp kỳ vọng (dựa trên tính chẵn lẻ của $mid - 1$), ranh giới nằm bên phải: $l = mid + 1$.
   - Ngược lại, ranh giới nằm tại hoặc bên trái $mid$: $r = mid$.
3. Khi $l = r$, ghế $l-1$ và $l$ cùng màu. Xuất $l - 1$.

**Bất biến:** Ranh giới cùng màu nằm trong $[l-1, r-1]$. Ban đầu $l = 2, r = n$, ranh giới nằm trong $[1, n-1]$. Mỗi bước giảm đôi khoảng tìm. Khi $l = r$, ranh giới tại vị trí $l - 1$.

**Số truy vấn:** 2 truy vấn ban đầu + $\lceil\log_2(n-1)\rceil$ truy vấn chặt nhị phân. Với $n \le 2 \times 10^5$: $2 + 18 = 20$.

### Ví dụ minh họa

$n = 5$, ghế $= [R, B, B, R, B]$ (ghế 2 và 3 là cặp kề cùng màu, trùng với ví dụ đề bài):

- Hỏi ghế 1: **R**. Hỏi ghế 5: **B**. Khác màu → chặt nhị phân.
- $l = 2, r = 5, mid = 3$. Hỏi ghế 3: **B**. Khoảng cách $= 2$ (chẵn), kỳ vọng $=$ trùng R $= $ R. Thực tế B $\neq$ R → không khớp → $r = 3$.
- $l = 2, r = 3, mid = 2$. Hỏi ghế 2: **B**. Khoảng cách $= 1$ (lẻ), kỳ vọng $=$ khác R $=$ B. Thực tế B $=$ B → khớp → $l = 3$.
- $l = r = 3$. Kết quả: ghế $l - 1 = 2$ và $l = 3$ cùng màu. Xuất **2**.

## Độ phức tạp

- **Thời gian:** $O(\log n)$ truy vấn
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Colored%20Chairs.cpp)
