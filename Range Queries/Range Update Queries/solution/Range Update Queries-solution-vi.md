# Range Update Queries - Lời giải

**ID:** 1651 | **URL:** https://cses.fi/problemset/task/1651

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn:
1. Tăng mỗi giá trị trong đoạn $[a, b]$ lên $u$.
2. Giá trị tại vị trí $k$ là bao nhiêu?

### Ý tưởng cốt lõi

Bài toán có **cập nhật đoạn** và **truy vấn điểm** — pattern lý tưởng cho **truyền lười** (lazy propagation) trên cây phân đoạn. Cây phân đoạn thông thường cần $O(n)$ mỗi cập nhật đoạn; truyền lười giảm xuống $O(\log n)$ bằng cách trì hoãn cập nhật.

Mỗi nút lưu `SNode[idx]` (tổng đoạn) và `Lazy[idx]` (lượng cộng cho mỗi phần tử đang chờ truyền xuống). Khi cộng $u$ lên đoạn $[a, b]$:

- Nếu đoạn $[l, r] \subseteq [a, b]$: cộng $u \cdot (r-l+1)$ vào `SNode[idx]` và $u$ vào `Lazy[idx]`. Không cần đệ quy sâu hơn — mọi phần tử trong đoạn tăng $u$, nên tổng tăng $u$ lần độ dài đoạn.
- Ngược lại: đẩy lười xuống con, rồi đệ quy vào cả hai nhánh. Sau khi đệ quy, `SNode[idx] = SNode[2*idx] + SNode[2*idx+1]`.

**Đẩy lười** phân phối `Lazy[idx]` xuống con: mỗi con nhận `Lazy[idx]` cộng vào lazy và `Lazy[idx] * (độ dài con)` cộng vào tổng. Tổng lượng tăng được bảo toàn: $u \cdot (r-l+1) = u \cdot (mid-l+1) + u \cdot (r-mid)$, nên việc phân rã nút lười bảo toàn tính đúng.

**Truy vấn điểm** tại $k$: duyệt từ gốc đến lá tại vị trí $k$, đẩy lười dọc đường đi. Giá trị tại lá chính là đáp án.

### Thuật toán

1. **Xây dựng** cây phân đoạn lưu tổng đoạn.
2. **Cập nhật đoạn** $[a, b]$ cộng $u$: truyền lười thông thường — tại nút bị bao trọn, cập nhật `SNode` và `Lazy`; tại nút giao một phần, đẩy lười xuống và đệ quy.
3. **Truy vấn điểm** tại $k$: duyệt đến lá, đẩy lười dọc đường đi. Trả về giá trị lá.

### Ví dụ minh họa

Đầu vào:
```
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
```

Mảng: $[3, 2, 4, 5, 1, 1, 5, 3]$.

- Truy vấn vị trí 4: giá trị $= 5$.
- Cập nhật cộng 1 lên $[2, 5]$: mảng thành $[3, 3, 5, 6, 2, 1, 5, 3]$.
- Truy vấn vị trí 4: giá trị $= 5 + 1 = 6$.

Kết quả:
```
5
6
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Range%20Update%20Queries.cpp)
