# Chuyến Đi Vòng Quanh II - Lời giải

**ID:** 1678 | **URL:** https://cses.fi/problemset/task/1678

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh và $m$ cạnh, tìm một chu trình đơn có hướng, hoặc kết luận "IMPOSSIBLE" nếu không tồn tại.

### Ý tưởng chính

Chạy DFS trên đồ thị có hướng dùng kỹ thuật **ba màu** để phát hiện cạnh ngược và tái thiết chu trình. Mỗi đỉnh được gán một màu:

- **Màu 0** (chưa thăm): đỉnh chưa được khám phá.
- **Màu 1** (đang xử lý): đỉnh nằm trên đường DFS hiện tại (trong ngăn xếp đệ quy).
- **Màu 2** (đã xử lý): đỉnh và tất cả đỉnh con đã được duyệt hoàn toàn.

Khi xét cạnh $u \to v$ từ đỉnh $u$:

- Nếu $\text{color}[v] = 0$: đệ quy thăm $v$.
- Nếu $\text{color}[v] = 1$: phát hiện **cạnh ngược** — $v$ là tổ tiên của $u$ trên đường DFS hiện tại, tức tồn tại chu trình từ $v$ đi theo cây DFS đến $u$ rồi quay lại qua cạnh $u \to v$.
- Nếu $\text{color}[v] = 2$: bỏ qua (cạnh chéo hoặc cạnh tiếp — không tạo chu trình).

**Tại sao cần ba màu thay vì hai?** Trong đồ thị vô hướng (như bài Chuyến Đi Vòng Quanh I), một đỉnh kề đã thăm không phải cha thì chắc chắn là tổ tiên trên đường DFS hiện tại, nên chỉ cần hai trạng thái (đã thăm/chưa thăm) cộng mảng `parent` là đủ. Trong đồ thị có hướng, một đỉnh kề đã thăm có thể là tổ tiên vẫn đang trên đường hiện tại (màu 1 — tạo chu trình) hoặc là đỉnh thuộc nhánh khác đã duyệt xong (màu 2 — không tạo chu trình). Nếu không phân biệt hai trường hợp này, ta sẽ báo sai chu trình khi gặp cạnh chéo.

**Tính đúng đắn.** Nếu DFS phát hiện cạnh ngược $u \to v$ với $\text{color}[v] = 1$, thì $v$ nằm trên đường DFS hiện tại, tức tồn tại đường đi $v \leadsto u$ trong cây DFS; thêm cạnh $u \to v$ khép thành chu trình. Ngược lại, nếu đồ thị chứa chu trình $v_1 \to v_2 \to \cdots \to v_k \to v_1$, gọi $v_i$ là đỉnh đầu tiên trong chu trình được DFS thăm. Khi DFS đến $v_i$, tất cả đỉnh khác trong chu trình chưa thăm, nên DFS duyệt theo chu trình: $v_i \to v_{i+1} \to \cdots \to v_k \to v_1 \to \cdots \to v_{i-1}$. Khi xét cạnh $v_{i-1} \to v_i$, đỉnh $v_i$ vẫn có màu 1, nên cạnh ngược được phát hiện.

### Thuật toán

1. Với mỗi đỉnh chưa thăm, chạy DFS duy trì ngăn xếp $S$ chứa đường đi hiện tại.
2. Khi DFS tại $u$ xét cạnh $u \to v$:
   - Nếu $\text{color}[v] = 0$: đẩy $u$ vào $S$, đệ quy thăm $v$.
   - Nếu $\text{color}[v] = 1$: phát hiện cạnh ngược. Lấy các đỉnh từ đỉnh ngăn xếp xuống đến $v$, thêm $v$ để đóng chu trình, đảo ngược danh sách và xuất kết quả.
   - Nếu $\text{color}[v] = 2$: bỏ qua.
3. Sau khi xử lý xong tất cả đỉnh kề của $u$, đánh dấu $\text{color}[u] = 2$ và lấy $u$ ra khỏi $S$.
4. Nếu không tìm thấy chu trình sau tất cả DFS, xuất "IMPOSSIBLE".

### Ví dụ minh họa

Input:
```
4 5
1 3
2 1
2 4
3 2
3 4
```

Các cạnh: $1 \to 3$, $2 \to 1$, $2 \to 4$, $3 \to 2$, $3 \to 4$.

DFS từ đỉnh 1: $S = [1]$.
- Thăm đỉnh 3 (kề của 1): $S = [1, 3]$.
- Thăm đỉnh 2 (kề của 3): $S = [1, 3, 2]$.
- Xét cạnh $2 \to 1$: $\text{color}[1] = 1$ → phát hiện cạnh ngược!
- Tái thiết: $v = 1$. Lấy từ $S$: 2, 3, rồi đến 1. Chu trình (trước khi đảo): $[1, 2, 3, 1]$. Sau khi đảo: $[1, 3, 2, 1]$.

Kết quả:
```
4
1 3 2 1
```

(Bài toán chấp nhận bất kỳ chu trình hợp lệ. Kết quả mẫu `2 1 3 2` cũng đúng: $2 \to 1 \to 3 \to 2$.)

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — mỗi đỉnh và mỗi cạnh được xử lý tối đa một lần.
- **Bộ nhớ:** $O(n + m)$ — danh sách kề và các mảng phụ trợ.

## Mã nguồn (C++)

[Mã nguồn](../code/Round%20Trip%20II.cpp)
