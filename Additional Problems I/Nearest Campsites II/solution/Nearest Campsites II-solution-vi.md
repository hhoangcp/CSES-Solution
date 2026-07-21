# Nearest Campsites II - Lời giải

**ID:** 3307 | **URL:** https://cses.fi/problemset/task/3307

## Đề bài

Trên lưới tọa độ $10^6 \times 10^6$, cho $n$ điểm đã đặt trước (Reserved) và $m$ điểm trống (Free). Với mỗi điểm trống, hãy tìm khoảng cách Manhattan ngắn nhất đến một điểm đã đặt bất kỳ. Xuất kết quả của từng điểm trống theo đúng thứ tự nhập vào.

## Hướng tiếp cận

### 1. Phân tích 4 góc phần tư

Khoảng cách Manhattan $|x_1 - x_2| + |y_1 - y_2|$ được xử lý bằng cách chia không gian quanh mỗi điểm trống thành 4 vùng (góc phần tư). Trong mỗi vùng, công thức phá dấu giá trị tuyệt đối sẽ khác nhau:

<div align="center"><img src="../../../images/4-quadrants.png" width="400"/></div>

> **Chú thích ảnh:** Xét điểm $F$ là gốc tọa độ. Quadrant III (dấu $-,-$) tương ứng với vùng **Trái - Dưới**, Quadrant II (dấu $-,+$) tương ứng với vùng **Trái - Trên**, Quadrant IV (dấu $+,-$) tương ứng với vùng **Phải - Dưới**, Quadrant I (dấu $+,+$) tương ứng với vùng **Phải - Trên**.

- **Vùng Trái - Dưới** ($x_R \le x_F, y_R \le y_F$): $d = (x_F + y_F) - (x_R + y_R)$.
- **Vùng Trái - Trên** ($x_R \le x_F, y_R > y_F$): $d = (x_F - y_F) - (x_R - y_R)$.
- **Vùng Phải - Dưới** ($x_R > x_F, y_R \le y_F$): $d = (-x_F + y_F) - (-x_R + y_R)$.
- **Vùng Phải - Trên** ($x_R > x_F, y_R > y_F$): $d = (-x_F - y_F) - (-x_R - y_R)$.

### 2. Thuật toán Quét và BIT

Chúng ta sử dụng **Cây Fenwick (BIT)** để duy trì giá trị lớn nhất của biểu thức chứa $(x_R, y_R)$ trong mỗi vùng.

1. **Chuyển đổi tọa độ:** Thực hiện 4 lượt quét. Ở mỗi lượt, ta biến đổi tọa độ (lật trục $x$ hoặc $y$) để đưa vùng cần xét về trạng thái "Trái - Dưới".
2. **Quét (Sweep):** Sắp xếp tất cả các điểm theo hoành độ $x$ tăng dần.
3. **Cập nhật và Truy vấn BIT:**
   - Khi gặp điểm đã đặt $R$: Cập nhật giá trị biến đổi (ví dụ: $x_R + y_R$) vào BIT tại vị trí tung độ $y_R$. BIT được cấu hình để tìm giá trị **Max**.
   - Khi gặp điểm trống $F$: Truy vấn BIT để lấy giá trị cực đại trong khoảng $[0, y_F]$. Khoảng cách ứng viên bằng giá trị biến đổi của $F$ trừ đi giá trị cực đại lấy từ BIT.
4. **Lưu kết quả:** Với mỗi điểm trống $i$, ta duy trì $ans[i] = \min(ans[i], \text{khoảng cách ứng viên})$ qua cả 4 lượt quét.

### 3. Khác biệt so với bài I

Khác với bài I (chỉ lấy max tổng thể), bài II yêu cầu xuất kết quả cho **từng** điểm trống. Sau khi duyệt cả 4 biến đổi, $ans[i]$ chứa khoảng cách Manhattan tối thiểu đến chỗ đã đặt gần nhất.

## Ví dụ minh họa

Với 4 điểm đã đặt $(1,1), (5,2), (2,6), (4,7)$ và 2 điểm trống $(1,3), (7,5)$:

- **Điểm trống (1,3):**
  - Khoảng cách đến $(1,1)$ là $|1-1| + |3-1| = 2$.
  - Đây là khoảng cách ngắn nhất của nó.
- **Điểm trống (7,5):**
  - Khoảng cách đến $(5,2)$ là $|7-5| + |5-2| = 5$.
  - Khoảng cách đến $(4,7)$ là $|7-4| + |5-7| = 5$.
  - Khoảng cách ngắn nhất của nó là 5.

**Kết quả:** `2 5`.

## Độ phức tạp

- **Thời gian:** $O((n + m) \log (n + m))$ — Do thực hiện 4 lượt quét, mỗi lượt bao gồm sắp xếp và thao tác BIT.
- **Bộ nhớ:** $O(n + m)$ — Cần lưu trữ tọa độ, mảng sự kiện và mảng kết quả cho từng điểm trống.

## Mã nguồn (C++)

[Mã nguồn](../code/Nearest%20Campsites%20II.cpp)
