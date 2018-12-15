[This file mostly serves as a placeholder so Git keeps it in the repo even when no files exist.]

A place to store any useful Python code/snippets that could come in handy for designs.

When using CircuitPython, the following describe its use of the RGB status light:
    The Feather M0 Express, Feather M4 Express, Metro M0 Express, Metro M4 Express, ItsyBitsy M0 Express, ItsyBitsy M4 Express, Gemma M0, and Trinket M0 all have a single NeoPixel or DotStar RGB LED on the board that indicates the status of CircuitPython.

    Circuit Playground Express does NOT have a status LED. The LEDs will pulse green when in the bootloader. They do NOT indicate any status while running CircuitPython.

    Here's what the colors and blinking mean:

    steady GREEN: code.py (or code.txt, main.py, or main.txt) is running
    pulsing GREEN: code.py (etc.) has finished or does not exist
    YELLOW: Circuit Python is in safe mode: it crashed and restarted
    WHITE: REPL is running
    BLUE: Circuit Python is starting up
    Colors with multiple flashes following indicate a Python exception and then indicate the line number of the error. The color of the first flash indicates the type of error:

    GREEN: IndentationError
    CYAN: SyntaxError
    WHITE: NameError
    ORANGE: OSError
    PURPLE: ValueError
    YELLOW: other error
    These are followed by flashes indicating the line number, including place value. WHITE flashes are thousands' place, BLUE are hundreds' place, YELLOW are tens' place, and CYAN are one's place. So for example, an error on line 32 would flash YELLOW three times and then CYAN two times. Zeroes are indicated by an extra-long dark gap.