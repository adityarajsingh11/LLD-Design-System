---

# 📘 **LLD – DAY 9**

## 🏭 **Factory Design Pattern**

---

## 🔹 **Introduction**

* Factory Design Pattern is **one of the most used design patterns**
* It is mainly used to **separate object creation logic from business logic**

### 🧠 **Real World Analogy**

> Agar hum ek shop chalate hain,
> toh hum **customer ke saamne saman nahi banate**,
> hum bas **order lete hain** –
> banana ka kaam **factory karti hai**.

📌 Same concept in code:

* Client → **what object it wants**
* Factory → **how object is created**

---

## 🔹 **Why Factory Pattern?**

* Improves **readability**
* Improves **maintainability**
* Removes **tight coupling**
* Follows **OCP (Open–Closed Principle)**

---

## 🔹 **Earlier Learning Connection**

In **Strategy Pattern**, we learned:

* Behavior change at runtime

In **Factory Pattern**, we learn:

* **Object creation** handled by factory

📌 **Key Difference**
*Strategy → behavior choose*
*Factory → object create*

---

# 🔷 **Types of Factory**

```
Factory Types
├── Simple Factory      ❌ (NOT a design pattern)
├── Factory Method      ✅ (Design Pattern)
└── Abstract Factory    ✅ (Design Pattern)
```

---

# 🔶 **1️⃣ Simple Factory (NOT a Design Pattern)**

### 📌 Definition

> A factory class that decides **which concrete class to instantiate**


## 🍔 **Example: Burger Shop**

Shop sells:

* Basic Burger
* Standard Burger
* Premium Burger

👉 Based on type, object is created using `if-else`.

---

## 🖊️ **UML – Simple Factory (Burger Example)**

```
            <<abstract>>
               Burger
               prepare()
                  ▲
        --------------------------
        |           |            |
     BasicB      StandardB     PremiumB
     prepare()   prepare()     prepare()

                uses
            --------------------
            | BurgerFactory     |
            | createBurger(type)|
            --------------------
                  |
           if(type=="basic") → new BasicB()
           if(type=="standard") → new StandardB()
           if(type=="premium") → new PremiumB()

           BurgerFactory------------>Burger

```

---

## 📌 **Standard UML – Simple Factory**

```
Product <--------- Factory
   ▲
ConcreteProduct
```

---

## ❌ Why Simple Factory is NOT recommended?

* Uses `if-else`
* Breaks **OCP**
* Factory must be modified for every new product

---

# 🔶 **2️⃣ Factory Method (Proper Design Pattern)**

### 📌 Definition

> Defines an interface for creating objects
> but allows subclasses to decide
> **which class to instantiate**



## 🧠 **Concept**

* Burger can be created in **different shops**
* Each shop has its **own factory**
* Object creation responsibility moves to subclasses

---

## 🖊️ **UML – Factory Method (Burger Example)**

```

                              <<abstract>>
                                 Burger
                         -------------------------
                         |   prepare()            |
                         -------------------------
                                   ▲
        --------------------------------------------------------------------------------
        |                 |                 |               |          |               |
     BasicB           StandardB          PremiumB     BasicWheatB   StandardWheatB   PremiumWheatB
    prepare()         prepare()          prepare()      prepare()      prepare()       prepare()
                                           



                              <<abstract>>
                           BurgerFactory
                      --------------------------------
                      |  createBurger()              |
                      --------------------------------
                                   ▲
                     ----------------------------------
                     |                                |
               SinghBurger                        KingBurger
           --------------------              --------------------
           | createBurger()   |              | createBurger()   |
           --------------------              --------------------
                     |                                |
                     |  has-a (only concrete factory)|
                     |                                |
                     v                                v
         BasicB / StandardB / PremiumB        Wheat Burgers(BasicWB / StandardWB / PremiumWB)


```
![Factory Method](images\FactoryMethodUML.png)

---

## 📌 **Standard UML – Factory Method**
```

                    <<abstract>>
                       Product
                  -----------------
                  |  operation()  |
                  -----------------
                        ▲
            ---------------------------------
            |                               |
      ConcreteProductA                ConcreteProductB
      -----------------              -----------------
      | operation()   |              | operation()   |
      -----------------              -----------------



                    <<abstract>>
                       Factory
                  -------------------------
                  | createProduct()       |
                  -------------------------
                        ▲
                ---------------------
                |   ConcreteFactory |
                ---------------------
                | createProduct()   |
                ---------------------
                        |
                        |
                        v
              returns ConcreteProductA
              OR
              returns ConcreteProductB
```

![Factory Method Standard UML](images\FactoryMethodStandardUML.png)



## 📌 **Key Points**

✔ No `if-else`
✔ Follows **OCP**
✔ Loose coupling
✔ Creation logic in subclasses

