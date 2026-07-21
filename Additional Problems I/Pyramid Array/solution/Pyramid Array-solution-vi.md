# Pyramid Array - Lời giải

**ID:** 1747 | **URL:** https://cses.fi/problemset/task/1747

## Đề bài

Cho mảng gồm $n$ số nguyên phân biệt, yêu cầu tìm số phép đổi chỗ hai phần tử kề nhau ít nhất để biến mảng ban đầu thành mảng hình kim tự tháp (tăng dần rồi giảm dần, hoặc chỉ tăng/giảm).

## Hướng tiếp cận

### 1. Phân tích bài toán

- **Mảng hình kim tự tháp:** Có dạng $x_1 < x_2 < \dots < x_k > x_{k+1} > \dots > x_n$.
- **Phép đổi chỗ kề (Adjacent Swap):** Số phép đổi chỗ kề tối thiểu để đưa một phần tử về đúng vị trí tỉ lệ thuận với số lượng phần tử mà nó phải "đi xuyên qua".
- **Tính chất tham lam:** Trong mảng kim tự tháp, các phần tử nhỏ nhất sẽ nằm ở hai đầu (trái hoặc phải) và các phần tử lớn dần sẽ tiến vào giữa (đỉnh kim tự tháp). Với mỗi phần tử, ta có hai lựa chọn: di chuyển nó về phía biên trái hoặc biên phải của mảng.

### 2. Hướng tiếp cận bằng Cây Fenwick (BIT)

Để tối ưu hóa số phép đổi chỗ, mỗi phần tử $a[i]$ sẽ chọn hướng di chuyển (trái hoặc phải) sao cho số lượng phần tử nó phải băng qua là ít nhất.

- **Bước 1: Nén tọa độ:** Vì các giá trị $x_i$ có thể lên tới $10^9$, ta cần sắp xếp mảng và ánh xạ chúng về các giá trị từ $1 \dots n$ để sử dụng BIT.
- **Bước 2: Tính số phần tử lớn hơn bên trái:** Quét mảng từ trái sang phải. Với mỗi phần tử $a[i]$, số lượng phần tử nhỏ hơn đã xuất hiện bên trái là `Query(a[i])`. Suy ra số lượng phần tử **lớn hơn** bên trái là $inv[i] = (i - 1) - Query(a[i])$.
- **Bước 3: Tính số phần tử lớn hơn bên phải:** Reset BIT, quét mảng từ phải sang trái. Số lượng phần tử nhỏ hơn đã xuất hiện bên phải là `Query(a[i])`. Suy ra số lượng phần tử **lớn hơn** bên phải là $(n - i) - Query(a[i])$.
- **Bước 4: Tính tổng tối ưu:** Với mỗi phần tử, số bước di chuyển ít nhất là giá trị nhỏ hơn giữa hai hướng. Kết quả là:
  $$Ans = \sum_{i=1}^{n} \min(inv[i], (n - i) - Query(a[i]))$$

### 3. Chứng minh tính đúng đắn

- **Chiến lược tham lam:** Khi xét các phần tử theo thứ tự từ nhỏ đến lớn, phần tử nhỏ nhất hiện tại có thể được đẩy ra biên trái hoặc biên phải của mảng hiện tại mà không làm ảnh hưởng đến thứ tự tương đối của các phần tử lớn hơn.
- **Số phép đổi chỗ:** Khi phần tử nhỏ nhất di chuyển ra biên, nó chỉ cần đổi chỗ với các phần tử lớn hơn đang cản đường nó. Do đó, chi phí chính là số lượng phần tử lớn hơn hiện đang nằm bên trái hoặc bên phải nó, và ta chọn hướng rẻ hơn.

## Ví dụ minh họa

Mảng: `2 1 5 3`.

1. Phần tử nhỏ nhất là `1`. Bên trái nó có 1 số lớn hơn (`2`), bên phải có 2 số lớn hơn (`5, 3`).
2. Đẩy `1` sang trái mất 1 bước: `1 2 5 3` (Đây đã là mảng kim tự tháp).
3. Kết quả: **1** bước.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — Do thao tác sắp xếp nén tọa độ và $2$ lần quét mảng với các truy vấn BIT.
- **Bộ nhớ:** $O(n)$ — Để lưu trữ các mảng phụ và cấu trúc BIT.

## Mã nguồn (C++)

[Mã nguồn](../code/Pyramid%20Array.cpp)
