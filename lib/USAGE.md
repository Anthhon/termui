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

This will display a text box with the message "Hello, termui!" inside, surrounded by asterisks `*` as the border.

You can also display text boxes at specific coordinates using the `termui_text_box_at` function. Here's an example:

```c
char message[] = "Hello, termui!";
termui_text_box_at(message, '*', 1, 3, 2);
```

This will display a text box with the message "Hello, termui!" inside, starting at column 3 and row 2, surrounded by asterisks `*` as the border.
