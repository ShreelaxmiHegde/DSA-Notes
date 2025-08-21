# 📝 Two-Pointer Approach Cheat Sheet

The **two-pointer technique** is one of the most versatile patterns in algorithms.  
It helps solve problems efficiently by reducing nested loops into a single pass with two markers.

---

## 🔹 1. Types of Two-Pointer Approaches

1. **Opposite Direction (Meet in the Middle)**
   - Pointers: One at the start, one at the end.
   - Use Case: Sorted arrays (e.g., `2Sum`, `3Sum`, `4Sum`).
   - Example: Checking if two numbers sum to a target.

2. **Same Direction (Sliding Window / Fast-Slow)**
   - Pointers: Both start at the beginning, one moves faster than the other.
   - Use Case: Subarray/substring problems, removing duplicates, partitioning.
   - Example: `Remove Duplicates from Sorted Array`, `Sort Colors`, `Longest Substring Without Repeating Characters`.

---

## 🔹 2. Common Patterns

### Pair Finding
- `2Sum` (sorted): Move `left`/`right` depending on sum vs target.
- Variants: `3Sum`, `4Sum`, `KSum` → reduce higher-order sums into nested 2Sum.

### Window Expansion / Shrinking
- Expand `right` pointer until condition breaks, then move `left`.
- Example: Minimum size subarray with sum ≥ target.

### Partitioning
- Place valid elements on one side, invalid on the other.
- Example: `Sort Colors`, `Move Zeroes`, `Dutch National Flag Problem`.

### Slow-Fast Pointers
- Detect cycles in linked lists (Floyd’s Cycle Detection).
- Find middle of linked list.

### Overlap Checking
- Merging intervals.
- Checking if two arrays intersect.

---

## 🔹 3. Extra Tips & Tricks (Beyond Basics)

1. **Unsorted Arrays → Sorting Helps**
   - If order doesn’t matter, sort first → two-pointer becomes usable.
   - Example: `3Sum`, `4Sum` need sorting first.

2. **Skipping Duplicates**
   - After finding a valid pair/triplet, move pointers carefully to skip duplicates.
   - Avoids redundant results.

3. **Binary Search + Two-Pointer**
   - Use binary search for one element, two-pointer for others.
   - Example: `3Sum Closest` (choose one element, then 2Sum with two pointers).

4. **Two-Pointer with Hashing**
   - When sorting is not possible, combine with `HashSet`.
   - Example: Detecting duplicates in unsorted arrays.

5. **Linked List Variants**
   - Two-pointer isn’t just for arrays → works on linked lists too.
   - Example: `Reversing sublists`, `Finding intersection of two linked lists`.

6. **Two-Pointer in Strings**
   - Palindrome check (`left` and `right` pointers).
   - Remove adjacent duplicates.
   - Reverse words/characters in-place.

7. **Meet-in-the-Middle Optimization**
   - Useful in subset problems or `KSum` extensions.
   - Divide array in half → apply two-pointer on halves.

8. **Geometric Applications**
   - Trapping Rain Water (height[left], height[right]).
   - Container With Most Water.

9. **Prefix-Sum + Two Pointers**
   - For range problems, prefix sums + sliding window improves efficiency.

10. **Dynamic Window Size**
   - Window can grow/shrink dynamically depending on problem constraints.
   - Example: Longest substring problems in strings.

---

## 🔹 4. When *Not* to Use Two Pointers
- Input must usually be **sorted** (or order irrelevant).
- If strict order of elements matters (like original index positions), prefer **hashing** or **binary search**.

---

## 🔹 5. Complexity
- **Time**: Usually O(n) or O(n log n) if sorting required.
- **Space**: O(1) unless combined with hashing.

---

## 🔹 6. Quick Reference Problems
- Pair Sum in Sorted Array
- 3Sum / 4Sum
- Remove Duplicates from Sorted Array
- Sort Colors (Dutch National Flag)
- Move Zeroes
- Trapping Rain Water
- Container With Most Water
- Minimum Size Subarray Sum
- Palindrome Check in Strings
- Linked List Cycle Detection

---

**Pro Tip**: Always think — “Can I solve this by narrowing from both ends or expanding a window instead of nested loops?”  
That’s the two-pointer mindset.

---
---

Great question 👌 Let’s carefully break this down. I’ll show you how **problem flow/levels** differ between **easy, medium, and hard** problems in **two-pointers** (and also in general coding).

---

# 🔹 Two-Pointer Approach – Difficulty Levels

### 🟢 **Easy (Direct Application)**

* **Pattern:** Usually sorted arrays or simple scans.
* **Flow:**

  1. Place two pointers (`left`, `right`) at start/end.
  2. Move one/both based on a condition.
  3. Return result directly.
* **Examples:**

  * `Two Sum II (sorted array)`
  * `Reverse a String/Array`
  * `Remove Duplicates from Sorted Array`

✅ **Code Flow:**

* Simple conditions (`if sum > target → right-- else left++`).
* Only 1 loop.
* No auxiliary structures.

---

### 🟡 **Medium (Variable Conditions, Window Maintenance)**

* **Pattern:** More than one condition or need to track frequency/state.
* **Flow:**

  1. Use two pointers as **sliding window** or **shrinking/growing boundary**.
  2. Maintain additional info (count, freq map, max/min, etc.).
  3. Shrink/expand until constraints are satisfied.
* **Examples:**

  * `3Sum`
  * `Container With Most Water`
  * `Longest Substring Without Repeating Characters`

✅ **Code Flow:**

* More checks (`while invalid → shrink`).
* Sometimes nested movement of pointers.
* Auxiliary DS like `unordered_map`, `set`, or counters.

---

### 🔴 **Hard (Multiple States / Optimized Strategy)**

* **Pattern:** Needs **multi-pass two-pointer** or combining with **sorting, greedy, or binary search**.
* **Flow:**

  1. Break problem into subproblems (e.g., sort + two-pointer).
  2. Manage multiple conditions simultaneously (e.g., duplicates, k constraints).
  3. Optimize to O(n) / O(n log n) with careful pointer movement.
* **Examples:**

  * `Trapping Rain Water` (prefix/suffix + two pointers)
  * `Minimum Window Substring` (hashmap + sliding window shrink/expand)
  * `Subarray Product < K`

✅ **Code Flow:**

* Requires deeper reasoning (why both pointers move when).
* Must handle corner cases carefully.
* Usually multiple variables: window size, freq counts, valid/invalid check, etc.

---

👉 **Summary Flow Difference:**

* **Easy:** Straight pointer movement → 1 condition.
* **Medium:** Add constraints → shrink/expand with states.
* **Hard:** Multi-constraints + optimized movement → requires combining multiple approaches.
