# Bubble Sort Rounds II - Lời giải

**ID:** 3152 | **URL:** https://cses.fi/problemset/task/3152

## Đề bài

Cho mảng $n$ số nguyên và số nguyên $k$. Hãy tìm nội dung của mảng sau khi thực hiện $k$ vòng sắp xếp nổi bọt (Bubble Sort). Lưu ý rằng $k$ có thể rất lớn ($10^9$), vượt quá số vòng cần thiết để mảng được sắp xếp hoàn toàn.

## Hướng tiếp cận

### 1. Phân tích hiệu ứng sau $k$ vòng nổi bọt

Như đã biết ở bài trước, trong mỗi vòng của Bubble Sort, một phần tử có thể "nổi" lên (dịch sang trái) tối đa 1 vị trí. Do đó, sau $k$ vòng:

- Một phần tử ban đầu ở vị trí $i$ có thể di chuyển đến bất kỳ vị trí nào trong đoạn $[i-k, n-1]$ tùy thuộc vào giá trị của nó so với các phần tử xung quanh.
- Quan trọng hơn, tại vị trí $i$ của mảng kết quả, giá trị được chọn sẽ là **giá trị nhỏ nhất** trong số các phần tử chưa được chọn nằm trong phạm vi có thể "nổi" tới vị trí $i$ sau $k$ vòng.

### 2. Ý tưởng giải thuật: Cửa sổ trượt và Min-Heap

Để mô phỏng hiệu ứng này một cách hiệu quả mà không cần chạy từng vòng lặp $O(k \cdot n)$, ta sử dụng một hàng đợi ưu tiên (Min-Heap) để quản lý các ứng viên cho từng vị trí:

1. Duyệt qua từng vị trí $i$ từ $0$ đến $n-1$ của mảng kết quả.
2. Với mỗi vị trí $i$, tất cả các phần tử từ mảng gốc chưa được đưa vào Heap và có chỉ số nằm trong khoảng $[0, i+k]$ sẽ được đẩy vào Min-Heap.
3. Phần tử nhỏ nhất hiện tại trong Heap sẽ được lấy ra và đặt vào vị trí $i$ của mảng kết quả.
4. Lặp lại cho đến khi điền đầy mảng kết quả.

### 3. Chứng minh tính đúng đắn

- **Tính khả thi:** Một phần tử tại vị trí $j$ trong mảng gốc có thể xuất hiện tại vị trí $i$ trong kết quả nếu và chỉ nếu $j - i \le k$ (tức $j \le i+k$). Điều này khớp với việc ta nạp các phần tử vào Heap tới chỉ số $i+k$.
- **Tính tham lam:** Bubble Sort luôn ưu tiên đưa các phần tử nhỏ hơn lên trước. Việc lấy `pq.top()` (phần tử nhỏ nhất) đảm bảo mô phỏng đúng thứ tự ưu tiên của thuật toán nổi bọt.

### Ví dụ mô phỏng

Mảng: `3 2 4 1 4`, $k = 2$.

| Vị trí $i$ | Đoạn nạp thêm vào Heap | Heap (trước khi lấy ra) | Kết quả $res[i]$ |
|:---|:---|:---|:---|
| 0 | $a[0 \dots 2]: \{3, 2, 4\}$ | $\{2, 3, 4\}$ | **2** |
| 1 | $a[3 \dots 3]: \{1\}$ | $\{1, 3, 4\}$ | **1** |
| 2 | $a[4 \dots 4]: \{4\}$ | $\{3, 4, 4\}$ | **3** |
| 3 | (Không còn) | $\{4, 4\}$ | **4** |
| 4 | (Không còn) | $\{4\}$ | **4** |

Kết quả cuối cùng: `2 1 3 4 4`.

### Lưu ý về trường hợp $k$ lớn

Nếu $k \ge n-1$, mảng sẽ được sắp xếp hoàn toàn. Thuật toán dùng Min-Heap vẫn hoạt động chính xác trong trường hợp này vì phạm vi nạp vào Heap sẽ nhanh chóng bao phủ toàn bộ mảng gốc, tương đương với việc thực hiện `sort` toàn bộ.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$. Mỗi phần tử được nạp vào và lấy ra khỏi Min-Heap đúng một lần, mỗi thao tác tốn $O(\log n)$.
- **Bộ nhớ:** $O(n)$ để lưu trữ mảng gốc, mảng kết quả và hàng đợi ưu tiên.

## Mã nguồn (C++)

[Mã nguồn](../code/Bubble%20Sort%20Rounds%20II.cpp)
