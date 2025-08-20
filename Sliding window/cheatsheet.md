# 📝 Sliding Window Cheatsheet

Sliding Window is a technique where you use two pointers (`left`, `right`) to represent a "window" over an array or string.  
The window is expanded/shrunk to satisfy conditions efficiently in **O(n)**.

---

## 🔹 1. Types of Sliding Window Approaches

1. **Fixed-Size Window**
   - Window length = constant `k`.
   - Example: Max sum of subarray of size `k`.

2. **Variable-Size Window**
   - Window expands/shrinks dynamically based on conditions.
   - Example: Longest substring without repeating characters.

3. **Counting Windows**
   - Count how many subarrays/substrings satisfy a condition.
   - Often solved with `atMost(K)` trick.

4. **Optimized Windows with Data Structures**
   - Use deque, heap, multiset, or hashmap to maintain extra information inside window.
   - Example: Sliding Window Maximum (LC 239).

---

## 🔹 2. Common Patterns

### 2.1 Fixed-Size Template
```cpp
int left = 0;
long long windowValue = 0;
for (int right = 0; right < n; right++) {
    windowValue += nums[right]; // expand

    if (right - left + 1 > k) { // shrink
        windowValue -= nums[left++];
    }

    if (right - left + 1 == k) {
        // process window
    }
}

---

### 2.2 Variable-Size Template
int left = 0;
for (int right = 0; right < n; right++) {
    // expand: include nums[right]

    while (/* condition violated */) {
        // shrink: remove nums[left]
        left++;
    }

    // process valid window [left..right]
}

---

### 2.3 Longest Window

int ans = 0;
for (int right = 0; right < n; right++) {
    // expand
    while (/* invalid */) left++;
    ans = max(ans, right - left + 1);
}

---

### 2.4 Shortest Window

int ans = INT_MAX;
for (int right = 0; right < n; right++) {
    // expand
    while (/* valid */) {
        ans = min(ans, right - left + 1);
        left++;
    }
}

---

### 2.5 Counting Windows

long long count = 0;
for (int right = 0; right < n; right++) {
    // expand
    while (/* invalid */) left++;
    count += (right - left + 1); // all subarrays ending at right are valid
}


Exactly K trick:
countExactly(K) = countAtMost(K) - countAtMost(K - 1)

---

### 2.6 Sliding Window + Deque (Max/Min)

deque<int> dq;
for (int i = 0; i < n; i++) {
    if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) {
        // nums[dq.front()] = max in window
    }
} ```

---

### 🔹 3. Extra Tips & Tricks (Beyond Basics)

Use hashmap/set for character frequency or uniqueness.
Use deque for monotonic max/min problems.
Use two heaps / multiset for median or order statistics.
For counting subarrays, always think atMost(K).
For min window problems, shrink aggressively when valid.

---

### 🔹 4. When Not to Use Sliding Window

If the problem requires non-contiguous subarrays/subsequences → DP/greedy might be better.

If window condition depends on future elements (not just current window).

If constraints are not local (e.g., requires global sorting).

---

### 🔹 5. Complexity

Time: O(n) typically (each element enters & leaves window once).

Space:

O(1) for sum-based windows

O(k) or O(unique elements) for hashmap/set/deque-based windows

---

### 🔹 6. Quick Reference Problem Types

Fixed-Size

Max/Min sum of subarray of size k

Average of subarray of size k

Variable-Size

Longest substring without repeating chars

Longest substring with at most K distinct chars

Minimum size subarray sum ≥ target

Counting

Count subarrays with sum < K

Count substrings with at most K distinct

Count subarrays with exactly K distinct

Optimized DS

Sliding Window Maximum (deque)

Sliding Window Minimum

Sliding Window Median (heaps)

---

🔹 7. ASCII Visualization
Fixed Window (k = 3)

[1 2 3] 4 5
 L     R

slide →
1 [2 3 4] 5
  L     R

Variable Window
Expand →
[1 2 3 4 5]
 L       R

Shrink →
    [3 4 5]
    L   R

---

### Summary

Fixed-size → Add/remove, check when size == k.

Variable-size → Expand right, shrink left until valid.

Longest/Shortest → Track window length.

Counting → Add (right - left + 1).

Deque/Heap → Optimize max/min/median queries.