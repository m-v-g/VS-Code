#from curses.ascii import isalnum, isalpha, isupper
from pyclbr import Function
import re
import datetime

class Category:
    """Класс категории продукта"""
    category_id = 0

    def __init__(self, category_name, category_description = "") -> None:
        self.category_name = category_name
        self.category_description = category_description
        self.category_id = Category.category_id

        Category.category_id += 1

    def __str__(self) -> str:
        return f"Category ID: {self.category_id} \nCategory Name: {self.category_name} \nCategory Description: {self.category_description} \n"
    
class Product:
    """Класс продукта"""
    product_id = 0

    def __init__(self, product_category, product_name, product_unit, product_price, product_cost, product_date, product_description = "") -> None:
        self.product_category = product_category
        self.product_name = product_name
        self.product_unit = product_unit
        self.product_price = product_price
        self.product_cost = product_cost
        self.product_date = product_date
        self.product_description = product_description
        self.product_id = Product.product_id

        Product.product_id += 1

    def __str__(self) -> str:
        return f"Product ID: {self.product_id} \nProduct Name: {self.product_name} \nProduct Unit: {self.product_unit} \nProduct Price: {self.product_price} \nProduct Cost: {self.product_cost} \nProduct Date: {self.product_date} \nProduct Description: {self.product_description} \n"



category1 = Category("Drink")
category2 = Category("Alcohol")

category_array = [category1, category2]

product1 = Product(category_array[0].category_name, "Fanta", 100, 350, 295, "10 09 2023")
product2 = Product(category_array[1].category_name, "Bacherovka", 10, 12000, 10000, "10 09 2033")

product_array = [product1, product2]

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
    id = 0

    def __init__(self, name, surname, address, city, phone) -> None:
        super().__init__(name, surname, address, city, phone)
        self.id = Courier.id
        Courier.id += 1

    def __str__(self) -> str:
        return f"Courier ID:  {self.id} \nCourier Name: {self.name} \nCourier Surname: {self.surname} \nCourier Address: {self.address} \nCourier City: {self.city} \nCourier Phone: {self.phone} \n"


class Suplier(Person):
    """Класс поставщик"""
    id = 0

    def __init__(self, name, surname, address, city, phone, company) -> None:
        super().__init__(name, surname, address, city, phone)
        self.id = Suplier.id
        Suplier.id += 1
        self.company = company

    def __str__(self) -> str:
        return f"Suplier ID:  {self.id} \nSuplier Name: {self.name} \nSuplier Surname: {self.surname} \nSuplier Address: {self.address} \nSuplier City: {self.city} \nSuplier Phone: {self.phone} \nSuplier Company: {self.company} \n"
    
courier1 = Courier("Poxos", "Poxosyan", "1/1", "Hamzachiman", "(077) 12-34-56")
suplier1 = Suplier("Petros", "Petrosyan", "2/2", "Bayandur", "(033) 65-43-12", "Botlers Armenia")

courier_array = [courier1]
suplier_array = [suplier1]


