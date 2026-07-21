# Hotel Queries - Lời giải

**ID:** 1143 | **URL:** https://cses.fi/problemset/task/1143

## Hướng tiếp cận

### Tóm tắt đề bài

Có $n$ khách sạn, khách sạn thứ $i$ có $h_i$ phòng trống. Xử lý $m$ nhóm lần lượt: phân bổ nhóm cần $r_j$ phòng cho **khách sạn trái nhất** có đủ phòng, sau đó giảm số phòng của khách sạn đó. Nếu không khách sạn nào đủ, in 0.

### Ý tưởng cốt lõi

Với mỗi nhóm cần $x$ phòng, ta phải tìm chỉ số nhỏ nhất $p$ sao cho $h_p \ge x$, rồi cập nhật $h_p \leftarrow h_p - x$. **Cây phân đoạn lưu maximum** hỗ trợ cả hai thao tác trong $O(\log n)$.

Để tìm khách sạn trái nhất có $\ge x$ phòng, ta duyệt cây từ trên xuống. Tại mỗi nút nội, nếu maximum của con trái $\ge x$ thì đáp án nằm ở nửa trái (ưu tiên trái nhất), ngược lại nếu maximum của con phải $\ge x$ thì nằm ở nửa phải. Nếu cả hai đều $< x$, không có khách sạn phù hợp, trả về 0. Tìm kiếm đúng vì vị trí hợp lệ trái nhất $p^*$ chắc chắn nằm ở nửa trái khi nửa trái có bất kỳ vị trí nào thỏa mãn, và chỉ nằm ở nửa phải khi nửa trái không có vị trí nào đủ phòng. Mỗi bước giảm phạm vi tìm kiếm một nửa, nên duyệt tốn $O(\log n)$.

Sau khi tìm được vị trí $p$, cập nhật $h_p$ bằng thao tác cập nhật điểm trên cây phân đoạn.

### Thuật toán

1. **Xây dựng** cây phân đoạn lưu maximum từ mảng khách sạn.
2. **Với mỗi nhóm** cần $x$ phòng:
   - Duyệt cây từ trên xuống: tại mỗi nút, ưu tiên con trái nếu maximum $\ge x$; ngược lại đi con phải nếu maximum $\ge x$; ngược lại trả về 0.
   - Nếu tìm được vị trí $p$, xuất $p$ và cập nhật $h_p \leftarrow h_p - x$.
   - Ngược lại, xuất 0.

### Ví dụ

Đầu vào:
```
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
```

Khách sạn: $[3, 2, 4, 1, 5, 5, 2, 6]$.

- Nhóm cần 4: duyệt xuống — nửa trái $[1,4]$ max$=4 \ge 4$ → trái; $[1,2]$ max$=3 < 4$ → phải $[3,4]$; $[3,3]$ max$=4 \ge 4$ → trái; lá: khách sạn 3. Cập nhật: $h_3 = 0$. Mảng: $[3, 2, 0, 1, 5, 5, 2, 6]$.
- Nhóm cần 4: $[1,4]$ max$=3 < 4$ → phải $[5,8]$ max$=6 \ge 4$ → cuối cùng khách sạn 5. Cập nhật: $h_5 = 1$. Mảng: $[3, 2, 0, 1, 1, 5, 2, 6]$.
- Nhóm cần 7: gốc max$=6 < 7$ → 0.
- Nhóm cần 1: khách sạn 1 ($h_1=3$). Cập nhật: $h_1 = 2$.
- Nhóm cần 1: khách sạn 1 ($h_1=2$). Cập nhật: $h_1 = 1$.

Kết quả: `3 5 0 1 1`

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Hotel%20Queries.cpp)
