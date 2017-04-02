# python program for tree traversal
# A class that represents an individual node in a Binary tree


class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

# A function to do inorder tree traversal


def printInorder(root):
    if root:
        # first recur on left child
        printInorder(root.left)
        print(root.val)
        printInorder(root.right)

# A function to do postorder tree traversal


def printPostorder(root):
    if root:
        printPostorder(root.left)
        printPostorder(root.right)
        print(root.val)

# A function to do Preorder tree traversal


def printPreorder(root):
    if root:
        print(root.val)
        printPreorder(root.left)
        printPreorder(root.right)


# Driver code
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Preorder traversal: ")
printPreorder(root)

print("Inoder traversal: ")
printInorder(root)

print("postorder traversal: ")
printPostorder(root)