class Product_Managment:
    """Класс для управления менеджментом"""
    cash = 100000
    login = "admin"
    password = "admin"
    users = {login : password}

    @staticmethod
    def search():
        temp_array = input("Choise dhe array \n1 - product \n2 - category \n3 - supplier \n4 - courier \n")
        temp_kayword = input("Type the kayword ")
        if temp_array == '1':
            for iterator in product_array:
                if iterator.product_name == temp_kayword:
                    print(iterator)
                    return "founded"
        elif temp_array == '2':
            for iterator in category_array:
                if iterator.category_name == temp_kayword:
                    print(iterator)
                    return "founded"
        elif temp_array == '3':
            for iterator in suplier_array:
                if iterator.name == temp_kayword:
                    print(iterator)
                    return "founded"
        elif temp_array == '4':
            for iterator in courier_array:
                if iterator.name == temp_kayword:
                    print(iterator)
                    return "founded"
        else:
            answer = input("Wrong choise \ndo you want to try again y / any other cay ")
            if answer == 'y':
                return Product_Managment.show_array()
            else:
                return "See you next time"

    @staticmethod
    def add_remove_supplier():
        temp = input("Type the courier name ")
        for iterator in suplier_array:
            if iterator.name == temp:
                answer = input("The suplier is exist \nare yu shor you want to delite hem? y / any other cay ")
                if answer == 'y':
                    suplier_array.remove(iterator)
                    return "removed"
                else:
                    return "Thank you"
            else:
                answer = input("The suplier does not ezist \nare yu shor you want to add hem? y / any other cay ")
                if answer == 'y':
                    temp_supplier = Courier(input("Suplier name: "), input("Suplier surname: "), input("Suplier address: "), input("Suplier sity: "), input("Suplier phone: "), input("Suplier company: "))
                    suplier_array.append(temp_supplier)
                    Suplier.id -= 1
                    return "added"
                else:
                    return "Thank you"

    @staticmethod
    def add_remove_courier():
        temp = input("Type the courier name ")
        for iterator in courier_array:
            if iterator.name == temp:
                answer = input("The coirier is exist \nare yu shor you want to delite hem? y / any other cay ")
                if answer == 'y':
                    courier_array.remove(iterator)
                    return "removed"
                else:
                    return "Thank you"
            else:
                answer = input("The coirier does not ezist \nare yu shor you want to add hem? y / any other cay ")
                if answer == 'y':
                    temp_corier = Courier(input("Courier name: "), input("Courier surname: "), input("Courier address: "), input("Courier sity: "), input("Courier phone: "))
                    courier_array.append(temp_corier)
                    Courier.id -= 1
                    return "added"
                else:
                    return "Thank you"

    @staticmethod
    def del_product():
        temp_name = input("Type deleting product name ")
        for iterator in product_array:
            if iterator.product_name == temp_name:
                product_array.remove(iterator)
            else:
                answer = input("This product does not exist \ndo you want to try again y / any other cay ")
                if answer == 'y':
                    return Product_Managment.sell_product()
                else:
                    return "See you next time"

    @staticmethod
    def show_array():
        answer = input("Choise dhe array \n1 - product \n2 - category \n3 - supplier \n4 - courier \n")
        if answer == '1':
            for iterator in product_array:
                print(iterator)
        elif answer == '2':
            for iterator in category_array:
                print(iterator)
        elif answer == '3':
            for iterator in suplier_array:
                print(iterator)
        elif answer == '4':
            for iterator in courier_array:
                print(iterator)
        else:
            answer = input("Wrong choise \ndo you want to try again y / any other cay ")
            if answer == 'y':
                return Product_Managment.show_array()
            else:
                return "See you next time"

    @staticmethod
    def check_cash():
        print(f"Cash is equal to: {Product_Managment.cash}")

    @staticmethod
    def add_product():
        temp = Product(input("Type the categor "), input("Type the product name "), int(input("Type the product unit ")), int(input("Type the product price ")), int(input("Type the product coast ")), input("Type the product date "))
        product_array.append(temp)
        Product_Managment.cash -= temp.product_cost * temp.product_unit

    @staticmethod
    def add_caegory():
        temp = Category(input("Type the categor "))
        for iterator in category_array:
            if iterator.category_name == temp.category_name:
                answer = input("The category is exist \ndo you want to continue y / any other cay ")
                if answer == 'y':
                    return Product_Managment.add_caegory()
                else:
                    return "Thank You"
            else:
                category_array.append(temp)
                return "Thank You"

    @staticmethod
    def sell_product():
        temp_name = input("Type sel product name ")
        temp_qantity = int(input("Type sel product qantity "))
        for iterator in product_array:
            if iterator.product_name == temp_name:
                if iterator.product_unit >= temp_qantity:
                    iterator.product_unit -= temp_qantity
                    Product_Managment.cash += iterator.product_price * temp_qantity
                    return "sold"
                else:
                    print("Not enough product")
                    return "sold out"
            else:
                answer = input("This product does not exist \ndo you want to try again y / any other cay ")
                if answer == 'y':
                    return Product_Managment.sell_product()
                else:
                    return "See you next time"


