import re

class Category:
    """Класс категории продукта"""
    categoryId = 0

    def __init__(self, categoryName, categoryDescription = "") -> None:
        self.categoryName = categoryName
        self.categoryDescription = categoryDescription
        self.categoryId = Category.categoryId

        Category.categoryId += 1

    def __str__(self) -> str:
        return f"Category ID: {self.categoryId} \nCategory Name: {self.categoryName} \nCategory Description: {self.categoryDescription} \n"
    
class Product:
    """Класс продукта"""
    productId = 0

    def __init__(self, productCategory, productName, productUnit, productPrice, productCost, productDate, productDescription = "") -> None:
        self.productCategory = productCategory
        self.productName = productName
        self.productUnit = productUnit
        self.productPrice = productPrice
        self.productCost = productCost
        self.productDate = productDate
        self.productDescription = productDescription
        self.productId = Product.productId

        Product.productId += 1

    def __str__(self) -> str:
        return f"Product ID: {self.productId} \nProduct Name: {self.productName} \nProduct Unit: {self.productUnit} \nProduct Price: {self.productPrice} \nProduct Cost: {self.productCost} \nProduct Date: {self.productDate} \nProduct Description: {self.productDescription} \n"



category1 = Category("Drink")
category2 = Category("Alcohol")

categoryArray = [category1, category2]

product1 = Product(categoryArray[0].categoryName, "Fanta", 100, 350, 295, "10 09 2023")
product2 = Product(categoryArray[1].categoryName, "Bacherovka", 10, 12000, 10000, "10 09 2033")

productArray = [product1, product2]

#print(product2)

class Person:
    """Класс личность """
    def __init__(self, name, surname, address, city, phone) -> None:
        self.name = name
        self.surname = surname
        self.address = address
        self.city = city
        self.phone = phone

class Courier(Person):
    """Класс курьера"""
    ID = 0

    def __init__(self, name, surname, address, city, phone) -> None:
        super().__init__(name, surname, address, city, phone)
        self.ID = Courier.ID
        Courier.ID += 1

    def __str__(self) -> str:
        return f"Courier ID:  {self.ID} \nCourier Name: {self.name} \nCourier Surname: {self.surname} \nCourier Address: {self.address} \nCourier City: {self.city} \nCourier Phone: {self.phone} \n"

class Suplier(Person):
    """Класс поставщик"""
    ID = 0

    def __init__(self, name, surname, address, city, phone, company) -> None:
        super().__init__(name, surname, address, city, phone)
        self.ID = Suplier.ID
        Suplier.ID += 1
        self.company = company

    def __str__(self) -> str:
        return f"Suplier ID:  {self.ID} \nSuplier Name: {self.name} \nSuplier Surname: {self.surname} \nSuplier Address: {self.address} \nSuplier City: {self.city} \nSuplier Phone: {self.phone} \nSuplier Company: {self.company} \n"
    
courier1 = Courier("Poxos", "Poxosyan", "1/1", "Hamzachiman", "(077) 12-34-56")
suplier1 = Suplier("Petros", "Petrosyan", "2/2", "Bayandur", "(033) 65-43-12", "Botlers Armenia")

#print(suplier1)

class ProductManagment:
    """Класс для управления менеджментом"""
    cash = 100000
    login = "admin"
    password = "admin"

    @staticmethod
    def addCaegory():
        temp = Category(input("Type the categor "))
        for iterator in categoryArray:
            if iterator.categoryName == temp.categoryName:
                answer = input("The category is exist \ndo you want to continue y / any other cay ")
                if answer == 'y':
                    return ProductManagment.addCaegory()
                else:
                    return "Thank You"
            else:
                categoryArray.append(temp)
                return "Thank You"

    @staticmethod
    def addProduct():
        temp = Product(input("Type the categor "), input("Type the product name "), int(input("Type the product unit ")), int(input("Type the product price ")), int(input("Type the product coast ")), input("Type the product date "))
        
        for iterator in categoryArray: #stugenq ed kategorian voobshe ka te che
            if iterator.categoryName == temp.productCategory:
                continue
            else:
                answer = input("The category is doesn't exist \ndo you want to creat it y / any other cay ")
                if answer == 'y':
                    categoryArray.append(Category(temp.productCategory)) #sarkenq kategorian u miangamic qcenq masivi mej
                    return "Thank You"
        for iterator in productArray:
            if iterator.productName == temp.productName:
                pass

ProductManagment.addProduct()