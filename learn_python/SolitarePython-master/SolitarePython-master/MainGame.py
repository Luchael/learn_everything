from solitairebasics import *
from time import sleep
from PyAi import aichoose,enable,delay
global ncounter
ncounter = 0
lastcard = 0
def reveal():
    print("\n\n\n\n\n\n\n")
    print("Deck: ", end="[")
    print(deck[-1], end="]\n\n")
    for i in range(0, 6):
        print("Stack " + str(i + 1)+": ", end="")
        # choose the current stack
        currentstack = movetostacks[i]
        currentcount = revealedstacks[i]
        currentlen = len(currentstack)-1
        for i in range(0, (len(currentstack)-1) - currentcount):
            print("[ ╳ ]", end=" ")
        # print the revealed cards
        if currentlen>0:
            for i in range(currentlen-currentcount,currentlen):
                stylecard="["+str(currentstack[i+1])+"]"
                print(stylecard,end=" ")
            print("")
        # Print a new line if stack is empty
        else:
            print()
    print()
    # show the top cards of each final pile
    print("Clubs: "+str(club[-1]))
    print("Hearts: " + str(heart[-1]))
    print("Spades: " + str(spade[-1]))
    print("Diamonds: " + str(diamond[-1]))
    print()


def movemany(arraystart, nextarray,revealed,ai):
    keepgoing=True
    movevalid=False
    while (not movevalid) and keepgoing:
        movearray=[]
        numcards=""
        while numcards.__class__ is str and not numcards.isnumeric():
            if ai:
                numcards=aichoose(deck, finalstacks, movetostacks,revealedstacks,"N",lastcard)
            else:
                numcards=input("How many cards should be moved")
            if numcards.isnumeric() and "." not in numcards:
                pass
                if int(numcards)<=revealed:
                    numcards=int(numcards)
                else:
                    keepgoing=tryagain()
        if numcards.__class__ is int and keepgoing:
            movearray.append(arraystart[-numcards:])
        if (movearray[-1][0]).isalpha():
            pass
        if checkplace(nextarray[-1],movearray[-1][0]):
            movevalid=True
        else:
            movevalid=False
        movevalid = True

    if not keepgoing or movevalid == False:
        return [False,0]
    else:
        return [True, numcards]


def pickcard(ai, fromto):
    if ai==False:
        fromstack = checkres(input("Pick a stack:"))
    else:
        fromstack=checkres(aichoose(deck, finalstacks, movetostacks,revealedstacks,fromto,lastcard))
        sleep(delay)
    fcard=False
    # if the card exists, pick it
    # is the stack a number (Non 0)?
    if fromstack.__class__ is int:
        fromstack=int(fromstack)
        if fromstack>0  and fromstack<10 and len(movetostacks[fromstack-1])>1:
            fcard = ((movetostacks[fromstack-1])[-1])
            fromstack=movetostacks[int(fromstack)-1]
        elif fromstack>0  and fromstack<10 and len(movetostacks[fromstack-1])==1:
            fcard = "EMPTY"
            fromstack=movetostacks[int(fromstack)-1]
        elif fromstack == 0 and len(deck) >= 1:
            fcard = deck[-1]
            fromstack = deck
        else :
            print("invalid Choice")
    # is the stack one of the final?
    elif fromstack == "C" :
        fcard = club[-1]
        fromstack = club
    elif fromstack == "H":
        fcard = heart[-1]
        fromstack= heart
    # Did you pick spades?
    elif fromstack == "S" :
        fcard = spade[-1]
        fromstack = spade
    # Did you pick a diamond
    elif fromstack == "D":
        fcard = diamond[-1]
        fromstack = diamond
    # Do you want to pick the next card in the deck?
    elif fromstack == "N":
        fcard=deck[0]
        fromstack= deck
    elif fromstack == "A":
        fcard = "AI ON"
        fromstack = "AI ON"
    else:
        print("Invalid Choice. Choose Again")
    returnarr=[fcard, fromstack]
    return returnarr


# Welcome "Screen"
print("")
print("")
print("Welcome to Text-Solitare")
print("Made by Chinmai Srinivas")
print("Intro To CS Final project")
print("Made in Python 3.6")
print("Started on 12/9/17")
print("Projects Never end. Still a work in progress")
print("Press enter to continue\n")
input()
print("\n\n\n\n\n\n\n")


# reveal instructions
print("Instructions:")
print("To move from a stack, choose 1-6")
print("To move from deck, 0")
print("To move to final stacks:")
print("C- Clubs")
print("H- Hearts")
print("S- Spades")
print("D- Diamonds")
print("N- Next card in Deck")
input("Press enter to Continue")
print("\n\n")

# create the cards
suites=["♠", "♡", "♢", "♣"]
cards=[]
nums=[]
# ADD 1-10 to the numbers
for num in range(1, 10):
    nums.append(str(num))
nums.append("J")
nums.append("Q")
nums.append("K")
nums.append("T")
for suite in suites:
    for type in nums:
        cards.append(type+suite)


#start of the game

# create the piles
deck=[0]
stack1=[1]
stack2=[2]
stack3=[3]
stack4=[4]
stack5=[5]
stack6=[6]
movetostacks=[stack1, stack2,stack3, stack4, stack5, stack6]
club=["C"]
heart=["H"]
spade=["S"]
diamond=["D"]
finalstacks=[club,heart,spade,diamond]
#Show which cards are revealed
revealedstacks=[1,1,1,1,1,1]
for i in range(0,6):
    assign(cards, movetostacks[i],i+1)
assign(cards, deck, len(cards))


# reset score
score = 0
# Turn on or not turn on ai
aion=enable()
#aion = True

