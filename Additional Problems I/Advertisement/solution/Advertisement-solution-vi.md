# Advertisement - Lời giải

**ID:** 1142 | **URL:** https://cses.fi/problemset/task/1142

## Đề bài

Cho hàng rào gồm $n$ tấm ván, mỗi tấm có chiều rộng $1$ và chiều cao $h_i$. Tìm diện tích lớn nhất của một hình chữ nhật có thể đặt trên hàng rào này.

## Hướng tiếp cận

### Bước 1: Phân tích bài toán

Mỗi tấm ván có chiều rộng 1, nên một hình chữ nhật trên hàng rào sẽ bao phủ một đoạn liên tiếp các tấm ván với chiều cao bằng chiều cao của tấm ngắn nhất trong đoạn. Diện tích = chiều cao tối thiểu $\times$ chiều rộng đoạn.

Với mỗi tấm ván $i$, hình chữ nhật lớn nhất sử dụng toàn bộ chiều cao $h[i]$ phải mở rộng sang trái và phải càng xa càng tốt, miễn là tất cả tấm trong phạm vi có chiều cao $\geq h[i]$.

### Bước 2: Tính biên trái và biên phải bằng ngăn xếp đơn điệu

Gọi $L[i]$ là chỉ số gần nhất bên trái $i$ sao cho $h[L[i]] < h[i]$, và $R[i]$ là chỉ số gần nhất bên phải $i$ sao cho $h[R[i]] < h[i]$. Hình chữ nhật lớn nhất sử dụng toàn bộ chiều cao $h[i]$ có diện tích:

$$\text{area}(i) = h[i] \times (R[i] - L[i] - 1)$$

Tính $L[i]$ bằng ngăn xếp đơn điệu tăng:
- Quét từ trái sang phải, duy trì ngăn xếp chứa các chỉ số có chiều cao tăng dần.
- Khi gặp $h[i]$: pop tất cả phần tử có chiều cao $\geq h[i]$. Sau khi pop, đỉnh ngăn xếp (nếu có) chính là $L[i]$; nếu ngăn xếp rỗng thì $L[i] = 0$.
- Push $i$ vào ngăn xếp.

Tính $R[i]$ tương tự bằng cách quét từ phải sang trái.

### Chứng minh tính đúng

**Ngăn xếp đơn điệu đúng:** Sau khi pop tất cả phần tử $\geq h[i]$, đỉnh ngăn xếp chứa chỉ số gần nhất bên trái có chiều cao nhỏ hơn $h[i]$. Các phần tử đã pop có chiều cao $\geq h[i]$, nên chúng không giới hạn việc mở rộng hình chữ nhật của $h[i]$ sang trái.

**Công thức diện tích:** Hình chữ nhật sử dụng chiều cao $h[i]$ mở rộng từ $L[i]+1$ đến $R[i]-1$, tức chiều rộng là $R[i] - L[i] - 1$. Mọi tấm trong $[L[i]+1, R[i]-1]$ đều có chiều cao $\geq h[i]$, và $h[L[i]] < h[i]$, $h[R[i]] < h[i]$ nên không thể mở rộng thêm.

**Tính tối ưu:** Mọi hình chữ nhật hợp lệ đều có chiều cao bằng $h[i]$ với một $i$ nào đó trong đoạn. Vậy duyệt tất cả $i$ và lấy max đủ để tìm diện tích lớn nhất.

### Ví dụ

$n = 8$, $h = [4, 1, 5, 3, 3, 2, 4, 1]$:

| $i$ | $h[i]$ | $L[i]$ | $R[i]$ | Chiều rộng $(R-L-1)$ | Diện tích |
|-----|--------|--------|--------|----------------------|-----------|
| 1 | 4 | 0 | 2 | 1 | 4 |
| 2 | 1 | 0 | 9 | 8 | 8 |
| 3 | 5 | 2 | 4 | 1 | 5 |
| 4 | 3 | 2 | 6 | 3 | 9 |
| 5 | 3 | 2 | 6 | 3 | 9 |
| 6 | 2 | 2 | 8 | 5 | 10 |
| 7 | 4 | 6 | 8 | 1 | 4 |
| 8 | 1 | 0 | 9 | 8 | 8 |

Kết quả: $10$ (tại $i=6$, hình chữ nhật bao phủ các tấm từ vị trí $3$ đến $7$).

## Độ phức tạp

- **Thời gian:** $O(n)$ (mỗi phần tử push/pop đúng 1 lần)
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Advertisement.cpp)
