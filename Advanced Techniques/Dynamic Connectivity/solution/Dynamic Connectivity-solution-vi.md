# Dynamic Connectivity - Lời giải

**ID:** 2133 | **URL:** https://cses.fi/problemset/task/2133

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ nút và $m$ cạnh ban đầu. Xử lý $k$ sự kiện: thêm cạnh hoặc xóa cạnh. Sau mỗi sự kiện (và ban đầu), báo cáo số thành phần liên thông.

### Ý tưởng chính

DSU thông thường hỗ trợ thêm cạnh hiệu quả nhưng không thể xóa. Tuy nhiên, mỗi cạnh tồn tại trong một khoảng thời gian liên tục $[l, r]$ (từ lúc thêm đến lúc xóa, hoặc đến cuối nếu không bị xóa). Điều này gợi ý cách tiếp cận **cây đoạn theo thời gian**.

Xây cây đoạn trên trục thời gian $[0, k]$. Mỗi cạnh có thời gian sống $[l, r]$ được chèn vào $O(\log k)$ nút cây đoạn phủ khoảng $[l, r]$. Duyệt cây theo DFS: khi vào nút, union tất cả cạnh bằng **DSU có rollback**; khi ra, rollback các union đó. Tại mỗi lá $t$, DSU chứa đúng các cạnh còn sống tại thời điểm $t$ — vì cạnh có thời gian sống $[l, r]$ chỉ được union tại nút trên đường gốc-lá $t$ khi và chỉ khi khoảng nút đó nằm trong $[l, r]$, tức $t \in [l, r]$.

DSU rollback dùng union theo kích thước, không nén đường đi (vì nén đường đi sẽ làm sai rollback). Mỗi union thành công lưu trạng thái vào stack để khôi phục. Biến `cgs` theo dõi số thành phần liên thông, giảm khi union và tăng lại khi rollback.

### Thuật toán

1. Theo dõi thời gian sống mỗi cạnh bằng `map`. Cạnh ban đầu bắt đầu từ thời điểm 0. Sự kiện thêm ghi thời điểm bắt đầu. Sự kiện xóa đóng khoảng $[\text{start}, \text{current}-1]$ và chèn cạnh vào cây đoạn.
2. Sau tất cả sự kiện, các cạnh còn sống có khoảng kéo dài đến $k$.
3. Duyệt cây đoạn đệ quy:
   - Trước khi đệ quy: union tất cả cạnh tại nút hiện tại.
   - Đệ quy xuống con.
   - Sau khi đệ quy: rollback tất cả union tại nút này.
4. Tại lá $i$, ghi `cgs` vào `ans[i]`.

### Ví dụ minh họa

$n=5$, $m=3$, $k=3$. Cạnh ban đầu: (1,4), (2,3), (3,5).

| Thời điểm | Sự kiện | Thời gian sống cạnh | Số TPLL |
|-----------|---------|---------------------|---------|
| 0 | — | (1,4)[$0$,$3$], (2,3)[$0$,$3$], (3,5)[$0$,$1$] | 2 |
| 1 | Thêm (2,5) | +(2,5)[$1$,$3$] | 2 |
| 2 | Xóa (3,5) | (3,5) đóng tại $1$ | 2 |
| 3 | Thêm (1,2) | +(1,2)[$3$,$3$] | 1 |

- Thời điểm 0: $\{1,4\}$ và $\{2,3,5\}$ → 2
- Thời điểm 1: thêm (2,5), nhưng 2–5 đã nối qua $2 \to 3 \to 5$ → 2
- Thời điểm 2: xóa (3,5), nhưng 2–5 vẫn nối qua $2 \to 5$ → 2
- Thời điểm 3: thêm (1,2), gộp hai thành phần → 1

Kết quả: `2 2 2 1`

## Độ phức tạp

- **Thời gian:** $O((m + k) \log k \cdot \log n)$ — mỗi cạnh trong $O(\log k)$ nút cây đoạn, union/rollback $O(\log n)$ (không nén đường đi khi có rollback).
- **Không gian:** $O((m + k) \log k)$ — cạnh lưu trong nút cây đoạn.

## Mã nguồn (C++)

[Mã nguồn](../code/Dynamic%20Connectivity.cpp)
