import socket

HOST = "127.0.0.1"
PORT = 1234

print("Weather server stated...")
while(True):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind((HOST, PORT))
        sock.listen()
        client_socket, client_address = sock.accept()
        with client_socket:
            print(f"Sever connected to client at address: {client_address}")
            while True:
                client_data = client_socket.recv(1024)
                client_data_string = client_data.decode()
                if not client_data:
                    break
                server_response = f"SERVER RESPONSE: {client_data_string}"
                client_socket.sendall(server_response.encode())