class ManagementInterface:
    '''@staticmethod
    def authorization():
        while True:
            answer = input("LOGIN: ")
            if answer == Product_Managment.login:
                while True:
                    answer = input("PASSWORD: ")
                    if answer == Product_Managment.password:
                        return ManagementInterface.action()
                    else:
                        continue
            else:
                continue
    @staticmethod'''

    def authorization():
        while True:
            temp = input("Type 'l' to login or 'r' to sign up ")
            if temp == 'l':
                while True:
                    temp_login = input("LOGIN: ")
                    if temp_login in Product_Managment.users.keys():
                        while True:
                            temp_passw = input("PASSWORD: ")
                            if temp_passw == Product_Managment.users[temp_login]:
                                ManagementInterface.action()
                            else:
                                continue
                            break
                    else:
                        continue
                    break
            elif temp == 'r':
                while True:
                    temp_login = input("LOGIN: ")
                    if ManagementInterface.check_l_p(temp_login):
                        if temp_login not in Product_Managment.users.keys():
                            while True:
                                temp_passw = input("PASSWORD: ")
                                if ManagementInterface.check_l_p(temp_passw):
                                    Product_Managment.users[temp_login] = temp_passw
                                    ManagementInterface.action()
                                break
                        else:
                            continue
                    break
            else:
                continue
            break

    @staticmethod
    def check_l_p(tmp) -> bool:
        num_ok = False
        upper_ok = False
        later_ok = False
        #alp_ok = False
        znak = "+-*/@!#$%^&()\{\}"

        if len(tmp) >= 8 and tmp.isalpha() == False:
            for i in tmp:
                if i not in znak:
                    if i.isalnum():
                        num_ok = True
                        if i.isupper():
                            upper_ok = True
                        else:
                            later_ok = True

        if num_ok and upper_ok and later_ok:
            return True
    

    @staticmethod
    def action():
        while True:
            answer = input("Add product - 0 \nAdd category - 1 \nSell product - 2 \
                \nCheck cash - 3 \nShow info - 4 \nDelete product - 5 \
                \nAdd or remove courier - 6 \nAdd or remove suplier - 7\
                \nSearch - 8 \nExit - 9 \n")
            if answer == '0':
                Product_Managment.add_product()
            elif answer == '1':
                Product_Managment.add_caegory()
            elif answer == '2':
                Product_Managment.sell_product()
            elif answer == '3':
                Product_Managment.check_cash()
            elif answer == '4':
                Product_Managment.show_array()
            elif answer == '5':
                Product_Managment.del_product()
            elif answer == '6':
                Product_Managment.add_remove_courier()
            elif answer == '7':
                Product_Managment.add_remove_supplier()
            elif answer == '8':
                Product_Managment.search()
            elif answer == '9':
                return "Thank you"
            else:
                ManagementInterface.action()

#ManagementInterface.authorization()


class Paymant:
    paymant_id = 0
    def __init__(self) -> None:
        self.paymant_type = "Cash"
        self.paymant_id = Paymant.paymant_id
        Paymant.paymant_id += 1

    def __str__(self) -> str:
        return f"Paymant ID: {self.paymant_id} \nPaymant type: {self.paymant_type}"


class CardPaymant:

    def __init__(self, card_type, card_number, card_holder, card_date, card_cvi) -> None:
        self.paymant_type = "Card"
        self.paymant_id = Paymant.paymant_id
        self.card_type = card_type
        self.card_number = card_number
        self.card_holder = card_holder
        self.card_date = card_date
        self.card_cvi = card_cvi
        Paymant.paymant_id += 1

    def __str__(self) -> str:
        return f"Paymant ID: {self.paymant_id} \nPaymant type: {self.paymant_type} \nCard type: {self.card_type} \
            \nCard number: {self.card_number} \nCard holder {self.card_holder} \nCard date {self.card_date} \nCard CVI: {self.card_cvi} \n"


card1 = CardPaymant("Visa", "1234 5678 9009 8765", "ASDFGH QWERTY", "12/22", "999")
card2 = CardPaymant("Master Card", "9876 5432 1001 2345", "YTREWQ HGFDSA", "02/23", "666")
card3 = CardPaymant("American Express", "5612 3448 5564 9999", "POIUY LKJHGF", "56/98", "333")

card_array = [card1, card2, card3]

