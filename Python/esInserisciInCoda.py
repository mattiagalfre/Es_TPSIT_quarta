import Pile_Code as pc

def main():
    c = pc.Coda()
    
    risposta = "si"
    while(risposta == "si"):
        elemento = int(input("Inserisci il nuovo elemento della coda: "))
        c.enqueue(elemento)
        risposta = input("Vuoi inserire altri elementi? ('si' per continuare): ")
    
    print("CODA: ")
    c.print()

if __name__ == "__main__":
    main()