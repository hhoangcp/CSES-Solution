# Lines and Queries II - Lời giải

**ID:** 3430 | **URL:** https://cses.fi/problemset/task/3430

## Phương pháp

### Tóm tắt bài toán

Xử lý truy vấn trực tuyến: (1) thêm đường thẳng $y = ax + b$ hoạt động trên đoạn $[l, r]$, (2) tìm giá trị lớn nhất trong tất cả đường đang hoạt động tại vị trí $x$. Nếu không có đường nào hoạt động, in `NO`.

### Ý tưởng chính

Bài toán mở rộng Lines and Queries I: mỗi đường chỉ hoạt động trên đoạn $[l, r]$ thay vì toàn miền. Cây Li Chao đơn thuần không thể xử lý — nó giả sử mọi đường chèn vào đều hợp lệ ở mọi điểm, nên sẽ trả về giá trị của đường không hoạt động tại điểm truy vấn.

**Giải pháp: Cây phân đoạn + logic chèn Li Chao.** Xây cây phân đoạn trên $x \in [0, m]$. Mỗi nút cây phân đoạn lưu một đường thẳng, dùng cơ chế chèn Li Chao.

**Chèn đường $f$ trên $[l, r]$:** Thực hiện cập nhật đoạn chuẩn trên cây phân đoạn. Đoạn $[l, r]$ được phân giải thành $O(\log m)$ nút bị bao phủ hoàn toàn. Tại mỗi nút như vậy, áp dụng chèn Li Chao: so sánh $f$ với đường lưu $g$ tại mid. Nếu $f$ tốt hơn tại mid, đổi chỗ để đường tốt hơn ở lại. Đường kém hơn chỉ có thể chiếm ưu thế ở một nửa (hai đường thẳng cắt nhau nhiều nhất 1 lần), nên đẩy xuống con tương ứng dựa trên độ dốc. Đệ quy này dùng chính các con của cây phân đoạn — đường đẩy xuống vẫn hợp lệ ở các con vì khoảng của nút hiện tại hoàn toàn nằm trong $[l, r]$.

**Truy vấn tại $x$:** Duyệt từ gốc đến lá tại vị trí $x$. Tại mỗi nút trên đường đi, tính giá trị đường lưu tại $x$ và lấy lớn nhất. Điều này đúng vì mọi đường hoạt động tại $x$ được chèn tại một nút bị bao phủ hoàn toàn có khoảng chứa $x$; nút đó nằm trên đường gốc-lá, và chèn Li Chao đảm bảo đường tối ưu tại mỗi vị trí trong khoảng nút hoặc được lưu tại đó, hoặc được đẩy xuống con nằm trên đường đi. Nếu kết quả là `LLONG_MIN`, không có đường nào bao phủ $x$, xuất `NO`.

**Điểm khác biệt cốt lõi so với Lines and Queries I:** Ở bài I, một cây Li Chao đủ dùng vì mọi đường trải dài toàn miền. Ở đây, cây phân đoạn giới hạn mỗi đường trong khoảng hoạt động — đường chèn trên $[l, r]$ chỉ được lưu tại các nút có khoảng nằm trong $[l, r]$, nên không bao giờ được đánh giá tại điểm ngoài $[l, r]$.

### Thuật toán

1. Xây cây phân đoạn trên $[0, m]$ ($m = 10^5$), mỗi nút khởi tạo đường $b = \text{LLONG\_MIN}$.
2. Với mỗi truy vấn:
   - Loại 1 ($a, b, l, r$): gọi `update(root, 0, m, l, r, line(a, b))`.
   - Loại 2 ($x$): gọi `query(root, 0, m, x)`. Nếu kết quả là `LLONG_MIN`, xuất `NO`; ngược lại xuất kết quả.
3. `update(i, l, r, u, v, f)`: nếu $[l, r] \subseteq [u, v]$, gọi `insertLine(i, l, r, f)`; ngược lại đệ quy xuống các con.
4. `insertLine(i, l, r, f)`: so sánh $f$ với `liChao[i]` tại mid, đổi chỗ nếu cần, đệ quy đường kém xuống một con theo độ dốc.
5. `query(i, l, r, x)`: tính `liChao[i]` tại $x$, đệ quy xuống con chứa $x$, trả về giá trị lớn nhất.

### Ví dụ minh họa

6 truy vấn từ đề bài:

| # | Truy vấn | Thao tác | Kết quả |
|---|----------|----------|---------|
| 1 | `1 1 2 1 3` | Chèn $y = x + 2$ trên $[1, 3]$ | — |
| 2 | `2 3` | $f(3) = 5$ | 5 |
| 3 | `2 4` | Không có đường tại $x = 4$ | NO |
| 4 | `1 0 4 1 5` | Chèn $y = 4$ trên $[1, 5]$ | — |
| 5 | `2 3` | $\max(5, 4) = 5$ | 5 |
| 6 | `2 4` | $f(4) = 4$ | 4 |

Kết quả: `5 NO 5 4`.

## Độ phức tạp

- **Thời gian:** $O(\log^2 m)$ mỗi chèn, $O(\log m)$ mỗi truy vấn
- **Không gian:** $O(m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Lines%20and%20Queries%20II.cpp)
