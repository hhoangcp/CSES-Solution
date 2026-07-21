# Another Game - Lời giải

**ID:** 2208 | **URL:** https://cses.fi/problemset/task/2208

## Phương pháp

### Tóm tắt bài toán

Có $n$ đống đồng xu và hai người chơi luân phiên đi. Trên mỗi nước đi, người chơi chọn một tập con không rỗng các đống và lấy đi đúng một đồng xu từ mỗi đống đã chọn. Người lấy đồng xu cuối cùng thắng. Xác định người thắng khi cả hai chơi tối ưu.

### Ý tưởng chính

Xét tính chẵn/lẻ của mỗi đống. Gọi trạng thái **tất cả chẵn** khi mọi đống có số đồng xu chẵn.

**Trường hợp 1: Tất cả đống đều chẵn.** Đây là vị thế thua cho người đang đi. Mọi nước đi đều phải chọn một tập con không rỗng $T$ và giảm mỗi đống trong $T$ đi 1, biến các đống đó thành lẻ. Người đối thủ đối xứng bằng cách chọn đúng tập $T$ ở nước tiếp theo, đưa tất cả trở lại chẵn. Do tổng đồng xu giảm đúng $2|T| \geq 2$ mỗi cặp nước đi, trò chơi chắc chắn kết thúc và người đối thủ luôn lấy đồng cuối cùng.

**Trường hợp 2: Tồn tại ít nhất một đống lẻ.** Người đi trước lấy một đồng từ mọi đống lẻ. Sau nước đi này, tất cả đống trở thành chẵn, ép người đi sau vào Trường hợp 1 — vị thế thua.

**Hệ quả:** Người đi trước thắng $\iff$ tồn tại ít nhất một đống lẻ.

### Thuật toán

1. Với mỗi test case, duyệt qua tất cả đống.
2. Nếu có bất kỳ đống nào lẻ, xuất "first"; ngược lại, xuất "second".

### Ví dụ minh họa

**Test 1:** $n = 3$, đống = $\{1, 2, 3\}$. Đống 1 và 3 lẻ → người đi trước lấy từ đống 1 và 3 → $\{0, 2, 2\}$ (tất cả chẵn). Người đi sau ở vị thế thua. Kết quả: `first`.

**Test 2:** $n = 2$, đống = $\{2, 2\}$. Cả hai chẵn → người đi trước thua. Bất kể chọn tập nào cũng tạo ra đống lẻ, người đi sau đối xứng. Kết quả: `second`.

**Test 3:** $n = 4$, đống = $\{5, 5, 4, 5\}$. Đống 1, 2 và 4 lẻ → người đi trước lấy từ ba đống đó → $\{4, 4, 4, 4\}$ (tất cả chẵn). Người đi sau ở vị thế thua. Kết quả: `first`.

## Độ phức tạp

- **Thời gian:** $O(n)$ mỗi test case
- **Bộ nhớ:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Another%20Game.cpp)
