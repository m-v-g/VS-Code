import datetime

class Product:
    """doc"""
    def __init__(self, name, quantity, category, price, cost, prod_date, expiration_date, brand, color, url, description, company):
        self.name = name
        self.quantity = quantity
        self.category = category
        self.price = price
        self.cost = cost
        self.prod_date = prod_date
        self.expiration_date = expiration_date
        self.brand = brand
        self.color = color
        self.url = url
        self.description = description
        self.company = company

    def income(self):
        return self.price * self.quantity

    def profit(self):
        return self.price - self.cost

    def information(self):
        return self.description, self.price

    def status(self):
        now = datetime.datetime.now()
        if now.year >= self.prod_date:
            return True
        else:
            return False

tushonka = Product("Tushonka", 50, "Food", 500, 50, 2022, 2023, "MOO", "red", "https://meet.google.com/wsk-bcrr-okj", "wsk-bcrr-okj", "artfood")
kilka = Product("Kilka", 99, "Food", 600, 66, 2022, 2023, "KII", "black", "https://meet.google.com/wsk-bcrr-okj", "wsk-bcrr-okj", "map")

print(tushonka.__dict__)
print("tushomka.income:\t" + str(Product.income(tushonka)))
print("kilka.status:\t" + str(Product.status(kilka)))
setattr(tushonka, 'country', "Armenia")
print(tushonka.__dict__)
setattr(Product, 'ankap', 666)
print(Product.__dict__)
if hasattr(Product, 'ankap'):
    del Product.ankap
print(Product.__dict__)
print("============================================")

class Drinks(Product):
    def __init__(self, name, quantity, category, price, cost, prod_date, expiration_date, brand, color, url, description, company, alcohol, ml):
        super().__init__(name, quantity, category, price, cost, prod_date, expiration_date, brand, color, url, description, company)
        self.alcohol = alcohol
        self.ml = ml

    def is_alcohol(self, age):
        if self.alcohol:
            if age < 18:
                return False
        return True

bacherovka = Drinks("Bacherovka", 50, "Drink", 500, 50, 2022, 2023, "BAA", "green", "https://meet.google.com/wsk-bcrr-okj", "wsk-bcrr-okj", "bach", True, 40)
print("is_alcohol:\t" + str(bacherovka.is_alcohol(20)))