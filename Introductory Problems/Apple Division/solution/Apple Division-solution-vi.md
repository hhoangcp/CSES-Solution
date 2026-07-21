# Apple Division - Lời giải

**ID:** 1623 | **URL:** https://cses.fi/problemset/task/1623

## Phương pháp

### Tóm tắt bài toán

Cho $n$ quả táo với trọng lượng $p_1, p_2, \ldots, p_n$ ($1 \le n \le 20$, $1 \le p_i \le 10^9$). Chia thành hai nhóm sao cho $|S_1 - S_2|$ là nhỏ nhất, với $S_1, S_2$ là tổng trọng lượng mỗi nhóm. Tương đương, đặt $T = \sum_{i=1}^{n} p_i$, tìm tập con có tổng $S$ sao cho $|T - 2S|$ nhỏ nhất, tức gần $T/2$ nhất.

### Ý tưởng chính

Với $n \le 20$, có tối đa $2^n \approx 10^6$ cách chia — đủ nhỏ để duyệt tất cả. Mỗi quả táo có hai lựa chọn (nhóm 0 hoặc nhóm 1), tạo thành cây quyết định nhị phân độ sâu $n$. Đệ quy khám phá mọi nhánh lá, nên chắc chắn tìm được đáp án tối ưu. Việc duyệt vét cạn là bắt buộc vì cách tiếp cận tham lam không đảm bảo tối ưu cho bài toán phân hoạch NP-hard này.

**Tại sao tham lam sai:** Sắp xếp giảm dần rồi gán mỗi quả táo vào nhóm nhẹ hơn chỉ tối ưu cục bộ. Phản ví dụ: trọng lượng $[8, 7, 6, 5, 4]$:
- Tham lam: $N_1 = \{8, 5, 4\} = 17$, $N_2 = \{7, 6\} = 13$, hiệu = 4.
- Tối ưu: $N_1 = \{8, 7\} = 15$, $N_2 = \{6, 5, 4\} = 15$, hiệu = 0.

Vì tham lam không đảm bảo tối ưu, phải duyệt tất cả khả năng. Đệ quy khám phá toàn bộ $2^n$ cách gán nhị phân táo vào nhóm, không bỏ sót cách chia nào.

**Đệ quy so với Bitmask:** Cả hai đều duyệt $2^n$ cách chia. Đệ quy duy trì tổng dần với $O(1)$ mỗi bước, tổng cộng $O(2^n)$. Bitmask tính lại tổng cho mỗi mask mất $O(n)$, tổng cộng $O(n \cdot 2^n)$. Đệ quy nhanh hơn trong thực hành và cho phép dừng sớm khi hiệu đã bằng 0.

### Thuật toán

1. Khởi tạo `sum[0] = sum[1] = 0`, `res = ∞`.
2. Đệ quy tại táo $i$: thử cộng $p_i$ vào `sum[0]`, đệ quy sang $i+1$, rồi quay lui; thử cộng $p_i$ vào `sum[1]`, đệ quy sang $i+1$, rồi quay lui.
3. Khi $i > n$: cập nhật `res = min(res, |sum[0] - sum[1]|)`. Nếu `res == 0`, dừng sớm.
4. Xuất `res`.

### Ví dụ minh họa

$n = 5$, trọng lượng $[3, 2, 7, 4, 1]$. Tổng $T = 17$, mục tiêu $T/2 = 8.5$.

Đệ quy tìm được tập con $\{1, 7\}$ có tổng $S = 8$: $|T - 2S| = |17 - 16| = 1$. Tương đương, nhóm 1 = $\{2, 3, 4\}$ (tổng 9), nhóm 2 = $\{1, 7\}$ (tổng 8), hiệu = 1.

## Độ phức tạp

- **Thời gian:** $O(2^n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Apple%20Division.cpp)
