# Subarray Sum Queries - Lời giải

**ID:** 1190 | **URL:** https://cses.fi/problemset/task/1190

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, sau mỗi lần cập nhật điểm, báo cáo tổng mảng con lớn nhất. Mảng con rỗng (tổng 0) được phép.

### Ý tưởng cốt lõi

Tổng mảng con lớn nhất không có tính chất kết hợp đơn giản như sum/min/max — mảng con tối ưu có thể cắt ranh giới giữa hai nửa. Để xử lý, mỗi nút cây phân đoạn lưu **4 đại lượng**:

- **`Sum`**: tổng cả đoạn.
- **`Left`**: tổng tiền tố lớn nhất (mảng con bắt đầu từ biên trái).
- **`Right`**: tổng hậu tố lớn nhất (mảng con kết thúc tại biên phải).
- **`Max`**: tổng mảng con lớn nhất trong đoạn.

Với nút con trái $L$ (đoạn $[l, mid]$) và nút con phải $R$ (đoạn $[mid+1, r]$), công thức gộp:

$$\text{Sum} = L.\text{Sum} + R.\text{Sum}$$
$$\text{Left} = \max(L.\text{Left}, L.\text{Sum} + R.\text{Left})$$
$$\text{Right} = \max(R.\text{Right}, R.\text{Sum} + L.\text{Right})$$
$$\text{Max} = \max(L.\text{Max}, R.\text{Max}, L.\text{Right} + R.\text{Left})$$

Công thức `Max` đúng vì mọi mảng con trong $[l, r]$ hoặc nằm trọn bên trái, hoặc nằm trọn bên phải, hoặc cắt ranh giới (hậu tố trái + tiền tố phải) — ba trường hợp rời nhau và bao phủ toàn bộ. Công thức `Left` và `Right` tuân theo logic tương tự cho tiền tố/hậu tố liên tục.

Lá có giá trị $v$: `Sum = Max = Left = Right = v`. Vì mảng con rỗng được phép, xuất $\max(0, \text{root.Max})$.

### Thuật toán

1. **Xây dựng** cây phân đoạn, mỗi nút lưu (Sum, Left, Right, Max). Lá: cả bốn bằng $x_i$.
2. **Cập nhật** vị trí $k$ thành $x$: sửa lá rồi tính lại các nút cha theo công thức gộp.
3. **Xuất kết quả**: $\max(0, \text{root.Max})$ sau mỗi cập nhật.

### Ví dụ minh họa

Đầu vào:
```
5 3
1 2 -3 5 -1
2 6
3 1
2 -2
```

Mảng: $[1, 2, -3, 5, -1]$.

- Cập nhật vị trí 2 thành 6: mảng thành $[1, 6, -3, 5, -1]$. Root.Max $= 9$ (mảng con $[1, 6, -3, 5]$). Đáp án $= \max(0, 9) = 9$.
- Cập nhật vị trí 3 thành 1: mảng thành $[1, 6, 1, 5, -1]$. Root.Max $= 13$ (mảng con $[1, 6, 1, 5]$). Đáp án $= \max(0, 13) = 13$.
- Cập nhật vị trí 2 thành $-2$: mảng thành $[1, -2, 1, 5, -1]$. Root.Max $= 6$ (mảng con $[1, 5]$). Đáp án $= \max(0, 6) = 6$.

Kết quả:
```
9
13
6
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Subarray%20Sum%20Queries.cpp)
