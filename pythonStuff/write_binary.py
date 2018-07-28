import argparse
import numpy as np
import bitstring
import matplotlib.pyplot as plt

def multi_alignment():
    # Setup the argument parser
    parser = argparse.ArgumentParser(description="does some stuff",
                                     epilog="Use case: write_binary.py <pattern_name> <type>")
    parser.add_argument('pattern', help="valid entries: crosshair, \\, /, X, checkers")
    parser.add_argument('type', help="valid entries: frame, window")
    parser.add_argument('--frame_x', nargs='?', type=int, default=64)
    parser.add_argument('--frame_y', nargs="?", type=int, default=64)
    parser.add_argument('--window_x', nargs='?', type=int, default=64)
    parser.add_argument('--window_y', nargs='?', type=int, default=3)
    args = parser.parse_args()

    # Set up the frame and window based on user input values
    frame_size = args.frame_x * args.frame_y
    window_size = args.window_x * args.window_y if args.type == "window" else frame_size
    scans_per_frame = frame_size // window_size
    pxl_cnt = 0

    # Define the pixels based on word combinations
    # Each window pixel is an addition of the word type and pixel intensity
    # All full frame pixels consist of only pixel intensities
    start = 1024    # word sync value for the start of a new scan
    end1 = 512      # word sync value for the final pixel of a scan with odd pixel count
    end2 = 1536     # word sync value for the final pixel of a scan with even pixel count
    high = 2048     # high pixel value (equates with a '1')
    low = 256       # low pixel value (equates with a '0)

    # Initialize the stream buffer
    file_buf = np.array([])

    for i in range(0, scans_per_frame):
        for j in range(0, window_size):
            # Reset the counters on each new scan
            word = 0
            pxl = low

            # Set the window syncronization pixels
            if j == 0:
                word = start
            elif j == window_size-1:
                word = end1 if (window_size % 2 == 1) else end2

            # Generate a crosshair pattern
            if args.pattern == "crosshair":
                if (pxl_cnt // args.frame_x) == (args.frame_y / 2 - 1) or (pxl_cnt // args.frame_x) == (args.frame_y / 2):
                    pxl = high
                elif ((pxl_cnt % args.frame_x) % (args.frame_x / 2 - 1)) == 0 and ((pxl_cnt % args.frame_x) // (args.frame_x / 2 - 1)) == 1:
                    pxl = high
                elif ((pxl_cnt % args.frame_x) % (args.frame_x / 2)) == 0 and ((pxl_cnt % args.frame_x) // (args.frame_x / 2)) == 1:
                    pxl = high

            # Generate an X pattern
            if args.pattern == "x":
                if (pxl_cnt // args.frame_y) == (pxl_cnt % args.frame_x):
                    pxl = high
                if (pxl_cnt // args.frame_y) == (args.frame_x - (pxl_cnt % args.frame_x) - 1):
                    pxl = high

            # Generate a \ pattern
            if args.pattern == "\\":
                if (pxl_cnt // args.frame_y) == (pxl_cnt % args.frame_x):
                    pxl = high

            # Generate a / pattern
            if args.pattern == "/":
                if (pxl_cnt // args.frame_y) == (args.frame_x - (pxl_cnt % args.frame_x) - 1):
                    pxl = high

            #Generate a checkered pattern
            if args.pattern == "checker":
                if ((pxl_cnt // args.frame_y) % 2 == 0) and (pxl_cnt % 2 == 1):
                    pxl = high
                elif ((pxl_cnt // args.frame_y) % 2 == 1) and (pxl_cnt % 2 == 0):
                    pxl = high

            pxl_cnt += 1

            # Write the generated pixel values to the buffer
            file_buf = np.append(file_buf, [word + pxl]) if args.type == "window" else \
                    np.append(file_buf, [pxl])

    # Only full scans wil lbe loaded into the frame. If the window size doesn't fit
    # perfectly into the frame, fill the unused pixels with zeros.
    for i in range(pxl_cnt, frame_size):
        file_buf = np.append(file_buf, [0])

    # Resize the one dimensional array of pixel values to match the original frame dimensions
    file_buf = file_buf.reshape(args.frame_y, args.frame_x, order='C')

    # Plot/display the generated frame
    plt.subplot(111)
    plt.imshow(file_buf)
    plt.show()

if __name__ == '__main__':
    multi_alignment()