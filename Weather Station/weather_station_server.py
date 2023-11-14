import socket
import pandas as pd
import csv

HOST = "127.0.0.1"
PORT = 1234
output_filename = 'weather_station_recordings.csv'
print("Weather Station server started...")

def record_to_csv(environmental_reading):
     with open(output_filename, 'a', newline='') as output_file:
        output_writer = csv.writer(output_file)
        output_writer.writerow(environmental_reading)

try:
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
                    record_to_csv([client_data_string])
                    server_response = f"SERVER RESPONSE: Recorded {client_data_string}"
                    client_socket.sendall(server_response.encode())
except: print("Server closed.")