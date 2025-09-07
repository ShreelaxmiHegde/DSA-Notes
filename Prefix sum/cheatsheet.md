# Prefix Sum Cheat Sheet

## Core Idea
- Build an array (or map) that stores cumulative sums up to each index.
- Use differences between prefix sums to quickly get subarray sums.
- Often combined with hashmaps to check/count subarrays that meet a condition.

---

## Prefix Sum Formula

### For an array nums:
```c++
prefix[i] = nums[0] + nums[1] + ... + nums[i]
```


### Subarray sum from l to r is:
```c++
sum(l..r) = prefix[r] - prefix[l-1]   (if l > 0)
```
--- 

## Problem Patterns & Templates
### 1.Find Subarray Sum Quickly

When you need to get sum of any subarray in O(1) after preprocessing.
Template:
```c++
vector<int> prefix(n);
prefix[0] = nums[0];
for (int i = 1; i < n; i++) 
    prefix[i] = prefix[i-1] + nums[i];

// sum(l..r)
int subSum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
```

---

### 2.Check if Subarray with Given Sum Exists
Use hashmap to store prefix sums seen so far.
Template:
```c++
unordered_map<int,int> mp; 
mp[0] = 1;  // base case: sum from start
int currSum = 0;
for (int num : nums) {
    currSum += num;
    if (mp.count(currSum - k)) {
        // found a subarray with sum k
    }
    mp[currSum]++;
}
```
Used in Subarray Sum Equals K.

---

### 3.Count Number of Subarrays with Given Sum

Same as above but increment a counter.
Template:
```c++
int count = 0, currSum = 0;
unordered_map<int,int> mp;
mp[0] = 1;

for (int num : nums) {
    currSum += num;
    if (mp.count(currSum - k))
        count += mp[currSum - k];
    mp[currSum]++;
}
```

---

### 4.Prefix Sum in 2D (Matrix)

For fast rectangle queries.
Template:
```c++
vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        prefix[i][j] = matrix[i-1][j-1] 
                       + prefix[i-1][j] 
                       + prefix[i][j-1] 
                       - prefix[i-1][j-1];
    }
}

// Sum of rectangle (x1,y1) to (x2,y2)
int rectSum = prefix[x2+1][y2+1] - prefix[x1][y2+1] 
              - prefix[x2+1][y1] + prefix[x1][y1];
```

---

## Variants & Tricks
- Modulo with prefix sums → for divisibility problems (e.g., "Subarray Sums Divisible by K").
- Prefix sum on binary array → count subarrays with fixed number of 1’s (e.g., "Binary Subarrays With Sum").
- Tree DFS + prefix sum → path sum problems in binary trees.

---

## Intuition Builder
- Prefix sums transform repeated subarray sum calculations into constant time lookups.
- If you see words like range sum, subarray sum, divisible, equal to K, number of ways, prefix sums are a strong candidate.
- When the problem asks to count or check conditions on subarrays, often you’ll need prefix sums + hashmap.

---

## Quick Recognition:
- “Find sum of subarray quickly” → Simple prefix array.
- “How many subarrays… / does a subarray exist… ?” → Prefix + HashMap.
- “Matrix subarea / block sum” → 2D Prefix Sum.
- “Modulo or divisibility condition” → Prefix % K + HashMap.