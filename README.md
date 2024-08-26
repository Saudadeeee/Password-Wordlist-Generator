# Password Wordlist Generator

The **Password Wordlist Generator** is a C++ application that creates detailed wordlists based on a variety of user-specified input parameters. This tool is useful for security professionals and researchers who need to generate custom password lists for testing and auditing purposes.

## Features

- Generate wordlists from various input elements including names, nicknames, dates of birth, pet names, partner names, and special characters.
- Customizable to include combinations that meet specific criteria, such as length and inclusion of special characters.
- Supports generating combinations with prefixes and different lengths.

## Requirements

- C++17 or later
- A C++ compiler (e.g., g++, clang++)

## Installation

1. **Clone the repository:**

   ```bash
   git clone <repository-url>
   cd password-wordlist-generator
Compile the code:

bash

g++ -std=c++17 -o wordlist_generator main.cpp
Run the program:



./wordlist_generator
Usage
Run the executable:



./wordlist_generator
Provide input:

The program will prompt you to enter the following information. Type 'done' when you have finished entering each category.

Names (e.g., John, Alice)
Nicknames (e.g., Johnny, Ali)
Days of Birth (e.g., 01, 15)
Months of Birth (e.g., 01, 12)
Years of Birth (e.g., 1990, 2000)
Pet Names (e.g., Fluffy, Spot)
Partner Names (e.g., Jane, Bob)
Special Characters (e.g., @, #, $)
Enter the output file name:

The program will generate the wordlist and save it to the specified file.

Customization
Password Length: Adjust the code to change the minimum length requirement for the passwords.
Special Character Inclusion: Modify the special character list to match the specific requirements of your tests.
Contributing
Contributions are welcome! Please open an issue or submit a pull request if you have suggestions or improvements.

License
This project is licensed under the MIT License - see the LICENSE file for details.
