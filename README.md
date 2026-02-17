*This project has been created as part of the 42 curriculum by **bdropper***
# push_swap

A sorting program written in C for the 42 school curriculum. It sorts a list of integers using two stacks and a limited set of operations, outputting the minimum sequence of moves needed to sort the numbers.

---

## What is push_swap?

The goal is simple: given a list of unsorted integers as command-line arguments, print the smallest possible list of instructions that will sort them in ascending order.

You have two stacks, **stack A** and **stack B**, and only 11 allowed operations to move numbers between them. Stack A starts with all the numbers. Stack B starts empty. The program must sort everything back into stack A in ascending order using as few operations as possible.

---

## The 11 Allowed Operations

| Operation | What it does |
|-----------|-------------|
| `sa` | Swap the top two elements of stack A |
| `sb` | Swap the top two elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the top element of stack B and push it onto stack A |
| `pb` | Take the top element of stack A and push it onto stack B |
| `ra` | Rotate stack A — the top element goes to the bottom |
| `rb` | Rotate stack B — the top element goes to the bottom |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A — the bottom element comes to the top |
| `rrb` | Reverse rotate stack B — the bottom element comes to the top |
| `rrr` | `rra` and `rrb` at the same time |

**Visual example of rotate vs reverse rotate:**
```
Before ra:   After ra:    Before rra:  After rra:
[1]          [2]          [1]          [3]
[2]          [3]          [2]          [1]
[3]          [1]          [3]          [2]
```

---

## How to Build

```bash
make        # builds the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # full rebuild
```

Requires a C compiler (`cc`) and standard POSIX headers. No external libraries.

---

## Usage

```bash
./push_swap 4 2 5 1 3
```

Output (the list of operations):
```
pb
ra
pb
ra
ra
pa
pa
...
```

If the input is already sorted, the program outputs nothing. If there is only one number, it also outputs nothing.

### Error cases

The program prints `Error` to stdout and exits if:
- Any argument is not a valid integer (e.g. `abc`, `1.5`, `+`)
- Any integer is out of the 32-bit signed range (`< -2147483648` or `> 2147483647`)
- There are duplicate numbers

```bash
./push_swap 1 2 abc    # Error
./push_swap 1 1 2      # Error
./push_swap 2147483648 # Error
```

---

## How the Sorting Works

The program picks a different algorithm depending on how many numbers are given.

### 2 numbers

If the two numbers are out of order, do one `sa`. That's it.

### 3 numbers

Every possible arrangement of 3 numbers can be solved in at most 2 operations. The function checks which of the 5 unsorted permutations it's looking at and applies the right moves directly.

```
[3][1][2] → ra        → [1][2][3] ✓
[2][3][1] → rra       → [1][2][3] ✓
[3][2][1] → sa + rra  → [1][2][3] ✓
[1][3][2] → sa + ra   → [1][2][3] ✓
[2][1][3] → sa        → [1][2][3] ✓
```

### 5 numbers

The two smallest numbers are pushed to stack B one at a time, leaving 3 numbers in stack A. Those 3 are sorted using the 3-number algorithm above. Then the two numbers are pushed back from B to A. A final `sa` corrects the order of the top two if needed.

To find the smallest number efficiently, each node is first assigned a **rank index** (see Indexing below), and the list is scanned to find which position holds the lowest rank. The stack is then rotated the shortest way — forward with `ra` or backward with `rra` — to bring that number to the top.

### 6+ numbers — Radix Sort

For larger inputs the program uses a **bitwise radix sort**. This works on the rank indices rather than the raw values, which keeps the bit range small (e.g. 100 numbers only need 7 bits).

**How it works, one bit at a time:**

For each bit position (starting from the least significant):
1. Look at the current top of stack A
2. If that bit of its index is **1** → `ra` (rotate it to the back of A)
3. If that bit of its index is **0** → `pb` (push it to B)
4. Repeat for every element
5. Push everything back from B to A with `pa`

After processing all bit positions, the indices are in order 0, 1, 2, 3... which means the values are sorted ascending.

**Why this works:** Radix sort is stable — it processes from least significant to most significant bit, and because 0-indexed ranks are contiguous integers, every number ends up in exactly the right place.

---

## Indexing

Before radix sort or the 5-number sort runs, every node is assigned a **rank index** — a number from `0` to `n-1` representing its sorted position.

```
Values:   [42] [-7] [100] [3]
Indices:  [ 2] [ 0] [  3] [1]
```

This is done by counting, for each node, how many other nodes have a smaller value. The smallest value gets index 0, the next gets 1, and so on.

This normalisation is what makes radix sort possible — you can't do bitwise operations on arbitrary integers like `-382` and `486`, but you can on a clean sequence `0, 1, 2 ... n-1`.

---

## Data Structure

Both stacks are **singly linked lists**. Each node holds:

```c
typedef struct s_node
{
    int             value;  // the original number
    int             index;  // rank assigned before sorting (0 = smallest)
    struct s_node   *next;  // pointer to the node below in the stack
}   t_node;
```

The "top" of a stack is always the head of the list (`*stack`). Pushing, rotating, and swapping all work by relinking the `next` pointers rather than moving data around in memory.

---

## File Structure

```
push_swap/
├── push_swap.h     # struct definition and all function prototypes
├── main.c          # entry point, stack setup, input validation, memory cleanup
├── error_check.c   # number format validation, overflow detection, duplicate check
├── opperations.c   # the 4 primitive operations: push, rotate, reverse_rotate, swap
├── actions.c       # sa, sb, pa, pb — call primitives and print the operation name
├── actions_2.c     # ra, rb, rra, rrb
├── actions_3.c     # ss, rr, rrr (simultaneous operations)
├── sort.c          # sort_stack dispatcher, sort_three, sort_five, bring_to_top
├── radix.c         # radix_sort, assign_index, stack_size, get_max_bits
└── Makefile
```

---

## Validation

To check that the output actually sorts correctly you need a checker. The 42 project provides one, or you can pipe the output into a simple simulator:

```bash
# Count the number of operations
./push_swap 4 2 5 1 3 | wc -l

# Use the 42 checker (if available)
./push_swap 4 2 5 1 3 | ./checker 4 2 5 1 3
```

### Performance targets (approximate)

| Input size | Target operations |
|------------|-------------------|
| 3 numbers  | ≤ 3 |
| 5 numbers  | ≤ 12 |
| 100 numbers | ≤ 700 |
| 500 numbers | ≤ 5500 |

these comands will show how many opperations it takes
$(shuf -i 1-3 -n 3 | tr '\n' ' ') | wc -l
$(shuf -i 1-5 -n 5 | tr '\n' ' ') | wc -l
$(shuf -i 1-100 -n 100 | tr '\n' ' ') | wc -l
$(shuf -i 1-500 -n 500 | tr '\n' ' ') | wc -l

## To see the result of the sorting we can use 

void	print_stack(t_node *stack)
{
	int i;

	i = 0;
	if (!stack)
	{
		printf("(empty stack)\n");
		return ;
	}
	while (stack)
	{
		printf("[%d] value=%d index=%d\n", i, stack->value, stack->index);
		stack = stack->next;
		i++;
	}
	printf("----\n");
}

and put print_stack(stack_a); just befor freeing the stack i main.

## resources i used

mainly other students and github were where i learned,
i also used video's of the person i will link right now for learning about linked list
[linked list tutorial](https://www.youtube.com/watch?v=uBZHMkpsTfg&list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl)