class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTree:
    def perOrderTraversal(self, root: TreeNode) -> None:

        mystack = list()
        cur = root
        while cur is not None or mystack:
    
            while cur is not None:
                mystack.append(cur)
                print(cur.val)
                cur = cur.left
            
            tmp = mystack.pop()
            cur = tmp.right
            
        return None


#      1 
#    /   \
#   2     3
#  / \   / \
# 4   5 6   7

ob = TreeNode(1)
ob1 = TreeNode(2)
ob2 = TreeNode(3)


ob.left = ob1
ob.right = ob2

ob3 = TreeNode(4)
ob4 = TreeNode(5)

ob1.left = ob3
ob1.right = ob4


ob5 = TreeNode(6)
ob6 = TreeNode(7)
ob2.left = ob5
ob2.right = ob6

bt = BinaryTree()

bt.perOrderTraversal(ob)