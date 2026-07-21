# Reading Books - Lời giải

**ID:** 1631 | **URL:** https://cses.fi/problemset/task/1631

## Hướng tiếp cận

Gọi $\text{sum} = \sum_{i=1}^{n} t_i$ là tổng thời gian đọc và $\text{mmax} = \max_i t_i$ là thời gian đọc của cuốn sách dài nhất.

**Cận dưới:**

1. Mỗi cuốn sách phải được đọc bởi cả hai người, nên tổng thời gian ít nhất là $\text{sum}$.
2. Khi một người đọc cuốn sách dài nhất ($\text{mmax}$ phút), người kia đọc các sách còn lại (tổng $\text{sum} - \text{mmax}$ phút). Nếu $\text{mmax} > \text{sum} - \text{mmax}$, người kia đọc xong sớm và phải chờ rồi mới đọc cuốn dài nhất. Tổng thời gian ít nhất là $2 \cdot \text{mmax}$.

Do đó, đáp án $\geq \max(\text{sum}, 2 \cdot \text{mmax})$.

**Tính khả thi:**

- **Trường hợp $2 \cdot \text{mmax} \leq \text{sum}$:** Không có cuốn nào chi phối. Người A đọc từ trái sang, người B đọc từ phải sang. Vì tổng các sách còn lại (trừ sách dài nhất) $\geq \text{mmax}$, hai người không bao giờ đụng cùng một cuốn, tổng thời gian đúng bằng $\text{sum}$.
- **Trường hợp $2 \cdot \text{mmax} > \text{sum}$:** Người A đọc cuốn dài nhất từ $0$ đến $\text{mmax}$. Người B đọc các sách còn lại từ $0$ đến $\text{sum} - \text{mmax}$, chờ đến mốc $\text{mmax}$ rồi đọc cuốn dài nhất từ $\text{mmax}$ đến $2 \cdot \text{mmax}$. Tổng thời gian: $2 \cdot \text{mmax}$.

Đáp án: $\max(\text{sum}, 2 \cdot \text{mmax})$.

### Ví dụ minh họa

Xét $n = 3$, các sách $t = [2, 8, 3]$.

- $\text{sum} = 2 + 8 + 3 = 13$
- $\text{mmax} = 8$, $2 \cdot \text{mmax} = 16$
- Đáp án: $\max(13, 16) = 16$

Lịch trình: Người A đọc cuốn dài nhất (8) từ phút 0 đến 8. Người B đọc cuốn 2 và 3 từ phút 0 đến 5, sau đó chờ đến phút 8 rồi đọc cuốn dài nhất từ 8 đến 16. Cả hai hoàn thành ở phút 16.

## Độ phức tạp

- **Thời gian:** $O(n)$ — một vòng lặp duy nhất để tính $\text{sum}$ và $\text{mmax}$.
- **Bộ nhớ:** $O(1)$ — chỉ cần hai biến.

## Mã nguồn (C++)

[Mã nguồn](../code/Reading%20Books.cpp)
