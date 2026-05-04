<h1 align = "center" > 
♡୨ৎ🍔｡ᡣ QuickServe ｡ᡣ🍔୨ৎ♡ </h1>
<h2 align = "center" >  
*Fast Food Order Line Management System* </h2>
<h3 align = "center" </h3>
  "Serving smarter, faster, and in the right order."
<br/>
</div>

---

## ❓ Problem Description



### What problem are we solving?

Fast food chains often encounter significant challenges in managing orders efficiently, particularly during peak hours when demand is high (Blankenship, 2025). This problem often results to:
-Inaccurate orders and delays in handling urgent and priority orders such as express meals or special orders
-Customer dissatisfaction due to longer wait times
-Decreased overall service quality and staff performance

**QuickServe** addresses these issues by providing a structured, console-based order management system that enforces fair queuing, elevates priority orders automatically, and allows staff to undo accidental actions.
---

## 🗂️ Data Structures Used

### 1. queue<Order> — Normal Order Queue

- *What it is:* A linear structure following *FIFO* (First-In, First-Out) — first customer in, first customer served
- *Why we used it:* Ensures normal orders are processed in the exact sequence they were placed, with O(1) push and pop operations
```cpp
queue<Order> normalQueue;
normalQueue.push(order);  // joins the line
normalQueue.pop();        // served and removed
```
---

### 2. priority_queue<Order> — Priority Order Queue

- *What it is:* A container built on a *max-heap* — the element with the highest priority value is always at the top, regardless of insertion order
- *Why we used it:* Automatically elevates urgent orders above normal ones using the overloaded operator<, with O(log n) insertion and O(1) top access
```cpp
bool operator<(const Order& other) const {
    return priority < other.priority; // higher value = served first
}
```
---

### 3. stack<Order> — Undo Stack

- *What it is:* A linear structure following *LIFO* (Last-In, First-Out) — the most recently added item is always retrieved first
- *Why we used it:* Perfect for undo — every processed order is pushed on, and popping it instantly restores the last action in O(1) time
```cpp
stack<Order> undoStack;
undoStack.push(order);  // log processed order
undoStack.pop();        // restore it back to queue
```
---

## ⚙️ Algorithm Explanation

### ➕ addOrder()
- Prompt for Customer Name, Order Name, and Urgency (1 = Normal, 2 = Priority)
- If urgency is 2 → push to priorityQueueOrders
- If urgency is 1 → push to normalQueue
- If order duplicates → prints warning, not added

### ▶️ processOrder()
- Check priorityQueueOrders first — if not empty, pop the top order
- If priority queue is empty → pop from the front of normalQueue
- If both are empty → notify staff no orders are pending
- Push the processed order to undoStack in all successful cases

### ↩️ undoOrder()
- If undoStack is empty → notify that nothing can be undone
- Pop the most recently processed order
- If priority == 2 → restore to priorityQueueOrders
- If priority == 1 → restore to normalQueue

### 📋 displayOrders()
- Copy both queues into *temporary variables* before iterating
- Print all priority orders, then all normal orders
- Original queues remain completely unmodified

### 🔁 main()
- do-while loop keeps the menu alive until exit
- switch-case routes user input to the correct function

---

## 🔁 Iterative vs Recursive Comparison

| Criteria | ✅ Iterative (Used) | ❌ Recursive (Alternative) |
|---|---|---|
| *Speed* | Faster — no function call overhead | Slower — each call adds a stack frame |
| *Memory* | O(1) stack space | O(n) call stack depth |
| *Readability* | Simple and easy to follow | Harder to trace |
| *Risk* | No stack overflow | Risk of overflow on large inputs |
| *Best For* | Queue / stack traversal ✅ | Tree / graph traversal |

- 🏆 *Which is faster?* — *Iterative.* No repeated function call overhead or return address management.
- 📖 *Which is easier to understand?* — *Iterative.* A while (!queue.empty()) loop is immediately readable; recursion here adds unnecessary complexity.

---

## 🧠 Design Decisions

- *Two separate queues instead of one* — Clear processing hierarchy without complex shared logic. Trade-off: two structures to manage, but far cleaner code.

- **operator< overloading** — Lets priority_queue rank orders automatically. Trade-off: simple now, but needs redesign if ranking rules become more complex.

- *Stack for undo* — Every processed order is logged, enabling multi-level undo. Trade-off: only one undo is exposed in the menu intentionally to avoid confusion in live use.

- *Temporary copies for display* — Iterating over copies keeps the original queues intact. Trade-off: minor extra memory use, negligible at restaurant scale.

- *Console interface* — Keeps focus on data structure logic; portable and easy to compile anywhere. Trade-off: less visual than a GUI, but ideal for academic demonstration.

---

## 📁 Course Information . ݁₊ 🦢 . ݁˖

|||
|:---|:---|
| 📘 *Course* | CC 103 – Data Structures and Algorithms |
| 🏫 *Department* | Computer Science Department |
| 📅 *Semester* | 2nd Semester, AY 2025–2026 |
| 👥 *Team Number* | Team 8 |
| 🏷️ *Team Name* | Array-ko |

---

## 👨‍💻 Meet the Team ✨. ݁₊ 🦢 . ݁˖

| 🪪 SR-Code | 👤 Name | ⚙️ Role |
|:---:|:---|:---|
| 25-07559 | Carro, John Kristian Shine D. | 🖥️ Main Programmer · 🐛 Debugger |
| 25-08087 | Cebrero, Kelsey Leigh M. | 📝 Documentation · 🖥️  Programmer  |
| 25-04394 | Sudara, Marvin T. | 🖥️ Programmer · 📝 Documentation |

## Acknowledgement
We would like to sincerely thank our instructor, Ms. Fatima Marie Agdon, MSCS, for her continuous guidance, unwavering support, and meaningful insights that greatly aided us throughout this project.

We are also grateful to our classmates and peers, whose cooperation, encouragement, and collaborative ideas helped us refine and enhance this system.

Finally, we recognize the various learning resources and materials that deepened our understanding of the data structures and programming concepts applied in this project.




