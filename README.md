# 🚀 LeetCode Journey

Welcome to my coding journey! 

I’m on an exciting mission to prepare for technical interviews by improving my coding skills and mastering algorithms. While the perfect opportunity hasn’t come knocking yet, I’m determined to be ready when it does.

So far, I’ve solved 94 questions in C++, a language that holds a special place in my heart ❤️. From here on, I’ll keep solving medium-level problems in C++ while also exploring Python and JavaScript for simpler ones. It’s all part of my journey to becoming a more versatile programmer.

A quick update: the Chrome extension I was using to commit my solutions directly to Git isn’t working anymore. To keep things on track, I’m sharing my LeetCode profile here: https://leetcode.com/u/yose_14/.


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
