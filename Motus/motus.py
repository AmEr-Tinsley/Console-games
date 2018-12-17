from random import choice

def fileTolist(filename):
    return list(map(lambda x: x.split(" \n")[0], open(filename, "r").readlines()))


def randomWord(words, sz):
    return choice([x for x in words if len(x) == sz])


def compareWords(word, exact):
    return [word[i].upper() if word[i].upper() == exact[i] else word[i].lower() if word[i].upper() in exact else "." for i in
            range(len(word))]


def game():
    dico = fileTolist("dico.txt")
    sz = int(input("What's the length of the word: "))
    START_WORD = [randomWord(dico, sz).upper(),randomWord(dico, sz).upper()]
    best_done = [[START_WORD[0][x] if x == 0 else '.' for x in range(sz)],[START_WORD[1][x] if x == 0 else '.' for x in range(sz)]]
    wa = choice(range(1, 10))
    Tries = [wa,wa]
    turn=0
    print(START_WORD[0])
    print(START_WORD[1])
    while Tries[0] > 0 or Tries[1]>0:
        print("\n\n\n***********************************\n")
        print("It's player ",str(turn+1)," turn")
        print(str(Tries[turn]) + " remaining Tries : ")
        print(best_done[turn])
        next_try = input("That's your best result so far,can you Guess the word now ? ")
        next_try=next_try.upper()
        if next_try.upper() == START_WORD[turn]:
            Tries[int(not turn)]=0
            break
        best_done[turn] = compareWords(next_try, START_WORD[turn])
        Tries[turn]-=1
        turn=int(not turn)
    if  Tries[0]==0 and Tries[1]==0:
        print("\n\n\nBoth are unlucky , no one guessed his word ")
        print("Plyer 1 word was : ",START_WORD[0])
        print("Player 2 word was : ",START_WORD[1])
    elif Tries[0]>0:
        print("\n\n\n**********************\n\nAnd the winner of this game is player 1 !! Congrats!")
    else:
        print("\n\n\n**********************\n\nAnd the winner of this game is player 2 !! Congrats!")


game()
