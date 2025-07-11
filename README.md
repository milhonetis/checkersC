In order to compile this program, you will need a version of GCC on either Windows or Linux.

Use gcc main.c board.c -o checkers.exe to compile the .exe on windows.

You can run the .exe and begin to chose w/W for white which will leave player two with black (b/B).
After that you can run any legal moves you'd like.
For example: Player one's first move might be 11 5 and, when the second prompt shows, 9 5. This will move the center piece a space.
Note that for now, columns and rows must be odd numbers (1..3..5....) (Use the lines to the left as visual queues. Columns will also need a redesign to allign properly with the table columns).

No win condition is made for now neither double eating pieces or queen promotions.