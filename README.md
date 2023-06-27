# termui

`termui` is a terminal graphical library made in C that make easier to create static graphical interfaces in the terminal.

## Features

- Draw borders using a specified character
- Create boxes with customizable dimensions and border characters
- Display text boxes with messages inside and borders
.
. (working on more features)
.

## Getting Started

### Prerequisites

To use `termui`, you need a C compiler and the standard C library.

### Installation

1. Clone the repository:

```bash
git clone https://github.com/your-username/termui.git
```

2. Include the termui.h header file in your C project:

```bash
#include "lib/termui.h"
```

3. Compile your C program with the termui library:
```bash
gcc -o myprogram myprogram.c lib/termui.c
```

## Usage

### Drawing Borders

The `termui_draw_border` function allows you to draw a border using a specified character. Here's an example:

```c
termui_draw_border('*');
```

This will draw a border using asterisks `*` around the terminal window.

### Creating Boxes

You can create boxes with customizable dimensions and border characters using the `termui_box_create` function. Here's an example:

```c
termui_box_create(10, 5, '#');
```

This will create a box with dimensions of 10 columns and 5 rows, using hashes `#` as the border character.

You can also create boxes at specific coordinates using the `termui_box_create_at` function. Here's an example:

```c
termui_box_create_at(10, 5, 3, 2, '+');
```

This will create a box with dimensions of 10 columns and 5 rows, starting at column 3 and row 2, using plus signs `+` as the border character.

### Displaying Text Boxes

The `termui_text_box` function allows you to display a text box with a message inside and a border. Here's an example:

```c
char message[] = "Hello, termui!";
termui_text_box(message, '*', 1);
```

This will display a text box with the message "Hello, termui!" inside, surrounded by asterisks (*) as the border.

You can also display text boxes at specific coordinates using the `termui_text_box_at` function. Here's an example:

```c
char message[] = "Hello, termui!";
termui_text_box_at(message, '*', 1, 3, 2);
```

This will display a text box with the message "Hello, termui!" inside, starting at column 3 and row 2, surrounded by asterisks (*) as the border.

## Contributing

Contributions to `termui` are welcome! If you'd like to contribute to the project, you can follow these steps:

1. Fork the repository on GitHub.
2. Create a new branch for your feature or bug fix.
3. Make your modifications and ensure the code follows the project's coding style.
4. Write tests to cover your changes if applicable.
5. Commit your changes and push them to your fork.
6. Submit a pull request to the `termui` repository.

Please ensure your pull request includes a clear description of the problem you're solving or the feature you're adding. It's also helpful to include any relevant information or context.

Before making significant changes, it's recommended to open an issue to discuss the proposed changes with the project maintainers. This can help ensure that your contribution aligns with the project's goals and can avoid duplication of efforts.

By contributing to `termui`, you agree that your contributions will be licensed under the [MIT License](LICENSE).

## Contact

If you have any questions, suggestions, or need assistance, feel free to reach out to the project maintainers by [opening an issue](https://github.com/Anthhon/termui/issues).

We appreciate your interest in contributing to `termui` and look forward to your contributions!
