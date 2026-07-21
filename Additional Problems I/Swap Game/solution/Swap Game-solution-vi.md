# Swap Game - Lời giải

**ID:** 1670 | **URL:** https://cses.fi/problemset/task/1670

## Đề bài

Cho lưới $3 \times 3$ chứa số 1-9, tìm số phép đổi chỗ liền kề (ngang hoặc dốc) tối thiểu để đạt trạng thái đích $\begin{pmatrix} 1&2&3\\4&5&6\\7&8&9 \end{pmatrix}$.

## Hướng tiếp cận

### Không gian trạng thái

Có $9! = 362880$ trạng thái (hoán vị 9 số), đủ nhỏ để duyệt và lưu trữ toàn bộ.

### Mã hóa trạng thái

Mã hóa mỗi lưới thành số nguyên hệ cơ số 9: $\text{state} = \sum_{i=0}^{8} (grid[i] - 1) \times 9^i$. Mỗi hoán vị ánh xạ 1-1 với một số nguyên, cho phép dùng mảng `visited` 1 chiều. Để tiết kiệm bộ nhớ, dịch chuyển chỉ số bằng giá trị mã hóa nhỏ nhất.

### BFS

Vì mỗi phép đổi có chi phí 1, BFS tìm đường đi ngắn nhất:

1. Đẩy trạng thái ban đầu vào hàng đợi, khoảng cách 0.
2. Với mỗi trạng thái, thử 12 phép đổi kề hợp lệ (6 ngang: vị trí $i \bmod 3 < 2$, và 6 dốc: vị trí $i < 6$).
3. Đánh dấu visited khi lần đầu phát hiện; BFS đảm bảo khoảng cách ngắn nhất.
4. Dừng khi đạt trạng thái đích.

### Ví dụ

```
2 1 3        1 2 3
7 5 9   →    4 5 6
8 4 6        7 8 9
```

BFS tìm số bước tối thiểu: **4**.

## Độ phức tạp

- **Thời gian:** $O(9!) = O(362880)$ — trường hợp xấu nhất duyệt mọi hoán vị
- **Bộ nhớ:** $O(9!)$ cho mảng visited

## Mã nguồn (C++)

[Mã nguồn](../code/Swap%20Game.cpp)
