def enqueue(coda, elemento):
    coda.append(elemento)

def dequeue(coda):
    if(len(coda) != 0):
        return coda.pop(0)

coda = [1, 2, 3, 4, 5]

enqueue(coda, 6)
print(coda)
dequeue(coda)
print(coda)


    
