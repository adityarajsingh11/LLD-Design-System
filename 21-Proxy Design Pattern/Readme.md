

---

# 🟦 Day 21 – Proxy Design Pattern

---

# 🟩 <u>Introduction</u>

The **Proxy Design Pattern** is a **structural design pattern** used when we want to **control access to an object**.

Instead of allowing a client to communicate directly with a resource, we introduce an **intermediate object called a Proxy**.

The proxy acts as a **representative of the real object**.

✔ It controls access
✔ It may perform validation
✔ It may delay object creation
✔ It may manage remote communication

---

# 🟩 <u>Basic Idea of Proxy</u>

Suppose a **user wants to access a resource**.

### Without Proxy

```
User  -------- request --------> Resource
User  <------- response -------  Resource
```

In this case the **user directly communicates with the resource**.

---

### Problem

Sometimes we **do not want direct communication** because:

* resource contains **critical data**
* access must be **controlled**
* resource creation is **expensive**
* resource exists on **another server**

---

### Solution → Introduce Proxy

```
User  --------> Proxy --------> Resource
User  <-------- Proxy <-------- Resource
```

Process:

1. User sends request to **Proxy**
2. Proxy **validates the request**
3. Proxy forwards request to **Resource**
4. Resource sends response to **Proxy**
5. Proxy returns response to **User**

Proxy works as a **middle layer**.

---

# 🟩 <u>Why Proxy is Introduced</u>

Proxy is introduced for several reasons.

### 1️⃣ Security / Authentication

If resource contains **critical data**, we must ensure only authorized users can access it.

Proxy can perform:

* Authentication
* Authorization
* Validation

Example:

```
User → Proxy → Resource
```

Proxy checks if the user is valid before accessing resource.

---

### 2️⃣ Implement Checks on Data

Proxy can validate:

* data format
* permissions
* request limits

before sending it to the resource.

---

### 3️⃣ Handle Remote Communication

Sometimes the **resource exists on another server over the internet**.

Instead of exposing server details to the client, a **proxy object manages communication**.

Client interacts with proxy like a **local object**.

---

### Important Concept

> Proxy behaves exactly like the real object so that the client cannot differentiate between them.

---

# 🟩 <u>Types of Proxy</u>

There are three main types:

```
1. Virtual Proxy
2. Protection Proxy
3. Remote Proxy
```

The **core concept is same**: proxy acts as representative of resource.

---

# 🟦 <u>Virtual Proxy</u>

Virtual proxy is used to **control creation of expensive objects**.

Example: **Image Display System**

Loading an image may require:

* disk access
* compression
* filters
* decoding

So creating the image object is **expensive**.

---

## Example Class

```
ImageDisplay
-------------
string path

ImageDisplay(path)
display()
```

Constructor tasks:

```
1. load image from disk
2. compression
3. apply filters
```

---

### Problem

Client code:

```
ImageDisplay* img = new ImageDisplay("a.jpg");

img->display();
```

Here **expensive operations happen during object creation**.

But what if:

```
client never calls display()
```

Then we **waste time creating object unnecessarily**.

---

### Solution → Virtual Proxy

Introduce proxy between client and real image.

```
Client → Proxy → ImageDisplay
```

Proxy **delays object creation until needed**.

---

### Workflow

1. Client calls display()
2. Proxy checks if object exists
3. If not → create real object
4. Then call display()

---

### Diagram

```
Client → ImageProxy → ImageDisplay
```


## 🟦 <u>UML Diagram for Image Display Proxy</u>

First create an **interface/superclass**.

```
          <<interface>>
           IDisplay
           display()
```

Two classes implement it.

```
            IDisplay
           /       \
          /         \
 ImageProxy       ImageDisplay
```

---

### Client

```
Client
-------
IDisplay dis

dis->display()
```

Client interacts with interface only.

---

### ImageProxy

```
ImageProxy
------------
ImageDisplay* idis

display()
{
   if(idis == nullptr)
       idis = new ImageDisplay()

   idis->display()
}
```

Proxy creates object **only when needed**.

---

### ImageDisplay

```
ImageDisplay
--------------
string path

ImageDisplay(path)

display()
```

This is the **real object** performing expensive operations.

![alt text](<VirtualUML.png>)

---

# 🟦 <u>Protection Proxy</u>

Protection proxy controls **access rights**.

Example: **DocReader system**

We want only **premium users** to unlock PDFs.

---

### Classes

```
User
------
name
isPremium()
```

```
IDocReader
------------
unlockPdf(file,pwd)
```

```
RealDocReader
---------------
unlockPdf(file,pwd)
```

```
DocReaderProxy
----------------
RealDocReader rd
User user

unlockPdf()
```
![alt text](<ProtectedUML.png>)

---

### Workflow

1. Client calls unlockPdf()
2. Request goes to proxy
3. Proxy checks:

```
if user.isPremium()
    call RealDocReader
else
    throw error
```

---

### Diagram

```
Client
  |
  v
Proxy (DocReaderProxy)
  |
  v
RealDocReader
```

Proxy ensures **unauthorized users cannot access resource**.

---

### Conclusion

Protection Proxy:

✔ authenticates users
✔ protects critical resources

---

# 🟦 <u>Remote Proxy</u>

Remote proxy represents an object **located on another server**.

Example:

A class **DataService** exists on a remote server.

```
DataService
-------------
fetchData()
```

Client wants to call this method.

---

### Problem

Without proxy:

Client must:

1. know server location
2. establish network connection
3. manage communication

This makes client code complex.

---

### Solution → Remote Proxy

Introduce **DataProxy**.

Client communicates with proxy like local object.

Proxy handles network communication.

---

### Diagram

```
Client → DataProxy → DataService (Remote Server)
```

---

### Interface

```
IDataService
--------------
fetchData()
```

---

### Classes

```
DataProxy
-----------
DataService ds

fetchData()
```

```
DataService
------------
fetchData()
```

Proxy communicates with **remote server internally**.

![alt text](<RemoteUML.png>)

---

### Connection Methods

There are two ways:

### 1️⃣ First Loading

Connection created when object is created.

```
ds = new DataProxy()
```

---

### 2️⃣ Lazy Loading

Connection created when method is called.

```
ds->fetchData()
```

Lazy loading is similar to **Virtual Proxy concept**.


---

# 🟦 <u>Standard UML of Proxy Pattern</u>

```
Client
  |
  v
ISubject
operation()
  |
  |----------------|
  |                |
Proxy         RealSubject
operation()     operation()
```

Proxy contains reference to real subject.

```
Proxy
------
RealSubject rs
operation()
```
![alt text](<StandardUML.png>)

---

# 🟦 <u>Standard Definition</u>

> The Proxy Design Pattern provides a **surrogate or placeholder object** for another object to control access to it.

---

# 🟦 <u>Real World Usage</u>

### 1️⃣ Premium Feature Authentication

Example:

* Netflix premium content
* Paid APIs
* Subscription features

Proxy checks authentication before allowing access.

---

### 2️⃣ Framework API Calls

Many frameworks use **Remote Proxy** when calling APIs over internet.

Example:

```
Client → Proxy → Remote API Server
```

Proxy manages network communication.

---

# 🟦 <u>Summary</u>

Proxy pattern introduces an **intermediate object** that controls access to another object.

Main benefits:

✔ Security
✔ Lazy loading
✔ Network abstraction
✔ Resource management

Types:

```
Virtual Proxy → controls expensive object creation
Protection Proxy → controls user access
Remote Proxy → handles remote communication
```

---

