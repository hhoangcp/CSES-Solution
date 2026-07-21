# Bit Inversions - Lời giải

**ID:** 1188 | **URL:** https://cses.fi/problemset/task/1188

## Đề bài

Cho một chuỗi bit độ dài $n$ và $m$ yêu cầu đảo bit (0 thành 1, 1 thành 0) tại vị trí $x_i$. Sau mỗi lần đảo, hãy tìm độ dài của chuỗi con liên tiếp dài nhất gồm các bit giống nhau (toàn 0 hoặc toàn 1).

## Hướng tiếp cận

### 1. Cấu trúc dữ liệu: Cây phân đoạn (Segment Tree)

Để quản lý độ dài xâu con dài nhất trong một khoảng, mỗi nút trên cây phân đoạn cần lưu trữ các thông tin sau để hỗ trợ việc gộp (Merge) hai nút con:

- `longest`: Độ dài xâu con giống nhau dài nhất nằm hoàn toàn trong đoạn.
- `Left_0`, `Left_1`: Độ dài xâu con toàn 0 (hoặc toàn 1) liên tiếp tính từ biên trái của đoạn.
- `Right_0`, `Right_1`: Độ dài xâu con toàn 0 (hoặc toàn 1) liên tiếp tính từ biên phải của đoạn.
- `all_0`, `all_1`: Biến logic kiểm tra xem toàn bộ đoạn có phải toàn 0 hoặc toàn 1 hay không.

### 2. Thao tác Gộp (Merge) hai nút con

Khi gộp nút con trái $A$ và nút con phải $B$ thành nút cha $P$, ta cần xem xét xâu con dài nhất có thể nằm ở 3 vị trí:

- Nằm hoàn toàn trong $A$ ($A.\text{longest}$).
- Nằm hoàn toàn trong $B$ ($B.\text{longest}$).
- Vắt ngang qua ranh giới giữa $A$ và $B$. Điều này xảy ra khi $A$ kết thúc bằng bit giống với bit bắt đầu của $B$:
  - Nếu là bit 0: Độ dài là $A.\text{Right\_0} + B.\text{Left\_0}$.
  - Nếu là bit 1: Độ dài là $A.\text{Right\_1} + B.\text{Left\_1}$.

Vậy $P.\text{longest} = \max(A.\text{longest}, B.\text{longest}, A.\text{Right\_0} + B.\text{Left\_0}, A.\text{Right\_1} + B.\text{Left\_1})$.

Đối với các thuộc tính biên: nếu $A$ toàn là một loại bit, dãy bắt đầu từ biên trái có thể kéo dài sang $B$. Ví dụ, nếu $A$ toàn 0 thì $P.\text{Left\_0} = A.\text{longest} + B.\text{Left\_0}$; ngược lại $P.\text{Left\_0} = A.\text{Left\_0}$. Tương tự cho `Left_1`, `Right_0`, `Right_1`.

### 3. Cập nhật và Truy vấn

- **Cập nhật (Modify):** Khi đảo bit tại vị trí $p$, ta tìm đến lá tương ứng trên cây phân đoạn, đổi trạng thái từ `all_0` sang `all_1` (hoặc ngược lại). Sau đó, cập nhật ngược lên các nút tổ tiên bằng hàm gộp. Đảo bit tại lá thay đổi giá trị tại đúng 1 vị trí, và tất cả các nút tổ tiên được tính lại đúng bằng hàm gộp.
- **Truy vấn (Query):** Đáp án sau mỗi lần đảo chính là giá trị `longest` tại nút gốc (quản lý khoảng $[1, n]$).

Thay vì duyệt lại toàn bộ chuỗi $O(n)$ sau mỗi lần đảo bit, Segment Tree cho phép xử lý mỗi truy vấn trong $O(\log n)$.

### Ví dụ

Chuỗi ban đầu: `001011`. Xâu con giống nhau dài nhất: `00` (hoặc `11`), độ dài 2.

| Thao tác | Chuỗi sau đảo | Xâu dài nhất | Độ dài |
|----------|---------------|-------------|--------|
| Đảo vị trí 3 | `000011` | `0000` | 4 |
| Đảo vị trí 2 | `010011` | `00` hoặc `11` | 2 |
| Đảo vị trí 5 | `010001` | `000` | 3 |

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$, trong đó $n$ là độ dài chuỗi và $m$ là số lượng truy vấn.
- **Bộ nhớ:** $O(n)$ (thường là $4n$ để lưu trữ cây phân đoạn).

## Mã nguồn (C++)

[Mã nguồn](../code/Bit%20Inversions.cpp)
