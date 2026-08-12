

---

# 📘 **LLD – Day 1**

## **Topic Covered**

1. Introduction to LLD
2. Difference between LLD and HLD
3. Relation between DSA and LLD
 

---

## 🔹 **1. Introduction to Low-Level Design (LLD)**

### ✅ **Definition**

**Low-Level Design (LLD)** is the process of designing the **internal structure (skeleton)** of an application by:

* Identifying **classes / objects**
* Defining **relationships** between them
* Deciding **data flow**
* Embedding appropriate **DSA and algorithms** inside the design

📌 **In simple words:**

> LLD describes **how the code will be structured before writing actual code**

---

### 🔍 **What LLD Focuses On**

* Classes & interfaces
* Methods & responsibilities
* Object interactions
* Reusability & extensibility
* Maintainability & scalability

---

### 🧠 **LLD vs DSA (Basic Understanding)**

| DSA                      | LLD                          |
| ------------------------ | ---------------------------- |
| Solves isolated problems | Designs complete system      |
| Focus on algorithms      | Focus on object structure    |
| Example: Dijkstra        | Example: Ride-Booking System |

📌 **Key idea:**

> LLD decides **where** DSA fits, DSA decides **how efficiently** it works

---

## 🔹 **2. Difference Between LLD and HLD**

### 🧩 **What is HLD?**

**High-Level Design (HLD)** focuses on **system architecture**, not code structure.

HLD includes:

* Tech stack (Java, Spring Boot, etc.)
* Database choice (SQL / NoSQL)
* Server architecture
* Load balancers
* Cloud deployment (AWS / GCP)
* Cost optimization

---

### 📊 **LLD vs HLD Comparison Table**

| Feature      | **HLD**            | **LLD**                  |
| ------------ | ------------------ | ------------------------ |
| Level        | High level         | Low level                |
| Focus        | Architecture       | Code structure           |
| Talks about  | Modules & services | Classes & methods        |
| Output       | System diagram     | Class & sequence diagram |
| Coding ready | ❌ No               | ✅ Almost                 |
| Used by      | Architects         | Developers               |

📌 **One-line exam answer:**

> **HLD defines what the system does, LLD defines how the system does it**

---

## 🔹 **3. Relation Between DSA and LLD**

### 🧠 **Conceptual Relation**

* **DSA = Brain of the application**
* **LLD = Skeleton of the application**

📌 **Without LLD:**
DSA solutions remain isolated and unscalable.

📌 **Without DSA:**
LLD structure becomes slow and inefficient.

---

### 🧩 **Illustrative Story – “QuickRide” App**

#### ❌ **DSA-First Approach (Incomplete)**

* City mapped as graph
* Dijkstra for shortest path
* Min-heap for nearest driver

**Problems:**

* No classes like User, Rider, Payment
* No security handling
* No scalability consideration

---

#### ✅ **LLD-First Approach (Correct)**

* Identify entities:

  * User
  * Rider
  * Location
  * NotificationService
  * PaymentGateway
* Define interactions
* Address:

  * Security
  * Scalability
  * Integration
* Then apply DSA:

  * Shortest path
  * Driver matching

📌 **Conclusion:**

> DSA works best **inside a well-designed LLD**

---

### 🔗 **Examples: DSA Inside LLD**

| System       | LLD Classes   | DSA Used      |
| ------------ | ------------- | ------------- |
| Parking Lot  | Vehicle, Slot | HashMap, List |
| Ride Booking | Rider, Driver | Graph, Heap   |
| Notification | Service       | Queue         |
| Cache        | CacheManager  | HashMap       |

---

## 🔹 **4. Core Focus Areas of LLD**

### ✔ **Scalability**

* Handle millions of users
* Easy feature expansion

### ✔ **Maintainability**

* Easy debugging
* Minimal code breakage

### ✔ **Reusability**

* Generic components usable in multiple systems

---

## 🔹 **5. Summary & Takeaways**

* **DSA** solves algorithmic problems
* **LLD** organizes code structure
* **HLD** designs system architecture

📌 **Golden Line (Very Important):**

> **“If DSA is the brain, LLD is the skeleton of an application.”**

---

## 📝 **Day 1 Quick Revision (For Exam / Interview)**

✔ LLD = class-level design
✔ HLD = architecture-level design
✔ DSA = efficiency
✔ LLD = structure
✔ All three are interconnected

---


