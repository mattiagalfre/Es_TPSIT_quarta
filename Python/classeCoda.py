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

c1 = Coda()
c1.enqueue(7)
c1.print()
c1.dequeue()
c1.print()
c1.enqueue("ciao")
c1.enqueue("sistemi")
c1.print()