# Bubble Sort Rounds I - Lời giải

**ID:** 3151 | **URL:** https://cses.fi/problemset/task/3151

## Đề bài

Cho một mảng gồm $n$ số nguyên, yêu cầu tính số vòng (round) quét từ trái sang phải của thuật toán Sắp xếp nổi bọt (Bubble Sort) để mảng trở nên hoàn toàn được sắp xếp.

## Hướng tiếp cận

### 1. Cơ chế dịch chuyển trong Bubble Sort

Trong một vòng quét của Bubble Sort từ vị trí $0$ đến $n-1$:

- **Dịch chuyển sang phải:** Một phần tử lớn có thể "trôi" liên tục về phía cuối mảng và thay đổi nhiều vị trí trong cùng một vòng quét nếu nó liên tục lớn hơn các phần tử kề sau.
- **Dịch chuyển sang trái:** Một phần tử chỉ có thể dịch chuyển sang trái tối đa 1 vị trí trong mỗi vòng. Điều này xảy ra khi nó nhỏ hơn phần tử ngay bên trái và thực hiện một phép đổi chỗ (swap).

### 2. Ý tưởng giải thuật

Vì mỗi vòng quét chỉ cho phép một số "nhích" sang trái thêm 1 đơn vị, nên thời gian để mảng được sắp xếp xong sẽ phụ thuộc vào phần tử cần phải di chuyển sang trái nhiều nhất.

**Công thức tính toán:**

- Gọi vị trí ban đầu của một giá trị trong mảng chưa sắp xếp là $pos_{old}$.
- Gọi vị trí của giá trị đó trong mảng sau khi đã sắp xếp là $pos_{new}$.
- Số vòng cần thiết để phần tử này về đúng vị trí là hiệu số $(pos_{old} - pos_{new})$.
- Kết quả cuối cùng là giá trị lớn nhất của hiệu số này trên toàn bộ mảng: $Ans = \max(0, \max_i(pos_{old_i} - pos_{new_i}))$.

### 3. Chứng minh tính đúng đắn

**Cận dưới:** Một phần tử ở vị trí $i$ muốn về vị trí $j$ (với $i > j$) bắt buộc phải trải qua ít nhất $i - j$ vòng vì mỗi vòng nó chỉ tiến về trái được 1 bước.

**Cận trên:** Các phần tử lớn dịch chuyển sang phải không bị giới hạn số bước trong một vòng, nên chúng sẽ không bao giờ là "nút thắt" ngăn cản việc sắp xếp. Các phần tử nhỏ (cần dịch trái) cũng không chặn đường nhau: nếu hai phần tử cùng cần dịch trái, phần tử nằm bên trái hơn sẽ về đích trước hoặc đồng thời, không làm chậm tốc độ dịch chuyển của phần tử phía sau nó.

### Ví dụ minh họa

Xét mảng: `3 2 4 1 4` (Chỉ số từ $0$ đến $4$).

Mảng đã sắp xếp: `1 2 3 4 4`.

| Giá trị | Chỉ số cũ ($pos_{old}$) | Chỉ số mới ($pos_{new}$) | Độ lệch ($pos_{old} - pos_{new}$) |
|---------|-------------------------|--------------------------|-----------------------------------|
| 3 | 0 | 2 | $-2$ |
| 2 | 1 | 1 | $0$ |
| 4 | 2 | 3 | $-1$ |
| 1 | 3 | 0 | $3$ |
| 4 | 4 | 4 | $0$ |

Giá trị cực đại của độ lệch là $3$, do đó cần 3 vòng để sắp xếp xong.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — Thời gian chủ yếu tiêu tốn cho việc sắp xếp mảng ban đầu để xác định vị trí đích của từng phần tử.
- **Bộ nhớ:** $O(n)$ — Cần không gian lưu trữ mảng ban đầu và mảng đã sắp xếp (hoặc lưu dưới dạng cặp giá trị - chỉ số).

## Mã nguồn (C++)

[Mã nguồn](../code/Bubble%20Sort%20Rounds%20I.cpp)
