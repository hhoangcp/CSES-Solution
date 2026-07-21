# Stair Game - Lời giải

**ID:** 1099 | **URL:** https://cses.fi/problemset/task/1099

## Phương pháp

### Tóm tắt bài toán

Có $n$ bậc thang đánh số $1, 2, \ldots, n$, mỗi bậc có một số bóng. Hai người chơi luân phiên đi. Mỗi lượt, người chơi chọn bậc $k \neq 1$ có ít nhất một bóng, rồi di chuyển bất kỳ số bóng từ bậc $k$ xuống bậc $k-1$. Người đi cuối cùng thắng. Xác định người thắng khi cả hai chơi tối ưu.

### Ý tưởng chính

Di chuyển bóng từ bậc $k$ xuống $k-1$ giống Nim, nhưng bóng không biến mất — chúng chỉ chuyển xuống dưới. Bóng ở bậc 1 là trạng thái kết thúc (không thể di chuyển tiếp vì $k \neq 1$).

**Quan sát chính:** Trò chơi tương đương Nim chơi trên **các bậc vị trí chẵn**. Người đi trước thắng khi và chỉ khi XOR số bóng ở các bậc chẵn khác 0.

**Tại sao bậc lẻ không ảnh hưởng:** Di chuyển $m$ bóng từ bậc lẻ $2j+1$ xuống bậc chẵn $2j$ làm tăng "đống Nim" ở bậc $2j$ lên $m$. Nhưng đối thủ có thể di chuyển tiếp đúng $m$ bóng đó từ bậc $2j$ xuống bậc $2j-1$, khôi phục trạng thái cũ. Nước đi từ bậc lẻ luôn có thể bị trung hòa.

**Chứng minh tương đương:**
- Từ $S = 0$ (XOR bậc chẵn), mọi nước đi làm $S \neq 0$: di chuyển từ bậc chẵn $2j$ thay đổi $p_{2j}$; di chuyển từ bậc lẻ $2j+1$ thay đổi $p_{2j}$. Cả hai đều làm XOR bậc chẵn thay đổi.
- Từ $S \neq 0$, tồn tại nước đi về $S' = 0$: tìm bậc chẵn $2j$ đóng góp bit cao nhất của $S$, di chuyển $p_{2j} - (p_{2j} \oplus S)$ bóng từ bậc $2j$ xuống $2j-1$. Hợp lệ vì $p_{2j} \oplus S < p_{2j}$.
- Trạng thái kết thúc: mọi bóng ở bậc 1, tất cả bậc chẵn trống, $S = 0$. Đây là vị thế thua.

### Thuật toán

Với mỗi test case, tính XOR của $p_i$ tại các chỉ số chẵn $i$. Nếu khác 0, xuất "first"; ngược lại xuất "second".

### Ví dụ minh họa

| Bóng | Giá trị bậc chẵn | XOR | Người thắng |
|------|-------------------|-----|-------------|
| $[0, 2, 1]$ | $p_2 = 2$ | $2 \neq 0$ | first |
| $[1, 1, 1, 1]$ | $p_2 = 1, p_4 = 1$ | $1 \oplus 1 = 0$ | second |
| $[5, 3]$ | $p_2 = 3$ | $3 \neq 0$ | first |

## Độ phức tạp

- **Thời gian:** $O(n)$ mỗi test case
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Stair%20Game.cpp)
