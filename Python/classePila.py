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


p1 = Pila()     #istanza della classe Pila
p1.print()
p1.push("ciao")
p1.push("8")
p1.push("sistemi")
p1.print()
p1.pop()
p1.push(5)
p1.print()
