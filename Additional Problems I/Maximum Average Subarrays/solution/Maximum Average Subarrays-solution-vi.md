# Maximum Average Subarrays - Lời giải

**ID:** 3301 | **URL:** https://cses.fi/problemset/task/3301

## Đề bài

Với mỗi vị trí $i$ từ $1$ đến $n$, hãy tìm mảng con kết thúc tại $i$ có trung bình cộng lớn nhất. Nếu có nhiều mảng con cùng đạt trung bình lớn nhất, hãy chọn mảng con có độ dài lớn nhất.

## Hướng tiếp cận

### 1. Mô hình hóa hình học

Trung bình cộng của mảng con từ $j+1$ đến $i$ được tính bằng công thức:
$$\text{Average}(j+1, i) = \frac{S[i] - S[j]}{i - j}$$

Trong đó $S[i]$ là tổng tiền tố đến vị trí $i$.

Về mặt hình học, giá trị này chính là **độ dốc (slope)** của đoạn thẳng nối hai điểm $P_j(j, S[j])$ và $P_i(i, S[i])$ trên mặt phẳng tọa độ. Bài toán trở thành: với mỗi điểm $P_i$, tìm điểm $P_j$ ($0 \le j < i$) sao cho độ dốc $P_j P_i$ là lớn nhất.

### 2. Duy trì Bao lồi dưới (Lower Convex Hull)

Để tối đa hóa độ dốc đến một điểm $P_i$ nằm bên phải, ta chỉ cần quan tâm đến các điểm $P_j$ nằm trên **bao lồi dưới** của tập hợp các điểm phía trước.

- Khi duyệt qua từng $i$, ta thêm điểm $P_{i-1}(i-1, S[i-1])$ vào bao lồi.
- Nếu điểm mới tạo ra một "góc lõm" (concave), ta loại bỏ các điểm ở đỉnh góc đó để duy trì tính lồi.

### 3. Tìm kiếm nhị phân trên bao lồi

Một tính chất quan trọng là độ dốc từ các điểm trên bao lồi dưới đến điểm truy vấn $P_i$ có tính **đơn đỉnh (unimodal)** — tức là nó sẽ tăng dần đến một giá trị cực đại rồi sau đó giảm dần.

- Điều này cho phép ta sử dụng **Tìm kiếm nhị phân** trên các điểm của bao lồi để tìm ra điểm $P_j$ tối ưu trong thời gian $O(\log n)$.
- Để ưu tiên đoạn dài nhất khi độ dốc bằng nhau, ta chọn điểm $P_j$ có chỉ số $j$ nhỏ hơn (nằm xa $P_i$ hơn về bên trái).

## Ví dụ mô phỏng

Mảng: `1 6 4 6 2 5 5`, xét tại $i=5$ ($S[5]=19$):

- Các điểm trên bao lồi hiện tại: $P_0(0,0), P_1(1,1), P_3(3,11), P_4(4,17)$.
- Độ dốc đến $P_5(5, 19)$:
  - Từ $P_0$: $(19-0)/(5-0) = 3.8$
  - Từ $P_1$: $(19-1)/(5-1) = 4.5$
  - Từ $P_3$: $(19-11)/(5-3) = 4.0$
  - Từ $P_4$: $(19-17)/(5-4) = 2.0$
- Kết quả tối ưu tại $i=5$ là $j=1$, độ dài đoạn con là $5 - 1 = 4$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — Do thao tác thêm điểm vào bao lồi mất tổng cộng $O(n)$ và mỗi truy vấn tìm kiếm nhị phân mất $O(\log n)$.
- **Bộ nhớ:** $O(n)$ để lưu mảng tổng tiền tố và các điểm trên bao lồi.

## Mã nguồn (C++)

[Mã nguồn](../code/Maximum%20Average%20Subarrays.cpp)
