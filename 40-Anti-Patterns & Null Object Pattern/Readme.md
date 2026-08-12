
---

# 🟦 Day 40 – Wrapping Up System Design

---

## Anti-Patterns + Null Object Pattern

> **Day 40 mainly covers two things:**
>
> 1. Common **Anti-Patterns** that make software design worse
> 2. **Null Object Design Pattern** as a solution to repeated null checks

---

# 🟩 PART 1 — Anti-Patterns

## What is an Anti-Pattern?

An **Anti-Pattern** is a common way of designing/writing code that may look convenient initially but can create **problems later**.

Simple:

```text
Quick / Bad Design
       ↓
Looks easy initially
       ↓
Future requirements increase
       ↓
Problems appear
       ↓
Maintenance becomes difficult
```

## Definition

> **Anti-Pattern = A bad/repeated design practice that creates problems in the future.**

It is basically the opposite idea of a Design Pattern.

```text
Design Pattern → Good reusable solution

Anti-Pattern   → Common bad practice
```

---

## 🟩 1.God Object

### What is a God Object?

A **God Object** is a class/object that has **too many responsibilities** and handles a major portion of the application's functionality.

> Aise objects jisme bahut saare methods ho aur application ka major chunk God Object handle kar raha ho ya uske through handle ho raha ho.

Example:

```text
                 ┌───────────────────┐
                 │    God Object     │
                 ├───────────────────┤
                 │ User Management   │
                 │ Payment           │
                 │ Order             │
                 │ Database          │
                 │ Notification      │
                 │ Authentication    │
                 │ Logging           │
                 └───────────────────┘
                         │
              Handles almost everything
```

### ❌ Problem

One class becomes responsible for too many things.

This generally creates:

* High coupling
* Difficult maintenance
* Difficult testing
* Large class
* Many reasons to change

### Is an Orchestrator Class a God Object?

Your notes specifically raise this doubt:

> **"Is our orchestrator class God Object?"**

The answer depends on **what the orchestrator actually does**.

There are two scenarios.


#### 1.Delegating

Suppose:

```text
Orchestrator
     │
     ├── UserManager
     ├── PaymentManager
     ├── OrderManager
     └── NotificationManager
```

Orchestrator simply delegates:

```text
Orchestrator
      │
      ├── userManager.doTask()
      ├── paymentManager.doTask()
      └── orderManager.doTask()
```

If the orchestrator is **just delegating tasks to other classes**, then it is **not a God Object**.

### Why?

Because actual work is being performed by specialized classes.

```text
Orchestrator
     ↓ delegates
Specialized Classes
     ↓
Actual Work
```

#### 2.Delegating With a Twist

This is the important case from your notes.

Suppose the object delegates the task, **but before delegating, it also performs significant work itself**.

```text
Orchestrator
     │
     ├── Does some work
     │
     ↓
Delegates task
     │
     ↓
Other Class
```

Then it starts becoming a **God Object**.

### Example

```cpp
void placeOrder() {

    // lots of business logic here
    validateUser();
    calculatePrice();
    applyDiscount();
    checkInventory();

    // finally delegate
    orderManager.placeOrder();
}
```

The orchestrator is no longer just coordinating.

It is also doing business logic.



## Solution to God Object

Your notes give two options.

### Solution 1 — Create Multiple Objects

Instead of:

```text
              Client
                │
                ▼
          Huge God Object
                │
       ┌────────┼────────┐
       ↓        ↓        ↓
     User     Payment   Order
```

Create separate classes:

```text
                  Client
                    │
        ┌───────────┼───────────┐
        ↓           ↓           ↓
   UserManager PaymentManager OrderManager
```

Now the client may need to know about these classes.

### Solution 2 — Orchestrator with Delegation

Keep an orchestrator as a **single entry point**, but make sure it only coordinates/delegates.

```text
Client
  │
  ▼
Orchestrator
  │
  ├────────► UserManager
  │
  ├────────► PaymentManager
  │
  └────────► OrderManager
```

## Key Point

> **Orchestrator should coordinate, not contain all the business logic.**

Your notes also connect this with the idea of a **single entry point**, making it easier for the client.

Example mentioned:

```text
API
 ↓
Controller
 ↓
What sort of layer...
```

The idea is that the client interacts through a controlled entry point instead of knowing every internal class.

---

## 🟩 2.Spaghetti Code

## What is Spaghetti Code?

Spaghetti code means code that is **too complicated, tangled, and difficult to follow**.

> Making objects so complex that there is no clear entry point and no clear exit point.

And:

> Objects become too tightly coupled and there are no clear paths.

### Diagram

