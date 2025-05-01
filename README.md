# Minitalk

## Description

Minitalk is a simple client-server program demonstrating inter-process communication using POSIX signals (SIGUSR1 and SIGUSR2).

* The server starts and prints its Process ID (PID).
* The client takes the server's PID and a message string as command-line arguments.
* The client converts the message into a sequence of bits and sends each bit to the server using SIGUSR1 (for bit 0) and SIGUSR2 (for bit 1).
* The server listens for these signals, reconstructs the bits into bytes, and then assembles the original message.
* The client waits for an acknowledgment signal (SIGUSR1) from the server after sending each bit before sending the next one.
* Once the entire message is received (signaled by the client sending eight consecutive 0 bits), the server prints the message to the standard output and sends a final acknowledgment (SIGUSR2) to the client.
* The project uses a custom library `libft` for utility functions.

## Compilation

It's assumed you have `make` and a C compiler like `cc` installed.

1.  **Compile the `libft` library:**
    ```bash
    cd minitalker/libft
    make
    cd ..
    ```
    *(Note: This assumes `libft` has its own Makefile. If not, you'll need to compile its `.c` files into an archive `libft.a` manually)*

2.  **Compile the server and client:**
    ```bash
    # In the minitalker directory
    	make
    ```

## How to Run

1.  **Start the server:**
    Open a terminal and run:
    ```bash
    ./server
    ```
    The server will print its PID. Note this PID down.

2.  **Run the client:**
    Open another terminal and run:
    ```bash
    ./client <Server_PID> "Your message here"
    ```
    Replace `<Server_PID>` with the actual PID printed by the server. Replace `"Your message here"` with the text you want to send.

The server terminal should then display "Your message here", and the client terminal will show "Msg printed succesfully!".