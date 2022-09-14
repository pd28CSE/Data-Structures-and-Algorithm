class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTree:
    def inorderTraversal(self, root: TreeNode) -> None:

        stac = list()
        cur = root
        while cur is not None or stac:
    
            while cur is not None:
                stac.append(cur)
                cur = cur.left
            
            tmp = stac.pop()
            print(tmp.val)
            cur = tmp.right
            
            
        return None


#     1 
#    / \
#   2   3
#  / \
# 4   5

ob = TreeNode(1)
ob1 = TreeNode(2)
ob2 = TreeNode(3)


ob.left = ob1
ob.right = ob2

ob3 = TreeNode(4)
ob4 = TreeNode(5)

ob1.left = ob3
ob1.right = ob4


bt = BinaryTree()

bt.inorderTraversal(ob)