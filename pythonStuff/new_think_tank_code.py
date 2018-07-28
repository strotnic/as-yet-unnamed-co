import random
import sys
import os
import math

import argparse


def operators():
    ''' OPERATORS
        Arithmatic Operators
            +           plus
            -           minus
            *           multiply
            /           divide
            %           modulo
            **          exponent
            //          floor
            -           negation
            abs()       absolute value
            math.sqrt() square root
            round(<num>, <dec_place>)
        Assignment Operators
            =           equals
            +=          plus equals
            -=          minus equals
            *=          multiply equals
            /=          divide equals
            %=          modulus equals
            **=         exponential equals
            //=         floor equals
        Comparison Operators
            ==          are equal
            !=          are not equal
            <>          are not equal
            >           greater than
            <           less than
            >=          greater than or equal to
            <=          less than or equal to
        Logical Operators
            and
            or
            not
        Bitwise Operators
            &           and
            |           or
            ^           xor
            ~           not
            <<          left shift
            >>          right shift

        Order of Operations
            1   eponentiation (**)
            2   complement and unary plus and minus (~, +@, -@)
            3   multiply, divide, modulo, and floor (*, /, %, //)
            4   addition and subtraction (+, -)
            5   bitwise shift (<<, >>)
            6   bitwise and (&)
            7   bitwise or (^, |)
            8   comparison operators (<, >, <=, >=)
            9   equality operators (==, !=, <>)
            10  assignment operators (=, %=, //=, /=, **=, *=, -=, +=)
            11  identity operators (is, is not)
            12  membership operators (in, not in)
            13  logical operators (not, or, and)

        Data Types
            Numbers
            Strings
            Lists
            Tuples
            Dictionaries
            <variable_name> global
    '''
    print("5 + 2 = ", 5+2)
    print("5 - 2 = ", 5-2)
    print("5 * 2 = ", 5*2)
    print("5 / 2 = ", 5/2)
    print("5 % 2 = ", 5%2)
    print("5 ** 2 = ", 5**2)
    print("5 // 2 = ", 5//2)

def multi_line_strings():
    # Multi-Line Strings and formatted printing
    quote = "\"Always remember you are unique"
    multi_line_quote = '''just
    like everyone else\"'''
    print("%s %s %s" % ('I like the quote', quote, multi_line_quote))

    # Print multiple new lines (for example)
    print('\n' * 5)

    # Get rid of new lines after print statements
    print("I don't like ", end="")
    print("newlines.")

def lists():
    ''' Lists
    '''
    grocery_list = ['Juice', 'Tomatoes', 'Potatoes',
                    'Bannanas']
    print('First Item: ', grocery_list[0])
    grocery_list[0] = "Green Juice"
    print('First Item: ', grocery_list[0])
    print(grocery_list[1:3]) # the upper bound is NOT inclusive!!
    other_events = ['Wash Car', 'Pick Up Kids', 'Cash Check']
    todo_list = [other_events, grocery_list] # List of lists
    print((todo_list[1][1]))

    # List Comprehension Commands
    # [<expr> for <item1> in <seq1> for <item2> in <seq2> ... for <itemx> in <seqx> if <condition>] <- general syntax

    # Other List Commands
    grocery_list.append('Onions')
    grocery_list.insert(1, 'Pickle')
    grocery_list.remove('Pickle')
    grocery_list.sort()
    grocery_list.reverse()
    del grocery_list[4]

def tuples():
    ''' Tuples
    '''
    pi_tuple = (3,1,4,5,9)
    new_tuple = list(pi_tuple)
    new_list = tuple(new_tuple)
    len(new_list)
    min(new_list)
    max(new_list)

def dictionaries():
    ''' Dictionaries
    '''
    super_villains = {'Fiddler' : 'Isaac Bowin',
                    'Captain Cold' : 'Leonard Snart',
                    'Weather Wizard' : 'Mark Mardon',
                    'Mirror Master' : 'Sam Scudder',
                    'Pied Piper' : 'Thomas Peterson'}
    print(super_villains['Captain Cold'])
    del super_villains['Fiddler']
    super_villains['Pied Piper'] = 'Hartley Rathaway'
    print(len(super_villains))
    print(super_villains.get("Pied Piper"))
    print(super_villains.keys())
    print(super_villains.values())

def conditionals():
    ''' Conditionals
        if
        elif
        else
    '''
    age = 21
    if age >= 21:
        print('You are old enough to drink')
    elif age >= 16:
        print('You are old enough to drive')
    else:
        print('You are not old enough to drive')

def loops():
    ''' Loops
        for
        while
        with
        break
        continue
    '''
    grocery_list = ['Juice', 'Tomatoes', 'Potatoes', 'Bannanas']

    for x in range(0, 10): # The upper bound is NOT inclusive!!
        print(x, ' ', end="")
        print('\n')
    for y in grocery_list:
        print(y)
    for x in [2,4,6,8,10]:
        print(x)
    num_list = [[1,2,3],[10,20,30],[100,200,300]]
    for x in range(0, 3):
        for y in range(0,3):
            print(num_list[x][y])
    random_num = random.randrange(0, 100)
    while(random_num != 15):
        print(random_num)
        random_num = random.randrange(0, 100)

    print('\n')

    u = 0
    while(u <= 20):
        if (u%2 == 0):
            print(u)
        elif(u == 9):
            break
        else:
            u += 1
            continue
        
        u += 1

def functions():
    ''' Functions
        - must be defined before being used
        - scope prevents variables local to the function to not be available outside the function
    '''
    def addNumber(fNum, lNum):
        sumNum = fNum + lNum
        return sumNum
    print('\n', addNumber(1, 4))
    # print(sumNum) # returns: (NameError: name 'sumNum' is not defined)

def user_inputs():
    ''' User Input
    '''
    print('What is your name: ')
    name = sys.stdin.readline()

    print('Hello', name)

def string_manipulation():
    ''' String Commands
        .capitalize()
        .find("<string>")
        .isalpha()
        .isalnum()
        .replace("<string1>", "<string2>")
        .strip() #strips white space
        .split("<char used to split the string>") #creates a list of the strings split at the defined character
    '''
    long_string = "I'll catch you if you fall - The Floor"
    print(long_string[0:4])
    print(long_string[-5:]) # prints the last five characters
    print(long_string[:-5]) # prints up to the last five characters
    print("%c is my %s letter and my %d number is %.5f" %
           ('X', 'favorite', 1, .14)) # the %.5f prints out 5 decimal places
    
def file_io():
    test_file = open("test.txt","wb")
    print(test_file.mode())
    print(test_file.name)
    test_file.write(bytes("Write me to the file\n", 'UTF-8'))
    test_file.close()

    test_file = open("test.txt", "r+")
    text_in_file = test_file.read()
    print(text_in_file)
    #test_file.close()
    os.remove("test.txt")

''' Throws errors even though code is the same as in the video (maybe version issue?)
def objects():
    '''''' Classes
        the '__' designates private variables
        setters and getters are necessary for access to all private variables
        constructors used to initialized an object
    ''''''
    class Animal:
        __name = None
        __height = 0
        __weight = 0
        __sound = 0

        def __init__(self, name, height, weight, sound):
            self.__name = name
            self.__height = height
            self.__wight = weight
            self.__sound = sound

        def set_name(self, name):
            self.__name = name

        def set_height(self, height):
            self.__height = height

        def set_weight(self, weight):
            self.__weight = weight

        def set_sound(self, sound):
                self.__sound = sound
        
        def get_name(self):
            return self.__name
        
        def get_height(self):
            return self.__height
        
        def get_weight(self):
            return self.__weight
        
        def get_sound(self):
            return self.__sound

        def get_type(self):
            print("Animal")

        def toString(self):
            return "{} is {} cm tall and {} kilograms and says {}".format(self.__name, self.__height, self.__weight, self.__sound)

    cat = Animal('Whiskers', 33, 10, 'Meow')
    print(cat.toString())

    # Inheritance Example of dog inheriting the traits of animal
    class Dog(Animal):
        __owner = ""

        def __int__(self, name, height, weight, sound, owner):
            self.__owner = owner
            super(Dog, self).__init__(name, height, weight, sound)

        def set_owner(self, owner):
            self.__owner = owner

        def get_owner(self):
            return self.__owner

        def get_type(self):
            print("Dog")

        def toString(self):
            return "{} is {} cm tall and {} kilograms and says {} and is owned by {}".format(self.__name, self.__height, self.__weight, self.__sound, self.__owner)

        # Function Overloading example for how many times we want the dog to bark
        def multiple_sounds(self, how_many=None):   # value of None allows how_many to be an optional argument
            if how_many is None:
                print(self.get_sound())
            else:
                print(self.get_sound() * how_many)

    spot = Dog("Spot", 53, 27, "Ruff", "Derek")
    print(spot.toString())

    # Example of poly-morphism: refering to the super class and having the correct functions automatically
    class AnimalTesting:
        def get_type(self, animal):
            animal.get_type()

    test_animals = AnimalTesting()
    test_animals.get_type(cat)
    test_animals.get_type(spot)

    spot.multiple_sounds(4)
    spot.multiple_sounds()
'''

operators()
multi_line_strings()
lists()
tuples()
dictionaries()
conditionals()
loops()
functions()
user_inputs()
string_manipulation()
file_io()
# objects() - throws errors right now.=(

