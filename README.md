# Item Tracker - Portfolio Reflection

### 1. Summarize the project and what problem it was solving.
The Item Tracker project was designed for a grocery store client to analyze item purchasing frequencies from a daily text-based log file (`CS210_Project_Three_Input_File.txt`). The program processes this data to solve the problem of inventory tracking by tracking exactly how many times each item was purchased. It offers an interactive menu allowing users to look up a specific item's frequency, print a complete list of all items with their numerical frequencies, display a visual text-based histogram of purchases, and safely back up the aggregated data into a data file (`frequency.dat`).

### 2. What did you do particularly well?
I think I structured the object-oriented design particularly well by isolating the data management into a dedicated `GroceryItem` class and managing the inventory processing cleanly within `main.cpp`. Additionally, implementing data validation for the user input menu helped prevent the program from crashing or looping infinitely when an invalid menu choice or unexpected character was entered.

### 3. Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
The code could be enhanced by optimizing the search and storage mechanism. Currently, reading files sequentially works fine for smaller datasets, but implementing a hash map (`std::unordered_map`) to track the frequencies would significantly improve data retrieval speeds to $O(1)$ time complexity for large-scale files. From a security standpoint, hardcoded filenames could be replaced with user-defined paths that undergo strict input sanitization to ensure malicious system files cannot be targeted.

### 4. Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adapting?
The most challenging part was managing file I/O operations seamlessly—specifically, handling the edge case where the input file might be missing or corrupt, and ensuring `frequency.dat` correctly updated every time the program ran. I overcame this by leveraging standard library documentation (`<fstream>`) and using CLion's built-in debugger to inspect the stream states (`.is_open()` and `.fail()`) during runtime execution.

### 5. What skills from this project will be particularly transferable to other projects or course work?
The object-oriented programming principles, file stream handling, and strict input validation routines are highly transferable skills that I will apply directly to upcoming 300-level computer science coursework. Understanding how to model real-world data tracking into clean C++ classes forms a foundational bridge into building database applications and systems-level software.

### 6. How did you make this program maintainable, readable, and adaptable?
To ensure high maintainability and readability, I strictly adhered to industry standards by modularizing the project into separate header (`.h`) and implementation (`.cpp`) files. I used descriptive, camelCase variable names, maintained consistent indentation, and thoroughly commented the logic across functions. This clear separation of concerns makes the codebase highly adaptable if the client decides to migrate from text files to a relational database layout in the future.