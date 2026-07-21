# Room Allocation - Lời giải

**ID:** 1164 | **URL:** https://cses.fi/problemset/task/1164

## Hướng tiếp cận

Với mỗi khách $i$, tạo hai sự kiện: **đến** tại ngày $a_i$ với loại $+1$ (cần phòng), và **rời** tại ngày $b_i$ với loại $-1$ (trả phòng). Tổng cộng $2n$ sự kiện.

Sắp xếp tất cả sự kiện theo ngày tăng dần. Khi trùng ngày, xử lý đến ($+1$) trước rời ($-1$) (sắp xếp theo `type` giảm). Điều này đảm bảo phòng giải phóng tại ngày $t$ **không** được cấp ngay cho khách đến cùng ngày $t$, vì đề bài yêu cầu ngày rời phải **nhỏ hơn nghiêm ngặt** ngày đến mới được dùng chung phòng.

Duy trì ngăn xếp các số phòng trống, khởi tạo bằng $1, 2, \ldots, n$ (đẩy ngược nên phòng 1 ở đỉnh — phòng nhỏ nhất được ưu tiên dùng lại). Xử lý sự kiện theo thứ tự đã sắp:

- **Đến ($+1$):** Lấy phòng trên đỉnh ngăn xếp, gán cho khách này. Cập nhật $\text{res} = \max(\text{res}, \text{phòng})$.
- **Rời ($-1$):** Đẩy phòng của khách này trở lại ngăn xếp.

**Tính đúng:** Gọi $d(t)$ là số khách có mặt tại ngày $t$. Số phòng tối thiểu cần thiết là $\max_t d(t)$ vì tại thời điểm đông nhất mỗi khách cần phòng riêng. Thuật toán dùng đúng số này: tại mỗi ngày $t$, số phòng đang dùng bằng $d(t)$ (đến thì thêm, rời thì bớt, và xử lý đến trước rời cùng ngày đảm bảo đúng ràng buộc nhỏ hơn nghiêm ngặt). Mỗi phòng chỉ gán cho nhiều nhất một khách tại một thời điểm (phòng chỉ trả lại ngăn xếp khi khách rời), nên hai khách dùng chung phòng khi và chỉ khi khoảng thời gian không giao nhau.

### Ví dụ minh họa

Xét $n = 3$ khách: $(1, 2)$, $(2, 4)$, $(4, 4)$.

Sự kiện sau sắp xếp (đến trước rời cùng ngày): $(1, +1, 0)$, $(2, +1, 1)$, $(2, -1, 0)$, $(4, +1, 2)$, $(4, -1, 1)$, $(4, -1, 2)$.

Ngăn xếp ban đầu: $[1, 2, 3]$ (phòng 1 ở đỉnh).

| Sự kiện | Hành động | Ngăn xếp sau | Phòng đang dùng |
|---------|----------|--------------|-----------------|
| $(1, +1, 0)$ | Gán phòng 1 cho khách 0 | $[2, 3]$ | 1 |
| $(2, +1, 1)$ | Gán phòng 2 cho khách 1 | $[3]$ | 2 |
| $(2, -1, 0)$ | Trả phòng 1 | $[1, 3]$ | 1 |
| $(4, +1, 2)$ | Gán phòng 1 cho khách 2 | $[3]$ | 2 |
| $(4, -1, 1)$ | Trả phòng 2 | $[2, 3]$ | 1 |
| $(4, -1, 2)$ | Trả phòng 1 | $[1, 2, 3]$ | 0 |

Đáp án: 2 phòng, phân bổ `1 2 1`.

Lưu ý: khách 1 đến ngày 2 khi khách 0 rời — vì xử lý đến trước, khách 1 nhận phòng 2 (không phải phòng 1), đúng vì ngày 2 không nhỏ hơn nghiêm ngặt ngày 2. Khách 2 đến ngày 4 khi khách 1 rời — tương tự nhận phòng 1 (đã trống từ ngày 2), không phải phòng 2.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp $2n$ sự kiện; mỗi thao tác ngăn xếp $O(1)$.
- **Bộ nhớ:** $O(n)$ — mảng sự kiện, ngăn xếp, và mảng phân phòng.

## Mã nguồn (C++)

[Mã nguồn](../code/Room%20Allocation.cpp)
