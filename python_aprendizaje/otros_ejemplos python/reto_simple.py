def combination( numbers: list , objetive: int, operations: str, actual:int)-> tuple :
   
    from operator import add , sub, floordiv , mul

#     print( 'actual: ', actual , ' operations: ', operations )

    operation = [add , sub , floordiv , mul]
    op_rep = [' + ' , ' - ' , ' // ' , ' * ']
    conditions = [lambda a,b : True , lambda a,b : a-b >0 ,
                  lambda a,b : a%b == 0 , lambda a,b : True]
    operations2=operations
    actual2 = actual

    if ( actual != objetive and len(numbers)> 0 ): # go through number set
        i = 0

        while ( actual2 != objetive and i < len(numbers)):
            j = 0
            while ( actual2 != objetive and j < len(conditions)): # 4 operations
                if conditions[j](actual,numbers[i] ):
                    actual2 , operations2 = combination(numbers[:i]+numbers[i+1:] ,         # pop the number from the list 
                                                      objetive ,                            # remain the goal number 
                                                      operations+op_rep[j]+str(numbers[i]), # add new operation 
                                                      operation[j](actual,numbers[i]) )     # update actual number 
                
                j+=1
            i+=1
    return actual2, operations2
                
            
# en caso de interpretarse el archivo:         
if __name__ == '__main__':

    listas_de_muestra = [[6,8,10,9,4,75] , [3,4,7]]
    a_buscar=[835,28]
    for i,lista in enumerate(listas_de_muestra):
        print (f'Para la lista {lista}, se busca {a_buscar[i]} ')
        
        for j, val in enumerate(listas):
           ret,op = combination( lista[:j]+lista[1+j]  , a_buscar[i] ,'' , val ) )
           if ret ==  a_buscar[i]:
               print( f' Con un resultado exitoso, la operación: {op} ')
               encontrado = True
               break
        

               


 # Muestra en pantalla: 

