# University access system (v3.0)

## Description

The program implements university access system, in fact, it is easily adjustable for your own needs.

By default program supports:

1. 6 classes representing types of users
2. 5 classes representing types of rooms
3. 5 types of access levels
4. Creating temporary guest account
5. Emergency mode

Any of the abovementioned is easily expandable.

## Installation

You will need to build the program from source code.

In order to run the program you need to provide two databases:

1. User database (you can replace the default one named `database.txt` consisting of 60 users)
2. Room database (you can replace the default one named `room-database.txt` consisting of 47 rooms)

Make sure to follow the name convention and the structure:

1. For `database.txt`:

    ```cpp
    {
       {
          name,
          occupation,
          subject,
          age,
          subjectYears
       },
       {
          name,
          occupation,
          subject,
          age,
          subjectYears
       },
    	 //...
    }
    ```

2. For `room-database.txt`:

    ```cpp
    {
       name,
       name,
    	 //...
    }
    ```

## How to run

You should double check the correctness of your databases, then initialize them:

```cpp
Users::initialize();
Rooms::initialize();
```

Now the Access System is ready to use.

## Methods

Primary methods that you will use have the following signatures:

```cpp
class User {
	public:
		void goToRoom(Room* room);
		virtual void allowUser(User* user, Room* room);
		virtual void forbidUser(User* user, Room* room);
}
```

### goToRoom(room)

Calls `checkAccess(user, room)` of `AccessSystem` passing current user as a `user`

### allowUser(user, room)

Checks if the `user` is an admin and if it is, calls `grantCustomAccess(user, room)` of `AccessSystem`

### forbidUser(user, room)

Checks if the `user` is an admin and if it is, calls `withdrawAccess(user, room)` of `AccessSystem`

Abovementioned methods internally use methods of the `AccessSystem` class:

```cpp
class AccessSystem {
	bool logEnabled;
	bool emergencyStatus;
	AccessSystem();

public:

	static AccessSystem sys;

	void enableLog();
	void disableLog();
	void activateEmergency();
	void deactivateEmergency();
	bool checkAccess(User* user, Room* room);
	bool grantCustomAccess(User* user, Room* room);
	bool withdrawAccess(User* user, Room* room);
	int createUserAccount();
};
```

### enableLog()

Enables log to admin's console

### disableLog()

Disables log to admin's console

### activateEmergency()

Activates emergency mode of the system

### deactivateEmergency()

Activates emergency mode of the system

### checkAccess(user, room)

Checks permission of the user to open the room based on `accessLevel` of the room, `accessibleLevel` of the user, list of banned users from this room and users with custom access to this room (whitelist).

### grantCustomAccess(user, room)

Adds user to whitelist and removes from banlist of a specific room.

### withdrawAccess(user, room)

Adds user to banlist and removes from whitelist of a specific room.

### createUserAccount()

Starts the process of creating temporary user account in admin's console. Returns id of newly created account

## Other information

This is not stable release of a program. You are running this program at your own risk.

Copyright © 2021. All rights reserved.