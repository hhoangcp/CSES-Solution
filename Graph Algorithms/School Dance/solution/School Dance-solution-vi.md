# Khiêu Vũ Trường Học - Lời giải

**ID:** 1696 | **URL:** https://cses.fi/problemset/task/1696

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị hai phía với $n$ nam, $m$ nữ và $k$ cặp tiềm năng (cạnh), tìm ghép cặp cực đại — tập cạnh lớn nhất mà không có hai cạnh nào chung đỉnh — và liệt kê các cặp.

### Ý tưởng chính

Mô hình hóa bài toán thành **ghép cặp cực đại trên đồ thị hai phía** và giải bằng **thuật toán Kuhn** (thuật toán đường tăng).

**Đường tăng** (augmenting path) là đường đi bắt đầu từ một nam chưa ghép, xen kẽ giữa cạnh không thuộc ghép cặp và cạnh thuộc ghép cặp, kết thúc tại một nữ chưa ghép. Đảo trạng thái các cạnh trên đường tăng (khác ghép ↔ thuộc ghép) làm tăng kích thước ghép cặp đúng 1, vì đường tăng có độ dài lẻ với nhiều hơn một cạnh không thuộc ghép.

**Định lý Berge:** Một ghép cặp là cực đại khi và chỉ khi không tồn tại đường tăng đối với ghép cặp đó. Do đó, liên tục tìm và đảo đường tăng cho đến khi không còn sẽ thu được ghép cặp cực đại.

Để tìm đường tăng từ một nam chưa ghép $u$, dùng DFS: với mỗi nữ $v$ kề $u$, nếu $v$ chưa ghép thì đường tăng hoàn tất; nếu $v$ đã ghép với nam $u'$, đệ quy tìm bạn thay thế cho $u'$. Nếu thành công, $u'$ được ghép chỗ khác, giải phóng $v$ cho $u$.

**Tính đúng đắn.** Mỗi lần đảo đường tăng làm tăng kích thước ghép cặp đúng 1 (đường có $2k+1$ cạnh: $k$ thuộc ghép cũ và $k+1$ không thuộc; sau đảo, $k+1$ thuộc ghép mới và $k$ bị loại). Theo định lý Berge, khi không còn đường tăng, ghép cặp hiện tại là cực đại. Thuật toán luôn dừng vì kích thước ghép cặp bị chặn bởi $\min(n, m)$ và tăng mỗi bước.

### Thuật toán

1. Bắt đầu với ghép cặp rỗng ($\text{match}[v] = 0$ với mọi nữ $v$).
2. Với mỗi nam $u$ từ 1 đến $n$:
   - Đặt lại mảng `visited` cho các nữ.
   - Gọi DFS tìm đường tăng từ $u$. Nếu tìm được, cập nhật ghép cặp và tăng bộ đếm.
3. Xuất số cặp đã ghép và mỗi cặp $(\text{match}[v], v)$.

### Ví dụ minh họa

Input:
```
3 2 4
1 1
1 2
2 1
3 1
```

Các cạnh: nam 1 → [nữ 1, nữ 2], nam 2 → [nữ 1], nam 3 → [nữ 1].

- Nam 1: DFS tìm được nữ 1 (chưa ghép) → match[1] = 1.
- Nam 2: DFS thử nữ 1 (đã ghép với nam 1) → đệ quy tìm thay thế cho nam 1 → nam 1 tìm được nữ 2 (chưa ghép) → ghép lại: match[2] = 1, match[1] = 2.
- Nam 3: DFS thử nữ 1 (đã ghép với nam 2) → đệ quy tìm thay thế cho nam 2 → nam 2 không có nữ khác → thất bại.

Kết quả: 2 cặp — $(1, 2)$ và $(2, 1)$.

Kết quả:
```
2
1 2
2 1
```

(Bài toán chấp nhận bất kỳ ghép cặp hợp lệ. Kết quả mẫu `1 2, 3 1` cũng đúng.)

## Độ phức tạp

- **Thời gian:** $O(n \cdot k)$ — mỗi DFS mất $O(k)$, gọi tối đa $O(n)$ lần (mỗi lần thành công tăng kích thước ghép, có tối đa $\min(n, m)$ lần thành công).
- **Bộ nhớ:** $O(n + m + k)$ — danh sách kề, mảng ghép cặp và mảng đã thăm.

## Mã nguồn (C++)

[Mã nguồn](../code/School%20Dance.cpp)
