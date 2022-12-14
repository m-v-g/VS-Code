# -*- coding: utf-8 -*-
"""Python_Basic_OOP.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1I5zb5URXxuIO1y0Qge3mvmGXHKP2GCie

# Lesson 1
"""

class Animal:
    color = 'black'
    gender = 'male'

dog = Animal()

dog.color

dog.gender

Animal.color = 'grey'

dog.color

cat = Animal()

cat.color

Animal.__dict__

dog.__dict__

dog.color = 'red'

dog.__dict__

dog.color

Animal.color

cat.color

setattr(Animal, 'age', 10)

Animal.name = 'AT'

Animal.__dict__

setattr(dog, 'age', 20)

dog.__dict__

#update attr
setattr(dog, 'age', 50)

dog.age

Animal.res

getattr(Animal, 'res', "there is no attrbute like this")

getattr(Animal, 'age', "there is no attrbute like this")

del Animal.color

Animal.__dict__

cat.color

dog.color

del Animal.color

# check if exists

hasattr(Animal,'color')

hasattr(Animal,'gender')

if hasattr(Animal,'gender'): #hasattr(Animal,'gender')
    del Animal.gender

Animal.__dict__

Animal.gender = 'male'

delattr(Animal, 'gender') # del Animal.gender

Animal.__dict__

cat.__dict__

hasattr(cat, 'age') #not its' attribute though

del cat.age #not it's attribute so we can't delete it

class Animal:
    "class for animals"
    
    color = 'black'
    gender = 'male'

Animal.__doc__

"""# Lesson 2"""

class Animal:
    color = 'black'
    gender = 'male'
    
    def actions():
        print('animal actions')

Animal.actions

Animal.actions()

dog = Animal()

dog.actions

dog.actions()

class Animal:
    color = 'black'
    gender = 'male'
    
    def actions(self): # self is a pointer reference to instance
        print('animal actions' + str(self))



dog = Animal()

dog.actions() #adress of instance dog

# We're giving access to class instaces to our parent class methods

Animal.actions()

Animal.actions(dog)

class Animal:
    color = 'black'
    gender = 'male'
    
    def animal_params(self,weight, height): # self is a pointer reference to instance
        
        self.weight = weight
        self.height = height
        
        print(self.weight * self.height)

cat = Animal()

cat.__dict__

cat.animal_params(10,50)

cat.__dict__

dog = Animal()
dog.animal_params(20,70)

dog.__dict__

Animal.__dict__

class Animal:
    color = 'black'
    gender = 'male'
    height = 10000
    
    def animal_params(self,weight, height): # self is a pointer reference to instance
        
        self.weight = weight
        self.height = height
        
        print(self.weight * self.height)
        
    def get_params(self):
        
        return(self.weight, self.height)

cat = Animal()
cat.animal_params(20,50)

cat.get_params()

"""# Lesson 3"""

class Animal:
    color = 'black'
    gender = 'male'
    
    def __init__(self,weight, height):
        
        self.weight = weight
        self.height = height
        
    def get_params(self):
        
        return(self.weight, self.height)

cat = Animal(10,50)

cat.__dict__

cat.color

cat.get_params()

Animal.__dict__

class Animal1:
    color = 'black'
    gender = 'male'
    
    def __init__(self,weight, height):
        
        self.weight = weight
        self.height = height
        
    # def __del__(self):
    #     print('deleting instance')
        
    def get_params(self):
        
        return(self.weight, self.height)

dog = Animal1(10,20)

dog.__dict__

dog = 'animal'

dog.__dict__

"""# Lesson 4"""

class Animal:
    min_height = 10
    max_height = 200
    
    @classmethod
    def validate_height(cls, height):
        return cls.min_height <= height <= cls.max_height
    
    def __init__(self,weight, height):
        
        if Animal.validate_height(height):
            self.weight = weight
            self.height = height
        else:
            self.height = 0
            self.weight = weight
        
    def get_params(self):
        
        return(self.weight, self.height)

Animal.validate_height(20)

Animal.validate_height(7720)

parrot = Animal(10,60)

parrot.__dict__

parrot = Animal(1,50000)

parrot.__dict__

class Animal:
    min_height = 10
    max_height = 200
    
    @classmethod
    def validate_height(cls, height):
        return cls.min_height <= height <= cls.max_height
    
    def __init__(self,weight, height):
        
        if self.validate_height(height) and self.validate_height(weight):
            self.weight = weight
            self.height = height
        else:
            self.height = 0
            self.weight = 0
        
    def get_params(self):
        
        return(self.weight, self.height)

cat = Animal(20,9999)

cat.__dict__

cat = Animal(20,17)

cat.__dict__

class Animal:
    min_height = 10
    max_height = 200
    
    def __init__(self, x, y):
        if self.animal_size(x, y) < 100:
            print('wrong input')
            self.x = self.y = 0
        else:
            self.x = x
            self.y = y
    
    @staticmethod
    def animal_size(a, b):
        return a + b

cat = Animal(10,20)

cat.__dict__

cat = Animal(1000,2000)

cat.__dict__

Animal.animal_size(30,70)

