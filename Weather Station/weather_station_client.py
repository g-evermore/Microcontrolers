import socket

HOST = "127.0.0.1"
PORT = 1234

input_msg = input("Please provide a messag to send to server:\n")

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.connect((HOST, PORT))
    byt_input_msg = input_msg.encode()
    sock.sendall(byt_input_msg)
    byt_server_response = sock.recv(1024)

print(f"{byt_server_response.decode()}")