

---

# 🟦 <u>1. Overall System Samajh</u>

👉 Ye ek **Tinder-like Dating App System** hai jisme:

* User profile banata hai
* Nearby users dekhta hai
* Swipe karta hai
* Match hota hai
* Chat + Notification hota hai

---

# 🟩 <u>2. High Level Flow</u>

```text
User Create
   ↓
Set Profile + Preferences
   ↓
Find Nearby Users (Strategy)
   ↓
Swipe (LEFT / RIGHT)
   ↓
Matcher calculate score
   ↓
Match found
   ↓
ChatRoom create
   ↓
Message + Notification
```

---

# 🟨 <u>3. Design Patterns Used</u>

| Pattern   | Use                                             |
| --------- | ----------------------------------------------- |
| Singleton | NotificationService, LocationService, DatingApp |
| Observer  | Notifications                                   |
| Strategy  | Location finding                                |
| Factory   | Matcher creation                                |
| (Hybrid)  | Matching logic                                  |

---

# 🟥 <u>4. Notification System (Observer Pattern)</u>

---

## 📌 Code Logic

```cpp
class NotificationObserver {
    virtual void update(string msg) = 0;
};
```

```cpp
class NotificationService {
    map<userId, observer>
}
```

---

## 🧠 Flow

```text
User → Register Observer
       ↓
NotificationService
       ↓
notify(userId, msg)
       ↓
UserNotificationObserver → print message
```

---

## ✔ Simple Samajh

👉 Jab match ya message aata hai:

```
NotificationService → user ko notify karta hai
```

---

# 🟦 <u>5. User + Profile System</u>

---

## 📌 User Class

```cpp
class User {
   id
   profile
   preference
   swipeHistory
}
```

---

## 📌 Key Functions

```cpp
swipe(userId, action)
hasLiked(userId)
hasDisliked(userId)
```

---

## 🧠 Logic

👉 Swipe history store hota hai:

```text
map<userId, LEFT/RIGHT>
```

---

## 📌 Profile

```cpp
UserProfile {
  name, age, gender
  bio, photos
  interests
  location
}
```

---

## 📌 Preference

```cpp
Preference {
  genderPreference
  age range
  distance
  interests
}
```

---

# 🟩 <u>6. Location System (Strategy Pattern)</u>

---

## 📌 Code

```cpp
class LocationStrategy {
   findNearbyUsers()
}
```

```cpp
class BasicLocationStrategy
```

```cpp
class LocationService (Singleton)
```

---

## 🧠 Flow

```text
User → LocationService
         ↓
    Strategy call
         ↓
 Nearby users return
```

---

## ✔ Meaning

👉 Different algorithms use kar sakte ho:

* Distance based
* City based
* Premium users

---

# 🟥 <u>7. Matching System (CORE PART)</u>

---

## 📌 Matcher Interface

```cpp
class Matcher {
   calculateMatchScore(u1, u2)
}
```

---

## 🔹 1. BasicMatcher

✔ Checks:

* Gender preference
* Age range
* Distance

👉 Return:

```
0.5 (50% score)
```

---

## 🔹 2. InterestsBasedMatcher

✔ Adds:

* Common interests

👉 Logic:

```text
sharedInterests / maxInterests
```

---

## 🔹 3. LocationBasedMatcher

✔ Adds:

* Distance score

👉 Closer → higher score

---

## 🧠 Final Score

```text
Basic + Interest + Location
```

---

## 📌 Factory

```cpp
MatcherFactory::createMatcher(type)
```

👉 Creates matcher dynamically

---

# 🟨 <u>8. Swipe + Match Logic</u>

---

## 📌 Code

```cpp
bool swipe(userId, targetId, action)
```

---

## 🧠 Flow

```text
User1 RIGHT swipe User2
User2 RIGHT swipe User1
        ↓
MATCH
        ↓
ChatRoom create
        ↓
Notification send
```

---

## ✔ Important Line

```cpp
if (action == RIGHT && targetUser->hasLiked(userId))
```

👉 Ye check karta hai:

👉 "Dono ne ek dusre ko like kiya hai?"

---

# 🟩 <u>9. Chat System</u>

---

## 📌 ChatRoom

```cpp
ChatRoom {
   participants
   messages
}
```

---

## 📌 Message

```cpp
Message {
   senderId
   content
   timestamp
}
```

---

## 🧠 Flow

```text
Match → ChatRoom
        ↓
sendMessage()
        ↓
Message store
        ↓
Receiver notified
```

---

# 🟥 <u>10. DatingApp (Facade Pattern)</u>

---

## 📌 Main Class

```cpp
class DatingApp {
   users
   chatRooms
   matcher
}
```

---

## 📌 Important Methods

```cpp
createUser()
findNearbyUsers()
swipe()
sendMessage()
displayChatRoom()
```

---

## 🧠 Role

👉 Ye pura system control karta hai

👉 Client sirf isi class se interact karta hai

---

# 🟦 <u>11. Complete Flow (Real Execution)</u>

---

## Step-by-Step

### 1. App start

```cpp
DatingApp::getInstance()
```

---

### 2. Users create

```cpp
user1, user2
```

---

### 3. Profile + Preferences set

✔ Name
✔ Age
✔ Interests
✔ Distance

---

### 4. Location set

```cpp
profile->setLocation()
```

---

### 5. Nearby users

```cpp
findNearbyUsers()
```

👉 LocationService + Strategy

---

### 6. Swipe

```cpp
user1 RIGHT user2
user2 RIGHT user1
```

👉 Match created

---

### 7. Notification

```text
"You have a match"
```

---

### 8. Chat

```cpp
sendMessage()
```

---

### 9. Output

```text
ChatRoom display
```

---

# 🟨 <u>12. Key Concepts (Interview Ready)</u>

---

## ✔ Why Observer?

👉 Notification system ke liye

---

## ✔ Why Strategy?

👉 Different matching / location logic

---

## ✔ Why Factory?

👉 Matcher dynamically create

---

## ✔ Why Singleton?

👉 Shared services (Notification, App)

---