#Game Loop
while not haswon(finalstacks):
    score+=1
    reveal()
    # reset the turn variables
    fromcard = 0
    tocard = 0
    fromstack = False
    tostack = False
    movevalid=False
    movedcards = []
    while not movevalid:
        fromcard = 0
        tocard = 0
        fromstack = False
        tostack = False
        breakout=False
        #Choose the stack to move from
        while not fromstack and fromstack.__class__ is bool:
            print("Where should the card come from?")
            if aion:
                fromarr = pickcard(True,"F")
            else:
                fromarr=pickcard(False, "F")
            fromcard = fromarr[0]
            fromstack = fromarr[1]
            print("You chose: "+ str(fromcard))
            isn=False
            #account for the N
            if fromcard==deck[0] and len(deck)>0:
                #bypass the next stuff
                movevalid=True
                fromcard = deck[0]
                tostack= deck[-1]
                isn=True
                ncounter += 1
            else:
                ncounter = 0
            if len(fromstack)<2:
                fromstack=False
            if fromstack == "EMPTY":
                fromstack=False
            if fromstack == "AI ON":
                aion = True
                tocard = "AI ON"
                movevalid = True
                breakout = True
                break
        #choose the stack to move to
        while tocard == 0 and tostack == False:
            print("Where should the card go?")
            if aion:
                toarr = pickcard(True, "T")
            else:
                toarr=pickcard(False, "T")
            tocard=toarr[0]
            tostack=toarr[1]
            print("You chose: "+ str(tocard))
            if tostack==0:
                print("invalid Choice")

        #if you should move many...
        if fromstack in movetostacks and tostack in movetostacks:
            stacknum=movetostacks.index(fromstack)
            many=movemany(fromstack,tostack, revealedstacks[stacknum],aion)
            if many[0]==False:
                many=False
                breakout=True
            else:
                nummoved=many[1]
                nummoved=int(nummoved)
                movedcards=fromstack[-nummoved:]
                print("moving",movedcards)
                for i in movedcards:
                    tostack.append(i)
                    fromstack.remove(i)
                many=True
                movevalid=True
                breakout=False
        else:
            many=False
        # Are you trying to move to the same stack?, not getting the next card in the deck, not moving multiple cards, and not trying agian...
        if tostack != fromstack and not isn and not many and not breakout:
            # Are you trying to move to one of the mid stacks?
            if tostack[0].__class__ is int and tostack[0]>0:

                # Is your move valid?
                if checkplace(tocard, fromcard):
                    movevalid=True
                    movedcards.append(fromcard)
                else:
                    # Make them move again
                    print("invalid Choice Cant Wrong color/number")
            if tostack[0].__class__ is str:
                if checkfinal(tostack,fromcard):
                    movevalid=True
                    movedcards.append(fromcard)
            else:
                pass
    if not breakout:
        lastcard = movedcards
        numcards=len(movedcards)


        # Move throught the deck
        if fromcard == deck[0]:
            deck.append(deck[1])
            deck.pop(1)
        # Otherwise, move the card to the correct spot
        elif many == False:
            fromstack.pop(-1)
            tostack.append(fromcard)

        #check if you have lost
        if ncounter >= 2*len(deck) and len(deck) > 1:

            if aion:
                print("OUT OF MOVES. THE AI HAS FAILED YOU. TRY YOURSELF.")
                aion= False
                ncounter = 0
            else:
                print("OUT OF MOVES. YOU LOOSE. BETTER LUCK NEXT TIME.")
                break
        if tostack in movetostacks:
            # convoluted way of adding 1 to the revealed for that stack
            replace(revealedstacks, int(tostack[0]) - 1, numcards)

        if fromstack in movetostacks:
            # convoluted way of subtracting 1 to the revealed for that stack
            replace(revealedstacks, int(fromstack[0]) - 1, -1 * numcards)
        # if the top card isnt shown, show it
        for i in range(0, 6):
            stack = movetostacks[i]
            stackval=revealedstacks[i]
            if stackval == 0 and len(stack)>1:
                replace(revealedstacks,i,1)
        #make sure nothing is revealed too far
        for i in range(0,6):
            if revealedstacks[i] >= (len(movetostacks[i])):
                replace(revealedstacks,i,-1)
# Make the score better, mostly arbitrary
score += len(deck)*2
for i in range(0,6):
    score += len(movetostacks[i])
    score -= revealedstacks[i]/2
score= 1/score
#make the score not a decimal
score=score*1000000
score=round(score)
#end message. Unimportant
if haswon(finalstacks):
    print("YOU WIN! YAY!")
#Show all the cards
print("Deck: ",end = "")
for i in deck:
    if i == 0:
        pass
    else:
        print("["+i+"]")
print()
for i in range(0, 6):
    print("Stack " + str(i + 1)+": ", end="")
    # choose the current stack
    currentstack = movetostacks[i]
    if len(currentstack)>1:
        for i in currentstack:
            stylecard="["+str(i)+"]"
            print(stylecard,end=" ")
        print("")
    # Print a new line if stack is empty
    else:
        print()
# show the top cards of each final pile
for stack in finalstacks:
    print()
    if stack[0] == "C":
        print("Clubs:    ", end="")
    if stack[0] == "H":
        print("Hearts:   ", end="")
    if stack[0] == "S":
        print("Spades:   ", end="")
    if stack[0] == "D":
        print("Diamonds: ", end="")
    for i in stack:
        if len(i) != 1:
            # Output the card and fix the spacing
            stylecard = "[" + str(i) + "]"
            # Fix an annoying spacing issue
            if stack[0] == "C" or stack[0] == "S":
                #there might not look to be a difference but 1/6 spaces add up
                stylecard = "[" + str(i) + " ]"
            print(stylecard, end=" ")
print()
print("You got a score of", score)
