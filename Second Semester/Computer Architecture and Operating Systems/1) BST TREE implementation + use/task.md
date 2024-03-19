## TASK

# First Part
The first part of the task was to read integers from user input and print them out in increasing order without repeating. We can do this suboptimally with a BST tree (it's depth could be non-logarythmical so that would mean non-logarythmical traversal of a tree).

# Second Part
The second part of the task was to modify the code used in the first half of a task to make it so that any negative integer input from a user would delete the absolute value of this integer from a tree. This of course is not as trivial but in summary we can find the node with our integer and check if it's right subtree is empty. If it is we can swap our node with it's left descendant. If it's not we exchange the value in our node with the smallest value removed from right subtree of our node.  
