# Range Queries and Copies - Lời giải

**ID:** 1737 | **URL:** https://cses.fi/problemset/task/1737

## Hướng tiếp cận

### Tóm tắt đề bài

Duy trì danh sách các mảng, ban đầu có một mảng gồm $n$ phần tử. Xử lý $q$ truy vấn:
1. Đặt giá trị tại vị trí $a$ trong mảng $k$ thành $x$.
2. Tính tổng đoạn $[a, b]$ trong mảng $k$.
3. Tạo bản sao của mảng $k$ và thêm vào cuối danh sách.

### Ý tưởng cốt lõi

Sao chép cây phân đoạn thông thường tốn $O(n)$, cho độ phức tệ $O(qn)$ — quá chậm và tốn bộ nhớ. **Cây phân đoạn bền vững** cho phép sao chép trong $O(1)$ bằng cách chia sẻ các cây con không thay đổi.

Mỗi nút lưu con trỏ `Left`, `Right` và `sum`. Duy trì mảng `ver[]` chứa con trỏ gốc, với `ver[k]` là gốc của mảng $k$.

**Sao chép** (loại 3): chỉ cần `ver[++cur] = ver[k]` — sao chép con trỏ gốc. Vì nút cây bền vững không bao giờ bị sửa đổi sau khi tạo, cả hai mảng chia sẻ cùng cây an toàn. Nếu mảng $k$ cập nhật sau đó, gốc mới được tạo cho `ver[k]` nhưng `ver[new]` vẫn trỏ gốc cũ — không bị ảnh hưởng.

**Cập nhật** (loại 1): dùng **sao chép đường đi** (path copying). Tạo nút mới chỉ trên đường từ gốc đến lá $p$, đặt lá bằng giá trị mới và tính lại `sum = Left->sum + Right->sum` theo hướng lên. Các nhánh không đổi được chia sẻ với phiên bản cũ. Thay thế `ver[k] = new_root`. Đây là cập nhật tại chỗ trên mảng $k$, nhưng các mảng khác dùng chung gốc cũ không bị ảnh hưởng vì nút cũ không bao giờ sửa đổi.

**Truy vấn** (loại 2): truy vấn tổng đoạn thông thường trên cây gốc `ver[k]` — $O(\log n)$.

### Thuật toán

1. **Xây dựng** cây phân đoạn bền vững cho mảng ban đầu. Đặt `ver[1]` là gốc.
2. **Cập nhật** vị trí $p$ trong mảng $k$ thành $x$: sao chép đường từ `ver[k]` đến lá $p$, đặt lá bằng $x$, tính lại tổng ngược lên. Thay `ver[k]` bằng gốc mới.
3. **Truy vấn** tổng $[a, b]$ trên `ver[k]`: truy vấn tổng đoạn thông thường — $O(\log n)$.
4. **Sao chép** mảng $k$: `ver[++cur] = ver[k]` — $O(1)$.

### Ví dụ minh họa

Đầu vào:
```
5 6
2 3 1 2 5
3 1
2 1 1 5
2 2 1 5
1 2 2 5
2 1 1 5
2 2 1 5
```

Mảng ban đầu: $[2, 3, 1, 2, 5]$.

- Sao chép mảng 1 → mảng 2: `ver[2] = ver[1]`. Cả hai chia sẻ cùng cây.
- Truy vấn $[1,5]$ trên mảng 1: $2+3+1+2+5 = 13$.
- Truy vấn $[1,5]$ trên mảng 2: $13$ (cây dùng chung).
- Cập nhật vị trí 2 trong mảng 2 thành 5: path-copy tạo gốc mới cho `ver[2]`. Mảng 2 thành $[2, 5, 1, 2, 5]$. Cây mảng 1 không thay đổi.
- Truy vấn $[1,5]$ trên mảng 1: vẫn $13$ (gốc cũ không bị ảnh hưởng).
- Truy vấn $[1,5]$ trên mảng 2: $2+5+1+2+5 = 15$.

Kết quả:
```
13
13
13
15
```

## Độ phức tạp

- **Thời gian:** $O(n + q \log n)$
- **Bộ nhớ:** $O(n + q \log n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Range%20Queries%20and%20Copies.cpp)
