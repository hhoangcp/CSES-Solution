# Sliding Window Advertisement - Lời giải

**ID:** 3227 | **URL:** https://cses.fi/problemset/task/3227

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ tấm ván có chiều cao $h_1, h_2, \ldots, h_n$, với mỗi cửa sổ trượt gồm $k$ tấm ván liên tiếp, tìm diện tích hình chữ nhật lớn nhất lọt vào biểu đồ tần suất của cửa sổ đó. Xuất tất cả $n-k+1$ kết quả.

### Ý tưởng chính

Diện tích hình chữ nhật lớn nhất trong biểu đồ luôn được xác định bởi một tấm ván $i$ làm chiều cao ranh giới, với đáy bằng đoạn liên tiếp rộng nhất quanh $i$ mà mọi tấm ván đều có chiều cao $\ge h_i$. Với mỗi tấm ván $i$, đáy này trong một cửa sổ chính là phần giao giữa miền trội $[L[i], R[i]]$ và cửa sổ hiện hành. Khi cửa sổ trượt, phần giao này biến đổi theo hàm tuyến tính phân khúc theo biên phải của cửa sổ — tăng, rồi bằng phẳng, rồi giảm. Mỗi tấm ván đóng góp tối đa 3 đoạn đường thẳng, ta chèn tất cả vào cây phân đoạn Li Chao rồi truy vấn cực đại tại từng vị trí.

### Thuật toán

**Bước 1: Miền trội bằng ngăn xếp đơn điệu.** Với mỗi vị trí $i$, tính $L[i]$ (chỉ số đầu tiên bên trái có $h_j < h_i$; mặc định 1) và $R[i]$ (chỉ số đầu tiên bên phải có $h_j < h_i$; mặc định $n$) bằng ngăn xếp đơn điệu trong hai lượt quét, $O(n)$. Miền trội của $i$ là $[L[i], R[i]]$ với độ dài $len_i = R[i] - L[i] + 1$.

Mọi hình chữ nhật trong biểu đồ đều có một tấm ván làm chiều cao nhỏ nhất, nên lấy cực đại trên đóng góp của tất cả tấm ván sẽ bao trọn không gian nghiệm. Tấm ván $i$ nằm ngoài cửa sổ hiện hành sẽ có phần giao bằng 0 (hoặc chỉ tính phần nằm trong cửa sổ), nên không đóng góp vi phạm ranh giới cửa sổ.

**Bước 2: Hàm diện tích tuyến tính phân khúc.** Với phần tử $i$ có miền trội $[l, r]$ và biên phải cửa sổ $x$ (cửa sổ $[x-k+1, x]$), đóng góp là $h_i \cdot w(x)$ với $w(x) = \text{overlap}([l, r], [x-k+1, x])$. Khi $x$ tăng từ $l$ đến $r+k-1$, $w(x)$ có ba giai đoạn:

1. **Tăng** (hệ góc $+1$): Cửa sổ đi vào miền trội. $w(x) = x - l + 1$.
2. **Bằng phẳng** (hệ góc $0$): Cửa sổ bao trọn miền trội (hoặc miền trội nằm gọn trong cửa sổ). $w(x) = \min(k, len_i)$.
3. **Giảm** (hệ góc $-1$): Cửa sổ trượt ra khỏi miền trội. $w(x) = r + k - x$.

Vì $\text{overlap}([l, r], [x-k+1, x])$ liên tục và tuyến tính phân khúc theo $x$, mỗi giai đoạn là một đường thẳng $y = ax + b$ trên khoảng $[u, v]$ xác định, nên mỗi phần tử chèn tối đa 3 đoạn đường thẳng. Ranh giới chính xác của các giai đoạn phụ thuộc vào $len_i \ge k$ hay $len_i < k$, nhưng cấu trúc ba giai đoạn là giống nhau.

**Bước 3: Cây phân đoạn Li Chao.** Chèn tất cả đoạn đường thẳng vào cây Li Chao trên $[1, n]$. Truy vấn tại từng $x = k, k+1, \ldots, n$. Cây Li Chao duy trì bao trên (upper envelope) của tất cả đường thẳng, nên mỗi truy vấn trả về $\max_i \text{Area}_i(x)$ — diện tích hình chữ nhật lớn nhất cho cửa sổ kết thúc tại $x$.

### Ví dụ minh họa

Với $n=8$, $k=3$, chiều cao $[4,1,5,3,3,2,4,1]$:

Miền trội:
| $i$ | $h_i$ | $L[i]$ | $R[i]$ | $len_i$ |
|-----|-------|---------|---------|---------|
| 1   | 4     | 1       | 1       | 1       |
| 2   | 1     | 1       | 8       | 8       |
| 3   | 5     | 3       | 3       | 1       |
| 4   | 3     | 3       | 5       | 3       |
| 5   | 3     | 3       | 5       | 3       |
| 6   | 2     | 3       | 7       | 5       |
| 7   | 4     | 7       | 7       | 1       |
| 8   | 1     | 1       | 8       | 8       |

Xét phần tử $i=4$ ($h=3$, miền $[3,5]$, $len=3$), vì $len = k$ nên không có giai đoạn bằng phẳng:
- Tăng: $x \in [3,5]$, diện tích $= 3(x-2) = 3x - 6$. Tại $x=3$: diện tích 3; tại $x=5$: diện tích 9.
- Giảm: $x \in [6,7]$, diện tích $= 3(8-x) = 24-3x$. Tại $x=6$: diện tích 6; tại $x=7$: diện tích 3.

Kết quả truy vấn:
- $x=3$ (cửa sổ $[1,3]$): max = 5 (ván 3, chiều cao 5, độ rộng 1)
- $x=4$ (cửa sổ $[2,4]$): max = 6 (ván 4, chiều cao 3, độ rộng 2)
- $x=5$ (cửa sổ $[3,5]$): max = 9 (ván 4, chiều cao 3, độ rộng 3)
- $x=6$ (cửa sổ $[4,6]$): max = 6 (ván 6, chiều cao 2, độ rộng 3)
- $x=7$ (cửa sổ $[5,7]$): max = 6 (ván 6, chiều cao 2, độ rộng 3)
- $x=8$ (cửa sổ $[6,8]$): max = 4 (ván 7, chiều cao 4, độ rộng 1)

Kết quả: `5 6 9 6 6 4`

## Độ phức tạp

- **Thời gian:** $O(n \log^2 n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Advertisement.cpp)