---

# 🔶 **3️⃣ Abstract Factory Method**

### 📌 Definition (from notes)

> Provides an interface for creating **families of related objects**
> without specifying their concrete classes

---

## 🍔 **Example**

Factory creates:

* Burger
* Garlic Bread

👉 Same family products together

---

## 🖊️ **UML – Abstract Factory**

```
                    <<abstract>>
                        Burger
                    ----------------
                    | prepare()    |
                    ----------------
                          ▲
              --------------------------------
              |                              |
          BasicBurger                  BasicWheatBurger
          prepare()                    prepare()



                    <<abstract>>
                    GarlicBread
                --------------------
                | prepare()        |
                --------------------
                          ▲
              --------------------------------
              |                              |
        BasicGarlicBread              BasicWheatGarlicBread
        prepare()                     prepare()


                    <<abstract>>
                       Factory
                ------------------------
                | createBurger()       |
                | createGarlicBread()  |
                ------------------------
                          ▲
              --------------------------------
              |                              |
            SinghFactory                 KingFactory
        -------------------             -------------------
        | createBurger()   |           | createBurger()   |
        | createGarlic()   |           | createGarlic()   |
        -------------------             -------------------

        ✅ IS-A (Inheritance)
        BasicBurger ------------▷ Burger
        BasicWheatBurger -------▷ Burger

        BasicGarlicBread -------▷ GarlicBread
        BasicWheatGarlicBread --▷ GarlicBread

        SinghFactory -----------▷ Factory
        KingFactory ------------▷ Factory

        ✅ HAS-A (Creation responsibility)
        SinghFactory ---> BasicBurger
        SinghFactory ---> BasicGarlicBread

        KingFactory  ---> BasicWheatBurger
        KingFactory  ---> BasicWheatGarlicBread


```
![Abstract Factory](images\AbstractFactoryUML.png)

---

## 📌 **Standard UML – Abstract Factory Method**

```

                <<abstract>>
                ProductA
            -----------------
            | operationA()  |
            -----------------
                    ▲
            -----------------
            | ConcreteA1    |
            | ConcreteA2    |
            -----------------


                <<abstract>>
                ProductB
            -----------------
            | operationB()  |
            -----------------
                    ▲
            -----------------
            | ConcreteB1    |
            | ConcreteB2    |
            -----------------


                <<abstract>>
                  Factory
        --------------------------------
        | getProductA() : ProductA     |
        | getProductB() : ProductB     |
        --------------------------------
                    ▲
            ------------------------------
            |     ConcreteFactory        |
            ------------------------------
            | getProductA()              |
            | getProductB()              |
            ------------------------------
                    |
                    | creates
        -----------------------------------------
        |                                       |
   ConcreteA1 / ConcreteA2            ConcreteB1 / ConcreteB2
```

![Abstract Factory Method Standard UML](images\AbstractFactoryStandardUML.png)

---

## 📌 **Why Abstract Factory?**

* Multiple related objects
* Consistent product families
* No tight coupling

---

# 🔷 **Real-Life Example (VERY IMPORTANT)**

## 📩 **Notification System**

### 📌 Problem

We want to send notifications using:

* SMS
* Email
* Push

---

## 🖊️ **UML – Without Factory (Problem)**

```
NotificationSystem
      ▲     ▲     ▲
   SMS    Email   Push
```

❌ Client tightly coupled
❌ Hard to add new notification

---

## 🖊️ **UML – Using Factory**

```
              <<abstract>>
             Notification
                 send()
                    ▲
        --------------------------------
        |              |               |
     SMSNot        EmailNot        PushNot
     send()        send()          send()

                uses
            -------------------
            | NotificationFactory |
            | createNotification()|
            -------------------
```

---

## 🧠 **Factory vs Strategy (from notes)**

| Factory                 | Strategy           |
| ----------------------- | ------------------ |
| Object creation         | Behavior selection |
| Compile-time            | Runtime            |
| Creation logic separate | Algorithm vary     |

---

## 📌 **Golden Line (Exam / Interview)**

> Factory is used when object creation logic needs to be separated
> Strategy is used when behavior needs to be changed at runtime

---

# 📝 **DAY 9 – SUMMARY**

✔ Factory Pattern = **Creational Pattern**
✔ Separates **object creation from usage**
✔ Simple Factory → ❌
✔ Factory Method → ✅
✔ Abstract Factory → ✅
✔ Improves **OCP, Maintainability, Readability**

---

## 🎯 **One-Line Interview Answers**

* **Simple Factory** → Not a design pattern
* **Factory Method** → Subclass decides object creation
* **Abstract Factory** → Creates family of related objects
* **Real life example** → Notification system, Burger shop

---


