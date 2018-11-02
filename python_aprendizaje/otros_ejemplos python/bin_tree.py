"""
HOW TO MANAGE BINARI TREE STORAGE
Blanca Cano Camarero
Granada 1/X/18
"""
from sys import argv
null= "0"
############################## Node Class ##############################
class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.value = data

    def printTree(self, level=0):
        print(f'{"   "*level}|__ { self.value}')
        
        if( self.left != None):
            self.left.printTree(level+1)
            
        if( self.right != None):
            self.right.printTree(level+1)

############################## conversion funcions ##############################

# ~~~~~~~~~~~~~~~~~~~~~~~~ list to tree ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def aux_list_to_tree( root, argv):
    # left child node
    if argv : # if not empty
        dato = argv.pop(0)
        if( dato  != null): 
            root.left = Node(dato)
            argv = aux_list_to_tree( root.left , argv )
    # right child node
    if argv:
        dato = argv.pop(0)
        if dato!= null:
            root.right = Node(dato)
            argv = aux_list_to_tree( root.right , argv )

    return argv


def list_to_tree( l):
    # conversion type, aux list
    code = str( bin(l[-1] ))
    code = code[3:] # elinimo la b1, la b de binario y el 1 por defecto
     
    final = l
    final.pop()
    
     
    for i, a in enumerate(code):
        if a == '1':
            final.insert(i, null)

    # create tree
    root = Node(final[0])
    aux_list_to_tree( root, final[1:] ) #le quitamos el inicial a la lista que ya se le ha metido
    #root.printTree()
    return root

# ~~~~~~~~~~~~~~~~~~~~~~~~ tree to list  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def aux_tree_to_list(root, l = []):
    l.append(root.value)
    
    if root.left != None:
        aux_tree_to_list(root.left, l)
    else:
        l.append( null )

    if root.right != None:
        aux_tree_to_list(root.right, l)
    else:
        l.append( null )
    return l

def list_to_dec(l):
    num = 1 # debe empezar en 1 para no comerse los 0 del prinicpio
    
    for i in l:
        num*= 2
        if i == null:
            num += 1
    return num

def tree_to_list(root,l=[]):
    
    l = aux_tree_to_list(root)
    final = [ i for i in l if i != null]
    final.append( (list_to_dec(l)))
    
    return final
            
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ fin ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
if __name__== '__main__':
    if(len(argv) > 1):
        tree = Node(argv[1])
        aux_list_to_tree( tree, argv[2:])
        tree.printTree()
    l = aux_tree_to_list(tree)
    print( l )
    
    final = [ i for i in l if i != null]
    final.append( (list_to_dec(l)))
    #print(final)
    #print( bin(final[-1]))

    tree3 = list_to_tree( final)
    tree3.printTree()
    
    """
        tree2 = Node(1)
        tree2.left = Node(3)
        tree2.left.right = Node(4)
        tree2.left.left = Node('a')
        tree2.right = Node(2)
        tree2.right.right = Node(100)

        tree2.printTree()
      """  