```text
A ───────► B
│ ╲       │
│  ╲      ↓
↓   ╲    C
D ◄─── E ─┘
│
└────► F
  ╲      ↑
   └─────┘
```

Everything is connected with everything.


## Problems with Spaghetti Code

### 1️⃣ Highly tightly coupled

```text
Class A → B → C → D
       ↘ E ↗
```

Changing one class may affect many others.

### 2️⃣ Prone to errors

Because the flow is difficult to understand:

```text
No clear flow
     ↓
Hard to debug
     ↓
More chances of mistakes
```

---

## 🟩 3.Hard-Coding Things

Your notes give this example:

```cpp
void m1() {
    string s = "Hello";
}
```

Here `"Hello"` is directly written inside the code.

If tomorrow the value changes:

```text
"Hello"
   ↓
"Hi"
```

we need to modify the source code.

### Problem

```text
Hard-coded value
      ↓
Requirement changes
      ↓
Source code modification
```


### How to Avoid Hard-Coding?

Your notes suggest using a **constructor**.

Instead of:

```cpp
void m1() {
    string s = "Hello";
}
```

we can provide the value from outside:

```cpp
class Message {
    string message;

public:
    Message(string message) {
        this->message = message;
    }
};
```

Now:

```cpp
Message m("Hello");
```

or:

```cpp
Message m("Hi");
```

No need to change internal logic.

### Idea

> **Values that may change should not unnecessarily be hard-coded inside business logic.**

---

## 🟩 4.Gold-Plating / Over-Engineering

### Meaning

Gold-plating means trying to make the design **more complicated/perfect than actually required**.

Your notes mention:

* Trying to always achieve perfection in design
* Handling cases that will never arise
* Applying patterns unnecessarily
* Over-complicated code

## Example

Requirement:

```text
Simple calculator
+
-
*
/
```

But developer creates:

```text
Calculator
 ├── AbstractCalculator
 ├── CalculatorFactory
 ├── CalculatorStrategy
 ├── CalculatorBuilder
 ├── CalculatorVisitor
 ├── CalculatorObserver
 └── CalculatorFacade
```

😂 This is unnecessary for a simple problem.

### Rule

> **Don't use a Design Pattern just because you know it. Use it when the problem requires it.**

---

## 🟩 5.DRY — Don't Repeat Yourself

DRY means:

> **Don't Repeat Yourself.**

Your notes mention:

* Copy-pasting some code
* Too much repetition
* If change is needed, change has to be made everywhere the code is used

### Bad Example

```cpp
void calculateA() {
    cout << "Tax calculation";
    // same logic
}

void calculateB() {
    cout << "Tax calculation";
    // same logic
}

void calculateC() {
    cout << "Tax calculation";
    // same logic
}
```

Same logic is repeated.

If logic changes:

```text
Change A
Change B
Change C
...
```


### How to Avoid DRY Violation?

Your notes give two solutions:

### 1️⃣ Extract repeated code

Put repeated logic into a:

```text
Method
   OR
Class
   OR
Separate Logic
```

Example:

```cpp
void calculateTax() {
    // common logic
}
```

Then:

```cpp
calculateTax();
```

can be reused.

### 2️⃣ Use Utility Class

Common reusable functionality can be placed in a utility class.

```text
Utility
 ├── calculateTax()
 ├── validate()
 └── format()
```

---

## 🟩 6.Constructor Overloading / Telescoping Constructor

> Creating too many constructors.

Example:

```cpp
User();
User(string name);
User(string name, int age);
User(string name, int age, string city);
User(string name, int age, string city, string email);
```

As parameters increase, constructors increase.

This is called **Telescoping Constructor Problem**.

### Problem

```text
Too many constructors
        ↓
Hard to understand
        ↓
Hard to maintain
```

### Solution

Your notes give:

> **Builder Design Pattern**

Builder allows us to construct complex objects step-by-step.

```text
UserBuilder
   │
   ├── setName()
   ├── setAge()
   ├── setCity()
   └── build()
```

---

## 🟩 7.Overuse of Getters / Setters

Your notes mention that providing getters/setters for **all private members by default** can be problematic.

### ❌ Common mistake

```cpp
class User {
private:
    string name;
    int age;
    double salary;

public:
    getName();
    setName();

    getAge();
    setAge();

    getSalary();
    setSalary();
};
```

Just because a variable is private doesn't mean we must expose it through getters/setters.


### Why is this bad?

It can weaken **encapsulation**.

The main purpose of private members is:

```text
Hide internal state
       ↓
Control access
       ↓
Maintain valid state
```

If we provide unrestricted setters:

```cpp
user.setAge(-100);
```

we may allow invalid data.

