# 🔄 Push Swap

## 📖 About

"Push Swap" is an algorithm project that challenges you to sort a stack of integers using a limited set of instructions, with the goal of using the fewest operations possible.

## 🎯 Objectives

- Implement efficient sorting algorithms
- Understand and optimize algorithm complexity
- Practice C programming and rigorous coding

## 🛠️ Features

- Sort a stack of integers using two stacks (a and b)
- Use a specific set of stack operations
- Generate the shortest list of instructions to sort the stack
- Handle error cases and invalid inputs

## 🖥️ Supported Operations

- `sa`: swap the first two elements of stack a
- `sb`: swap the first two elements of stack b
- `ss`: perform sa and sb simultaneously
- `pa`: push the top element from b to a
- `pb`: push the top element from a to b
- `ra`: rotate stack a (first element becomes last)
- `rb`: rotate stack b
- `rr`: perform ra and rb simultaneously
- `rra`: reverse rotate stack a (last element becomes first)
- `rrb`: reverse rotate stack b
- `rrr`: perform rra and rrb simultaneously

## 🚀 Usage

```
./push_swap 2 1 3 6 5 8
```

This will output the list of operations needed to sort the given numbers.

## ⚙️ Installation

1. Clone the repository:
   ```
   git clone https://github.com/your-username/push_swap.git
   ```
2. Navigate to the project folder:
   ```
   cd push_swap
   ```
3. Compile the project:
   ```
   make
   ```

---

Made with ❤️ as part of the 42 School curriculum.
