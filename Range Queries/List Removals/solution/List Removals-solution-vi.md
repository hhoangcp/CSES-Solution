# List Removals - Lời giải

**ID:** 1749 | **URL:** https://cses.fi/problemset/task/1749

## Hướng tiếp cận

### Tóm tắt đề bài

Cho danh sách $n$ số nguyên, xóa lần lượt $n$ phần tử tại các vị trí $p_1, p_2, \ldots, p_n$ (danh sách đánh số lại sau mỗi lần xóa). Báo cáo giá trị phần tử bị xóa.

### Ý tưởng cốt lõi

Sau mỗi lần xóa, các phần tử dịch trái làm thay đổi vị trí tương đối. Cần tìm hiệu quả phần tử hoạt động (chưa xóa) thứ $k$ và đánh dấu đã xóa. **Cây phân đoạn** lưu số phần tử hoạt động tại mỗi nút hỗ trợ cả hai thao tác trong $O(\log n)$.

Để tìm phần tử hoạt động thứ $k$, duyệt cây từ trên xuống. Tại mỗi nút nội: nếu số hoạt động của con trái $\ge k$, mục tiêu nằm ở cây con trái; ngược lại nằm ở cây con phải ở vị trí $k - \text{số hoạt động con trái}$. Điều này đúng vì cây con trái chứa đúng $\text{số hoạt động con trái}$ phần tử hoạt động đầu tiên theo thứ tự, nên phần tử thứ $k$ hoặc thuộc trái (khi $k \le$ số trái) hoặc thuộc phải (khi $k >$ số trái), sau khi trừ đi số phần tử bên trái. Mỗi bước đi xuống một tầng, tốn $O(\log n)$ mỗi truy vấn.

Xóa phần tử đặt lá về 0 và lan truyền lên, duy trì bất biến mỗi nút lưu đúng số phần tử hoạt động.

### Thuật toán

1. **Xây dựng** cây phân đoạn với tất cả lá khởi tạo bằng 1.
2. **Với mỗi vị trí xóa** $p_i$:
   - Tìm vị trí thực tế: `pos = query(gốc, p_i)` bằng duyệt top-down.
   - Xuất $a[\text{pos}]$.
   - Xóa: cập nhật lá `pos` về 0 và lan truyền lên.

### Ví dụ

Đầu vào:
```
5
2 6 1 4 2
3 1 3 1 1
```

Danh sách: $[2, 6, 1, 4, 2]$. Cây: tất cả lá = 1, tổng gốc = 5.

- Xóa vị trí 3: duyệt — trái $[1,2]$ số hoạt động$=2 < 3$ → phải, tìm phần tử thứ $(3-2)=1$ bên phải → vị trí thực tế 3. Xuất $a[3]=1$. Đánh dấu lá 3 = 0. Danh sách: $[2, 6, 4, 2]$.
- Xóa vị trí 1: duyệt — trái $[1,2]$ số hoạt động$=2 \ge 1$ → trái → vị trí 1. Xuất $a[1]=2$. Đánh dấu lá 1 = 0. Danh sách: $[6, 4, 2]$.
- Xóa vị trí 3: duyệt — trái $[1,2]$ số hoạt động$=1 < 3$ → phải, tìm phần tử thứ $(3-1)=2$ → vị trí 5. Xuất $a[5]=2$. Đánh dấu lá 5 = 0. Danh sách: $[6, 4]$.
- Xóa vị trí 1: duyệt → vị trí 2. Xuất $a[2]=6$. Đánh dấu lá 2 = 0. Danh sách: $[4]$.
- Xóa vị trí 1: duyệt → vị trí 4. Xuất $a[4]=4$. Đánh dấu lá 4 = 0.

Kết quả: `1 2 2 6 4`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/List%20Removals.cpp)
