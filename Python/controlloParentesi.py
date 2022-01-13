#1) chiedere la stringa all'utente
#2) ciclo sulla stringa in cui si snobba tutto ciò che non è parentesi: ()[]{}
#3) se trovo parentesi aperta faccio push
#4) se trovo parentesi chiusa faccio pop e confronto

def main():
    stringa = input("Inserisci una stringa con parentesi: ")
    print(stringa)
    pila = []
    errori = 0
    
    for carattere in stringa:
        if carattere == '(' or carattere == '[' or carattere == '{':
            pila.append(carattere)
        if carattere == ')' or carattere == ']' or carattere == '}':
            parentesiAperta = pila.pop()
            if parentesiAperta == '(' and carattere != ')':
                errori += 1
            elif parentesiAperta == '[' and carattere != ']':
                errori += 1
            elif parentesiAperta == '{' and carattere != '}':
                errori += 1

    if errori == 0:
        print("Tutto corretto!")
    else:
        print("Ci sono degli errori")

if __name__ == "__main__":
    main()