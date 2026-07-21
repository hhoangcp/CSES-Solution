# Traffic Lights - Lời giải

**ID:** 1163 | **URL:** https://cses.fi/problemset/task/1163

## Đề bài

Có một con đường dài $x$ mét, ban đầu không có đèn giao thông nào. Thêm $n$ bộ đèn giao thông lần lượt vào đường tại các vị trí $p_1, p_2, \ldots, p_n$. Sau mỗi lần thêm đèn, in ra độ dài đoạn đường liên tục dài nhất không có đèn giao thông.

## Hướng tiếp cận

### 1. Mô hình hóa bài toán

Con đường dài $x$ mét ban đầu là một đoạn duy nhất từ $0$ đến $x$. Mỗi khi thêm đèn tại vị trí $p$, nó chia đoạn chứa $p$ thành hai đoạn nhỏ hơn. Ta cần duy trì đồng thời:

- vị trí các đèn đã dựng (để nhanh chóng xác định đoạn bị chia),
- danh sách độ dài mọi đoạn đường hiện có (để truy vấn đoạn dài nhất tức thời).

### 2. Cấu trúc dữ liệu tối ưu

Dùng kết hợp hai cây tìm kiếm cân bằng:

- **Tập vị trí $S$:** chứa các vị trí đèn, kể cả hai đầu mút $0$ và $x$, tự động sắp xếp tăng dần để tìm lân cận bằng tìm kiếm nhị phân (`lower_bound`/`upper_bound`).
- **Đa tập độ dài $T$:** chứa độ dài tất cả các đoạn, sắp xếp giảm dần nên phần tử đầu luôn là đoạn dài nhất.

### 3. Quy trình thêm đèn tại vị trí $p$

1. **Tìm đoạn bị chia:** tìm nhị phân trên $S$ hai đèn lân cận bao quanh $p$: $l$ (lớn nhất vẫn $< p$, tiền nhiệm) và $r$ (nhỏ nhất $> p$, kế nhiệm).
2. **Cập nhật đoạn:** đoạn cũ $[l, r]$ độ dài $r - l$ bị xóa; thay bằng hai đoạn mới $[l, p]$ và $[p, r]$ với độ dài $p - l$ và $r - p$. Cập nhật các thay đổi này vào $T$.
3. **Cập nhật vị trí:** chèn $p$ vào $S$.
4. **Lấy kết quả:** đoạn dài nhất là phần tử đầu của $T$.

## Ví dụ minh họa

Xét $x = 8$, $n = 3$, vị trí thêm đèn $[3, 6, 2]$.

- **Khởi tạo:** $S = \{0, 8\}$, $T = \{8\}$.
- **Thêm đèn tại $3$:** lân cận $l = 0$, $r = 8$. Xóa $8$ khỏi $T$, chèn $3 - 0 = 3$ và $8 - 3 = 5$. $S = \{0, 3, 8\}$, $T = \{5, 3\}$. Đoạn dài nhất $= 5$.
- **Thêm đèn tại $6$:** lân cận $l = 3$, $r = 8$. Xóa $5$ khỏi $T$, chèn $6 - 3 = 3$ và $8 - 6 = 2$. $S = \{0, 3, 6, 8\}$, $T = \{3, 3, 2\}$. Đoạn dài nhất $= 3$.
- **Thêm đèn tại $2$:** lân cận $l = 0$, $r = 3$. Xóa $3$ khỏi $T$, chèn $2 - 0 = 2$ và $3 - 2 = 1$. $S = \{0, 2, 3, 6, 8\}$, $T = \{3, 2, 2, 1\}$. Đoạn dài nhất $= 3$.

Kết quả sau các bước: `5 3 3`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — mỗi lần thêm đèn, các thao tác tìm ranh giới, xóa/chèn độ dài trên cây cân bằng đều tốn $O(\log n)$; với $n$ truy vấn tổng $O(n \log n)$.
- **Bộ nhớ:** $O(n)$ để lưu tối đa $n + 2$ vị trí trong $S$ và $n + 1$ độ dài đoạn trong $T$.
