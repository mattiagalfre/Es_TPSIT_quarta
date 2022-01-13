def push(pila, elemento):
    pila.append(elemento)

def pop(pila):
    if(len(pila) != 0):
        return pila.pop()
    else:
        print("ERRORE!")
        return None

pila = []
risposta = "si"

while( risposta == "si"):
    elemento = input("Inserisci l'elemento da aggiungere alla pila: ")
    push(pila, elemento)
    risposta = input(f"Vuoi inserire altri elementi? ('si' per continuare)")
print(pila)

inverso = []
for _ in range(len(pila)):
    push(inverso, pop(pila))

print(inverso)