---

## Better Approach

Use getters/setters **only when needed**, with validation/control.

```cpp
void setAge(int age) {
    if(age >= 0) {
        this->age = age;
    }
}
```

### Remember

> **Not every private variable needs a getter/setter.**

---

## 🟩 8.Premature Optimization

Premature optimization means:

> **Optimizing the code too early, before knowing where the actual performance problem is.**

Your notes give the principle:

> **"Make it work, then make it fast."**

### Correct approach

```text
First:
Make it work
     ↓
Test correctness
     ↓
Measure performance
     ↓
Find bottleneck
     ↓
Optimize
```


### Example

Suppose a brute-force solution works correctly:

```text
Brute Force
     ↓
Correct Answer
```

First ensure correctness.

Then:

```text
Measure
   ↓
Find slow part
   ↓
Optimize
```

Your notes specifically mention:

> **Brute Force Solution First, then optimize for performance.**


## 🟩 9.Overuse of Inheritance

Your notes mention that excessive inheritance:

* Leads to complex hierarchies
* Causes tight coupling

Example:

```text
        Animal
          │
        Mammal
          │
        Dog
          │
      SpecialDog
          │
     SuperSpecialDog
```

This can become difficult to understand and maintain.

### Alternatives

Your notes list:

```text
Overuse of Inheritance
          │
          ├── Composition
          ├── Strategy Pattern
          ├── Visitor Pattern
          ├── Bridge Pattern
          └── Inheritance only for appropriate abstract relationships
```

### Important

Inheritance should represent a genuine **is-a relationship**.

Composition often gives more flexibility:

```text
Car
 ├── Engine
 ├── Transmission
 └── GPS
```

instead of creating a huge inheritance hierarchy.

---

# 🟩 Benefits of Avoiding Anti-Patterns

Your notes list four benefits:

### 1️⃣ Better Code Quality

Code becomes:

```text
Cleaner
Readable
Maintainable
```

### 2️⃣ Loosely Coupled Code

Classes become less dependent on each other.

```text
A → B
```

instead of:

```text
A ↔ B ↔ C ↔ D ↔ E
```

### 3️⃣ Improved Design Pattern Application

We use patterns where they actually solve a problem instead of unnecessarily applying them.

### 4️⃣ Easier New Feature Integration

Clean architecture makes adding new functionality easier.

```text
Existing System
      ↓
New Feature
      ↓
Minimal Changes
```

---

# 🟦 PART 2 — Null Object Pattern

## 🟩 What is Null Object Pattern?

Null Object is a design pattern used to **avoid repeated null checks**.

Normally we write:

```cpp
if(obj != nullptr) {
    obj->method();
}
```

If this appears everywhere:

```text
if(obj != null)
if(obj != null)
if(obj != null)
if(obj != null)
...
```

code becomes cluttered.

### Null Object solution:

Instead of giving `null`, give a **special object that does nothing**.

```text
Real Object
    OR
Null Object
```

Both implement the same interface.



## 🟩 Purpose of Null Object Pattern

Your notes list three purposes:

### 1️⃣ Avoid Null Checks

Instead of:

```cpp
if(obj == null)
```

we provide a Null Object.

### 2️⃣ Prevent NullPointerException

Instead of:

```text
null → method call → runtime error ❌
```

we have:

```text
Null Object → method call → safe behavior ✅
```

### 3️⃣ Replace Conditionals with Polymorphism

Instead of:

```cpp
if(obj != null)
    obj->m();
else
    // do nothing
```

we can simply:

```cpp
obj->m();
```

The actual object decides what happens.

---

## 🟩 Null Object Concept

Suppose we have:

```text
              <<abstract>>
             AbstractClass
             ─────────────
                  m()
                   ▲
          ┌────────┴────────┐
          │                 │
   ConcreteClass        NullObject
       m()                 m()
     actual work       does nothing
```

Now client doesn't need to know whether it received a real object or a Null Object.


## 🟩 Client Flow

Your diagram shows:

```text
                 AbstractClass
                     ▲
             ┌───────┴────────┐
             │                │
      ConcreteClass       NullObject
             │                │
          m() actual        m() empty
             │                │
             └───────┬────────┘
                     │
                   Client
```

Client simply works with:

```cpp
AbstractClass* obj;
```

It doesn't care whether:

```text
obj = ConcreteClass
```

or:

```text
obj = NullObject
```

---

## 🟩 How Null Object Works

Suppose normal code is:

```cpp
void func(AbstractClass* obj) {

    if(obj != nullptr) {
        obj->m();
    }
}
```

With Null Object:

```cpp
void func(AbstractClass* obj) {
    obj->m();
}
```

