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
                if cur.right is not None:
                    mystack.append(cur.right)
                mystack.append(cur)
                cur = cur.left
            
            if cur is None:
                cur = mystack.pop()
                if mystack and cur.right == mystack[-1]:
                    tmp = mystack.pop()
                    mystack.append(cur)
                    cur = tmp
                else:
                    print(cur.val)
                    cur = None
            
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