# Distinct Values Splits - Lời giải

**ID:** 3190 | **URL:** https://cses.fi/problemset/task/3190

## Đề bài

Cho một mảng gồm $n$ số nguyên. Bạn cần đếm số cách chia mảng này thành các đoạn liên tiếp sao cho mỗi đoạn đều chỉ chứa các giá trị phân biệt (không có giá trị nào lặp lại trong cùng một đoạn). Kết quả được tính theo modulo $10^9 + 7$.

## Hướng tiếp cận

### 1. Công thức Quy hoạch động (DP)

Gọi $dp[i]$ là số cách chia hợp lệ cho tiền tố gồm $i$ phần tử đầu tiên ($a[1 \dots i]$).

- Trường hợp cơ sở: $dp[0] = 1$ (có một cách chia duy nhất cho mảng rỗng).
- Để tính $dp[i]$, ta có thể đặt vết cắt cuối cùng tại vị trí $j$ ($0 \le j < i$). Khi đó, cách chia là hợp lệ nếu:
  1. Tiền tố $a[1 \dots j]$ đã được chia hợp lệ (có $dp[j]$ cách).
  2. Đoạn cuối cùng $a[j+1 \dots i]$ chứa các giá trị phân biệt.
- Công thức: $dp[i] = \sum dp[j]$ với mọi $j$ thỏa mãn điều kiện đoạn $a[j+1 \dots i]$ gồm các giá trị phân biệt.

### 2. Tối ưu hóa bằng Hai con trỏ

Với mỗi vị trí kết thúc $i$, tồn tại một vị trí bắt đầu nhỏ nhất $L[i]$ sao cho đoạn $a[L[i] \dots i]$ chứa các giá trị phân biệt. Khi đó, mọi vị trí cắt $j$ hợp lệ phải nằm trong khoảng $[L[i]-1, i-1]$.

- Sử dụng kỹ thuật hai con trỏ phối hợp với một cấu trúc dữ liệu (như `std::map` hoặc mảng đánh dấu) để lưu vị trí xuất hiện cuối cùng của từng giá trị.
- Khi con trỏ phải $i$ tăng lên, nếu gặp một giá trị đã tồn tại trong đoạn hiện tại, con trỏ trái $j$ sẽ được đẩy lên vị trí ngay sau lần xuất hiện trước đó của giá trị đó.

### 3. Tối ưu hóa tổng khoảng bằng Mảng cộng dồn

Thay vì tính tổng $dp[j]$ bằng vòng lặp (tốn $O(n)$), ta sử dụng mảng tổng tiền tố $pre[i] = \sum_{k=0}^{i} dp[k]$ để tính tổng trong $O(1)$.

- Công thức tối ưu: $dp[i] = pre[i-1] - pre[L[i]-2]$.
- Lưu ý: Nếu $L[i]-2 < 0$, ta coi giá trị $pre$ tại đó bằng $0$.

### Chứng minh tính đúng đắn

- **Tính toàn vẹn:** Mọi cách chia mảng kết thúc tại $i$ đều có đoạn cuối cùng $a[j+1 \dots i]$ thỏa mãn điều kiện phân biệt. Khoảng $[L[i], i]$ bao quát toàn bộ các điểm bắt đầu hợp lệ này.
- **Tính đơn điệu:** Khi $i$ tăng, $L[i]$ chỉ có thể giữ nguyên hoặc tăng lên (dịch sang phải) vì việc thêm phần tử chỉ có thể làm tăng khả năng bị trùng lặp, không bao giờ làm giảm đi.

## Ví dụ mô phỏng

Mảng: `1 2 1 3`, $n=4$.

| $i$ | $a[i]$ | Đoạn phân biệt dài nhất kết thúc tại $i$ | $j$ hợp lệ ($j \in [L-1, i-1]$) | $dp[i]$ |
|:---|:---|:---|:---|:---|
| 0 | - | - | - | $dp[0]=1$ |
| 1 | 1 | `[1]` | $j \in [0, 0]$ | $dp[1] = dp[0] = 1$ |
| 2 | 2 | `[1, 2]` | $j \in [0, 1]$ | $dp[2] = dp[0] + dp[1] = 2$ |
| 3 | 1 | `[2, 1]` | $j \in [1, 2]$ | $dp[3] = dp[1] + dp[2] = 3$ |
| 4 | 3 | `[2, 1, 3]` | $j \in [1, 3]$ | $dp[4] = dp[1] + dp[2] + dp[3] = 6$ |

Kết quả: **6** cách chia.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ nếu dùng `std::map` hoặc $O(n)$ nếu dùng mảng đánh dấu/`unordered_map`.
- **Bộ nhớ:** $O(n)$ để lưu mảng $dp$, $pre$ và vị trí xuất hiện cuối cùng của các phần tử.

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Splits.cpp)