If we don't have a real object:

```text
obj → NullObject
```

Then:

```cpp
obj->m();
```

calls:

```cpp
NullObject::m()
```

which does nothing or returns a default value.

---

## 🟩 Creating a Null Object

Your notes give these steps:

### Step 1

Create a **Null Object class**.

### Step 2

Make it inherit/implement the same abstract class/interface.

### Step 3

Implement methods such that they:

```text
Do nothing
       OR
Return default values
```

Examples:

```text
int → 0

string → ""

bool → false
```

### Step 4

Client always receives an object reference:

```text
Concrete Object
       OR
Null Object
```

Therefore client doesn't need repeated null checking.

---

## 🟩 Why Null Object?

This is an important distinction from your page 6.

## Null Reference

A null reference:

```text
obj → nothing
```

It points to nothing in the heap.

If we do:

```cpp
obj->method();
```

we can get a runtime error such as a **NullPointerException** in languages where such an exception exists.


## Null Object

A Null Object is an **actual object**:

```text
obj
 ↓
NullObject
```

It exists in memory but represents:

> "There is no meaningful real object to perform this operation."

Its methods safely do nothing or return default values.

### Easy Difference

```text
NULL
 ↓
Nothing ❌

NULL OBJECT
 ↓
Actual empty/do-nothing object ✅
```

---

## 🟩 Null Object and Liskov Substitution Principle

Your notes mention:

> **Avoids Liskov Substitution Principle break**

The idea is that the Null Object follows the same interface/contract as the normal object.

For example:

```text
ICommand
   ▲
   ├── LightOnCommand
   └── NoCommand
```

Both can be used where an `ICommand` is expected.

The `NoCommand` simply performs no action.

So client doesn't need a special case.

---

## 🟩 Example 1 — Strategy Pattern

Your notes connect Null Object with the **Strategy Design Pattern**, using the Robot example.

Earlier we had:

```text
Robot
  │
  └── IFlyStrategy
```

Some robots can fly:

```text
Robot
  ↓
FlyStrategy
  ↓
fly()
```

But some robots cannot fly.

Instead of:

```cpp
if(robotCanFly) {
    flyStrategy->fly();
}
```

we create:

```text
NoFlyBehaviour
```

### NoFlyBehaviour

```cpp
class NoFlyBehaviour : public IFlyBehaviour {
public:
    void fly() {
        // do nothing
    }
};
```

So:

```text
Flying Robot
      ↓
FlyBehaviour

Non-Flying Robot
      ↓
NoFlyBehaviour
```

Client can always call:

```cpp
flyBehaviour->fly();
```

No null check is required.

## 🟩 Strategy + Null Object Diagram

```text
                    IFlyBehaviour
                         ▲
              ┌──────────┴──────────┐
              │                     │
         FlyBehaviour          NoFlyBehaviour
              │                     │
            fly()                  fly()
          actual work            do nothing
              ▲                     ▲
              │                     │
        Flying Robot         Non-Flying Robot
```

### Flow

```text
Robot
  │
  └── has IFlyBehaviour
          │
     ┌────┴────┐
     ↓         ↓
 Fly         NoFly
```

This avoids:

```cpp
if(flyBehaviour != nullptr)
```

---

## 🟩 Example 2 — Command Design Pattern

Your notes also connect Null Object with the **Command Design Pattern**, using the Remote Control example.

Suppose remote control has a button.

Normally:

```text
Button
  ↓
Command
  ↓
execute()
```

But what if no command is assigned?

Without Null Object:

```cpp
if(command != nullptr) {
    command->execute();
}
```


## Null Object Solution

Create:

```text
NoCommand
```

which implements the same Command interface.

```text
              ICommand
                 ▲
        ┌────────┴────────┐
        │                 │
   LightCommand       NoCommand
        │                 │
     execute()          execute()
     actual work       do nothing
```

Initialize the button with:

```text
Button → NoCommand
```

Now whenever the button is pressed:

```text
button.press()
      ↓
command.execute()
      ↓
NoCommand.execute()
      ↓
Nothing happens safely
```

No null check is required.

---

## 🟩 Complete Null Object Flow

```text
                         Client
                           │
                           ▼
                    Abstract Interface
                           │
                    ┌──────┴──────┐
                    │             │
                    ▼             ▼
              Real Object     Null Object
                    │             │
                    ▼             ▼
               Actual Work     Do Nothing
                    │             │
                    └──────┬──────┘
                           ▼
                     Same Interface
```

### Main benefit:

```text
Before:

if(obj != null)
    obj->method();

After:

obj->method();
```

Because `obj` is **always an object**.
