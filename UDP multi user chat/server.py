import os
import socket
import threading

class Server:
	clients = []
	def create(self):
		self.port = 25000
		self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
		self.sock.bind(('',self.port))
		print("Socket binded successfuly to port : "+str(self.port))
		self.chatWindow()
		return

	def chatWindow(self):
		os.system("clear")
		print("Chat Messenger Server : \n")
		threadS = threading.Thread(target = self.sender)
		threadR = threading.Thread(target = self.receiver)

		threadS.start()
		threadR.start()

	def sender(self):
		while True:
			msg = bytes(input(),"utf-8")
			for i in self.clients:
				self.sock.sendto(msg,i)

	def receiver(self):
		while True:
			msg , self.addr = self.sock.recvfrom(1024)

			if(self.addr not in self.clients):
				self.clients.append(self.addr)
			else:
				print("Message from "+str(self.addr)+" : "+str(msg.decode("utf-8")))
				msg = str(msg.decode("utf-8"))
				msg = msg + "|||" + str(self.addr)
				for i in self.clients:
					if(i != self.addr):
						self.sock.sendto(bytes(msg,"utf-8"),i)

if __name__ == '__main__':
	server = Server()
	server.create()

