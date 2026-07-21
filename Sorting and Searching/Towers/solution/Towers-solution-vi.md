# Towers - Lời giải

**ID:** 1073 | **URL:** https://cses.fi/problemset/task/1073

## Đề bài

Cho $n$ khối lập phương theo một thứ tự nhất định. Hãy xây các tháp từ các khối này sao cho khi hai khối xếp chồng, khối trên luôn nhỏ hơn nghiêm ngặt khối dưới. Các khối phải được xử lý lần lượt theo đúng thứ tự đề bài cho. Tại mỗi bước, bạn có thể đặt khối hiện tại lên đỉnh một tháp đã có hoặc khởi tạo một tháp mới. Tìm số lượng tháp tối thiểu.

## Hướng tiếp cận

### 1. Phân tích chiến lược tham lam

Khi xử lý một khối kích thước $a$, ta có hai lựa chọn:

1. Đặt $a$ lên đỉnh một tháp hiện có (yêu cầu đỉnh tháp đó $> a$).
2. Tạo một tháp mới với đỉnh ban đầu là $a$.

Để tối thiểu hóa số tháp, ta luôn ưu tiên đặt vào tháp sẵn có. Khi có nhiều tháp có đỉnh $> a$, áp dụng quy tắc: **đặt $a$ lên tháp có đỉnh nhỏ nhất nhưng vẫn lớn hơn $a$**.

**Lý do:** Nếu chọn tháp có đỉnh quá lớn, ta lãng phí một "nền móng" tốt có thể đỡ các khối lớn hơn xuất hiện sau. Chọn đỉnh nhỏ nhất vẫn $> a$ giúp giữ lại các đỉnh cao cho các khối tương lai, tối đa hóa khả năng tái sử dụng tháp.

### 2. Tối ưu bằng tìm kiếm nhị phân

Ta duy trì mảng `top[]` lưu đỉnh của các tháp, luôn được sắp xếp tăng dần. Với mỗi khối kích thước $a$, tìm nhị phân vị trí $p$ nhỏ nhất thỏa $\text{top}[p] > a$ (tức `std::upper_bound`):

- **Tìm thấy:** gán $\text{top}[p] = a$ (đặt khối lên đỉnh tháp $p$).
- **Không tìm thấy:** tức mọi đỉnh đều $\le a$, ta phải tạo tháp mới bằng cách thêm $a$ vào cuối mảng `top[]`.

### 3. Bảo trì tính chất sắp xếp của mảng đỉnh

Khi thay $\text{top}[p] = a$, mảng vẫn giữ thứ tự tăng nhờ:

- $\text{top}[p-1] \le a$: vì $p$ là vị trí đầu tiên có giá trị $> a$, phần tử ngay trước nó chắc chắn $\le a$.
- $a < \text{top}[p+1]$: vì $a < \text{top}[p]_{\text{cũ}}$ và $\text{top}[p]_{\text{cũ}} \le \text{top}[p+1]$ (do mảng tăng), nên $a < \text{top}[p+1]$.

### 4. Chứng minh qua Định lý Dilworth

Bài toán là một ứng dụng kinh điển của **Định lý Dilworth**. Xét thứ tự từng phần: khối $i$ có thể nằm dưới khối $j$ khi và chỉ khi $i$ xuất hiện trước $j$ ($i < j$) và $k_i > k_j$ (khối dưới lớn hơn khối trên). Mỗi tháp hợp lệ là một chuỗi (chain) giảm nghiêm ngặt trong thứ tự này.

Theo Dilworth, số chuỗi tối thiểu để phủ toàn bộ tập bằng kích thước phản chuỗi (antichain) lớn nhất. Một phản chuỗi là tập các khối đôi một không xếp chồng được, tương ứng một **dãy con tăng không nghiêm ngặt** (nếu $i < j$ và $k_i \le k_j$ thì $i$ không thể nằm dưới $j$). Vậy số tháp tối thiểu bằng độ dài dãy con tăng không nghiêm ngặt dài nhất (LNDS). Thuật toán tham lam + tìm kiếm nhị phân ở trên mô phỏng chính xác việc tìm độ dài LNDS, nên kết quả luôn tối ưu.

## Ví dụ minh họa

Xét mảng kích thước khối $a = [3, 8, 2, 1, 5]$, $n = 5$.

| Bước | Khối $a$ | `top[]` trước | Vị trí $p$ | Hành động | `top[]` sau |
| --- | --- | --- | --- | --- | --- |
| 1 | 3 | $[]$ | không thấy | tháp mới | $[3]$ |
| 2 | 8 | $[3]$ | không thấy ($3 \le 8$) | tháp mới | $[3, 8]$ |
| 3 | 2 | $[3, 8]$ | $p=1$ ($\text{top}[1]=3>2$) | đặt lên tháp 1 | $[2, 8]$ |
| 4 | 1 | $[2, 8]$ | $p=1$ ($\text{top}[1]=2>1$) | đặt lên tháp 1 | $[1, 8]$ |
| 5 | 5 | $[1, 8]$ | $p=2$ ($\text{top}[2]=8>5$) | đặt lên tháp 2 | $[1, 5]$ |

Kết quả: số tháp tối thiểu bằng số phần tử của `top[]`, tức $2$. (Tháp 1: $3 \to 2 \to 1$; tháp 2: $8 \to 5$.)

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — duyệt $n$ khối, mỗi khối tìm nhị phân trên mảng đỉnh (dài tối đa $n$) tốn $O(\log n)$.
- **Bộ nhớ:** $O(n)$ để lưu mảng `top[]`.
