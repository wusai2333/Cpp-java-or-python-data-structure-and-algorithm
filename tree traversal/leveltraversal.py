# Recursive Python program for level order traversal of Binary tree
# A Node class


class Node:
    # A utility funtion to create a new Node
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


def printLevelOrder(root):
    h = height(root)
    for i in range(1, h + 1):
        printGivenLevel(root, i)


def printGivenLevel(root, level):
    if root is None:
        return
    if level == 1:
        print("%d " % root.data, end="")
    elif level > 1:
        printGivenLevel(root.left, level - 1)
        printGivenLevel(root.right, level - 1)

# Compute the height of the tree -- the number of nodes along the longest path
# from the root node to the farthest leaf node


def height(node):
    if node is None:
        return 0
    else:
        # Computer the height of each subtree
        lheight = height(node.left)
        rheight = height(node.right)

        # Use the larger one
        if lheight > rheight:
            return lheight + 1
        else:
            return rheight + 1


# Driver program to test above function
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Level order traversal of binary tree is: ")
printLevelOrder(root)
