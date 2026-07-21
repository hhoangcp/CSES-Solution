# Hành Trình Mã - Lời giải

**ID:** 1689 | **URL:** https://cses.fi/problemset/task/1689

## Phương pháp

### Tóm tắt bài toán

Cho vị trí xuất phát trên bàn cờ $8 \times 8$, tìm một dãy nước đi của quân mã thăm mỗi ô đúng một lần. Quân mã di chuyển theo hình chữ L: hai ô theo một chiều và một ô theo chiều vuông góc.

### Ý tưởng chính

Bài toán tương đương tìm đường Hamilton trên đồ thị nước đi của mã. Duyệt quay lui thông thường không khả thi do số nhánh quá lớn, nên ta dùng **heuristic Warnsdorff** — một chiến lược tham lam gần như luôn tìm được lời giải trong lần thử đầu tiên:

> Từ vị trí hiện tại, luôn chọn nước đi đến ô chưa thăm có **ít ô kề chưa thăm nhất** (bậc tự do nhỏ nhất).

Nguyên lý: các ô có ít lối vào (góc, biên) sẽ bị khóa nếu để đến sau — các lối vào bị "tiêu thụ" bởi các nước đi trước đó. Việc thăm sớm các ô này giúp giữ cho các ô trung tâm (nhiều lối vào) vẫn tiếp cận được ở giai đoạn sau. Trên bàn cờ $8 \times 8$, heuristic này thành công với xác suất rất cao.

Khi nhiều ô kề có cùng bậc tự do nhỏ nhất, việc ngẫu nhiên hóa thứ tự duyệt giúp phá hòa. Nếu thuật toán bị kẹt trước khi thăm đủ 64 ô, nó sẽ khởi động lại. Thực tế chỉ cần 1–3 lần thử để hội tụ.

### Thuật toán

1. Khởi tạo tất cả ô là chưa thăm. Đánh dấu ô xuất phát là bước 1.
2. Với mỗi bước trong 63 bước còn lại:
   - Với 8 hướng di chuyển của mã (bắt đầu từ một chỉ số ngẫu nhiên), tính bậc của ô đích — số ô chưa thăm kề với nó.
   - Di chuyển đến ô chưa thăm có bậc nhỏ nhất.
3. Nếu không còn nước đi hợp lệ trước khi đủ 64 ô, xóa bàn cờ và thực hiện lại từ bước 1.

### Ví dụ minh họa

Input: `2 1` (bắt đầu tại hàng 1, cột 2).

Một kết quả hợp lệ:

```
 8  1 10 13  6  3 20 17
11 14  7  2 19 16 23  4
26  9 12 15 24  5 18 21
49 58 25 28 51 22 33 30
40 27 50 59 32 29 52 35
57 48 41 44 37 34 31 62
42 39 46 55 60 63 36 53
47 56 43 38 45 54 61 64
```

Tại ô xuất phát $(1,2)$, mã có 3 ô kề hợp lệ:

| Ô kề    | Bậc tự do |
|---------|-----------|
| $(3,3)$ | 7         |
| $(2,4)$ | 5         |
| $(3,1)$ | 3         |

Warnsdorff chọn $(3,1)$ vì có bậc tự do nhỏ nhất (3). Quá trình lặp lại tương tự cho đến khi thăm đủ 64 ô.

## Độ phức tạp

- **Thời gian:** $O(N^2)$ kỳ vọng, với $N$ là kích thước bàn cờ
- **Không gian:** $O(N^2)$

## Mã nguồn (C++)

[Mã nguồn](../code/Knight%27s%20Tour.cpp)
