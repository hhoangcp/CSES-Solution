# Stick Difference - Lời giải

**ID:** 3401 | **URL:** https://cses.fi/problemset/task/3401

## Đề bài

Bạn được cho $n$ thanh gỗ có độ dài $a_1, a_2, \ldots, a_n$. Bạn phải thực hiện đúng $k$ lần cắt các thanh gỗ sao cho số thanh gỗ trở thành $n + k$. Sau khi cắt, hiệu giữa độ dài thanh dài nhất và ngắn nhất phải càng nhỏ càng tốt. Nhiệm vụ của bạn là tính hiệu nhỏ nhất có thể đạt được cho tất cả các giá trị $k = 1, 2, \ldots, m$.

## Hướng tiếp cận

### Bước 1: Ép thanh Max nhỏ nhất (Mảng `H` và `seg`)

Dùng max-heap, mỗi phần tử là $(\lceil a_i/p \rceil,\ p,\ id)$. Tại mỗi bước, lấy thanh sinh ra mảnh dài nhất để cắt thêm 1 nhát ($p \to p+1$). Gọi $H[k]$ là kích thước Max nhỏ nhất sau $k$ nhát cắt. Đồng thời ghi nhận `seg[k] = (Min thực tế, Max thực tế)` của cấu hình này.

**Tính tối ưu của $H[k]$ (Bổ đề Trao đổi):** Giả sử tồn tại cách cắt $k$ nhát cho Max nhỏ hơn $H[k]$. Trong cách cắt đó, nếu có nhát cắt không cắt thanh dài nhất hiện tại mà cắt thanh $t$, đổi sang cắt thanh dài nhất sẽ cho Max $\le$ trước đổi (thanh dài nhất bị chia nhỏ hơn, $t$ không bị cắt vẫn $\le$ thanh dài nhất). Lặp lại trao đổi, chiến lược luôn cắt thanh dài nhất là tối ưu. Chia đều cho mảnh dài nhất $\lceil a_i/p \rceil$ là tối ưu nội bộ.

**Tính duy nhất của `seg[k]`:** Để ép Max xuống đúng $H[k]$, ta bắt buộc tiêu đúng $k$ nhát cắt cho các thanh dài, không còn nhát dư để điều chỉnh thanh ngắn. Cấu hình cắt là duy nhất, `seg[k].fst` phản ánh chính xác Min bị rớt trong cấu hình bắt buộc đó.

### Bước 2: Giữ thanh Min lớn nhất (Mảng `L`)

Dùng max-heap theo giá trị $\lfloor a_i/p \rfloor$: luôn cắt thanh có mảnh ngắn nhất lớn nhất. Gọi $L[k]$ là giới hạn trần tuyệt đối của Min sau $k$ nhát cắt.

**Tính tối ưu của $L[k]$ (Bổ đề Trao đổi):** Nếu cắt thanh $t$ (có $\lfloor a_t/p_t \rfloor$ nhỏ) thay vì thanh $s$ (có $\lfloor a_s/p_s \rfloor$ lớn hơn), đổi cắt từ $t$ sang $s$ cho mảnh ngắn nhất của $s$ là $\lfloor a_s/(p_s+1) \rfloor \ge \lfloor a_t/(p_t+1) \rfloor$, không giảm Min toàn cục. Lặp lại thu được chiến lược tham lam.

**Hệ quả:** Mọi cách cắt $k$ nhát đều có Min $\le L[k]$. Hệ thống cấp cho ta một quỹ ít nhất $k$ nhát cắt an toàn mà không làm Min vượt $L[k]$.

### Bước 3: Tổ hợp lai ghép (Cửa sổ trượt)

Với mỗi $k$, ta tìm cấu hình "lai": dùng $i$ nhát đầu để ép Max (theo `seg[i]`), $k-i$ nhát dư để gọt tiếp mà không làm Min tụt quá sâu.

Dùng 2 con trỏ `pA`, `pR` và `multiset st`:
- `pA` mở rộng: đưa các cấu hình có $\text{Max} \ge H[k]$ vào `st`.
- `pR` thu hẹp: loại các cấu hình có $\text{Min} > L[k]$ khỏi `st`.

Đáp án cho $k$ nhát cắt là min của 2 trường hợp:
1. **`*st.begin()`** (Min vỡ vụn dưới đáy $L[k]$): cấu hình trong `st` ($pR \le i < pA$), hiệu số là `seg[i].snd - seg[i].fst`.
2. **`seg[pR - 1].snd - L[k]`** (Hạ cánh an toàn tại $L[k]$): tại trạng thái $pR-1$, mọi mảnh đều $> L[k]$. Còn nợ $k - (pR-1)$ nhát. Theo tính chất $L[k]$, quỹ nhát cắt an toàn còn lại lớn hơn nợ, nên dùng Chiến lược B cho nhát nợ sẽ làm Min giảm đồng đều và **dừng chính xác tại $L[k]$**.

### Ví dụ

$n = 3, m = 3$, độ dài: $[7, 3, 2]$.

- $H[1] = 4$, $H[2] = 3$, $H[3] = 3$; $L[1] = 2$, $L[2] = 2$, $L[3] = 1$.
- Kết quả: $k=1$: $4-2=2$; $k=2$: $3-2=1$; $k=3$: $3-1=2$.

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$ cho thao tác heap + $O(m \log m)$ cho cửa sổ trượt.
- **Bộ nhớ:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Stick%20Difference.cpp)
