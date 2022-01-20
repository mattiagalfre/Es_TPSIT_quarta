class Pila():
    def __init__ (self):
        self.pila = []
    
    def push(self, elemento):     #ai metodi bisogna sempre passare self
        self.pila.append(elemento)
    
    def pop(self):
        if(len(self.pila) == 0):
            print("ERRORE!")
            return None
        else:
            return self.pila.pop()
    
    def print(self):
        print(self.pila)

class Coda():
    def __init__(self):
        self.coda = []
    
    def enqueue(self, elemento):
        self.coda.append(elemento)

    def dequeue(self):
        if(len(self.coda) != 0):
            return self.coda.pop(0)
        else:
            print("ERRORE!")
            return None
    
    def print(self):
        print(self.coda)

def main():
    p = Pila()
    p.push(1)
    p.push(2)
    x = p.pop()
    p.print()

    q = Coda()
    q.enqueue(5)
    q.enqueue(6)
    x = q.dequeue()
    q.print()

if __name__ == "__main__":
    main()