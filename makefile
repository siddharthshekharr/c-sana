# Makefile for Data Structures Lab Experiments

CC = gcc
CFLAGS = -Wall -lm

# Define targets
all: exp1 exp2 exp3 exp4 exp5 exp6 exp7 exp8 exp9 exp10

# Experiment 1: Tower of Hanoi
exp1: exp1_tower_of_hanoi.c
	$(CC) $(CFLAGS) -o exp1 exp1_tower_of_hanoi.c

# Experiment 2: Stack Operations
exp2: exp2_stack_operations.c
	$(CC) $(CFLAGS) -o exp2 exp2_stack_operations.c

# Experiment 3: Infix to Postfix
exp3: exp3_infix_to_postfix.c
	$(CC) $(CFLAGS) -o exp3 exp3_infix_to_postfix.c

# Experiment 4: Circular Queue
exp4: exp4_circular_queue.c
	$(CC) $(CFLAGS) -o exp4 exp4_circular_queue.c

# Experiment 5: Singly Linked List
exp5: exp5_singly_linked_list.c
	$(CC) $(CFLAGS) -o exp5 exp5_singly_linked_list.c

# Experiment 6: Binary Search Tree
exp6: exp6_binary_search_tree.c
	$(CC) $(CFLAGS) -o exp6 exp6_binary_search_tree.c

# Experiment 7: Graph Traversal
exp7: exp7_graph_traversal.c
	$(CC) $(CFLAGS) -o exp7 exp7_graph_traversal.c

# Experiment 8: Binary Search
exp8: exp8_binary_search.c
	$(CC) $(CFLAGS) -o exp8 exp8_binary_search.c

# Experiment 9: Hashing with Linear Probing
exp9: exp9_hashing.c
	$(CC) $(CFLAGS) -o exp9 exp9_hashing.c

# Experiment 10: Case Study
exp10: exp10_case_study.c
	$(CC) $(CFLAGS) -o exp10 exp10_case_study.c

# Clean up
clean:
	rm -f exp1 exp2 exp3 exp4 exp5 exp6 exp7 exp8 exp9 exp10

# Run specific experiments
run_exp1: exp1
	./exp1

run_exp2: exp2
	./exp2

run_exp3: exp3
	./exp3

run_exp4: exp4
	./exp4

run_exp5: exp5
	./exp5

run_exp6: exp6
	./exp6

run_exp7: exp7
	./exp7

run_exp8: exp8
	./exp8

run_exp9: exp9
	./exp9

run_exp10: exp10
	./exp10 