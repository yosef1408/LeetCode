# 🚀 LeetCode Journey

Welcome to my coding journey! 

Unfortunately, the Chrome extension I was using to automatically commit my solutions directly to Git is broken. Therefore, I'm sharing my LeetCode profile here: [https://leetcode.com/u/yose_14/](https://leetcode.com/u/yose_14/) to track my progress.

I'm preparing for technical interviews by improving my coding skills and mastering algorithms. While I don't know exactly when the opportunity will come, I'm determined to be ready when it does.

This repository is where I'll document my progress, track my solutions, and reflect on my growth. Feel free to follow along or contribute!

Happy coding! 💻✨

<p align="center">
  <img src="https://leetcard.jacoblin.cool/yose_14?theme=dark&font=Besley" alt="LeetCode Card">
</p>


## 🧠 Tips & Tricks

- When working with a **2D matrix** of size \( m * n \):
  - **Row index**: \( {mid} / n \)
  - **Column index**: \( {mid} % n \)
 
- Beware of Duplicates: Binary search can fail in rotated arrays with duplicates, as it's hard to determine the sorted half (e.g., [1, 1, 1, 1, 2, 1, 1, 1]).
Alternative: Skip duplicate boundaries (start++ or end--), but this may degrade the time complexity to 
𝑂(𝑛)
