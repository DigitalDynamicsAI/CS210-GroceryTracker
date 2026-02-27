# CS 210 Grocery Tracker (Corner Grocer Item-Tracking Program)

## Project Summary (What problem this solves)
This project is a grocery item-tracking program built for the Corner Grocer scenario. The store keeps a daily text log of purchased items (one item per line, recorded in order throughout the day). The goal of the program is to analyze that file and calculate how often each item appears so the store can make better decisions about how to organize the produce section.

The program provides a simple menu that lets the user:
1. Search for a specific item and return its purchase frequency  
2. Print a full list of all items with their frequencies  
3. Print a text-based histogram using asterisks to visualize frequencies  
4. Exit the program  

It also writes a backup output file (`frequency.dat`) that stores the calculated counts for all items.

---

## What I did particularly well
- I broke the problem into smaller pieces so the program flow stayed simple: load data, show menu, handle user choice, repeat.
- I used a data structure that supports fast lookups for item frequencies, which made searching for a single item straightforward.
- I kept the output user-friendly by formatting the list and histogram in a readable way.
- I created the `frequency.dat` file automatically so the user doesn’t have to do anything extra to generate the backup.

---

## Where I could enhance the code (and why it matters)
If I had more time, I would improve a few areas:
- **Input normalization:** Make item searches case-insensitive (ex: “apples” vs “Apples”) and trim extra spaces. This would reduce user errors and make the tool feel more reliable.
- **Stronger input validation:** Handle non-numeric menu input more safely and keep the program from getting stuck if the user types unexpected values.
- **Error handling for files:** Add clearer messages if the input file is missing or cannot be opened, and fail gracefully instead of continuing with empty data.
- **More modular design:** Move file loading and menu rendering into smaller helper functions or separate files. That would make the program easier to extend and maintain.

These improvements would make the code more secure (fewer crash cases), more efficient for real users (less friction), and easier to evolve over time.

---

## Most challenging parts and how I overcame them
The hardest part was getting everything to work together cleanly: reading the input file, building the frequency data, and then producing multiple outputs (single item search, full list, histogram, and the backup file) without duplicating logic.

What helped me get through it:
- Testing each part separately (file reading first, then counting, then menu options)
- Using debugging output to confirm the program was reading the file correctly before worrying about formatting
- Referring back to zyBooks sections on file input/output and maps when I got stuck on syntax or logic

Going forward, I’m adding these to my support network:
- C++ reference documentation (cppreference)
- Visual Studio debugging tools (breakpoints/watch variables)
- Short test input files to validate program behavior quickly

---

## Skills that transfer to other projects
This project strengthened skills that apply to almost any software project:
- Breaking requirements into an implementation plan
- File input/output (reading source data, writing output data)
- Using data structures to solve real problems efficiently
- Designing menu-driven programs and clean control flow
- Debugging and validating program behavior with test inputs

---

## How I made the program maintainable, readable, and adaptable
To keep the program maintainable and readable, I focused on:
- Using clear variable and function naming to make intent obvious
- Keeping the menu logic predictable and organized with a consistent structure
- Using comments where needed to clarify what a section of code is doing
- Avoiding “magic behavior” by keeping the program flow easy to follow (load data → menu loop → handle choice)

With a few extensions (like case-insensitive matching and stronger input handling), the program could be adapted to support larger datasets, different item categories, or even additional reporting options.

---

## How to run
- Open the project in Visual Studio
- Build and run the solution
- Make sure `CS210_Project_Three_Input_File.txt` is present in the expected project directory so the program can read it
