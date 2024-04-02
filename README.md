# Tools_Booking_System
This project provided a Self-served IoT station that allows the users to borrow and return the IoT device by themselves. The station was developed for Hong Kong Polytechnic University students which users must use their Student ID card to identify. Besides, this self-served station contains the full functions of borrowing, returning, and administrator monitoring and controlling.

**Workflow**  
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/img/description-workflow.jpg)

**System Operattion Guidelines** 
----------------------------

#### Situation 1: Borrowing equipment
1. Tap Polyu's ID card on the card reader
2. Select Categories (IoT, Electronic, Hand Tools, Equipments)
3. Select an Item for borrowing
4. Select the quantity for borrowing
5. Double-check the input information and click the "Submit" button
6. Go to the Self-server Koisk to get the borrowed item in a specific container

#### Situation 2: Returning equipment
1. Tap Polyu's ID card on the card reader
2. Double-check the borrowed item list
3. Selected the borrowed item for returning
4. Selected the quantity of a borrowed item
5. Click the "Locker" button and wait for the corresponding container to open
6. Place the borrowed item inside the corresponding container and close it
7. Ask for the verification from administrator

#### Situation 3: Administrator controller
1. Tap Administrator Card
2. Select the Container ID
3. Wait for the container to open

**Dashboard Support**
----------------------------
All the Dashboard and operation can be completed via the touch screen monitor with Raspberry Pi or NUC. The only requirement is that the controller needs to install the browser and be able to connect to the internet.

##### Borrowing Dashboard
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/img/borrow_full.JPG)

##### Returning Dashboard
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/img/return_full.jpg)

##### Administrator Dashboard
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/img/admin_full.jpg)

**Data Record Format**
----------------------------
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/img/psotgre_database.jpg)

**Product Demonstration**
----------------------------
##### Borrow equipment Demonstration
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/demo/borrow_demo.gif)

##### Return equipment Demonstration
![image](https://github.com/Summer-Lo/Tools_Booking_System/blob/main/doc/demo/return_demo.gif)

