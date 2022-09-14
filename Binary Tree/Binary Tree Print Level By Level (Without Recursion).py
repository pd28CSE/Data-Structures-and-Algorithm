from queue import Queue

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTree:
    def levelByLebelTraversal(self, root: TreeNode) -> None:

        myq = Queue()

        if root is not None:
            myq.put(root)

        lavel = 0
        while myq.empty() == False:
            
            print('Lavel: {}'.format(lavel), end=' -->  ')
            totalnode = myq.qsize()
            for i in range(totalnode):
                cur = myq.get()
                print(cur.val, end='  ')
                if cur.left is not None:
                    myq.put(cur.left)
                if cur.right is not None:
                    myq.put(cur.right)
            print()
            lavel += 1
            
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

bt.levelByLebelTraversal(ob)