class OrderConstructor:
    shopping_bag = {}
    chosen_product = {}
    total_amount = {}

    def __init__(self, product, count) -> None:
        self.product = product
        self.count = count

    def add_product_to_order(self):
        for iterator in product_array:
            if iterator.product_name == self.product and iterator.product_unit >= self.count:
                OrderConstructor.shopping_bag[self.product] = self.count
                OrderConstructor.chosen_product[iterator.product_name] = iterator.product_unit
                OrderConstructor.total_amount[iterator.product_name] = [iterator.product_price, self.count]
                return OrderConstructor.shopping_bag
            elif iterator.product_unit < self.count:
                return "Quantity not required"
            else:
                return "No such product"
    
    @staticmethod
    def remove_product_to_order():
        temp = input("Type the removing product name ")
        if temp in OrderConstructor.shopping_bag.keys():
            del(OrderConstructor.shopping_bag[temp])
            del(OrderConstructor.total_amount[temp])
            return OrderConstructor.shopping_bag
        else:
            return "Product not found"

    @staticmethod
    def reduce_quantity ():
        temp_name = input("Type the rdused product name ")
        temp_qantity = int(input("Type the quntity "))
        if temp_name in OrderConstructor.shopping_bag.keys():
            if OrderConstructor.shopping_bag[temp_name] > temp_qantity:
                OrderConstructor.shopping_bag[temp_name] -= temp_qantity
                OrderConstructor.total_amount[temp_name][1] -= temp_qantity
            elif OrderConstructor.shopping_bag[temp_name] <= temp_qantity:
                del(OrderConstructor.shopping_bag[temp_name])
                del(OrderConstructor.total_amount[temp_name])
            return OrderConstructor.shopping_bag
        else:
            return "Product not found"

    @staticmethod
    def add_quantity ():
        temp_name = input("Type the added product name ")
        temp_qantity = input("Type the quntity ")
        if temp_name in OrderConstructor.shopping_bag.keys():
            OrderConstructor.shopping_bag[temp_name] += temp_qantity
            OrderConstructor.total_amount[temp_name][1] += temp_qantity
            return OrderConstructor.shopping_bag
        else:
            return "Product not found"


class OrderDetail:
    order_detail_id = 0

    def __init__(self, delivery_address, delivery_city, recipient_phone) -> None:
        self.order_detail_id = OrderDetail.order_detail_id
        self.shopping_bag = OrderConstructor.shopping_bag
        self.total_payment = OrderConstructor.total_amount
        self.delivery_address = delivery_address
        self.delivery_city = delivery_city
        self.recipient_phone = recipient_phone
        OrderDetail.order_detail_id += 1

    def __str__(self) -> str:
        return f"Order detail ID: {self.order_detail_id} \nShopping bag: {self.shopping_bag} \
            \nTotal payment: {self.total_payment} \nDelivery address: {self.delivery_address} \
            \nDelivery city: {self.delivery_city} \nRecipient phone: {self.recipient_phone} \n"


class RegisteredUser (Person):
    registered_user_id = 0
    login_password_dict = {}

    def __init__(self, name, surname, address, city, phone, email, password) -> None:
        super().__init__(name, surname, address, city, phone)
        self.registered_user_id = RegisteredUser.registered_user_id
        self.email = email
        self.password = password
        self.reg_date = datetime.datetime.now()
        registered_user_id += 1

    def add_credentials(self):
        if self.email not in RegisteredUser.login_password_dict.keys():
            RegisteredUser.login_password_dict[self.email] = self.password
            return True
        else:
            return False

    def __str__(self) -> str:
        return f"User name: {self.name} \nUser surname{self.surname} \nUser address{self.address} \
            \nUser city{self.city} \nUser phone{self.phone} \nUser email{self.email} \nUser password{self.password}"


r_user1 = RegisteredUser("Anna", "Anyan", "asda", "Gyumri", "5464654", "qwerty@mail.ru", "54564654")
r_user2 = RegisteredUser("Abo", "Abyan", "asda", "Erevan", "5464654", "asdfgh@mail.ru", "87878868")

registred_user_array = [r_user1, r_user2]

for iterator in registred_user_array:
    iterator.add_credentials()


class SignIn:
    def __init__(self, email, password) -> None:
        self.email = email
        self.password = password

    def check_pass(self):
        if self.email in RegisteredUser.login_password_dict.keys():
            if self.password in RegisteredUser.login_password_dict.values():
                return True
            else: 
                return False
        else:
            return False

    def edit_account(self):
        for iteraator in registred_user_array:
            if iteraator.password == self.password:
                edit = Function.for_print("Edit name - 1 \nEdit surname - 2 \nEdit address - 3\
                    \nEdit city - 4 \nEdit phone - 5 \nEdit email - 6 \nEdit password - 7 \n")
                accaunt = iteraator
                if edit in ['1', '2', '3', '4', '5', '6', '7']:
                    new = input("Enter new value ")
                    if edit == '1':
                        accaunt.name = new
                    elif edit == '2':
                        accaunt.surname = new
                    elif edit == '3':
                        accaunt.address = new
                    elif edit == '4':
                        accaunt.city = new
                    elif edit == '5':
                        accaunt.phone = new
                    elif edit == '6':
                        accaunt.email = new
                    elif edit == '7':
                        accaunt.password = new
                else:
                    return False

    def delete_account(self):
        for iterator in registred_user_array:
            if iterator.password == self.password:
                delete = input("If you want to delete account pres 1 otherwize pres any other kay")
                if delete == 1:
                    registred_user_array.pop(registred_user_array.index(iterator))
                    del RegisteredUser.login_password_dict[iterator.email]
                    return True
                else:
                    return False


