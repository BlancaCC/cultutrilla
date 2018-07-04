def debug (f):
    def new_f (a ,b):
        print( "La suma de {0} y {1} es: ".format(a,b) )
        return f(a,b)
    return new_f

@debug
def add(a,b):
    return a+b

if __name__ == '__main__':
    print( add(1,2) )
    

    
