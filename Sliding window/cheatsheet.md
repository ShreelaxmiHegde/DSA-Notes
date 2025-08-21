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
```

---

### 2.2 Variable-Size Template

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // expand: include nums[right]

    while (/* condition violated */) {
        // shrink: remove nums[left]
        left++;
    }

    // process valid window [left..right]
}
```
---

### 2.3 Longest Window

```cpp
int ans = 0;
for (int right = 0; right < n; right++) {
    // expand
    while (/* invalid */) left++;
    ans = max(ans, right - left + 1);
}
```
---

### 2.4 Shortest Window

```cpp
int ans = INT_MAX;
for (int right = 0; right < n; right++) {
    // expand
    while (/* valid */) {
        ans = min(ans, right - left + 1);
        left++;
    }
}
```
---

### 2.5 Counting Windows

```cpp
long long count = 0;
for (int right = 0; right < n; right++) {
    // expand
    while (/* invalid */) left++;
    count += (right - left + 1); // all subarrays ending at right are valid
}
```

Exactly K trick:
`countExactly(K) = countAtMost(K) - countAtMost(K - 1)`

---

### 2.6 Sliding Window + Deque (Max/Min)

```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) {
        // nums[dq.front()] = max in window
    }
}
```

---

### 🔹 3. Extra Tips & Tricks (Beyond Basics)

- Use hashmap/set for character frequency or uniqueness.
- Use deque for monotonic max/min problems.
- Use two heaps / multiset for median or order statistics.
- For counting subarrays, always think atMost(K).
- For min window problems, shrink aggressively when valid.

---

### 🔹 4. When Not to Use Sliding Window

- If the problem requires non-contiguous subarrays/subsequences → DP/greedy might be better.
- If window condition depends on future elements (not just current window).
- If constraints are not local (e.g., requires global sorting).

---

### 🔹 5. Complexity

- **Time** : O(n) typically (each element enters & leaves window once).
- **Space** :
   - O(1) for sum-based windows
   - O(k) or O(unique elements) for hashmap/set/deque-based windows

---

### 🔹 6. Quick Reference Problem Types

**1. Fixed-Size**
   - Max/Min sum of subarray of size k
   - Average of subarray of size k

**2.Variable-Size**
   - Longest substring without repeating chars
   - Longest substring with at most K distinct chars
   - Minimum size subarray sum ≥ target

**3.Counting**
   - Count subarrays with sum < K
   - Count substrings with at most K distinct
   - Count subarrays with exactly K distinct

4.Optimized DS
   - Sliding Window Maximum (deque)
   - Sliding Window Minimum
   - Sliding Window Median (heaps)

---

🔹 7. ASCII Visualization
- **Fixed Window (k = 3)**
   ```
   [1 2 3] 4 5
    L     R
   
   slide →
   1 [2 3 4] 5
     L     R
   ```

- **Variable Window**
  ```
   Expand →
   [1 2 3 4 5]
    L       R
   
   Shrink →
       [3 4 5]
       L   R
     ```

---

### Summary

- Fixed-size → Add/remove, check when size == k.
- Variable-size → Expand right, shrink left until valid.
- Longest/Shortest → Track window length.
- Counting → Add (right - left + 1).
- Deque/Heap → Optimize max/min/median queries.



---
---

## 🔹 1. Sliding Window Problems: Code Flow Across Easy → Medium → Hard

### ✅ Easy Level (Direct Expanding Window)

* **Examples**: `Leetcode 3 (Longest Substring Without Repeating Characters)`, `Leetcode 1004 (Max Consecutive Ones III)`
* **Flow**:

  1. Keep two pointers: `left`, `right`.
  2. Expand `right` to explore more elements.
  3. If condition breaks (duplicate / too many flips), move `left`.
  4. Update result with `right-left+1`.
* **Key Insight**: Single condition check, usually O(1) updates.
* **Mental Load**: Track one rule only → “Am I valid? If not, shrink.”

---

### ⚖️ Medium Level (Window + Frequency Map / Constraint Tracking)

* **Examples**: `Leetcode 424 (Character Replacement)`, `Leetcode 159 (At Most Two Distinct Characters)`, `Leetcode 567 (Permutation in String)`
* **Flow**:

  1. Expand `right`, update frequency map (`unordered_map` or array).
  2. Check constraint (e.g., max frequency, distinct count, match with target freq).
  3. Shrink `left` while constraint invalid.
  4. Maintain an auxiliary variable (`maxFreq`, `distinctCount`) to decide window validity.
* **Key Insight**: More bookkeeping → not just length but also frequency counts.
* **Mental Load**: Must design *what condition defines a valid window* (flexible).

---

### 🔥 Hard Level (Window + Multiple Constraints / Optimization / Two Maps)

* **Examples**: `Leetcode 76 (Minimum Window Substring)`, `Leetcode 239 (Sliding Window Maximum)`, `Leetcode 727 (Minimum Window Subsequence)`
* **Flow**:

  1. Expand `right`, maintain full frequency map.
  2. Shrink `left` to optimize (e.g., smallest window).
  3. Must track multiple variables: size, validity, character match counts.
  4. Sometimes requires *two passes* (expand → shrink → expand again).
* **Key Insight**:

  * Handling **multiple constraints simultaneously**.
  * Optimizing for *min length* instead of *max length* (harder logic).
  * May require *deque*, *priority queue*, or *extra preprocessing*.
* **Mental Load**: Higher → careful about “what is valid”, “when to update answer”, “when to shrink aggressively.”

---

👉 **Summary for Sliding Window:**

* **Easy** → simple expand/shrink rule.
* **Medium** → frequency maps, derived constraints.
* **Hard** → multiple moving parts (two maps, optimization, bidirectional shrinking).

---
