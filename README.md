# Inventory Management System  

## Overview  
The **Inventory Management System** is a command-line application written in C that allows users to manage inventory items efficiently. It supports adding, viewing, updating, and deleting items, along with generating reports about inventory levels. This project is ideal for learning about file handling, structures, and basic algorithms in C.  

---

## Features  
- Add new inventory items.  
- View all inventory items.  
- Search for items by name or ID.  
- Update existing inventory details.  
- Delete items from the inventory.  
- Save and retrieve data from files for persistence.  

---

## Requirements  
To run this program, you need:  
- A C compiler (e.g., GCC)  
- Basic knowledge of command-line tools  

---

## How to Run  

1. **Clone the Repository**  
   ```bash  
   git clone https://github.com/KIRIT-P-S/Inventory-Management.git  
   cd Inventory-Management  
   ```  

2. **Compile the Program**  
   ```bash  
   gcc inventory_management.c -o inventory_management  
   ```  

3. **Run the Program**  
   ```bash  
   ./inventory_management  
   ```  

---

## File Structure  

- **inventory_management.c**: The main source code for the program.  
- **inventory.txt**: A file where inventory data is stored persistently.  

---

## Usage  

1. **Main Menu**:  
   Upon running the program, you'll see a menu with options to choose from.  

2. **Operations**:  
   - **Add Item**: Enter details like item name, ID, quantity, and price.  
   - **View Items**: Display a list of all inventory items.  
   - **Search Item**: Look for an item using its name or ID.  
   - **Update Item**: Modify the details of an existing item.  
   - **Delete Item**: Remove an item from the inventory.  
   - **Exit**: Save data to the file and exit the program.  

---

## Example Workflow  

1. Add a new item:  
   ```  
   Enter Item ID: 101  
   Enter Item Name: Widget  
   Enter Quantity: 50  
   Enter Price: 25.99  
   ```  

2. View the list of items:  
   ```  
   ID    Name      Quantity    Price  
   101   Widget    50          25.99  
   ```  

3. Update an item:  
   ```  
   Enter Item ID to Update: 101  
   Enter New Quantity: 60  
   ```  

---

## Contributing  

1. Fork the repository.  
2. Create a new branch (`git checkout -b feature-branch`).  
3. Commit your changes (`git commit -m "Added a new feature"`).  
4. Push the branch (`git push origin feature-branch`).  
5. Create a pull request.  

---

## License  

This project is licensed under the MIT License.  

---
