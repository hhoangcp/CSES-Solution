# Reversal Sorting - Lời giải

**ID:** 2075 | **URL:** https://cses.fi/problemset/task/2075

## Hướng tiếp cận

### Tóm tắt bài toán
Cho hoán vị $1, 2, \ldots, n$, sắp xếp tăng bằng cách đảo đoạn con. Dùng tối đa $n$ lần đảo.

### Ý tưởng cốt lõi
Xử lý từng vị trí $i = 1, 2, \ldots, n$. Nếu vị trí $i$ đã chứa giá trị $i$, bỏ qua. Ngược lại, tìm vị trí $p$ hiện tại của giá trị $i$ và đảo đoạn $[i, p]$. Đảo $[i, p]$ ánh xạ vị trí $j$ sang $i+p-j$, cụ thể $p \to i$, nên giá trị $i$ chuyển đúng vào vị trí $i$. Các phần tử trước $i$ không bị ảnh hưởng, và vì các đảo sau bắt đầu từ vị trí $> i$, giá trị $i$ không di chuyển nữa. Sau $n$ vị trí, mảng sắp xếp hoàn toàn với tối đa $n$ lần đảo.

### Cấu trúc dữ liệu: Treap với đảo lười
Đảo mảng thông thường mất $O(n)$ mỗi phép. Treap (BST ngẫu nhiên) hỗ trợ các thao tác trong $O(\log n)$:
- **Split & Merge:** Chia cây tại vị trí bất kỳ và gộp lại.
- **Cờ đảo lười (`rev`):** Đánh dấu đoạn cần đảo, chỉ hoán đổi con trái/phải khi truy cập (push down).
- **Tìm vị trí (`Find_pos`):** Duy trì con trỏ cha (`Par`). Leo từ nút `Pos[x]` lên gốc, đẩy cờ đảo lười, đếm kích thước cây con trái để xác định vị trí chính xác.

### Thuật toán
1. Xây treap từ hoán vị đầu vào.
2. Với $i = 1$ đến $n$:
   - Tìm giá trị tại vị trí $i$. Nếu bằng $i$, bỏ qua.
   - Tìm vị trí $p$ của giá trị $i$ bằng `Find_pos(i)`.
   - Ghi nhận đảo $(i, p)$.
   - Tách treap thành 3 phần tại $i$ và $p+1$, bật cờ đảo lười trên phần giữa, gộp lại.
3. Xuất số lần đảo và chi tiết các đoạn.

### Ví dụ minh họa
Hoán vị $[2,3,1,4]$.
- $i=1$: giá trị 1 ở vị trí 3. Đảo $[1,3]$: $[1,3,2,4]$.
- $i=2$: giá trị 2 ở vị trí 3. Đảo $[2,3]$: $[1,2,3,4]$.
- Kết quả: 2 lần đảo: `1 3` và `2 3`.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Reversal%20Sorting.cpp)
