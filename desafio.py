idade = int(input("Digite sua idade "))

if (idade >= 16 or idade >= 18) | (idade > 70):
    print("VOce nao precisa votar")

elif idade < 16:
    print("seu voto nao e obrigatorio")
    
elif idade > 18 & idade < 70:
    print("voce e obrigado a votar")