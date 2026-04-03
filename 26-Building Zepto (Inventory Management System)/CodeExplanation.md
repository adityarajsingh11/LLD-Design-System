

---

# 🟦 <u>1. High Level Overview</u>

📄 Code Reference: 

👉 Ye system simulate karta hai:

* Product system
* Inventory management
* Dark stores (warehouse)
* Order placement
* Delivery allocation

👉 Real-world: **Zepto / Blinkit / Swiggy Instamart**

---

# 🟨 <u>2. Major Components</u>

### ✔ 1. Product System

* `Product`
* `ProductFactory`

👉 Responsibility:

* Product banana (Factory Pattern)

---

### ✔ 2. Inventory System

* `InventoryStore (Abstract)`
* `DbInventoryStore (Concrete)`
* `InventoryManager`

👉 Responsibility:

* Stock manage karna

---

### ✔ 3. Dark Store System

* `DarkStore`
* `DarkStoreManager (Singleton)`

👉 Responsibility:

* Nearest store find karna

---

### ✔ 4. User System

* `User`
* `Cart`

👉 Responsibility:

* User order create karega

---

### ✔ 5. Order System

* `Order`
* `OrderManager (Singleton)`

👉 Responsibility:

* Order place karna + split karna

---

### ✔ 6. Strategy Pattern

* `ReplenishStrategy`
* `ThresholdReplenishStrategy`

👉 Responsibility:

* Stock refill logic

---

# 🟩 <u>3. Complete Flow of Code</u>

---

## 🟣 Step 1: Initialization

```cpp
ZeptoHelper::initialize();
```

👉 Internally:

```
Create 3 DarkStores:
  DarkStoreA (0,0)
  DarkStoreB (4,1)
  DarkStoreC (2,3)

Add stock:
  A → Apple(5), Banana(2)
  B → Apple(3), Chocolate(10)
  C → Banana(5), T-shirt(7)

Register in DarkStoreManager
```

---

## 🟣 Step 2: User Entry

```cpp
User* user = new User("Aditya", 1.0, 1.0);
```

👉 User location important hai (nearest store find karne ke liye)

---

## 🟣 Step 3: Show Products

```cpp
ZeptoHelper::showAllItems(user);
```

👉 Flow:

```
User → DarkStoreManager
     → getNearbyStores (within 5km)
     → collect all products
     → remove duplicates
     → display
```

---

## 🟣 Step 4: Add to Cart

```cpp
cart->addItem(101, 4);
cart->addItem(102, 3);
cart->addItem(103, 2);
```

👉 Cart structure:

```
Cart
 ├── (Apple, 4)
 ├── (Banana, 3)
 └── (Chocolate, 2)
```

---

## 🟣 Step 5: Place Order (MAIN LOGIC)

```cpp
OrderManager::placeOrder(user, cart);
```

---

# 🟥 <u>4. Order Flow (VERY IMPORTANT)</u>

---

## ✅ Step 5.1: Find Nearby Stores

```
DarkStoreManager → getNearbyStores(user location)
```

👉 Sorted by distance

---

## ✅ Step 5.2: Check First Store

```
Check if ALL items available in closest store
```

👉 Condition:

```
if(stock >= required for all items)
```

---

### ✔ Case 1: Single Store Fulfillment

```
All items available → use 1 store
```

👉 Flow:

```
Remove stock
Create order
Assign 1 delivery partner
```

---

### ❌ Case 2: Split Order (IMPORTANT)

```
Not all items available → split across stores
```

👉 Flow:

```
Map: SKU → qty

Loop all stores:
   For each store:
      take available qty
      reduce required qty

Assign delivery partner per store
```

---

### Example:

```
Apple needed = 4
A has 5 → take 4

Banana needed = 3
A has 2 → take 2
C has 5 → take 1

Chocolate needed = 2
B has 10 → take 2
```

---

### Result:

```
Multiple stores used
Multiple delivery partners assigned
```

---

## 🟣 Step 5.3: Order Summary

```
Print:
- Order ID
- Items
- Total price
- Delivery partners
```

---

# 🟦 <u>5. Design Patterns Used</u>

---

## ✔ 1. Factory Pattern

```
ProductFactory → creates Product
```

👉 Loose coupling

---

## ✔ 2. Strategy Pattern

```
ReplenishStrategy
   ├── ThresholdReplenish
   └── WeeklyReplenish
```

👉 Dynamic behavior change

---

## ✔ 3. Singleton Pattern

```
DarkStoreManager
OrderManager
```

👉 Single instance

---

## ✔ 4. Abstraction

```
InventoryStore (interface)
```

👉 Future DB change possible

---

# 🟨 <u>6. UML Text Diagram</u>

```
User
 └── Cart
      └── (Product, qty)

ProductFactory → Product

InventoryManager → InventoryStore (Abstract)
                     └── DbInventoryStore

DarkStore
 └── InventoryManager
 └── ReplenishStrategy

DarkStoreManager (Singleton)
 └── list of DarkStores

OrderManager (Singleton)
 └── creates Order
 └── assigns DeliveryPartner

Order
 └── User
 └── Items
 └── DeliveryPartners
```

---

# 🟩 <u>7. Hinglish Summary (Best for Exam)</u>

👉 Ye system basically:

* User cart me items add karta hai
* System nearest dark store find karta hai
* Check karta hai ek store se ho sakta hai ya split karna padega
* Agar ek store se ho gaya → 1 delivery partner
* Agar split hua → multiple delivery partners
* Finally order create hota hai

---

# 🟥 <u>8. Key Learning</u>

✔ Real-world LLD system

✔ Multiple design patterns

✔ Scalability (easy to add stores/products)

✔ Loose coupling