class Order:
    order_id = 0

    def __init__(self, delivery_address, delivery_city, recipient_phone, payment_type, total_payment, shopping_bag, order_detail_id) -> None:
        self.delivery_address = delivery_address
        self.delivery_city = delivery_city
        self.recipient_phone = recipient_phone
        self.payment_type = payment_type
        self.total_payment = total_payment
        self.shopping_bag = shopping_bag
        self.order_detail_id = order_detail_id
        self.order_id = Order.order_id
        self.order_date = datetime.datetime.now()
        Order.order_id += 1

    def __str__(self) -> str:
        return f"Order id: {self.order_id} \nOrder detail id: {self.order_detail_id} \nOrder date: {self.order_date}\
            \nShoping bag: {self.shopping_bag} \nTotal paymant: {self.total_payment} \nPaymant type {self.payment_type}\
            \nRecipient phone: {self.recipient_phone} \nDelivery city: {self.delivery_city} \nDelivery address: {self.delivery_address}\n"

order_array = []


class UserManagement:
    @staticmethod
    def reg():
        new_user = RegisteredUser(input("Name: "), input("Surname: "), input("Address: "), input("City: "),
                                 input("Phone: "), input("Email: "), input("Password: "), )
        if new_user.add_credentials() == True:
            registred_user_array.append(new_user)
        else:
            print("User with this email alredy exist")

    @staticmethod
    def shopping():
        while True:
            choose = Function.for_print("Add product - 1 \nRemove product - 2 \nReduce quantity - 3 \
                \nAdd quantity- 4 \nSee shopping bag - 5 \nPrevious menu - 6 \n")
            if choose == '1':
                buy = OrderConstructor(input("Product name: "), int(input("Product quantity: ")))
                buy.add_product_to_order()
            elif choose == '2':
                OrderConstructor.remove_product_to_order()
            elif choose == '3':
                OrderConstructor.reduce_quantity()
            elif choose == '4':
                OrderConstructor.add_quantity()
            elif choose == '5':
                for i, k in OrderConstructor.shopping_bag.items():
                    print(i, "-", k)
            elif choose == '0':
                return "Thank you"
    @staticmethod
    def sign_in():
        user = SignIn(input("Input email: "), input("Input password: "))
        if user.check_pass() == True:
            while True:
                choose = Function.for_print("See product - 1 \nEdit accaunt - 2\nDelite accaunt - 3\
                    \nEdit shoping bag - 4 \nFill order deatil - 5 \nExit - 0")
                if choose == '1':
                    for iterator in product_array:
                        print(iterator.product_name, '   ', iterator.product_unit)
                elif choose == '2':
                    edit = user.edit_account()
                    if edit == False:
                        print("Something gon wrong!")
                elif choose == '3':
                    delete = user.delete_account()
                    if delete == False:
                        print("Accaunt was not deleted")
                elif choose == '4':
                    UserManagement.shopping()
                elif choose == '5':
                    detail = OrderDetail(input("Delivery address: "), input("Delivery city: "), input("Recipient phone: "))
                    paymant_type = Function.for_print("Card - 1 \nCash - any other kay ")
                    if paymant_type == '1':
                        paymant_type = CardPaymant(input("Card type: "), input("Card number: "), input("Card holder: "), 
                        input("Card date: "), input("Card cvi: "))
                        return "Thank you"
                    else:
                        print("Wrong email or password")
                        return "Thank you"


class UserInterface:
    @staticmethod
    def authorization():
        print("Welcome to online shopin system\n")
        while True:
            choose = Function.for_print("Sign in - 1 \nRegistr - 2 \nExit - 0 \n")
            if choose == '1':
                UserManagement.sign_in()
            elif choose == '2':
                UserManagement.reg()
            elif choose == '0':
                print("Thank you")
                break
            else:
                print("Wrong action id \n")
                again = input("If you want try again press 1")
                if again != '1':
                    return "Thank you"


UserInterface.authorization()